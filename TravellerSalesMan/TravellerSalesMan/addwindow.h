#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>

namespace Ui {
class AddWindow;
}

class AddWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();

private slots:
    // Реализация кнопок

    void AddRoad();
    void AddNode();


private:
    Ui::AddWindow *ui;
};

#endif // ADDWINDOW_H
