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
    localfilename="";
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


void TextEditorMainWindow::on_actionSave_as_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save as...", QDir::homePath(), file_types);
    localfilename = filename;

    if(localfilename == "") {
        return;
    }
    QFile file(filename);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        if (file.exists()) {
            QMessageBox::warning(this, "Error saving file", "File cannot be saved");
        }
        return;
    }
    QTextStream out_file(&file);
    QString text=ui->textEdit->toPlainText();
    out_file << text;
    file.flush();
    file.close();
}


void TextEditorMainWindow::on_actionSave_triggered()
{
    QString filename;
    if (localfilename=="") {
        filename = QFileDialog::getSaveFileName(this, "Save as...", QDir::homePath(), file_types);
        localfilename = filename;
    } else {
        filename=localfilename;
    }
    QFile file(filename);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        if (file.exists()) {
            QMessageBox::warning(this, "Error saving file", "File cannot be saved");
        }
        return;
    }
    QTextStream out_file(&file);
    QString text=ui->textEdit->toPlainText();
    out_file << text;
    file.flush();
    file.close();
}


void TextEditorMainWindow::on_actionQuit_triggered()
{
    close();
}


void TextEditorMainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void TextEditorMainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void TextEditorMainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void TextEditorMainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void TextEditorMainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void TextEditorMainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Choose a color");
    if (color.isValid()) {
        ui->textEdit->setTextColor(color);
    }
}


void TextEditorMainWindow::on_actionBackground_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Choose a background color");
    if (color.isValid()) {
        ui->textEdit->setTextBackgroundColor(color);
    }
}


void TextEditorMainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font= QFontDialog::getFont(&ok,this);
    if (ok) {
        ui->textEdit->setFont(font);
    }
}


void TextEditorMainWindow::on_actionAbout_this_app_triggered()
{
    QMessageBox::about(this,"About this app", "Developed by Thiago");
}


void TextEditorMainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    QPrintDialog dialog_printer;
    if (dialog_printer.exec() == QDialog::Rejected) {
        return;
    }
    ui->textEdit->print(&printer);
}

