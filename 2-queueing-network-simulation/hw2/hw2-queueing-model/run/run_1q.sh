# this script runs a set of simulations with only one station in the system, and compares with the theory
S=2  # average service time
A=3.333333  # average interarrival time
TOTAL_TIME=50000  # total simulation time
NUM_STATIONS=1
IS_DEBUG=0

# running simulation
for i in $(seq 1 1 20)
do
    ../bin/simulate ${S} ${A} ${NUM_STATIONS} ${TOTAL_TIME} ${IS_DEBUG}
    sleep 1  # sleep to get different random seed for each run
done
