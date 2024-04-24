#ifndef FORMATTER_H
#define FORMATTER_H

#include <QTextEdit>

class Formatter
{
public:
    Formatter(QTextEdit& textEdit);
    void bold();
    void italic();
    void underline();
    void color();
    void backgroundColor();

private:
    QTextEdit& textEdit;
};

#endif // FORMATTER_H
