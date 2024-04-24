#ifndef EXPORT_H
#define EXPORT_H


#include <QString>

class ExportStrategy
{
public:
    virtual bool doExport(QString file, QString text) = 0;
};

#endif // EXPORT_H
