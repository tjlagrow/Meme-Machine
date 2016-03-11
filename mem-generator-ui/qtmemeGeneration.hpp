#ifndef QMEMEGEN_HPP_
#define QMEMEGEN_HPP_

#include "memeGeneration.hpp"
#include <QtWidgets>

class QmemeGeneration : public QWidget {
    Q_OBJECT

public:
    QgenerateMeme();


public slots:
    void generateMemeQT(QString, QString, QString);

}


#endif