#ifndef EXPORTCONTEXT_H
#define EXPORTCONTEXT_H

#include <QString>
#include "export.h"

class ExportContext
{
private:
    Export* exporter;

public:
    void setExport(Export* exporter);

    void executeExport(bool& flag,QString file, QString text);
};

#endif // EXPORTCONTEXT_H
