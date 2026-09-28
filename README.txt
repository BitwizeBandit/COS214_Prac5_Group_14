COS 214 Practical 5 - CampusGuard (Group 14)
=============================================

Team
  Dian le Roux      u25147065
  Motheo Motsemme   u25099184
  Heinrich Klopper  u25030932

CampusGuard is an emergency-response coordination demo for a university campus.
WorkFlow (Facade) runs three end-to-end stories: a fire drill, a medical
emergency and a security breach. Each story is driven by Command objects made
by Factory Methods and handled by decorated response Teams, while the buildings
coordinate through a Mediator and the access control goes through an Adapter.


1. Build and run with Docker (the way the project is assessed)
---------------------------------------------------------------
Requirements: Docker with the "docker compose" plugin.

From the repository root:

    docker compose up --build

This builds the image from the Dockerfile (Ubuntu 22.04, g++, make, gdb,
valgrind), runs "make" inside it (-std=c++11 -Wall -Wextra) and starts the
application. The program prints the three stories and the container exits with
code 0.

If Docker reports that the container name "/campusguard" is already in use
(left over from an earlier run), remove it and run again:

    docker rm campusguard
    docker compose up --build

To clean up afterwards:

    docker compose down


2. Build and run without Docker
-------------------------------
    make
    ./campusguard
    make clean

"make debug" rebuilds with -g -O0 for use with gdb.


3. Valgrind evidence (inside Docker)
------------------------------------
    docker compose run --rm campusguard valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./campusguard

Expected result: "All heap blocks were freed -- no leaks are possible" and
"ERROR SUMMARY: 0 errors from 0 contexts".


4. GDB investigation (inside Docker)
------------------------------------
gdb_demo/ holds a reproduction of a real bug we found and fixed: the decorators'
allClear() only passed the all-clear down the chain if that decorator was
itself deployed. gdb_demo/Team.h is the ORIGINAL (buggy) Team.h from commit
8fce590, kept only for this demonstration. The fixed version is ./Team.h.

    docker compose run --rm campusguard bash

then, inside the container:

    g++ -std=c++11 -g -O0 -I. gdb_demo/chain_bug.cpp Building.cpp Mediator.cpp EmergencyCoordinator.cpp SecurityBuilding.cpp MedicalBuilding.cpp Facilities.cpp -o chain_bug
    ./chain_bug
    gdb -q -batch -x gdb_demo/commands.gdb ./chain_bug

If GDB cannot attach ("ptrace: Operation not permitted"), start the container
with:  docker compose run --rm --cap-add=SYS_PTRACE --security-opt seccomp=unconfined campusguard bash


5. Design summary
-----------------
Pattern participants:

  Command          Command (abstract); FireEmergency, MedicalEmergency,
                   SecurityBreach, AllClear (concrete). Invoker/client: WorkFlow.
                   Receiver: Team (via dispatch() / allClear()).
  Mediator         Mediator (abstract); EmergencyCoordinator (concrete).
                   Colleagues: Building; SecurityBuilding, MedicalBuilding,
                   Facilities.
  Adapter          Target: BuildingAdapter (lock/unlock). Adapter:
                   BuildingAdapterImpl (object adapter). Adaptee: Building
                   (legacy toggleLocked()/getLocked()).
  Facade           WorkFlow: fireDrill(), medicalEmergency(), securityBreach().
  Factory Method   Factory (creator); FireEmergencyFactory, MedicalEmergencyFactory,
                   SecurityBreachFactory, AllClearFactory. Product: Command.
  Decorator        Component: Team. ConcreteComponent: BasicTeam. Decorator:
                   Decorator. ConcreteDecorators: SecurityTeam, MedicalTeam,
                   FacilitiesTeam.

Ownership and destruction policy:

  - Everything in a WorkFlow story (buildings, mediator, teams, adapter,
    factories) is a stack object owned by that WorkFlow method, and is released
    automatically when the method returns.
  - Buildings are declared before the mediator and the teams, so they are
    destroyed last and are never used after destruction.
  - Commands are the only heap objects. A Factory returns a raw pointer from
    "new"; the caller (WorkFlow) owns it and deletes it after solve().
  - Non-owning links: the Mediator keeps references (std::reference_wrapper) to
    the buildings, each Building keeps a non-owning Mediator*, each Command keeps
    a Team&, the Adapter keeps a Building&, and each Decorator keeps a non-owning
    Team* and building pointer to objects that outlive it.
  - Every polymorphic base has a virtual destructor: Team, Command, Factory,
    Mediator, Building, BuildingAdapter.

Invalid operations are reported, not ignored: locking an already locked
building prints "Adapter: building is already locked, no action taken." and
leaves the state unchanged
