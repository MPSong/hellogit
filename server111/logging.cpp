/*---------------------------------------
시작일시: 2017. 05. 21(일)
최종일시: 2017. 05. 21(일)
최종 작성자: 송민표
-----------------------------------------*/

#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include "logging.h"


Logging::Logging(QString filename){  //Creator
    //loggingFile=new QFile(filename);
    loggingFile.setFileName(filename);
}

Logging::~Logging(){
    loggingFile.flush();
    loggingFile.close();
}

bool Logging::openFile(){

    if(!loggingFile.open(QIODevice::WriteOnly|QIODevice::Append|QFile::Text)) //File open(write and text mode)
        return false;
    else
        return true;

}

void Logging::writeFile(QString wl){
    QTextStream out(&loggingFile);   //using textStream
    out<<wl<<"is connected \n";
}
