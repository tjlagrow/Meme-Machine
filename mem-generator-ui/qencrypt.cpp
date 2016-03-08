#include "qencrypt.hpp"
#include <QtWidgets>

QEncryption(){
    this->me = MessageEncryption();
}
QEncryption(int key){
    this->me = MessageEncryption(key);
}
~QEncryption();

void QEncryption::encryptimage(std::string);
void QEncryption::decryptimage(std::string); 
void QEncryption::encrypttext(std::string);
void QEncryption::decrypttext(std::string);

#endif
