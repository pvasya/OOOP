#ifndef HTML_H
#define HTML_H

#include <QString>
#include "export.h"

class Html : public ExportStrategy
{
public:
    bool doExport(QString file, QString text) override;
};

#endif // HTML_H
