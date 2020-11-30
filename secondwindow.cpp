 #include "secondwindow.h"
#include "ui_secondwindow.h"
#include "mainwindow.h"
#include <QScrollBar>



//QScrollBar VertBar;



SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui_2(new Ui::SecondWindow)
{
    ui_2->setupUi(this);
    /*QScrollBar *sc_bar=ui_2->textEdit->verticalScrollBar();

    sc_bar->setMinimum(0);

    sc_bar->setMinimum(100);

    sc_bar->setSliderPosition(50);




    sc_bar->triggerAction(QAbstractSlider::SliderToMinimum);*/





    //VertBar=QScrollBar();
    //ui_2->textEdit->append("<b>Hello</b> <i>Qt!</i> fufgjfhijgh<br />jhjgkjhj");
    //ui_2->textEdit->append("<table border=\"1\"><tr><th>NAME</th><th>PHONE</th></tr><tr><td>Hello</td><td>Hello</td></tr><tr><td>6756756756</td><td>54666543</td></tr></table>");
    ui_2->textEdit_2->insertHtml(Qt_OutFile_name);

    //ui_2->textEdit->cursorForPosition(QPoint(0, 0));
    //ui_2->textEdit->ensureCursorVisible();

    //QScrollBar *sc_bar=ui_2->textEdit->verticalScrollBar();

    /*sc_bar->setMinimum(0);

    sc_bar->setMinimum(100);

    sc_bar->setSliderPosition(50);*/

    //sc_bar->hide();


    //ui_2->textEdit->setVerticalScrollBar();


    //ui_2->textEdit->verticalScrollBar()->setMinimum(0);

    //ui_2->textEdit->verticalScrollBar()->setMaximum(99);

    //ui_2->textEdit->verticalScrollBar()->;

    //ui_2->verticalScrollBar->setValue(99);


    //ui_2->textEdit->scr

    //ui_2->textEdit->setText(Qt_OutFile_name);
    ui_2->textEdit_2->setReadOnly(true);
    //ui_2->textEdit->setText("Не удалось открыть файл с информацией циклограммы!");

}

SecondWindow::~SecondWindow()
{
    delete ui_2;

}


void SecondWindow::on_CloseButton_clicked()
{
    //printf("%d\n", Perem);
    QWidget::close();
}
