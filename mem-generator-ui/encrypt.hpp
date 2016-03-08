/*
 * An implementation of the Game of Livestock.
 */

#ifndef MESSAGEENCRYPTION_HPP_
#define MESSAGEENCRYPTION_HPP_

#include <cstdlib>
#include <iostream>
#include "imageops.hpp"

class MessageEncryption {
public:

	MessageEncryption();
	MessageEncryption(int key);
    ~MessageEncryption();
    
    
    void encrypt(std::string imgpath, std::string outpath);
    std::string encrypt(std::string &str);
    
    void decrypt(std::string imgpath, std::string outpath);
    std::string decrypt(std::string &str);

private:
	
    
    int key;

};

#endif
