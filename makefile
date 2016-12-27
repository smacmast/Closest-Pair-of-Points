OBJS = Main.o FileSysIO.o Point.o Pair.o CPAlgo.o
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

run : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o run

Main.o : Main.cpp FileSysIO.cpp FileSysIO.h Point.cpp Point.h Pair.cpp Pair.h CPAlgo.cpp CPAlgo.h
	$(CC) $(CFLAGS) Main.cpp

FileSysIO.o : FileSysIO.cpp FileSysIO.h Point.cpp Point.h
	$(CC) $(CFLAGS) FileSysIO.cpp

CPAlgo.o : CPAlgo.cpp CPAlgo.h FileSysIO.cpp FileSysIO.h Pair.cpp Pair.h Point.cpp Point.h
	$(CC) $(CFLAGS) CPAlgo.cpp

Pair.o : Pair.cpp Pair.h Point.cpp Point.h
	$(CC) $(CFLAGS) Pair.cpp

Point.o : Point.cpp Point.h
	$(CC) $(CFLAGS) Point.cpp

clean:
	\rm *.o *~ run

tar:
	tar cfv run.tar Main.cpp FileSysIO.cpp FileSysIO.h Point.cpp Point.h Pair.cpp Pair.h CPAlgo.cpp CPAlgo.h
