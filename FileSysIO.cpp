/*
* @author: Spencer MacMaster
* @description: FileSysIO class of CSE 450 project.
*/

#include<iostream>
#include<fstream>
#include <string>
#include <vector>
#include "Point.h"
#include "FileSysIO.h"

//-----------------------------------------Constructors-----------------------------------------\\

/*
* Defualt Constructor of FileSysIO class
*/
FileSysIO::FileSysIO() {
	myReadFile.open("data");
	myWriteFile.open("output");
}

/*
* Defualt Constructor of FileSysIO class
*/
FileSysIO::FileSysIO(std::string in, std::string out) {
	myReadFile.open(in);
	myWriteFile.open(out);
}

/*
* Destructor of FileSysIO class
*/
FileSysIO::~FileSysIO() {
	myReadFile.close();
	myWriteFile.close();
}

//-------------------------------------------Functions------------------------------------------\\

/*
* Reads from the data file given in the constructor
*/
void FileSysIO::readFile(std::vector<Point> &plist, int &mode){
	int input = 0, line = 0, x, y;
	Point p;
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {

			if (line == 0) {
				myReadFile >> input; //get size of list
				plist.resize(input);
				myReadFile >> mode; //get debug mode
			}
			else if(line != 0 && line <= (int) plist.size()){
				myReadFile >> input; //get x coord
				x = input;
				myReadFile >> input; //get y coord
				y = input;
				p = Point(line, x, y); //create point

				plist[line - 1] = p; //add point to plist
			}
			else {
				break;
			}
			++line;
		}
	}
}

/*
* Writes to the output file given in the constructor
*/
void FileSysIO::writeFile(std::string info, std::string end){
	if (myWriteFile.is_open()) {
		myWriteFile << info;
		end.compare("\n") == 0 ? (myWriteFile << std::endl) : (myWriteFile << end);
	}
}
