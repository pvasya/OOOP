#ifndef PDF_H
#define PDF_H

#include <QString>
#include "export.h"

class Pdf : public Export
{
public:
    void doExport(bool& flag,QString file, QString text) override;
};

#endif // PDF_H
