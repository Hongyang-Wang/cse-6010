# Makefile for cse6010 hw2-queueing-model

simulate:
	gcc -std=c99 -lm ../src/main.c \
	../src/event/event_data.h ../src/event/event_handler.c ../src/event/event_handler.h \
        ../src/utils/priority_queue/PriorityQueue.h ../src/utils/priority_queue/PriorityQueue.c \
        ../src/utils/queue/Queue.h ../src/utils/queue/Queue.c \
        ../src/utils/random/random.h ../src/utils/random/random.c \
        -o ../bin/simulate

clean:
	rm -rf ../bin/simulate
