# Makefile for cse6010 hw2-queueing-model

simulate:
	gcc -std=c99 -lm test-pq.c \
	../src/event/event_data.h \
        ../src/utils/priority_queue/PriorityQueue.h ../src/utils/priority_queue/PriorityQueue.c \
        ../src/utils/random/random.h ../src/utils/random/random.c \
        -o ../bin/test-pq

clean:
	rm -rf ../bin/test-pq
