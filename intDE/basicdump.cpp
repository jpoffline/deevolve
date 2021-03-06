#include "basicdump.h"

// Function to print data before the run starts
void BasicDump::printinfo(const double data[], IntParams &params) {

	// Require scientific notation, 15 digits
	myLog->precision(15);

	// Print the header
	cout << "Beginning evolution" << endl;
	*myLog << "Omega_m: \t" << params.getparams().OmegaM() << endl;
	*myLog << "Omega_k: \t" << params.getparams().OmegaK() << endl;
	*myLog << "T_gamma: \t" << params.getparams().Tgamma() << endl;
	*myLog << "Omega_r: \t" << params.getparams().OmegaR() << endl;
	*myLog << "h: \t" << params.getparams().h() << endl;
	*myLog << "z_init: \t" << params.getparams().z0() << endl;
	*myLog << "rho_c: \t" << params.getparams().rhoc() << endl << endl;

}

// Function to print a header before output starts (e.g., column headings)
void BasicDump::printheading(const double data[], IntParams &params) {

	// Dumping everything. Make nice headers.
	//*myData << "time, a, redshift, H, Hdot, phi, phidot, phiddot, Omega_m, Omega_r, Omega_k, Omega_Q, w_total, rho_Q/rho_c, P_Q/rho_c, w_Q, Error" << endl;
	*myLog << "Columns in data file are as follows."
		   << endl
		   << "time, a, redshift, H, Hdot, phi, phidot, phiddot, Omega_m, Omega_r, Omega_k, Omega_Q, w_total, rho_Q/rho_c, P_Q/rho_c, w_Q, Error"
		   << endl << endl;

	// Set up the output form
	*myData << scientific;
	myData->precision(15);

}

// Function to print information after each timestep
void BasicDump::printstep(const double data[], double time, IntParams &params, double status[]) {

	/* Just as a reminder...
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
	   * 16 Error
	 */

	// We are just dumping everything here, except for consistency flags
	for (int i = 0; i < 16; i++)
		*myData << status[i] << ", ";
	*myData << status[16] << endl;

}

// Constructor
BasicDump::BasicDump(const std::string &filename) {

	// Give a message about the output filename
	cout << "Outputting to " << filename << endl;

	// Construct filenames
	string logfile = filename + ".log";
	string datfile = filename + ".dat";

	// Open the log files
	myLog = new ofstream(logfile.c_str());
	myData = new ofstream(datfile.c_str());

}

// Destructor
BasicDump::~BasicDump() {

	// Close the log files...
	myLog->close();
	myData->close();

	// ... and release memory
	delete myLog;
	delete myData;

}

// Did the files open correctly?
bool BasicDump::filesready() {

	if (myLog->is_open() && myData->is_open())
		return true;
	else
		return false;

}

// Print a "We're done!" message
void BasicDump::printfinish(const double time) {
	*myLog << setprecision(4) << "Evolution complete in " << time << " milliseconds." << endl;
	cout << "Evolution complete" << endl;
}

// Print a line to the log file
void BasicDump::printlog(const std::string &output) {
	*myLog << output << endl;
}
