#!/bin/bash
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=SimpleSampleClient-valgrind-out.txt \
         ./build/SimpleSampleClient

valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --log-file=SimpleClientWithThreads-valgrind-out.txt \
         ./build/SimpleClientWithThreads