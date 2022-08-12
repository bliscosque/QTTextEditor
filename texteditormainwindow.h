#ifndef TEXTEDITORMAINWINDOW_H
#define TEXTEDITORMAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditorMainWindow; }
QT_END_NAMESPACE

class TextEditorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TextEditorMainWindow(QWidget *parent = nullptr);
    ~TextEditorMainWindow();
    QString localfilename;
    QString file_types = "Text files (*.txt) ;; Markdown files (*.md)";

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

private:
    Ui::TextEditorMainWindow *ui;
};
#endif // TEXTEDITORMAINWINDOW_H
