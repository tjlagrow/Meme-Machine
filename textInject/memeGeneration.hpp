#ifndef MEME_HPP_
#define MEME_HPP_

#include "gd.h"
#include "gdfontg.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Meme {
public:

	int getexten(string path);
	string getFileName(const string& s);
	void generateMeme(string memeText, string inPath, string outPath);

};

#endif /* MEMEHPP_ */
