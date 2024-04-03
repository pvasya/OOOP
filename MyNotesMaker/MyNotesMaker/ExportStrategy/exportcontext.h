#ifndef EXPORTCONTEXT_H
#define EXPORTCONTEXT_H

#include <QString>
#include "export.h"

class ExportContext
{
private:
    ExportStrategy* exporter;

public:
    void setExport(ExportStrategy* exporter);

    bool executeExport(QString file, QString text);
};

#endif // EXPORTCONTEXT_H
