#include "preview.h"
#include <QtGui>
#include <QtWebKit>
#include <cstdlib>

Preview::Preview(QWidget *parent) :
    QWidget(parent)
{
    QGroupBox *prevBlock = new QGroupBox;
    prevBlock->setTitle(tr("Preview"));
    QGroupBox *htmlBlock = new QGroupBox;
    htmlBlock->setTitle(tr("HTML"));
    QGroupBox *cssBlock = new QGroupBox;
    cssBlock->setTitle(tr("StyleSheet"));
    QPushButton *brBtn = new QPushButton(tr("Browse"));
    pathStr = getenv("HOME");
    pathLab = new QLabel(QString("Path to images is: <span style='color: #008000;'>" + pathStr + "</span>"));


    web = new QWebView;
    htmlEdit = new CodeEditor;
    htmlEdit->setPlainText("<h1>Welcome to Simple HTML Previewer!</h1>");
    cssEdit = new CodeEditor;
    cssEdit->setPlainText("h1 {\ntext-align: center;\n}");
    this->textToHtml();

    QHBoxLayout *pathLay = new QHBoxLayout;
    pathLay->addWidget(pathLab);
    pathLay->addWidget(brBtn);

    QVBoxLayout *prevLay = new QVBoxLayout;
    prevLay->addLayout(pathLay);
    prevLay->addWidget(web);
    prevBlock->setLayout(prevLay);

    QVBoxLayout *htmlLay = new QVBoxLayout;
    htmlLay->addWidget(htmlEdit);
    htmlBlock->setLayout(htmlLay);

    QVBoxLayout *cssLay = new QVBoxLayout;
    cssLay->addWidget(cssEdit);
    cssBlock->setLayout(cssLay);

    QSplitter *vSplit = new QSplitter(Qt::Vertical);
    vSplit->addWidget(prevBlock);
    vSplit->addWidget(htmlBlock);

    QSplitter *hSplit = new QSplitter(Qt::Horizontal);
    hSplit->addWidget(vSplit);
    hSplit->addWidget(cssBlock);

    QVBoxLayout *mainLay = new QVBoxLayout;
    mainLay->addWidget(hSplit);



    this->setLayout(mainLay);
    this->connect(cssEdit, SIGNAL(textChanged()), this, SLOT(textToHtml()));
    this->connect(htmlEdit, SIGNAL(textChanged()), this, SLOT(textToHtml()));
    this->connect(brBtn, SIGNAL(clicked()), this, SLOT(setPath()));
}

void Preview::textToHtml(){
    QString html;
    QString css;
    css = cssEdit->toPlainText();
    html = htmlEdit->toPlainText();
    //pathLab->setText(css.replace("url(", "url(file:///home/levitan/"));
    css.replace("url(", "url(file://" + pathStr );
    html.replace("src=\"", "src=\"file://" + pathStr );
    //pathLab->setText(html);
    web->setHtml("<style>" + css + "</style>" + html);
    //this->textToCss();
}

void Preview::setPath(){
    pathStr = QFileDialog::getExistingDirectory(this, "Title", "~");
    pathStr.toUtf8();
    pathLab->setText("Path to images is: <span style='color: #008000;'>" + pathStr + "</span>");
    this->textToHtml();
}
