#include "exportcontext.h"

void ExportContext::setExport(Export *exporter)
{
    this->exporter = exporter;
}

void ExportContext::executeExport(bool& flag,QString file, QString text)
{
    exporter->doExport(flag, file, text);
}
