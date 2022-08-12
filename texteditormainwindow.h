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
    QString localfilename="";
    QString file_types = "Text files (*.txt) ;; Markdown files (*.md)";

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();

    void on_actionQuit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::TextEditorMainWindow *ui;
};
#endif // TEXTEDITORMAINWINDOW_H
