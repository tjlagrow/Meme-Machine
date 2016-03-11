#include "qtmemeGeneration.hpp"
#include <QtWidgets>


QgenerateMeme(){
    this->me = meme();
}

void QgenerateMeme::generateMemeQT(QString memeText, QString inPath, QString outPath){
	std::string newmemeText = memeText.toStdString();
    std::string newinpath = inPath.toStdString();
    std::string newoutpath = outPath.toStdString();
    (this->me).generateMeme(newmemeText,newinpath,newoutpath);
}

