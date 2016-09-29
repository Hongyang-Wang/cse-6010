# this script runs the program with debug info printed, and uses valgrind to check memory leakage
valgrind --tool=memcheck ../bin/simulate 10 30 3 50 1
