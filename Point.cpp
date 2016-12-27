/*
* @author: Spencer MacMaster
* @description: Point class of CSE 450 project.
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <limits>

#include "Point.h"

//-----------------------------------------Constructors-----------------------------------------\\

/*
 * Default Constructor of Point Class
 */
Point::Point() {
	index = -1;
	xCoord = 0;
	yCoord = 0;
}

/*
* Constructor of Point Class
*/
Point::Point(int i, int x, int y) {
	index = i;
	xCoord = x;
	yCoord = y;
}

//-------------------------------------------Functions------------------------------------------\\

/*
* Returns string representation of Point class.
*/
std::string Point::toString() {
	return std::to_string(index) + ": " + std::to_string(xCoord) + " " + std::to_string(yCoord);
}


//-------------------------------------------Comparators----------------------------------------\\

//Compares using yCoord Value
bool Point::operator < (const Point & obj0) const {
	return yCoord < obj0.yCoord ? true : false;
}

bool Point::operator > (const Point & obj0) const {
	return yCoord > obj0.yCoord ? true : false;
}

bool Point::operator <= (const Point & obj0) const {
	return yCoord <= obj0.yCoord ? true : false;
}

bool Point::operator >= (const Point & obj0) const {
	return yCoord >= obj0.yCoord ? true : false;
}

//Compares using xCoord & yCoord Value
bool Point::operator == (const Point & obj0) const {
	return ((xCoord == obj0.xCoord) && (yCoord == obj0.yCoord));
}

bool Point::operator != (const Point & obj0) const {
	return !((xCoord == obj0.xCoord) && (yCoord == obj0.yCoord));
}