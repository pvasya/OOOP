#ifndef HTML_H
#define HTML_H

#include <QString>
#include "export.h"

class Html : public Export
{
public:
    void doExport(bool& flag,QString file, QString text) override;
};

#endif // HTML_H
