# this script runs the program with debug info printed, and uses valgrind to check memory leakage
valgrind --tool=memcheck ../bin/simulate 10 3 3 100 1
