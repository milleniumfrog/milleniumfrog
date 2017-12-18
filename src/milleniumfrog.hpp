//
//  milleniumfrog.hpp
//  milleniumfrog_bib
//
//  Created by René on 07.12.17.
//  Copyright © 2017 René Schwarzinger. All rights reserved.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>


namespace mfrog {
	struct Console {
		void log (std::string str);
		void log (int tabs, std::string str);
	};

	namespace vars{
		static int logLevel {0};
	}

	void setLogLevel(int newlogLevel);
	int getLogLevel();
	
	class String {
	private:
		std::string value {""};
	public:
		String();
		String(std::string str);
		void setValue(std::string &k);
		std::string toStdString();
		int toInt();
		long toLong();
		String operator+(String &other);
		String operator+(std::string &other);
		String operator+(const char* other);
		friend std::istream& operator>>(std::istream& is, mfrog::String &obj);
		void concat(String &firstString);
		void concat(String &firsxtString, std::vector<String> &otherStrings);
	};
}