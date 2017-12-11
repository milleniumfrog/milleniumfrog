	//
	//  milleniumfrog.cpp
	//  milleniumfrog_bib
	//
	//  Created by René on 07.12.17.
	//  Copyright © 2017 René Schwarzinger. All rights reserved.
	//

#include "milleniumfrog.hpp"


void mfrog::setLogLevel(int newlogLevel) {
	using namespace std;
	cout << newlogLevel << endl;
	vars::logLevel = newlogLevel;
	cout << mfrog::vars::logLevel << endl;
};

int mfrog::getLogLevel () {
	return vars::logLevel;
};

/***********
 * Console *
 ***********/

void mfrog::Console::log(std::string str){
	std::cout << str << std::endl;
}
void mfrog::Console::log(int tabs, std::string str){
	std::string out {""};
	for (int i = 0; i < tabs; ++i) {
		out += "\t";
	}
	std::cout << out << str << std::endl;
}


/***********
 * Strings *
 ***********/

	// constructors
mfrog::String::String(std::string str): value{str} {
	if (vars::logLevel > 0) {
		std::cout << "created String with value " << str << std::endl;
	}
};
// default functions
std::string mfrog::String::toStdString() {
	return value;
};

int mfrog::String::toInt () {
	return std::stoi(value);
};

long mfrog::String::toLong () {
	return std::stol(value);
};
		
mfrog::String mfrog::String::operator+(mfrog::String &other){
	mfrog::String res(value + other.toStdString());
	return res;
};
mfrog::String mfrog::String::operator+(std::string &other){
	mfrog::String res(value + other);
	return res;
};
mfrog::String mfrog::String::operator+(const char* other){
	std::string k = std::string(other);
	return mfrog::String (value + k);
};
