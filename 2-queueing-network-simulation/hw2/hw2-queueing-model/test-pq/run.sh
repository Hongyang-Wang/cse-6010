# this script measures the performance of the priority queue
NUM_ITERS=1000  # total number of insertions and deletions in the for loop

# testing performance
for ((N=10000; N <= 100000; N+=10000))
do
    ../bin/test-pq ${N} ${NUM_ITERS}
done
