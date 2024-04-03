#ifndef PDF_H
#define PDF_H

#include <QString>
#include "export.h"

class Pdf : public ExportStrategy
{
public:
    bool doExport(QString file, QString text) override;
};

#endif // PDF_H
