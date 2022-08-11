#include "texteditormainwindow.h"
#include "ui_texteditormainwindow.h"

TextEditorMainWindow::TextEditorMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TextEditorMainWindow)
{
    ui->setupUi(this);
}

TextEditorMainWindow::~TextEditorMainWindow()
{
    delete ui;
}

