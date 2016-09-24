# Makefile for cse6010 hw2-queueing-model

simulate:
        gcc -std=c99 ../src/event/*.h ../src/event/*.c/ \
        ../src/utils/priority_queue/*.h ../src/utils/priority_queue/*.h \
        ../src/utils/queue/*.h ../src/utils/queue/*.h \
        ../src/utils/random/*.h ../src/utils/random/*.h \
        -o ../bin/simulate

clean:
        rm -rf ../bin/simulate