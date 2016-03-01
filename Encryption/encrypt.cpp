#include "encrypt.hpp"
	

MessageEncryption::MessageEncryption(){this->key = 1;}
MessageEncryption::MessageEncryption(int key){this->key = key;}
MessageEncryption::~MessageEncryption(){}
    
    
gdImagePtr
MessageEncryption::encrypt(gdImagePtr &img){return NULL;}

std::string
MessageEncryption::encrypt(std::string &str){return NULL;}
    

gdImagePtr
MessageEncryption::decrypt(gdImagePtr &img){return NULL;}

std::string
MessageEncryption::decrypt(std::string &str){return NULL;}
