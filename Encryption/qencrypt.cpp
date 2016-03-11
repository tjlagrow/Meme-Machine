#include "qencrypt.hpp"
#include <QtWidgets>

QEncryption::QEncryption(){
    this->me = MessageEncryption();
}
QEncryption::QEncryption(int key){
    this->me = MessageEncryption(key);
}
~QEncryption::QEncryption();

void QEncryption::encryptimage(QString inpath, QString outpath){
    std::string newinpath = inpath.toStdString();
    std::string newoutpath = outpath.toStdString();
    (this->me).encrypt(newinpath,newoutpath);
}

void QEncryption::decryptimage(QString inpath, QString outpath){
    std::string newinpath = inpath.toStdString();
    std::string newoutpath = outpath.toStdString();
    (this->me).decrypt(newinpath,newoutpath);
}

QString QEncryption::encrypttext(QString text){
    std::string newtext = text.toStdString();
    return QString::fromStdString((this->me).encrypt(newtext));
}

QString QEncryption::decrypttext(QString text){
    std::string newtext = text.toStdString();
    return QString::fromStdString((this->me).decrypt(newtext));
}