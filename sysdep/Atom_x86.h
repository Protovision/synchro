#ifndef ATOM_H
#define ATOM_H

#include <stdint.h>

class Atom {
protected:
	volatile int32_t value;
public:
	Atom() : value() {}
	Atom(int32_t val) : value(val) {}

	inline int32_t	operator = (int32_t val) {
		asm("lock xchgl %0, %1" : "+r"(val), "+m"(value));
		return val;
	}
	inline int32_t	operator += (int32_t val) {
		asm("lock xaddl %1, %0" : "+m"(value), "+r"(val));
		return val;
	}
	int32_t	operator -= (int32_t val) {
		val *= -1;
		asm("lock xaddl %1, %0" : "+m"(value), "+r"(val));
		return val;
	}
	int32_t	operator &= (int32_t val);
	int32_t	operator |= (int32_t val);
	int32_t	operator ^= (int32_t val);
	
	int32_t	operator ++ ();
	int32_t	operator ++ (int);
	int32_t	operator -- ();
	int32_t	operator -- (int);
};

#endif

