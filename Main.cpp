/*
* @author: Spencer MacMaster
* @description: Main class of CSE 450 project.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

#include "Point.h"
#include "Pair.h"
#include "CPAlgo.h"
#include "FileSysIO.h"

#define ttime std::chrono::steady_clock::time_point

/*
* Writes the Closest Pair information to the file
*/
void outputCPTime(std::string ver, Pair cp, int ms, FileSysIO * fio) {
	fio->writeFile("Closest pair by O(" + ver + ") algorithm: " + cp.toString(), "\n");
	fio->writeFile("Distance: " + std::to_string(cp.dst), "\n");
	fio->writeFile("Time: " + std::to_string(ms) + " ms.", "\n");
}

/*
* Calls and times the Closest Point N ^ 2 Algorithm
*/
void AlgoN2(std::vector<Point> mstr, int mode, FileSysIO * fio) {
	CPAlgo c = CPAlgo(mode); Pair cp;

	ttime start_time = std::chrono::steady_clock::now();

	//Closest Pair Algorithm N ^ 2
	cp = c.ClosestPairN2(mstr);

	ttime end_time = std::chrono::steady_clock::now();
	auto time = end_time - start_time;
	int ms = std::chrono::duration_cast<std::chrono::microseconds>(time).count();

	outputCPTime("n^2", cp, ms, fio);
	fio->writeFile("", "\n");
}

/*
* Calls and times the Closest Point N log ( N ) Algorithm
*/
void AlgoNLogN(std::vector<Point> lx, int mode, FileSysIO * fio) {
	CPAlgo c = CPAlgo(mode, fio);
	Pair cp;

	std::vector<Point> ly = lx;
	std::sort((ly.begin()), (ly.begin()));

	ttime start_time = std::chrono::steady_clock::now();

	//Closest Pair Algorithm N log( N )
	cp = (mode != 1) ? c.ClosestPairNLogN(lx, ly) : c.dbgClosestPairNLogN(lx, ly);

	ttime end_time = std::chrono::steady_clock::now();
	auto time = end_time - start_time;
	int ms = std::chrono::duration_cast<std::chrono::microseconds>(time).count();

	outputCPTime("nlog(n)", cp, ms, fio);

	fio->writeFile("", "\n");

	int n = lx.size();

	float c1 = ms / (n * std::log(n));
	float c2 = ms / (n * std::log(n) * std::log(n));
	fio->writeFile("n: " + std::to_string(n), "\n");
	fio->writeFile("time2/(n*log(n)): " + std::to_string(c1), "\n");
	fio->writeFile("time2/(n*log(n)^2): " + std::to_string(c2), "\n");
}

/*
* Compares 2 Points using their xCoord
*/
bool compX(const Point &obj0, const Point &obj1) {
	return (obj0.xCoord < obj1.xCoord) ? true : false;
}

/*
* Launch Point of the program
*/
int main(int argc, char* argv[]) {

	std::string input = "data";
	std::string output = "output";
	
	if (argc >= 2) { input = std::string(argv[1]); }
	if (argc >= 3) { output = std::string(argv[2]); }

	std::vector<Point> mstr; int mode = 0;
	FileSysIO * fio = new FileSysIO(input, output);

	fio->readFile(mstr, mode);

	std::sort(mstr.begin(), mstr.end(), compX);

	//calculate brute
	AlgoN2(mstr, mode, fio);

	//calculate efficient
	AlgoNLogN(mstr, mode, fio);
	return 0;
}
