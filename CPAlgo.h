/*
* @author: Spencer MacMaster
* @description: CPAlgo class header of CSE 450 project.
*/

#pragma once

#include <vector>

#include "Point.h"
#include "Pair.h"
#include "FileSysIO.h"

class CPAlgo {
public:
	//constructors
	CPAlgo();
	CPAlgo(int);
	CPAlgo(int, FileSysIO *);

	//Wrapper functions
	Pair ClosestPairN2(std::vector<Point> &);
	Pair ClosestPairNLogN(std::vector<Point> &, std::vector<Point> &);
	Pair dbgClosestPairNLogN(std::vector<Point> &, std::vector<Point> &);

private:
	//variables
	FileSysIO * fio;
	int debug;

	//Helper Functions
	Pair ClosestPairN2(std::vector<Point> &, int, int);
	Pair ClosestPairNLogN(std::vector<Point> &, std::vector<Point> &, int, int);
	Pair ClosestPairStrip(std::vector<Point> &, std::vector<Point> &, int, int, Pair &);

	//Functions for Debugging
	Pair dbgClosestPairNLogN(std::vector<Point> &, std::vector<Point> &, int, int);
	Pair dbgClosestPairStrip(std::vector<Point> &, std::vector<Point> &, int, int, Pair &);
	void outputVectors(std::vector<Point> &, std::vector<Point> &, int, int);
	void outputStrip(std::vector<Point> &, std::vector<Point> &, Pair &, int, int);
};