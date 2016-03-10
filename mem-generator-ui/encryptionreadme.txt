encryption folder

imageops.hpp
header file for 

imageops.cpp
has functions:
shiftrow
shiftcol
modpixel
which are all used as helper functions for encrypting



encrypt.hpp
defines the class implemented in

encrypt.cpp
a message encryption class
has encrypt, decrypt functions for both string and image messages

can be constructed by default (random key) or given a specific key