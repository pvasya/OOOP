#include "formatter.h"
#include "qcolordialog.h"

Formatter::Formatter(QTextEdit &textEdit):
    textEdit(textEdit)
{

}

void Formatter::bold()
{
    QTextCharFormat format;
    QTextCursor cursor = textEdit.textCursor();

    format = cursor.charFormat();

    if (format.fontWeight() != QFont::Bold) {
        format.setFontWeight(QFont::Bold);
    } else {
        format.setFontWeight(QFont::Normal);
    }
    cursor.mergeCharFormat(format);
}

void Formatter::italic()
{
    QTextCharFormat format;
    QTextCursor cursor = textEdit.textCursor();

    format = cursor.charFormat();

    if (!format.fontItalic()) {
        format.setFontItalic(true);
    } else {
        format.setFontItalic(false);
    }
    cursor.mergeCharFormat(format);
}

void Formatter::underline()
{
    QTextCharFormat format;
    QTextCursor cursor = textEdit.textCursor();

    format = cursor.charFormat();

    if (!format.fontUnderline()) {
        format.setFontUnderline(true);
    } else {
        format.setFontUnderline(false);
    }
    cursor.mergeCharFormat(format);
}

void Formatter::color()
{
    QColorDialog dialog;
    dialog.setCurrentColor(textEdit.textColor());
    QColor color = dialog.getColor();

    if (color.isValid()) {
        QTextCharFormat format;
        QTextCursor cursor = textEdit.textCursor();
        format = cursor.charFormat();
        format.setForeground(color);
        cursor.mergeCharFormat(format);
    }
}

void Formatter::backgroundColor()
{
    QColorDialog dialog;
    dialog.setCurrentColor(textEdit.textBackgroundColor());
    QColor color = dialog.getColor();

    if (color.isValid()) {
        QTextCharFormat format;
        QTextCursor cursor = textEdit.textCursor();
        format = cursor.charFormat();
        format.setBackground(color);
        cursor.mergeCharFormat(format);
    }
}
