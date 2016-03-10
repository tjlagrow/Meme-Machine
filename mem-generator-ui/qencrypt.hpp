#ifndef QENCRYPT_HPP_
#define QENCRYPT_HPP_

#include "encrypt.hpp"
#include <QtWidgets>

class QEncryption : public QWidget
{
    Q_OBJECT

public:
    QEncryption();
    QEncryption(int key);
    ~QEncryption();

public slots:
    void encryptimage(std::string);
    void decryptimage(std::string); 
    void encrypttext(std::string);
    void decrypttext(std::string);

private:
    MessageEncryption me;
}


#endif
