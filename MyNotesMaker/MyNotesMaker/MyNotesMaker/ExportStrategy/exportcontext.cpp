#include "exportcontext.h"

void ExportContext::setExport(ExportStrategy *exporter)
{
    this->exporter = exporter;
}

bool ExportContext::executeExport(QString file, QString text)
{
    return exporter->doExport(file, text);
}
