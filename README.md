# Closest-Pair-of-Points
AUTHOR
=======
Spencer MacMaster

DESCRIPTION
============
C++ implementation of the Closest Pair of Points Brute
Force O(N^2) Algorithm  and Closets Pair of Points Recursive O(N(Log(N)) Algorithm.

INPUT FILE SETUP
===============
Write input to the "data" file or  INPUT_FILENAME(a user specified) using the format below:
To view results open the "output" or OUTPUT_FILENAME (user specified) file. 

INPUT FORMAT
~~~~~~~~~~~~
NumberOfPoints(N) DebugMode(0: OFF, 1: ON)
xCoord1 yCoord1
...
xCoordN yCoordN

EXAMPLE INPUT
~~~~~~~~~~~~~
2 0
1 1
5 3

EXAMPLE OUTPUT
~~~~~~~~~~~~~~~
Closest pair by O(n^2) algorithm: (1, 1) (5, 3)
Distance: 4.472136
Time: 13 ms.

Closest pair by O(nlog(n)) algorithm: (1, 1) (5, 3)
Distance: 4.472136
Time: 3 ms.

n: 2
time2/(n*log(n)): 2.164042
time2/(n*log(n)^2): 3.122053

HOW TO RUN
===========
Run 'make' to compile the program and create the executable 'run' using the makefile.
Execute the created run executable by calling:
./run 
 OR
./run INPUT_ FILENAME
 OR 
./run INPUT_FILENAME OUTPUT_FILENAME

Also has the commands 'make clean' and 'make tar'

BASH COMMANDS EXAMPLES
~~~~~~~~~~~~~~~~~~~~~~~~
Reads input from "data" file and writes results to "output" file
$ make
$ ./run

OR

Reads input from INPUT_FILENAME file and writes results to "output" file
$ make
$ ./run INPUT_FILENAME

OR

Reads input from INPUT_FILENAME file and writes results to OUTPUT_FILENAME file.
$ make
$ ./run INPUT_FILENAME OUTPUT_FILENAME

INCLUDED FILES
===============

HEADER FILES
~~~~~~~~~~~~
CPAlgo.h
FileSysIO.h
Pair.h
Point.h

C++ PROGRAM FILES
~~~~~~~~~~~~~~~~~~
Main.cpp
CPAlgo.cpp
FileSysIO.cpp
Pair.cpp
Point.cpp

OTHER FILES
~~~~~~~~~~~
README.md
makefile
data
output
