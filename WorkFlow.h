#ifndef WORKFLOW_H
#define WORKFLOW_H

// Facade: one call per realistic CampusGuard workflow. Each method builds the
// buildings, mediator, decorated team and command it needs on the stack, so the
// client never has to connect the subsystems together itself
class WorkFlow
{
	public:
		// Facade + Factory + Command + Decorator + Mediator
		void fireDrill();
		// Facade + Factory + Command + Decorator
		void medicalEmergency();
		// Facade + Factory + Command + Decorator + Mediator + Adapter
		void securityBreach();
};

#endif
