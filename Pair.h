/*
* @author: Spencer MacMaster
* @description: Pair class header of CSE 450 project.
*/

#pragma once

#include "Point.h"

class Pair {
public:
	//Variables
	Point p1;
	Point p2;
	float dst;

	//Constructors
	Pair();
	Pair(Point, Point);

	//Functions
	std::string toString();
	bool operator < (const Pair &) const;
	bool operator <= (const Pair &) const;
};