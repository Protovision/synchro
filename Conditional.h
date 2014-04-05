#ifndef CONDITIONAL_H
#define CONDITIONAL_H

#include "Atom.h"

class Conditional {
protected:
	Atom atom;
public:
	Conditional() : atom(1) {}
	
	void wait() {
		while ((atom = 1) == 1);
	}
	void signal() {
		atom = 0;
	}
	void broadcast() {
		while ((atom = 0) == 1);
	}
};

#endif
