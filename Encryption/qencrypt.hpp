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
    void encryptimage(QString,QString);
    void decryptimage(QString,QString); 
    QString encrypttext(QString);
    QString decrypttext(QString);

private:
    MessageEncryption me;
}


#endif
