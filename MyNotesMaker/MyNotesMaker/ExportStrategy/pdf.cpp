#include "pdf.h"

#include <QFileDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>


bool Pdf::doExport(QString file, QString text)
{
    if (!file.isEmpty()) {
        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(file);
        QTextDocument document;
        document.setHtml(text);

        document.print(&printer);
        return true;
    }
    else
        return false;
}
