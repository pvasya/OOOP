#ifndef EXPORT_H
#define EXPORT_H


#include <QString>

class Export
{
public:
    virtual void doExport(bool& flag,QString file, QString text) = 0;
};

#endif // EXPORT_H
