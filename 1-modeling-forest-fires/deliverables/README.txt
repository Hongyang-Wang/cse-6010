CSE 6010
Assignment 1 - Modeling Forest Fires
Hongyang Wang
Sep 6, 2016

Instructions

1. Folder structure
	README.txt    // instructions on the software
	bin/    // a folder containing the executable after compile
		modeling-forest-fires    // the executable file for doing one simulation
	run/    // a folder containing the makefile and scripts to run the program
		Makefile    // the makefile
		run.sh    // the shell script to run a set of simulations with different g and f
		run_debug.sh    // the shell script to run a mini-scale simulation with debug info printed
	src/    // a folder containing all the C source code
		forest_fire.c    // a source file containing all the core functions needed for the simulation
		forest_fire.h    // the according header file
		main.c    // main function to run the simulation with command-line argument inputs
	report/
		report.pdf    // report of the assignment with the literature survey included

2. How to compile
	1) cd run
	2) make

3. How to run
	a) To run with debugging info
		1) cd run
		2) sh run_debug.sh
	b) To run the set of simulations for the plot	
		1) cd run
		2) sh run.sh
	c) Manually run the executable to test with any parameter sets
		1) cd bin
		2) ./modeling-forest-fires <height-of-grid> <width-of-grid> <g> <f> <num-of-iterations> <is-debug>
		   For example, ./modeling-forest-fires 10 10 0.2 0.1 100 1

