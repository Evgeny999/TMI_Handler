#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    int flag_opa;

private slots:
    //void closeEvent(QCloseEvent *event);

    void on_CloseButton_clicked();

private:
    Ui::SecondWindow *ui_2;
};

#endif // SECONDWINDOW_H
