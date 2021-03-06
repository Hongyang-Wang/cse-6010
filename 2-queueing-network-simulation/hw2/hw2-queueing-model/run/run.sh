# this script runs a set of simulations with different arrival rate 1/A
S=10  # average service time
TOTAL_TIME=10000  # total simulation time
NUM_STATIONS=3
IS_DEBUG=0

# running simulation
for A in $(seq 11 1 19)
do
    ../bin/simulate ${S} ${A} ${NUM_STATIONS} ${TOTAL_TIME} ${IS_DEBUG}
done
