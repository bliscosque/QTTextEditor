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


void TextEditorMainWindow::on_actionOpen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open", QDir::homePath(), file_types);
    QFile file(filename);
    localfilename = filename;

    if (file.exists()) {
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Error opening file", "File cannot be openned");
            return;
        }
        QTextStream enter_file(&file);
        QString text=enter_file.readAll();
        ui->textEdit->setText(text);
    }
    file.close();
}

