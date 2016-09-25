# this script measures the performance of the priority queue
NUM_ITERS=1000  # total number of insertions and deletions in the for loop

# testing performance
for ((N=1000; N <= 20000; N+=1000))
do
    ../bin/test-pq ${N} ${NUM_ITERS}
done
