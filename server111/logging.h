/*---------------------------------------
시작일시: 2017. 05. 21(일)
최종일시: 2017. 05. 21(일)
최종 작성자: 송민표
-----------------------------------------*/

#ifndef LOGGING_H
#define LOGGING_H

#include <QString>
#include <QFile>

class Logging
{
private:
    QFile loggingFile;

public:
    Logging();
    ~Logging();
    bool openFile();
    void writeFile(QString wl);

};

#endif // LOGGING_H
