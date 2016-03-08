#include "mainwindow.h"
#include "encrypt.hpp"
#include "test.h"
#include "imageops.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MessageEncryption(4) memencryptor;

    MainWindow w;
    w.show();

    return a.exec();
}
