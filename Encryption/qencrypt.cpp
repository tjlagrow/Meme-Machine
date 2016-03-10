#include "qencrypt.hpp"
#include <QtWidgets>

QEncryption(){
    this->me = MessageEncryption();
}
QEncryption(int key){
    this->me = MessageEncryption(key);
}
~QEncryption();

void QEncryption::encryptimage(QString inpath, QString outpath){
    std::string newinpath = inpath.toStdString();
    std::string newoutpath = outpath.toStdString();
    
}

void QEncryption::decryptimage(QString inpath, QString outpath){
    std::string newinpath = inpath.toStdString();
    std::string newoutpath = outpath.toStdString();

}

void QEncryption::encrypttext(QString inpath, QString outpath){
    std::string newinpath = inpath.toStdString();
    std::string newoutpath = outpath.toStdString();

}

void QEncryption::decrypttext(QString inpath, QString outpah){
    std::string newinpath = inpath.toStdString();
    std::string newoutpath = outpath.toStdString();

}

#endif
