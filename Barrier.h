#ifndef BARRIER_H
#define BARRIER_H

#include "Atom.h"

class Barrier {
protected:
	int _count;
	Atom atom, lock;
public:
	Barrier(int count) : _count(count), atom(0), lock(1) {}
	
	void wait() {
		if ((atom += 1) == _count - 1) {
			atom = 0;
			while ((lock = 0) == 1);
		} else while ((lock = 1) == 1);
	}
};

#endif
