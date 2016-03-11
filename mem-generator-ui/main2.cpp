#include "mainwindow.h"
#include "encrypt.hpp"
#include "test.h"
#include "imageops.hpp"
#include "chatdialog.h"
#include <QApplication>
#include <QtCore/QSettings>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>
#include <string>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MessageEncryption(4) memencryptor;

    MainWindow w;
    ChatDialog x;
    x.show();
    w.show();

    return a.exec();
}
