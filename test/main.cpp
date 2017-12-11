//
//  main.cpp
//  milleniumfrog_bib
//
//  Created by René on 07.12.17.
//  Copyright © 2017 René Schwarzinger. All rights reserved.
//

#include <iostream>
#include "../src/milleniumfrog.hpp"

void test (bool testcondition);

int main (int argc, const char* argv[]) {
    using std::cout;
    using std::cin;
    using std::endl;
    using mfrog::String;
    using mfrog::Console;
    
    Console console = Console();

    console.log("Started test Script for milleniumfrog Bib");

    console.log(1, "String Class");

    console.log(2, "Create a String with value=\"Hello world \"");
    String var {"Hello world"};
    test(var.toStdString() == "Hello world");

    console.log(2, "Add two mfrog::String variables and + them");
    String var2 {" with a Sky"};
    test((var+var2).toStdString() == "Hello world with a Sky");
	
	console.log(2, "Add mfrog::String and std::string variables and + them");
	std::string var3 {" , how is the weather today"};
	test((var+var3).toStdString() == "Hello world , how is the weather today");

    console.log(2, "Add mfrog::String and const char and + them");
    console.log((var+" how is the weather today").toStdString());
	test((var+" how is the weather today").toStdString() == "Hello world , how is the weather today");
	
	
    return 0;
}


void test (bool testcondition) {
    using mfrog::Console;
    Console console = Console();
    if (testcondition) {
        console.log(3, "Success");
    } else {
        console.log(3, "Failed");
    }
};
