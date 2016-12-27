/*
* @author: Spencer MacMaster
* @description: Point class header of CSE 450 project.
*/

#pragma once
#include <string>

class Point {
public:
	//Variables
	int index;
	int xCoord;
	int yCoord;

	//Constructors
	Point();
	Point(int, int, int);

	//Functions
	std::string toString();
	bool operator <= (const Point & obj0) const;
	bool operator >= (const Point & obj0) const;
	bool operator < (const Point & obj0) const;
	bool operator > (const Point & obj0) const;
	bool operator == (const Point & obj0) const;
	bool operator != (const Point & obj0) const;
};