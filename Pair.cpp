/*
* @author: Spencer MacMaster
* @description: Pair class of CSE 450 project.
*/

#include <limits>

#include <cmath>

#include "Point.h"
#include "Pair.h"

//-----------------------------------------Constructors-----------------------------------------\\

/*
* Defualt Constructor of Pair class
*/
Pair::Pair() {
	p1 = Point();
	p2 = Point();
	dst = std::numeric_limits<float>::infinity();
}

/*
* Constructor of Pair class
*/
Pair::Pair(Point a, Point b) {
	p1 = a;
	p2 = b;
	dst = std::sqrt(std::pow((p2.xCoord - p1.xCoord), 2) + std::pow((p2.yCoord - p1.yCoord), 2));
}

//-------------------------------------------Functions------------------------------------------\\

/*
* Returns string representation of Point class.
*/
std::string Pair::toString() {
	return "(" + std::to_string(p1.xCoord) + ", " + std::to_string(p1.yCoord) + ") (" + std::to_string(p2.xCoord) + ", " + std::to_string(p2.yCoord) + ")";
	return std::string();
}

bool Pair::operator < (const Pair & obj0) const {
	return dst < obj0.dst;
}

bool Pair::operator <= (const Pair & obj0) const {
	return dst <= obj0.dst;
}
