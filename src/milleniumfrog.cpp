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
mfrog::String::String(): value{""} {
	if (vars::logLevel > 0) {
		std::cout << "created String with value " <<  "" << std::endl;
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

void mfrog::String::setValue(std::string &k) {
	value = k;
};


// Operators
		
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

std::istream& mfrog::operator>>(std::istream& is, mfrog::String &Str) {
	std::string k;
	is >> k;
	Str.setValue(k);
	if(false) // TODO
        is.setstate(std::ios::failbit);
    return is;
};


void mfrog::String::concat(String &firstString) {
	value += firstString.value;
};

void mfrog::String::concat(String &firstString, std::vector<String> &stringArray) {
	value += firstString.value;
	for (String strEntry : stringArray) {
		value += strEntry.value;
	}
};
