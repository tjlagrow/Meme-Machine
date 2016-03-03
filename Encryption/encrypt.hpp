/*
 * An implementation of the Game of Livestock.
 */

#ifndef MESSAGEENCRYPTION_HPP_
#define MESSAGEENCRYPTION_HPP_

#include <string>
#include <cstdlib>
#include <iostream>
#include "imageops.hpp"

class MessageEncryption {
public:

	MessageEncryption();
	MessageEncryption(int key);
    ~MessageEncryption();
    
    
    gdImagePtr encrypt(gdImagePtr img);
    std::string encrypt(std::string &str);
    
    gdImagePtr decrypt(gdImagePtr img);
    std::string decrypt(std::string &str);

private:
	
    
    int key;

};

#endif
