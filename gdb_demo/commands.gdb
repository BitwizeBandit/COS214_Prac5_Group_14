set pagination off
set print object on
break SecurityTeam::allClear
run
echo \n--- Stopped at SecurityTeam::allClear (outer team) ---\n
print this->deployed
print this->team->deployed
print *this->team
echo \n--- Step over the if (deployed) check ---\n
next
echo \n--- Step out to main ---\n
next
print medicalTeam.deployed
continue
