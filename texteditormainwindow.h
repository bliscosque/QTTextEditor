#ifndef TEXTEDITORMAINWINDOW_H
#define TEXTEDITORMAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class TextEditorMainWindow; }
QT_END_NAMESPACE

class TextEditorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    TextEditorMainWindow(QWidget *parent = nullptr);
    ~TextEditorMainWindow();

private:
    Ui::TextEditorMainWindow *ui;
};
#endif // TEXTEDITORMAINWINDOW_H
