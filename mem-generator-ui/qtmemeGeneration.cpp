#include "qtmemeGeneration.hpp"
#include <QtWidgets>


QmemeGeneration::QmemeGeneration(){
    this->me = new Meme();
}

QmemeGeneration::~QmemeGeneration(){delete this->me;}

void QmemeGeneration::generateMemeQT(QString memeText, QString inPath, QString outPath){
	std::string newmemeText = memeText.toStdString();
    std::string newinpath = inPath.toStdString();
    std::string newoutpath = outPath.toStdString();
    (this->me)->generateMeme(newmemeText,newinpath,newoutpath);
}

