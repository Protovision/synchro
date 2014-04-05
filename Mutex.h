#ifndef MUTEX_H
#define MUTEX_H

#include "Atom.h"

class Mutex {
protected:
	Atom atom;
public:
	void lock() {
		while ((atom = 1) == 1);
	}
	bool trylock() {
		return (atom = 1) == 0;
	}
	void unlock() {
		atom = 0;
	}
	
};

#endif
