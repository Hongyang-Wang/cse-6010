# define arguments
S=10  # average service time
TOTAL_TIME=10000  # total simulation time
NUM_STATIONS=3
IS_DEBUG=0

# running simulation
for A in $(seq 1 1 100)
do
    ../bin/simulate ${S} ${A} ${NUM_STATIONS} ${TOTAL_TIME} ${IS_DEBUG}
done
