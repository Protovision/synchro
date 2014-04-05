#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "Atom.h"

class Semaphore {
protected:
	Atom _count;
	Atom _lock;
public:
	Semaphore(int32_t count) : _count(count), _lock() {}
	
	void lock() {
		if ((_lock = 1) == 0) {
			if ((_count -= 1) > 1) {
				_lock = 0;
			}
			return;
		} else while ((_lock = 1) == 1);
		_count -= 1;
		return;
	}
	bool trylock() {
		if ((_lock = 1) == 0) {
			if ((_count -= 1) > 1) {
				_lock = 0;
			}
			return true;
		} return false;
	}	
	void unlock() {
		_count += 1;
		_lock = 0;
	}	
};

#endif
