/*
 * model.h
 *
 * This defines an abstract "Model" class. Any dark energy model can be built off this class. At the very least, it must
 * implement the equations of motion in the derivatives function. Fancier implementations can also compute the speed of sound
 * and check for ghosts.
 *
 * Also available is a state function, which can compute a variety of (useful?) information from the present state.
 *
 */

#ifndef MODEL_H_
#define MODEL_H_

#include "params.h"

// This defines the Model abstract class.
// Individual models will inherit this class and implement the appropriate functions.
class Model {
	public:
		// The derivatives routine is given the state of the system (a, phi and \dot{\phi}) as well as the parameters of the system,
		// and returns the derivatives (\dot{a}, \dot{\phi}, \ddot{\phi})
		virtual int derivatives(const double data[], double derivs[], Parameters &params) = 0;
		/* The state routine is given the state of the system as well as the parameters of the model,
		   and returns information in the info array. The return values are as follows:

		   * 0 time
		   * 1 a
		   * 2 Redshift
		   * 3 H = \dot{a}/a
		   * 4 \dot{H}
		   * 5 phi
		   * 6 \dot{phi}
		   * 7 \ddot{phi}
		   * 8 Omega_matter (present value)
		   * 9 Omega_radiation (present value)
		   * 10 Omega_k (present value)
		   * 11 Omega_Q (present value)
		   * 12 w_total
		   * 13 rho_Q / rho_c
		   * 14 P_Q / rho_c
		   * 15 w_Q

		   Note that this needs an array of 16 doubles to return these values

		 */
		virtual void getstate(const double data[], double time, double info[], Parameters &params) = 0;

		// The speedofsound2 returns the speed of sound squared, given the state of the system
		virtual double speedofsound2(const double data[], const double derivs[]) {return 0;}
		// The implementsSOS function returns whether or not a class actually implements the speedofsound2 function
		virtual bool implementsSOS() {return false;}

		// The isghost function is given the state of the system (and some derivatives, because those might be helpful)
		// and returns whether or not the theory has become ghostlike
		virtual bool isghost(const double data[], const double derivs[]) {return false;}
		// The implementsghost function returns whether or not a class acutlaly implements the isghost function
		virtual bool implementsghost() {return false;}

		// Virtual destructor
		virtual ~Model() {return;}

};

#endif /* MODEL_H_ */