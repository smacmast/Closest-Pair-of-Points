/*
* @author: Spencer MacMaster
* @description: CPAlgo class of CSE 450 project.
*/

#include <algorithm>
#include <vector>

#include "Point.h"
#include "Pair.h"
#include "FileSysIO.h"
#include "CPAlgo.h"

//macros
#define min(p1, p2) (p1 <= p2 ? p1 : p2)

//-----------------------------------------Constructors-----------------------------------------\\

/*
* Default Constructor of CPAlgo class
*/
CPAlgo::CPAlgo() {
	debug = 0;
}

/*
* Constructor of CPAlgo class
*/
CPAlgo::CPAlgo(int mode) {
	debug = mode;
}

/*
* Constructor of CPAlgo class
*/
CPAlgo::CPAlgo(int mode, FileSysIO * f) {
	debug = mode;
	fio = f;
}

//===========================================Functions==========================================\\

//-------------------------------------------Public---------------------------------------------\\

/*
* Returns the closest pair of points in a vector list
*     using a O(N ^ 2) algorithm.
*/
Pair CPAlgo::ClosestPairN2(std::vector<Point> &mstr) {
	return ClosestPairN2(mstr, 0, mstr.size() - 1);
}

/*
* Returns the closest pair of points in a vector list
*     using a O(N Log ( N )) algorithm.
*/
Pair CPAlgo::ClosestPairNLogN(std::vector<Point> &lx, std::vector<Point> &ly) {
	return ClosestPairNLogN(lx, ly, 0, lx.size() - 1);
}

/*
* Identical to ClosestPairNLogN except it records debug information
* also skips n < 10 optimization
*/
Pair CPAlgo::dbgClosestPairNLogN(std::vector<Point> &lx, std::vector<Point> &ly) {
	return dbgClosestPairNLogN(lx, ly, 0, lx.size() - 1);
}

//-------------------------------------------Private--------------------------------------------\\

/*
* Returns the closest pair of points in a vector list
*     using a O(N ^ 2) algorithm.
*/
Pair CPAlgo::ClosestPairN2(std::vector<Point> &mstr, int start, int end) {
	Pair cp, temp;
	Point p1, p2;
	for (int i = start; i <= end; ++i) {
		p1 = mstr[i];
		for (int j = i + 1; j <= end; ++j) {
			p2 = mstr[j];
			temp = Pair(p1, p2);
			cp = min(cp, temp);
		}
	}
	return cp;
}

/*
* Returns the closest pair of points in a vector list
*     using a O(N Log ( N )) algorithm.
*/
Pair CPAlgo::ClosestPairNLogN(std::vector<Point> &lx, std::vector<Point> &ly, int start, int end) {

	Pair cp;

	if (end - start <= 10) { //Base Case
		return ClosestPairN2(lx, start, end);
	}

	// Compute separation line L such that half the points are on one side and half on the other side.
	int mid = (start + end) / 2;
	cp = min(ClosestPairNLogN(lx, ly, start, mid), ClosestPairNLogN(lx, ly, mid + 1, end)); //left half of vector  vs right half of vector

	//strip list
	ly = lx;

	int sStart = (mid - 6 > start) ? (mid - 6) : start;
	int sEnd = (mid + 6 < end) ? (mid + 6) : end;

	ClosestPairStrip(lx, ly, sStart, sEnd, cp);
	return cp;
}

/*
* Returns the closest pair of points in a delta strip range
*/
Pair CPAlgo::ClosestPairStrip(std::vector<Point> &lx, std::vector<Point> &strp, int start, int end, Pair &cp) {

	std::sort(strp.begin() + start, strp.begin() + end);

	for (int i = start; i <= end; ++i) {
		for (int j = i + 1; j <= end && (strp[j].yCoord - strp[i].yCoord) < cp.dst; ++j) {
			cp = min(cp, Pair(strp[i], strp[j]));
		}
	}
	return cp;
}

//------------------------------------Debuggers / Comparators-----------------------------------\\

/*
* Returns the closest pair of points in a vector list
*     using a O(N Log ( N )) algorithm.
*/
Pair CPAlgo::dbgClosestPairNLogN(std::vector<Point> &lx, std::vector<Point> &ly, int start, int end) {

	Pair cp;

	//For debug mode
	if (debug == 1) {
		ly = lx;
		std::sort(ly.begin() + start, ly.begin() + end + 1);
		outputVectors(lx, ly, start, end);
	}

	if (end - start <= 2) { //Base Case
		return ClosestPairN2(lx, start, end);
	}

	// Compute separation line L such that half the points are on one side and half on the other side.
	int mid = (start + end) / 2;
	cp = min(dbgClosestPairNLogN(lx, ly, start, mid), dbgClosestPairNLogN(lx, ly, mid + 1, end)); //left half of vector  vs right half of vector

	//strip list
	ly = lx;

	int sStart = (mid - 6 > start) ? (mid - 6) : start;
	int sEnd = (mid + 6 < end) ? (mid + 6) : end;

	dbgClosestPairStrip(lx, ly, sStart, sEnd, cp);
	return cp;
}

/*
* Returns the closest pair of points in a delta strip range
*/
Pair CPAlgo::dbgClosestPairStrip(std::vector<Point> &lx, std::vector<Point> &strp, int start, int end, Pair &cp) {

	std::sort(strp.begin() + start, strp.begin() + end);

	//For debug mode
	if (debug == 1) { outputStrip(lx, strp, cp, start, end); }

	for (int i = start; i <= end; ++i) {
		for (int j = i + 1; j <= end && (strp[j].yCoord - strp[i].yCoord) < cp.dst; ++j) {
			cp = min(cp, Pair(strp[i], strp[j]));
		}
	}
	return cp;
}

/*
* Writes the vector lists to the file between a specific range
*/
void CPAlgo::outputVectors(std::vector<Point> &lx, std::vector<Point> &ly, int start, int end) {
	fio->writeFile("pX(Lx) is :", "\n");
	for (int i = start; i <= end; ++i) {
		fio->writeFile(lx[i].toString(), "\n");
	}

	fio->writeFile("\npY(Ly) is :", "\n");
	for (int i = start; i <= end; ++i) {
		fio->writeFile(ly[i].toString(), "\n");
	}
	fio->writeFile("", "\n");
}

/*
* Writes the vector strips to the file between a specific range
*/
void CPAlgo::outputStrip(std::vector<Point> &xstrp, std::vector<Point> &ystrp, Pair &cp, int start, int end) {
	fio->writeFile("delta: " + std::to_string(cp.dst), "\n");

	fio->writeFile("\nLx_strip :", "\n");
	for (int i = start; i < end; ++i) {
		fio->writeFile(xstrp[i].toString(), "\n");
	}

	fio->writeFile("\nLy_strip :", "\n");
	for (int i = start; i < end; ++i) {
		fio->writeFile(ystrp[i].toString(), "\n");
	}
	fio->writeFile("", "\n");
}
