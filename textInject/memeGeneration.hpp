#ifndef TEXTINJECT_HPP_
#define TEXTINJECT_HPP_

#include "gd.h"
#include "gdfontg.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class textInject {
public:

	int getexten(string path);
	string getFileName(const string& s);
	void generateMeme(string memeText, string inPath, string outPath);

};

#endif /* TEXTINJECT_HPP_ */
