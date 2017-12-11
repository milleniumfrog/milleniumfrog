# milleniumfrogs lib for c++

the lib is packaged with npm (package.json).
You can test the lib with 
```bash
npm run test
```

## Strings
I dont like the way c++ handles a few things, so i wrote/write my own string class that 
is inspired from javascript strings.

### constructor
- String();
	- dont use it its for std::vector and std::array
- String(std::string str);
	- assign your std::string to the mfrog String

### Methods:
- std::string toStdString();
- int toInt();
- long toLong();
- void concat();
	- void concat(String &firstString);
	- void concat(String &firsxtString, std::vector<String> &otherStrings);
### Operators
- String operator+(String &other);
- String operator+(std::string &other);
- String operator+(const char* other);