/*
* @author: Spencer MacMaster
* @description: FileSysIO class header of CSE 450 project.
*/

#pragma once
#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include "Point.h"

class FileSysIO {
private:
	//Variables
	std::ifstream myReadFile;
	std::ofstream myWriteFile;
public:
	//Constructors
	FileSysIO();
	FileSysIO(std::string, std::string);
	~FileSysIO();

	//Functions
	void readFile(std::vector<Point> &, int &);
	void writeFile(std::string, std::string);
};