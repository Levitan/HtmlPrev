#ifndef PREVIEW_H
#define PREVIEW_H

#include <QWidget>
#include "codeeditor.h"

class QPlainTextEdit;
class QWebView;
class CodeEditor;
class QLabel;
class String;

class Preview : public QWidget
{
    Q_OBJECT
public:
    Preview(QWidget *parent = 0);

signals:

public slots:

private slots:
    void textToHtml();
    void setPath();

private:
    //QPlainTextEdit *htmlEdit, *cssEdit;
    CodeEditor *htmlEdit, *cssEdit;
    QWebView *web;
    QLabel *pathLab;
    QString pathStr;
};

#endif // PREVIEW_H
