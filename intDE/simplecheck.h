/*
 * simplecheck.h
 *
 * This provides a basic implementation of a consistency checking class.
 *
 */

#ifndef SIMPLECHECK_H_
#define SIMPLECHECK_H_

#include "consistency.h"

#include <cmath>
// stringstreams
#include <iostream>
#include <string>
#include <sstream>

class SimpleCheck : public Consistency {
	public:
		// Inherited functions
		void checkstate (double*, double, IntParams&, Output&, double*);
		void checkfinal (double*, double, IntParams&, Output&, double*);
};



#endif /* SIMPLECHECK_H_ */
