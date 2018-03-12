connectn.out: winLose.o playTurns.o boardWork.o readArgs.o main.o
	gcc -Wall -g -o connectn.out winLose.o playTurns.o boardWork.o readArgs.o main.o

main.o: main.c winLose.h playTurns.h boardWork.h readArgs.h
	gcc -Wall -g -c main.c

winLose.o: winLose.c winLose.h
	gcc -Wall -g -c winLose.c

playTurns.o: playTurns.c winLose.h boardWork.h
	gcc -Wall -g -c playTurns.c

boardWork.o: boardWork.c boardWork.h
	gcc -Wall -g -c boardWork.c

readArgs.o: readArgs.c readArgs.h
	gcc -Wall -g -c readArgs.c

clean:
	rm *.o *.out
