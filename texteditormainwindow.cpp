#include "texteditormainwindow.h"
#include "ui_texteditormainwindow.h"

TextEditorMainWindow::TextEditorMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditorMainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

TextEditorMainWindow::~TextEditorMainWindow()
{
    delete ui;
}


void TextEditorMainWindow::on_actionNew_triggered()
{
    ui->textEdit->clear();
    ui->textEdit->setFocus();
}

