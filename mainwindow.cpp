#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QString>
#include <QLayout>
#include <QtGui>
#include <QtDebug>
#include <QFileDialog>
#include <QFile>
#include <QSize>
#include <QDir>
#include <QSettings.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <vector>
#include <iostream>
#include <sys/stat.h>
#include <dir.h>
#include "tinyxml.h"
#include <windows.h>
#include <fstream>
#include <QProgressBar>




using namespace std;



int flag=0;
int counter_mas[36];
vector <char> vect_Cg_name;
char *Cg_Names=NULL;
char symbol;
FILE *input;
FILE *file;
FILE *protocol;



FILE *test_file=NULL;



int support_var=0;
int priznak0=1;
int priznak1=1;
int priznak2=9;
int priznak3=17;
int res=0;
int ind=1;
int sign=1;
float start_time=0;
int quant_point_less30per=0;
float stock=0;
int stock_msk=0;
int znach1=0;
int znach2=0;
int column_num=0;
//int fix_value=0;
int compare2=0;
int max_flag=-1;
int list_of_remove[9];
int size_of_empty=0;
int empty_flag=0;
int time_of_work_side=0;
int quant_of_sides=0;
int num_of_pvv[1000];
int pvv_quantity=0;
int pos_of_cg_name=0;
int num_of_point=0;
int storage[25];
int Num=0;
int Perem;
int Var1_on_time=0;
int Var2_on_time=0;
int quantity=0;
int Pos_Of_slash=0;
//Для теста rtvk
int count_rtvk_mas=0;
int quant_mas=1;
int count_quant_mas=0;
int number_mas[2];
int cur_kadr;

int flag_2=0;

    //char *mas=NULL;
//char *mas_inp_file=NULL;
char str[100];
char size_of_col[8];
int quant_of_symb_in_Tel_file=0;
int quant_of_symb_in_Tel_file_norm=0;

int count_Call_worker=0;
    //char *Cg_Names=NULL;
    //int mas_inp_int_inf[10000];
    //char mas_inp_char_inf[10000];
    //char mas_inp_inf[100000];

vector <char> mas_file;
    //vector <char> vect_Cg_name;
vector <char> vect_mas_inp_inf;
vector <char> vect_mas_inp_char_inf;
vector <int> vect_mas_inp_int_inf;
vector <int> vect_time_in_ZG;
vector <int> fix_value;
vector <char> vect_mas_inp_file;
vector<TiXmlElement*> vect_table_row;
vector<TiXmlElement*> vect_table_cell;
vector<TiXmlElement*> vect_text_p;
vector<TiXmlText*> vect_tixml_text;
vector <TiXmlElement> vector_TiXml;
vector<TiXmlElement*> vect_ptot_text;

vector <QString> CheckingPar;
vector <QString> TrueValue;
TiXmlDocument doc;
TiXmlDocument ods;
TiXmlDocument manifest_odt;
TiXmlDocument Report_allPar;

char storage2[20];
int quant_sym;
char chislo[3];
int counter_read1=0;
int counter_read2=0;
char buffer[30];
char Num1, Num2, Num3, Num4;
    //char symbol;
int countt=0;
float Var1_float=0;
float Var2_float=300;
QString Nominal_features="";



int count_features=0;
//QString Mas_Nominal_features[20];

vector <QString> Mas_Nominal_features;
vector <QString> SZO_Time;

struct multiple_feat
{
    QString identificator;
    QString value;
    int number=0;
    QString nominal_value;
};


vector <struct multiple_feat> vect_multpl_feat_schgr;
vector <struct multiple_feat> vect_multpl_feat_pfimass;
vector <struct multiple_feat> vect_multpl_feat_schd;
vector <struct multiple_feat> vect_multpl_feat_ptimass;



struct SZO
{
    QString SZO_time;
    QString value;
    QString SZO_description;

};

QString TimeKeeper;

SZO szo_keeper;




vector <struct SZO> vect_SZO;


vector <vector <struct multiple_feat>> vect_multpl_feat_output;


QString WrongFeatures;
QString RealValues;
//QString CheckingPar[20];
//QString TrueValue[20];


QString TEST;

//QString Nominal_rtvk_vkl[100][5];сделал двумерный массив
//QString Nominal_rtvk_vkl[100];

vector <QString> Nominal_rtvk_vkl;

//QString Mas_Nominal_features[0]="sdfasfs";


QString NewLine;


QString Qt_Inf_Zg;
QString Qt_Zg_Name;
QString Qt_Prot_Name;
QString Qt_Tel_Name;
QString Qt_sbl_file;
QString Qt_kdr_file;
QString Qt_Buf_LineEdit;
QString flpath;
QString flpath_2;
QString flpath_3;
QString flpath_5;

QString Qt_OutFile_name;
QString Qt_SystemInf;
QString test;
QString Empty;

QString ComboBox_Item;

QString WrongValuesRTVK[5];

QString Buffer;
QString Buf_Right_value;

QString out;


vector <QString> ProtNomValues;
vector <QString> ProtTMIValues;
vector <QString> ProtNamesModules;

//QFile File_Info;
QFile Pos_File;
QFile report_file;
QFile report_file_2;


ifstream Inf_file;
QByteArray buf;
const char* Ch_Tel_Name=NULL;
const char* Ch_Zg_Name=NULL;
const char* Ch_Inf_Zg=NULL;
const char* Ch_Prot_Name=NULL;
QSettings settings("MARS", "TMIWatcher");
char *buf_to_pos_file;
int counter=0;

int Pos_y=0;
int Pos_x=0;
LPSTR array_test;
STARTUPINFOA cif;
PROCESS_INFORMATION pi;
string stdString;


TiXmlElement *table_table = new TiXmlElement("table:table");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->hide();
    // восстанавливаем путь к файлу
        //QSettings settings("MARS", "TMIWatcher");
        settings.beginGroup("Ruby_script");
        flpath=settings.value("flpath", "/").toString();
        flpath_2=settings.value("flpath_2", "/").toString();
        Qt_sbl_file=settings.value("Qt_sbl_file", "/").toString();
        Qt_kdr_file=settings.value("Qt_kdr_file", "/").toString();
        settings.endGroup();


    //setFixedSize(500, 500);
    /*File_Info.setFileName("LAST.txt");
    if(File_Info.exists())
    {
        if(!File_Info.open(QIODevice::ReadOnly))
        {
            printf("Mistake during opening the file!");
            QApplication::quit();
        }

        File_Info.seek(0);

        buf=File_Info.readAll();
        counter_mas[26]=0;
        test=buf.data();

        Read_File_Inf();
        ui->lineEdit_4->setText(Qt_Buf_LineEdit);

        //printf("count_mas_26=%d\n", counter_mas[26]);
        //Считываем имя файла протокола

        Read_File_Inf();
        ui->lineEdit_2->setText(Qt_Buf_LineEdit);
        //Считываем имя циклограммы


        Read_File_Inf();
        ui->comboBox->addItem(Qt_Buf_LineEdit);
        //ui->lineEdit->setText(Qt_Buf_LineEdit);

        Form_PopupCgNamesList();

         File_Info.close();

          File_Info.remove("LAST.txt");

    }*/




    //MainWindow::readSettings();
}

MainWindow::~MainWindow()
{
    // сохраняем путь к файлу
    //qDebug()<<"WarningDDD!";


        int cnt=0;


        settings.beginGroup("Ruby_script");
        settings.setValue("flpath", flpath);
        settings.setValue("flpath_2", flpath_2);
        settings.setValue("Qt_sbl_file", Qt_sbl_file);
        settings.setValue("Qt_kdr_file", Qt_kdr_file);
        settings.endGroup();
        QDir dir("META-INF");
        //Sleep(2000);
        dir.removeRecursively();
        remove("content.xml");
        remove("manifest.xml");
        remove(qPrintable(out));

        for(cnt=0; cnt<vect_SZO.size(); cnt++)
        {
            qDebug()<<"------------";
            qDebug()<<"Time="<<vect_SZO[cnt].SZO_time;
            qDebug()<<"Value="<<vect_SZO[cnt].value;
            qDebug()<<"Descr="<<vect_SZO[cnt].SZO_description;
            qDebug()<<"------------";

        }



        //remove(qPrintable(out.remove("_new")));
        //qDebug()<<"Warning!";
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->show();
    ui->progressBar->setRange(0,100);

    ui->progressBar->setValue(0);




    counter_mas[34]=0;
    //Call_Worker();

    Init_Normative_values();

    /*TrueValue[0]="0004";
    TrueValue[1]="0001";
    TrueValue[2]="00FF";*/
    /*WrongFeatures.append("bkj;");
    RealValues.append("ll;");*/
    ui->progressBar->setValue(10);

    if(ui->radioButton->isChecked())
    {
        flag|=(1<<30);
    }

    Qt_sbl_file=QCoreApplication::applicationDirPath()+"/Cyclograms/"+"ArcM"+".sbl";
    Qt_sbl_file = QDir::fromNativeSeparators(Qt_sbl_file);
    Qt_kdr_file=ui->lineEdit_5->text();
    Call_Worker();
    ui->progressBar->setValue(40);


    //File_Info.close();
    if((flag&(1<<16)))
        {
            vect_Cg_name.clear();
            flag&=~(1<<16);
        }
    flpath=ui->lineEdit_2->text();
    flpath.remove(flpath.lastIndexOf("/"),flpath.count()-flpath.lastIndexOf("/"));

    //flpath_2=ui->lineEdit_4->text();
    flpath_2.remove(flpath_2.lastIndexOf("/"),flpath_2.count()-flpath_2.lastIndexOf("/"));
   // ui->progressBar->setValue(60);



    Qt_Inf_Zg = ui->lineEdit_2->text();
    //Qt_Zg_Name = ui->lineEdit->text();
    
    if(!Qt_Inf_Zg.isEmpty())
    {
       flag|=(1<<19);
       //qDebug()<<"WWWWWWWWWWWWWWW!!!!!!!!";
       //Qt_Zg_Name=ui->comboBox->currentText();

    }
    //ui->progressBar->setValue(70);
    /*if(flag&(1<<19))
    {
        qDebug()<<"LLLLLLL";


    }*/
    
    


    //qDebug() << "Qt_Tel_Name:";

    //qDebug() << Qt_Tel_Name;

    ///////////////////////
    //For test:

    //Qt_Tel_Name.clear();
    //Qt_Tel_Name="C:/Users/User/Desktop/tmi/VALUE_PVV_report.txt";

    ////////////////////////
     Ch_Tel_Name=qPrintable(Qt_Tel_Name);
     //qDebug() << "Ch_Tel_Name:";
     //qDebug() << Qt_Tel_Name;
     TEST=Ch_Tel_Name;
    file=fopen(Ch_Tel_Name, "r");
    qDebug()<<"Ch_Tel_Name="<<Ch_Tel_Name;
    /*Ch_Prot_Name=qPrintable(Qt_Prot_Name);
    protocol=fopen(Ch_Prot_Name, "w");*/
    //printf("Ch_Pr_Name=%s\n", Ch_Prot_Name);
    //ui->progressBar->setValue(80);
    
    
    
   if(flag&(1<<19))
    {
       //qDebug()<<"AAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!!";
       Ch_Inf_Zg=qPrintable(Qt_Inf_Zg);
       input=fopen(Ch_Inf_Zg, "r");
       //Действия в случае ошибки при открытии файла:
       //printf("AAAAAAAAAA!\n");
           if(input==NULL)
       {
           printf("Не удалось открыть файл %s!\n", Ch_Inf_Zg);
           //ui->label->setText("Не удалось открыть файл с информацией циклограммы");
           //flag_2=1;
           //SecondWindow window;
           //window.setModal(true);
           //window.flag_opa=1;
           //window.exec();
           //ui_2->
           //exit(3);
           QMessageBox::critical(this, "Ошибка!", "Ошибка при открытии файла с информацией циклограммы");
           flag|=(1<<16);
           //ui->comboBox->clear();
          // QApplication::quit();
       }
           //printf("AAAAAAAAAA!\n");

      }

       if(file==NULL)
   {
       printf("Не удалось открыть файл %s!\n", Ch_Tel_Name);
       QMessageBox::critical(this, "Ошибка!", "Ошибка при открытии файла телеметрической информации");
       flag|=(1<<16);
       //exit(2);
   }


       //huhjk


        ui->progressBar->setValue(50);
        /////////////////////
        Quant_Of_Symbl_In_File();
        //qDebug()<<quant_of_symb_in_Tel_file;


        quant_of_symb_in_Tel_file=quant_of_symb_in_Tel_file_norm;
        while(count_features!=Mas_Nominal_features.size())
        {
            fseek(file, 0, SEEK_SET);
            Nominal_features=Mas_Nominal_features[count_features];
            Test_of_others_features();
            WrongFeatures.append(Nominal_features);
            if(!Nominal_features.isEmpty())
            {
              WrongFeatures.append(";");
            }

            quant_of_symb_in_Tel_file=quant_of_symb_in_Tel_file_norm;
            count_features++;
            fseek(file, 0, SEEK_SET);
        }
        //qDebug()<<quant_of_symb_in_Tel_file;
        

   



        ////////////////////
        quant_of_symb_in_Tel_file=quant_of_symb_in_Tel_file_norm;

        Test_Rtvk_Vkl();
        ui->progressBar->setValue(70);

        if(WrongFeatures.contains(":5:"))
        {
            if(WrongFeatures.lastIndexOf("rtvk_vkl(19) = 0x8000")>WrongFeatures.indexOf(":5:"))
            {
                if(WrongFeatures.lastIndexOf("rtvk_vkl(20) = 0x0002")>WrongFeatures.indexOf(":5:"))
                {
                    Qt_Zg_Name="Cg1";
                }
            }
        }
        else
        {
           Qt_Zg_Name="Cg2";
        }

        fseek(file, 0, SEEK_SET);
        //qDebug()<<"WrongFeatures:"<<WrongFeatures;
        //qDebug()<<"RealValues:"<<RealValues;

        ///////////////////////////////////////


    //ui->progressBar->setValue(60);

     

if(flag&(1<<19))
{

    
    vect_Cg_name.clear();
    //qDebug() << "111";


    //Вносим имя циклограммы, введённое пользователем, в вектор, преназначенный для его хранения
    if(Qt_Zg_Name.count()!=0)
    {


         Ch_Zg_Name=qPrintable(Qt_Zg_Name);

        while(*Ch_Zg_Name!='\0')
        {
           vect_Cg_name.push_back(*Ch_Zg_Name);
           Ch_Zg_Name++;
           counter_mas[30]++;
           //counter_mas[0]++;
        }


        if(vect_Cg_name[0]=='c')
        {

            vect_Cg_name[0]='C';
        }
        if((vect_Cg_name[0]!='C')||(vect_Cg_name[1]!='g'))
        {
            printf("Mistake in the input the name of the CG!\n");
            QMessageBox::critical(this, "Ошибка!", "Ошибка в имени циклограммы!");
            flag|=(1<<16);
            //qApp->quit();
            //exit(4);
        }

    }
    else
    {
        QMessageBox::critical(this, "Ошибка!", "Ошибка в имени циклограммы!");
        flag|=(1<<16);
    }
 ui->progressBar->setValue(65) ;


    //--------------------------------------------------------------------------
    counter_mas[0]=0;

    for(support_var=0; support_var<25; support_var++)
    {
        counter_mas[support_var]=0;
    }
    //--------------------------------


        if(flag&(1<<19))
            {
                //qDebug()<<"FFFFFFFFFF";

            }
        else
        {
            //qDebug()<<"888";

        }







    //------------------------------------------------------------------
    if(!(flag&(1<<16)))
    {
        if(flag&(1<<19))
            {
                //qDebug()<<"22222222222";

            }
        else
        {
            //qDebug()<<"888";

        }


    if(!(flag&(1<<16)))
        {
            //printf("BBBBBBBB!\n");

        }

  
    //-----------------------------------

    counter_mas[1]=0;
    fseek(input, 0, SEEK_SET);

    counter_mas[0]=0;
    //printf("Start\n");
    ui->progressBar->setValue(93);
    Check_Quantity_CgSymbols();
    //printf("Символов в именах циклограмм: %d\n", counter_mas[0]);
    Cg_Names= (char*) malloc(counter_mas[0]*sizeof(char));
    if(Cg_Names == NULL)
    {
        printf("Ошибка выделения памяти");
        exit(5);
    }

    fseek(input, 0, SEEK_SET);
    counter_mas[1]=0;
    counter_mas[0]=0;
    counter_mas[2]=0;
    //ui->progressBar->setValue(94);
    Read_Cg_Names_In_Mas();
    //qDebug()<<Cg_Names;
    //printf("ext\n");
    //printf("BB=%s\n", Ch_Tel_Name);




    //printf("NAMES_OF_CG:%s\n", Cg_Names);
    fseek(input, 0, SEEK_SET);
    counter_mas[1]=0;
    counter_mas[0]=0;
    counter_mas[2]=0;
    flag&=~(1<<9);

    Install_Counter();
    //printf("1\n");

    counter_mas[1]=0;
    //counter_mas[0]=0;
    counter_mas[2]=0;
    flag&=~(1<<9);

   

    //qDebug() << "222";
    if(flag&(1<<19))
        {
            //qDebug()<<"LLLLLLL2";

        }


    Inst_Count_To_Pos();
    ui->progressBar->setValue(95);

                //-----------------------------------
                counter_mas[9]++;
                counter_mas[8]=0;
                counter_mas[5]=counter_mas[5]+3;
                counter_mas[15]=0;


                Read_Zg_File();
                

                counter_mas[13]=0;

                counter_mas[10]=0;
                Num=0;
                counter_mas[7]=0;
                Read_Stock_Inf_In_Mas();
                //Show_Vector(vect_mas_inp_int_inf);
                //printf("opa!\n");


                //Вывод в массив названий модулей-----------------------------

                Read_In_Mas_Module_Names();
                //printf("3\n");

                //---------------------------------------------------------
                for(counter_mas[22]=0; counter_mas[22]<vect_mas_inp_int_inf.size(); counter_mas[22]++)
                {
                    if(((vect_mas_inp_int_inf[counter_mas[22]]==0))&&(flag&(1<<14)))
                    {
                        if(vect_mas_inp_int_inf[counter_mas[22]-1]!=0)
                        {
                            fix_value.push_back(vect_mas_inp_int_inf[counter_mas[22]-1]);
                            //counter_mas[24]++;
                        }

                    }
                    flag|=(1<<14);
                    //counter_mas[23]=1;

                    //printf("fix_value=%d\n", fix_value[fix_value.size()-1]);

                }


                //printf("fix_value=%d\n", fix_value[1]);
                flag&=~(1<<14);
                counter_mas[23]=0;


                while(counter_mas[6]!=quantity)
                {
                    Var1_on_time=vect_mas_inp_int_inf[counter_mas[6]];
                    if(Var1_on_time==0)
                    {
                        vect_mas_inp_int_inf[counter_mas[6]]=0;
                    }
                    else
                    {
                        if((Var2_on_time==0)&&(flag&(1<<14)))
                        {
                            //printf("VAR1=%d\n", Var1_on_time);
                            //printf("elem=%d\n", fix_value[fix_value.size()-1]);
                            vect_mas_inp_int_inf[counter_mas[6]]=(Var1_on_time-fix_value[counter_mas[24]])*10;
                            counter_mas[24]++;
                            fix_value.pop_back();
                        }
                        else
                        {
                        //printf("VAR1=%d\n", Var1_on_time);
                        //printf("VAR2=%d\n", Var2_on_time);
                        //printf("elem=%d\n", Var2_on_time);
                            vect_mas_inp_int_inf[counter_mas[6]]=(Var1_on_time-Var2_on_time)*10;
                        }
                        flag|=(1<<14);
                        //counter_mas[23]=1;


                    }


                    Var2_on_time=Var1_on_time;
                    counter_mas[6]++;
                }
                quantity++;
                counter_mas[0]=0;
                counter_mas[6]=0;




                ui->progressBar->setValue(96);
                //---------------------------------------------------------------------------

                //Treatment_of_Mistakes();
                if(flag&(1<<16))
                {
                   QMessageBox::critical(this, "Ошибка!", "Ошибка в имени циклограммы!");
                   exit(2);


                }
                //printf("4\n");
                //printf("\n");
            //}
            //printf("---%s---\n", mas_inp_char_inf);

        //}
    //}
                 //printf("CC=%s\n", Ch_Tel_Name);
    counter_mas[15]=0;
    //***************************************
    for(counter_mas[3]=0; counter_mas[3]<9; counter_mas[3]++)
    {
        list_of_remove[counter_mas[3]]=0;// Инициализация массива list_of_remove
    }
    counter_mas[3]=0;
    if(fseek(file, 0, SEEK_SET)==0)
    {
        //printf("1-OK!\n");
    }
    //Подсчёт чсла символов в файле с исходной телеметрической информацией

    while((fgetc(file))!=EOF)
    {
        counter_mas[0]++;
    }
    counter_mas[0]++;






    //-----------------------------------------------------
    //mas[counter_mas[0]]='\0';
    //printf("%d\n", counter_mas[0]);
    quant_sym=counter_mas[0];
    //printf("FF=%s\n", Ch_Tel_Name);

    ReWrite_Value_pvv_InVector();
    //qDebug() << "333";
//    printf("5\n");

    //---------------------------------------------------------------------------------------


counter_mas[2]=0;
//cout<<endl;



counter_mas[15]=0;
//flag=0;
//flag&0;
flag&=~(1<<1);
flag&=~(1<<5);

    //--------------------------------------
//qDebug() << "444";


    Find_Quant_Of_Sides_And_Size_Of_Pass();
    //qDebug() << "444";
    if(counter_mas[34]==1)
    {






    Create_XML_Doc();
    //printf("GG=%s\n", Ch_Tel_Name);
    Fill_Hat();

    //rintf("6\n");


    /*if(quant_of_sides==1)
    {
        fprintf(protocol, "Номер_точки; Имя_модуля; Первая_грань[мкс];  Макс.значение[мкс]; Фактическое_время_работы_грани[мкс]; Время_завершения_по_ЦГ[мкс]; Время_по_ЦГ[мкс]; Запас[мкс]; Запас,%% \n");
    }
    if(quant_of_sides==2)
    {
        fprintf(protocol, "Номер_точки; Имя_модуля; Первая_грань[мкс];   Вторая_грань[мкс];  Макс.значение[мкс]; Фактическое_время_работы_грани[мкс]; Время_завершения_по_ЦГ[мкс]; Время_по_ЦГ[мкс]; Запас[мкс]; Запас,%% \n");
    }
    if(quant_of_sides==3)
    {
        fprintf(protocol, "Номер_точки; Имя_модуля; Первая_грань[мкс];   Вторая_грань[мкс];  Третья_грань[мкс];  Макс.значение[мкс]; Фактическое_время_работы_грани[мкс]; Время_завершения_по_ЦГ[мкс]; Время_по_ЦГ[мкс]; Запас[мкс]; Запас,%% \n");
    }*/


     max_flag=counter_mas[15];
     counter_mas[15]=0;
     //qDebug() << "444";
     //printf("%s\n", Ch_Tel_Name);
     //printf("%s\n", mas);
     //Show_Vector(mas_file);

    //--------------------------------------------------------------------------------------------------------------------------------------
    //Полготовка массивов с результатами и вывод значений данных массивов на экран


     counter_mas[6]=0;
        flag&=~(1<<5);
        //u=0;
        //int count5=0;
        Preparation_Results_and_Output();
       // printf("7\n");


        quantity--;

    pvv_quantity--;
    if(quant_of_sides==3)
    {
      pvv_quantity=pvv_quantity/3;
    }
    else if(quant_of_sides==2)
    {
        pvv_quantity=pvv_quantity/2;
    }



    //Вывод информации на экран:
    Print_Out_Inf_On_Screen(Ch_Prot_Name, vect_Cg_name, quantity, pvv_quantity, quant_of_sides, quant_point_less30per);
    //printf("8\n");


    End_Xml_Doc();
    Empty.clear();
    /*Qt_SystemInf=Empty+"\"7za.exe\" "+"a "+"-tzip "+"-mx=1 "+Qt_Prot_Name+" content.xml";
    Ch_Prot_Name=qPrintable(Qt_SystemInf);



    system(Ch_Prot_Name);*/
    //system("\"7za.exe\" a -tzip -mx=1 Protocol.ods content.xml");



    Create_ODS_File();
    Print_Out_Inf_To_Dialog();

    //qDebug() << "444";


    //free(mas_inp_file);
    free(Cg_Names);

    /*File_Info.setFileName("LAST.txt");
    if(!File_Info.open(QIODevice::WriteOnly))
    {
        printf("Mistake during opening the file!");
        QApplication::quit();
    }

    printf("%s\n", Ch_Inf_Zg);


    File_Info.write(Ch_Zg_Name);



    File_Info.close();*/
    /*remove("content.xml");
    remove("manifest.xml");*/
    //WinExec("rmdir /Q /S META-INF", SW_HIDE);
    //ShowWindow(GetConsoleWindow(), SW_HIDE);
    //WinExec("del.bat", SW_HIDE);
    //system("rmdir /Q /S META-INF");
    /*QDir dir("META-INF");
    dir.removeRecursively();*/
    //qDebug()<<counter_mas[34];

    Test_of_others_features();
    ui->progressBar->setValue(70);

    //Новая функция для анализа:


    SecondWindow window;
    window.setModal(true);
    window.exec();


    QMainWindow::close();
    fclose(file);
    fclose(input);
    QApplication::quit();

    }

    else
    {
        QMessageBox::critical(this, "Ошибка!", "Файл с телеметрической информацией содержит данные больше чем одного испытания");
        //
        fclose(file);





        file=fopen(Ch_Tel_Name, "r");


        //qDebug()<<"KKKKKK!!!";





        Analys_changing_values();
        Print_Out_Inf_To_Dialog();
        ui->progressBar->setValue(100);

        SecondWindow window;
        window.setModal(true);
        window.exec();

        QMainWindow::close();
        fclose(file);
        fclose(input);
        QApplication::quit();
    }
    /*SecondWindow window;
    window.setModal(true);
    window.exec();*/
    /*QMainWindow::close();
    fclose(file);
    fclose(input);
    QApplication::quit();*/






    }
 }
 else
 {
     //Call_Worker();
     //qDebug()<<"Name_of_file="<<TEST;


     //qDebug()<<"Name_of_file="<<TEST;







   // fclose(file);

    //Call_Worker();



    //qDebug()<<"Name_of_file="<<qPrintable(TEST);



     /*file=fopen(qPrintable(TEST), "r");
     if(file==NULL)
     {
         qDebug()<<"FAIL";

     }*/


     //qDebug()<<"111111";
     //Sleep(3000);



     fclose(file);



     file=fopen(qPrintable(QDir::fromNativeSeparators(QCoreApplication::applicationDirPath()+"/"+out)), "r");

     if(file==NULL)
     {
         //qDebug()<<"FAIL!";
     }


     //qDebug()<<qPrintable(QDir::fromNativeSeparators(QCoreApplication::applicationDirPath()+"/"+out));


     //qDebug()<<"KKKKKK!!!";
     ui->progressBar->setValue(80);



     Analys_changing_values();
     Print_Out_Inf_To_Dialog();
     ui->progressBar->setValue(100);

     ui->progressBar->close();
     SecondWindow window;
     window.setModal(true);
     window.exec();


     QMainWindow::close();
     fclose(file);
     //fclose(input);
     //qDebug()<<"KKKKKK!!!";
     QApplication::quit();

 }
    /*free(mas_inp_file);
    free(Cg_Names);*/

    /*fclose(file);
    fclose(input);*/








 //ui->progressBar->setValue(100);
    //QWidget::saveGeometry();

    //QWidget::close();
}









int Transl_To_Dec_System(char Num1, char Num2, char Num3, char Num4)
{
    int result;
    int Val1, Val2, Val3, Val4;
    Val1=Conv_Of_Types(Num1);
    Val2=Conv_Of_Types(Num2);
    Val3=Conv_Of_Types(Num3);
    Val4=Conv_Of_Types(Num4);
    result=Val1*power(16,3)+Val2*power(16, 2)+Val3*power(16,1)+Val4*power(16, 0);
    return result;
}

int power(int number, int indicator)
{
    if(indicator==0)
       {
          return 1;
       }
    return number * power(number, indicator-1);
}

int Conv_Of_Types(char num)
{
    if(num=='0')
    {
        return 0;
    }
    if(num=='1')
    {
        return 1;
    }
    if(num=='2')
    {
        return 2;
    }
    if(num=='3')
    {
        return 3;
    }
    if(num=='4')
    {
        return 4;
    }
    if(num=='5')
    {
        return 5;
    }
    if(num=='6')
    {
        return 6;
    }
    if(num=='7')
    {
        return 7;
    }
    if(num=='8')
    {
        return 8;
    }
    if(num=='9')
    {
        return 9;
    }
    if(num=='A')
    {
        return 10;
    }
    if(num=='B')
    {
        return 11;
    }
    if(num=='C')
    {
        return 12;
    }
    if(num=='D')
    {
        return 13;
    }
    if(num=='E')
    {
        return 14;
    }
    if(num=='F')
    {
        return 15;
    }
    return -1;
}

void Instruction(void)
{
    printf("Данная программа предназначена для вывода времени выполнения модулей на каждой грани");
    printf(" и их сравнения.\n");
    printf("Программу следует запускать так:\n");
    printf("Ziklogramma2.exe \n1) input_file        имя файла с исходной телеметрической информацией\n");
    printf("2) prot_file         имя файла протокола\n");
    printf("3) Cg_inf_file       имя файла с информацией циклограммы\n");
    printf("4) СgNumber          имя циклограммы\n");
}

int Conv_Char_To_Int(char *chislo)
{
    if(chislo[0]=='0')
    {
        if(chislo[1]=='0')
        {
            return 0;
        }
        if(chislo[1]=='1')
        {
            return 1;
        }
        if(chislo[1]=='2')
        {
            return 2;
        }
        if(chislo[1]=='3')
        {
            return 3;
        }
        if(chislo[1]=='4')
        {
            return 4;
        }
        if(chislo[1]=='5')
        {
            return 5;
        }
        if(chislo[1]=='6')
        {
            return 6;
        }
        if(chislo[1]=='7')
        {
            return 7;
        }
        if(chislo[1]=='8')
        {
            return 8;
        }
        if(chislo[1]=='9')
        {
            return 9;
        }
    }
    if(chislo[0]=='1')
    {
        if(chislo[1]=='0')
        {
            return 10;
        }
        if(chislo[1]=='1')
        {
            return 11;
        }
        if(chislo[1]=='2')
        {
            return 12;
        }
        if(chislo[1]=='3')
        {
            return 13;
        }
        if(chislo[1]=='4')
        {
            return 14;
        }
        if(chislo[1]=='5')
        {
            return 15;
        }
        if(chislo[1]=='6')
        {
            return 16;
        }
        if(chislo[1]=='7')
        {
            return 17;
        }
        if(chislo[1]=='8')
        {
            return 18;
        }
        if(chislo[1]=='9')
        {
            return 19;
        }
    }
    if(chislo[0]=='2')
    {
        if(chislo[1]=='0')
        {
            return 20;
        }
        if(chislo[1]=='1')
        {
            return 21;
        }
        if(chislo[1]=='2')
        {
            return 22;
        }
        if(chislo[1]=='3')
        {
            return 23;
        }
        if(chislo[1]=='4')
        {
            return 24;
        }
    }
    //printf("%c", chislo[0]);
    //printf("%c\n", chislo[1]);
    return -1;
}
void Show_Vector(vector <char> vect)
{
    for(vector<char>::iterator it=vect.begin(); it!=vect.end(); ++it)
    {
        cout<<*it;
    }
}
void Print_Out_Inf_On_Screen(const char *argv, vector <char> vect_Cg_name, int quantity, int pvv_quantity, int quant_of_sides, int quant_point_less30per)
{
    printf("\nВыходной файл: %s\n", argv);
    printf("Циклограмма:");
    Show_Vector(vect_Cg_name);
    printf("\n");
    printf("Количество точек в циклограмме: %d\n", quantity);
    printf("Количество точек в массиве value_pvv: %dx%d\n", pvv_quantity, quant_of_sides);
    printf("Количество точек с запасом: <30%% %d\n", quant_point_less30per);
}

void Print_Out_Inf_To_Dialog(void)
{
    //Create_Report_allPar_File();


    Qt_OutFile_name=Qt_OutFile_name+"Имя файла с расшифрованной ТМИ: "+QString(out)+"<br />";


    QDebug debug =qDebug();
    int flg=0;

    int internal_count_3=0;

    if(flag&(1<<19))
        {
            //qDebug()<<"OPA!!!!!!";

        }


    int internal_counter=0;
    int internal_counter_2=0;
    QString Buffer_Wrong;
    QString Buffer_Real;


   // Qt_OutFile_name.append("<b>Hello</b> <i>Qt!</i>");

    qDebug()<<"WrongFeatures="<<WrongFeatures;
    qDebug()<<"RealValues="<<RealValues;

    if((counter_mas[34]!=1)&&((flag&(1<<19))))
    {
      Qt_OutFile_name=Qt_OutFile_name+"Обрабатываемый файл телеметрической информации содержит информацию об нескольких испытаниях или не содержит нужных идентификаторов. Анализ нормативности в части value_pvv проводиться не будет.\n";
      //qDebug()<<"opa!";
    }
    else if(!(flag&(1<<19)))
    {
       // Qt_OutFile_name="Не указан файл с информацией циклограммы. Анализ нормативности в части value_pvv проводиться не будет.\n";
        Qt_OutFile_name=Qt_OutFile_name+"Не указан файл с информацией циклограммы. Анализ нормативности в части value_pvv проводиться не будет.<br />";

    }
    if(counter_mas[34]==1)
    {
        Qt_OutFile_name=Qt_OutFile_name+"Выходной файл: "+Qt_Prot_Name+"\n";
        //qDebug()<<Qt_Prot_Name;

        Qt_OutFile_name=Qt_OutFile_name+"Циклограмма: "+Qt_Zg_Name+"\n";
        Qt_OutFile_name=Qt_OutFile_name+"Количество точек в циклограмме: "+QString::number(quantity)+"\n";
        Qt_OutFile_name=Qt_OutFile_name+"Количество точек в массиве value_pvv: "+QString::number(pvv_quantity)+"x"+QString::number(quant_of_sides)+"\n";
        Qt_OutFile_name=Qt_OutFile_name+"Количество точек с запасом: <30%: "+QString::number(quant_point_less30per)+"\n";

    }

    //Qt_OutFile_name=Qt_OutFile_name+"Имя файла с расшифрованной ТМИ: \n";//+QString(out);
    //Qt_OutFile_name=Qt_OutFile_name+"\n";




    //qDebug()<<"WRONG_FEATURES:"<<WrongFeatures;
    if(WrongFeatures.contains(":5:"))
    {
        if(WrongFeatures.lastIndexOf("rtvk_vkl(19) = 0x8000")>WrongFeatures.indexOf(":5:"))
        {
            if(WrongFeatures.lastIndexOf("rtvk_vkl(20) = 0x0002")>WrongFeatures.indexOf(":5:"))
            {
                //qDebug()<<"NUMBER:"<<WrongFeatures.lastIndexOf("rtvk_vkl(19) = 0x8000");
                WrongFeatures.remove(WrongFeatures.lastIndexOf("rtvk_vkl(19) = 0x8000"), 22);
                WrongFeatures.remove(WrongFeatures.lastIndexOf("rtvk_vkl(20) = 0x0002"), 22);
                RealValues.remove(RealValues.lastIndexOf("rtvk_vkl(19) = 0x0000"), 22);
                RealValues.remove(RealValues.lastIndexOf("rtvk_vkl(20) = 0x0001"), 22);
                //WrongFeatures.remove(":5:");
                // = 0x8000
                //WrongFeatures.remove(":5:");
                //qDebug()<<"WRONG_FEATURES2:"<<WrongFeatures;

                if((WrongFeatures.lastIndexOf("rtvk_vkl")<WrongFeatures.indexOf(":5:"))||(!WrongFeatures.contains("rtvk_vkl")))
                {
                   WrongFeatures.remove(":5:");

                }
            }
        }

    }
    if(!WrongFeatures.isEmpty()&&(WrongFeatures[0]!=':')&&(WrongFeatures[0]!='?'))
    {
        Qt_OutFile_name=Qt_OutFile_name+"Следующие параметры ТМИ СОВП БВУ при начальном включении не соответствуют номинальным:";
        ProtNomValues.push_back("%");
        ProtTMIValues.push_back("%");
        ProtNamesModules.push_back("%");
        //Qt_OutFile_name=Qt_Ou tFile_name+"Номинальное значение          Значение по ТМИ\n";
        Set_Table_Head();

    }


    if(!WrongFeatures.isEmpty())
    {
        //Qt_OutFile_name=Qt_OutFile_name+"Следующие параметры ТМИ СОВП БВУ при начальном включении не соответствуют номинальным:\n";
        /*Qt_OutFile_name=Qt_OutFile_name+"Следующие параметры ТМИ СОВП БВУ при начальном включении не соответствуют номинальным:<br />";
        Qt_OutFile_name=Qt_OutFile_name+"Номинальное значение          Значение по ТМИ\n";*/

        while(WrongFeatures.count()!=internal_counter)
        {
            //qDebug()<<"Buffer_Real="<<Buffer_Real;
            //qDebug()<<"Buffer_Wrong="<<Buffer_Wrong;
            if((RealValues[internal_counter_2]==';')&&(WrongFeatures[internal_counter]==';')&&(WrongFeatures[internal_counter]!=':')&&(WrongFeatures[internal_counter]!='|'))
            {
               // "<table border=\"1\"><tr><th>NAME</th><th>PHONE</th></tr><tr><td>Hello</td><td>Hello</td></tr><tr><td>6756756756</td><td>54666543</td></tr></table>";
                Qt_OutFile_name=Qt_OutFile_name+"<tr><td>"+Buffer_Wrong+"</td>"+"<td>"+Buffer_Real+"</td></tr>";

                ProtNamesModules.push_back(Buffer_Wrong);
                ProtNamesModules[ProtNamesModules.size()-1].remove(ProtNamesModules[ProtNamesModules.size()-1].lastIndexOf(" ")-2, ProtNamesModules[ProtNamesModules.size()-1].count());
                ProtNomValues.push_back(Buffer_Wrong);
                ProtNomValues[ProtNomValues.size()-1].remove(0, ProtNomValues[ProtNomValues.size()-1].lastIndexOf(" ")+1);
                ProtTMIValues.push_back(Buffer_Real);
                ProtTMIValues[ProtTMIValues.size()-1].remove(0, ProtTMIValues[ProtTMIValues.size()-1].lastIndexOf(" ")+1);

                //qDebug()<<ProtTMIValues[ProtTMIValues.size()-1];


                //Qt_OutFile_name=Qt_OutFile_name+Buffer_Wrong+"          "+Buffer_Real+"\n";
                //qDebug()<<"Buffer_Wrong="<<Buffer_Wrong;
                //qDebug()<<"Buffer_Real="<<Buffer_Real;
                //qDebug()<<"Buffer_Real_SYMBOL="<<RealValues[internal_counter_2];
                Buffer_Wrong.clear();
                Buffer_Real.clear();
                internal_counter_2++;
                internal_count_3=0;
                //flag&=~(1<<3);
                /*flg=1;*/
            }
            else if((WrongFeatures[internal_counter]!=';')&&(WrongFeatures[internal_counter]!=':')&&(WrongFeatures[internal_counter]!='?')&&(WrongFeatures[internal_counter]!='|'))
            {
                Buffer_Wrong.append(WrongFeatures[internal_counter]);
                //debug<<internal_counter;
                if(RealValues[internal_counter_2]!=';')
                {
                    Buffer_Real.append(RealValues[internal_counter_2]);
                    //internal_counter++;
                    internal_counter_2++;

                }
                //flag_2|=(1<<3);
            }
            else if((WrongFeatures[internal_counter]==';')&&(RealValues[internal_counter_2]!=';'))
            {
                //qDebug()<<"MMMMMMMMMMMMMMMMMMMMMMMM";
                flag_2|=(1<<8);
                Buffer_Real.append(RealValues[internal_counter_2]);
                //qDebug()<<RealValues[internal_counter_2];
                internal_counter_2++;

            }




            if(WrongFeatures[internal_counter]==':')
            {
                internal_counter++;

                if(internal_counter!=1)
                {
                    Qt_OutFile_name=Qt_OutFile_name+"</table>";
                }


                //Qt_OutFile_name=Qt_OutFile_name+"                      Массив РТВК "+QString(WrongFeatures[internal_counter])+"-го кадра"+"\n";

                Qt_OutFile_name=Qt_OutFile_name+"                      Массив РТВК "+QString(WrongFeatures[internal_counter])+"-го кадра";
                ProtNomValues.push_back(":"+QString(WrongFeatures[internal_counter])+":");
                ProtTMIValues.push_back(":"+QString(WrongFeatures[internal_counter])+":");
                ProtNamesModules.push_back(":"+QString(WrongFeatures[internal_counter])+":");

                Set_Table_Head();

                internal_counter++;
                internal_counter++;
                /*if(flg!=1)
                {
                    internal_counter_2++;

                }*/


                flag_2|=(1<<8);///Убираем трабл с исчезновением первой буквы




            }
            if(WrongFeatures[internal_counter]=='?')
            {

                //Qt_OutFile_name=Qt_OutFile_name+"Значения следующих параметров ТМИ, характеризующих работу БВУ, не соответствуют номинальным:\n";
                Qt_OutFile_name=Qt_OutFile_name+"</table>";
                Qt_OutFile_name=Qt_OutFile_name+"Значения следующих параметров ТМИ, характеризующих работу БВУ, не соответствуют номинальным:";

                ProtNomValues.push_back("?");
                ProtTMIValues.push_back("?");
                ProtNamesModules.push_back("?");

                Set_Table_Head();

                //internal_counter++;
                //flag&=~(1<<22);
            }














            if(WrongFeatures[internal_counter]=='|')
            {

                //Qt_OutFile_name=Qt_OutFile_name+"Значения следующих параметров ТМИ, характеризующих работу БУК, не соответствуют номинальным:\n";
                Qt_OutFile_name=Qt_OutFile_name+"</table>";
                Qt_OutFile_name=Qt_OutFile_name+"Значения следующих параметров ТМИ, характеризующих работу БУК, не соответствуют номинальным:";
                Set_Table_Head();

                ProtNomValues.push_back("|");
                ProtTMIValues.push_back("|");
                ProtNamesModules.push_back("|");

                //internal_counter++;
                //flag&=~(1<<22);
            }
            /*qDebug()<<"WrongFeatures="<<WrongFeatures;
            qDebug()<<"RealValues="<<RealValues;*/
            //qDebug()<<WrongFeatures;
            //qDebug()<<internal_counter;

            if(!(flag_2&(1<<8)))
            {
                internal_counter++;

            }
            flag_2&=~(1<<8);


            flg=0;
            //internal_counter_2++;

        }


    }
    else
    {

        Qt_OutFile_name=Qt_OutFile_name+"Все анализируемые признаки соответствуют нормативным значениям\n";
        //qDebug()<<"Warning!";


    }
    Qt_OutFile_name=Qt_OutFile_name+"</table>";


    if(!vect_SZO.empty())
    {
        SZO_Out();

    }



    Create_Report_allPar_File();


}

/*void Treatment_of_Mistakes(void)
{
    //qDebug() << "AP!\n";
    while(Cg_Names[counter_mas[18]]!='\0')
    {
        counter_mas[18]++;
    }


    while((!(flag&(1<<11)))&&(!(flag&(1<<12))))
    {
        counter_mas[16]=0;
        while(Cg_Names[counter_mas[17]]==vect_Cg_name[counter_mas[16]])
        {

            counter_mas[17]++;
            counter_mas[16]++;
        }
        if((counter_mas[16]>=vect_Cg_name.size())&&(Cg_Names[counter_mas[17]]==':'))
            {
                flag|=(1<<12);
            }
        if(!(flag&(1<<12)))
        {
            if(Cg_Names[counter_mas[17]]!=vect_Cg_name[counter_mas[16]])
        {
            while(Cg_Names[counter_mas[17]]!=':')
            {
                counter_mas[17]++;

            }
            counter_mas[17]++;
        }
        if(counter_mas[17]>=counter_mas[18])
        {
            flag|=(1<<11);
        }
        }
    }
    if(!(flag&(1<<12)))
    {
        flag|=(1<<16);
    }
    //qDebug() << "OP!\n";
}*/
void Read_Cg_Names_In_Mas(void)
{
    flag&=~(1<<7);
    symbol=fgetc(input);
    int flg=0;
    int loc_count=0;
    while(symbol!=EOF)
    {
        if(counter_mas[0]!=0)
        {
           symbol=fgetc(input);
        }
        if(symbol=='C')
        {
            Cg_Names[counter_mas[0]]=symbol;
            //printf("%c", Cg_Names[counter_mas[0]]);
            counter_mas[0]++;
            //cv++;
            symbol=fgetc(input);
            if(symbol=='g')
            {
                Cg_Names[counter_mas[0]]=symbol;
                //printf("%c", Cg_Names[counter_mas[0]]);
                counter_mas[0]++;
                loc_count++;
                loc_count++;
                symbol=fgetc(input);
               while(!(flag&(1<<7)))
               {

                   if(symbol==':')
                   {
                       flag|=(1<<7);
                       flg=1;
                   }

                   Cg_Names[counter_mas[0]]=symbol;
                   //printf("%c", Cg_Names[counter_mas[0]]);
                   counter_mas[0]++;
                   loc_count++;
                   if((symbol==' ')||(symbol=='!')||(symbol=='\n'))
                   {
                       flag|=(1<<7);
                       if(flg==0)
                       {

                         counter_mas[0]=counter_mas[0]-loc_count;

                       }
                       //counter_mas[2]=0;
                   }
                   symbol=fgetc(input);
               }
                 flag&=~(1<<7);
                 flg=0;
                 loc_count=0;
            }
            else
            {
                counter_mas[0]--;
                //counter_mas[0]--;
            }

        }
        //counter_mas[0]=counter_mas[0]+counter_mas[2];
        //counter_mas[2]=0;
    }
    //printf("\n");
    //printf("counter_mas[0]=%d\n", counter_mas[0]);
    Cg_Names[counter_mas[0]]='\0';
}
void Find_Quant_Of_Sides_And_Size_Of_Pass(void)
{
    for(countt=0; countt<counter_read1; countt++)
    {
        if(mas_file[countt]=='v')
        {
            countt++;
            if(mas_file[countt]=='a')
            {
            countt++;
                if(mas_file[countt]=='l')
                {
                countt++;
                    if(mas_file[countt]=='u')
                    {
                    countt++;
                        if(mas_file[countt]=='e')
                        {
                        countt=countt+6;
                        //printf("%c\n", mas[countt]);
                        countt=countt+4;
                        if(mas_file[countt]=='=')
                        {
                        //printf("PRIZNAK=%d\n", priznak0);
                        countt=countt-4;
                        chislo[0]=mas_file[countt];
                        countt=countt+1;
                        chislo[1]=mas_file[countt];
                        num_of_pvv[counter_mas[15]]=Conv_Char_To_Int(chislo);
                        //flag_OK=0;
                        if(num_of_pvv[counter_mas[15]]==0)
                        {
                            countt=countt+7;
                            if((mas_file[countt]=='4')&&(mas_file[countt=countt+2]=='4')&&(mas_file[countt=countt+1]=='0'))
                            {
                                counter_mas[34]++;
                                //printf("OK!!!!!\n");
                                flag|=(1<<5);
                                countt=countt-2;
                                if((mas_file[countt]=='1')||(mas_file[countt]=='2')||(mas_file[countt]=='4')||(mas_file[countt]=='8'))
                                {
                                    quant_of_sides=1;
                                    //printf("Sides=%d!!!!\n", quant_of_sides);
                                }
                                if((mas_file[countt]=='3')||(mas_file[countt]=='6')||(mas_file[countt]=='5')||(mas_file[countt]=='9')||(mas_file[countt]=='A')||(mas_file[countt]=='C'))
                                {
                                    quant_of_sides=2;
                                    //printf("Sides=%d!!!!\n", quant_of_sides);
                                }
                                if((mas_file[countt]=='7')||(mas_file[countt]=='B')||(mas_file[countt]=='D')||(mas_file[countt]=='E'))
                                {
                                    quant_of_sides=3;
                                    //printf("Sides=%d!!!!\n", quant_of_sides);
                                }
                            }
                            else
                            {
                                flag&=~(1<<5);
                            }
                        }
                        if((flag&(1<<5)))
                        {

                        if(num_of_pvv[counter_mas[15]]!=0)
                        {
                            if(counter_mas[15]>=1)
                        {
                            znach1=num_of_pvv[counter_mas[15]];
                            //printf("--%d--\n", znach1);
                            counter_mas[15]--;
                            znach2=num_of_pvv[counter_mas[15]];
                            //printf("--%d--\n", znach2);
                            if((znach1%znach2)>1)
                            {
                                size_of_empty=znach1%znach2;
                                //printf("!!!!!\n");
                                empty_flag=1;
                            }
                            else
                            {
                                empty_flag=0;
                            }
                            counter_mas[15]++;
                        }
                        counter_mas[15]++;
                        }
                        if(!(flag&(1<<1)))
                            {
                                flag|=(1<<1);
                                priznak0--;
                            }
                            pvv_quantity++;
                        }
                        //printf("PVV_QUANTITY=%d", pvv_quantity);
                        }
                        }

                    }
                }
            }
        }
    }
}
void MainWindow::Create_ODS_File(void)
{
    //printf("OOO!\n");
    TiXmlDeclaration *dec1 = new TiXmlDeclaration("1.0", "ISO-8859-1", "");//XML декларация
    ods.LinkEndChild(dec1);
    TiXmlElement *element= new TiXmlElement("manifest:manifest");
    element->SetAttribute("xmlns:manifest", "urn:oasis:names:tc:opendocument:xmlns:manifest:1.0");
    element->SetAttribute("manifest:version", "1.2");
    TiXmlElement *element_2= new TiXmlElement("manifest:file-entry");

    element_2->SetAttribute("manifest:version", "1.2");
    element_2->SetAttribute("manifest:full-path", "/");
    element_2->SetAttribute("manifest:media-type", "application/vnd.oasis.opendocument.spreadsheet");


    TiXmlElement *element_3= new TiXmlElement("manifest:file-entry");
    element_3->SetAttribute("manifest:full-path", "Configurations2/accelerator/current.xml");
    element_3->SetAttribute("manifest:media-type", "");


    TiXmlElement *element_4= new TiXmlElement("manifest:file-entry");
    element_4->SetAttribute("manifest:full-path", "Configurations2/");
    element_4->SetAttribute("manifest:media-type", "application/vnd.sun.xml.ui.configuration");


    TiXmlElement *element_5= new TiXmlElement("manifest:file-entry");
    element_5->SetAttribute("manifest:full-path", "Thumbnails/thumbnail.png");
    element_5->SetAttribute("manifest:media-type", "image/png");


    TiXmlElement *element_6= new TiXmlElement("manifest:file-entry");
    element_6->SetAttribute("manifest:full-path", "content.xml");
    element_6->SetAttribute("manifest:media-type", "text/xml");


    TiXmlElement *element_7= new TiXmlElement("manifest:file-entry");
    element_7->SetAttribute("manifest:full-path", "settings.xml");
    element_7->SetAttribute("manifest:media-type", "text/xml");

    TiXmlElement *element_8= new TiXmlElement("manifest:file-entry");
    element_8->SetAttribute("manifest:full-path", "styles.xml");
    element_8->SetAttribute("manifest:media-type", "text/xml");

    TiXmlElement *element_9= new TiXmlElement("manifest:file-entry");
    element_9->SetAttribute("manifest:full-path", "manifest.rdf");
    element_9->SetAttribute("manifest:media-type", "application/rdf+xml");

    TiXmlElement *element_10= new TiXmlElement("manifest:file-entry");
    element_10->SetAttribute("manifest:full-path", "meta.xml");

    element_10->SetAttribute("manifest:media-type", "text/xml");




    element->LinkEndChild(element_2);
    element->LinkEndChild(element_3);
    element->LinkEndChild(element_4);
    element->LinkEndChild(element_5);
    element->LinkEndChild(element_6);
    element->LinkEndChild(element_7);
    element->LinkEndChild(element_8);
    element->LinkEndChild(element_9);
    element->LinkEndChild(element_10);


    ods.LinkEndChild(element);
    ods.SaveFile("manifest.xml");

    mkdir("META-INF");

    /*if(mkdir("META-INF")!=0)
    {
        cout<< "Mistake during creation the folder" <<endl;
    }*/

    if(!MainWindow::IsFoldExist("META-INF"))
        {
        QMessageBox::critical(this, "Ошибка!", "Ошибка при создании файла протокола!");
        exit(1);

        }
    CopyFile(L"manifest.xml",L"META-INF/manifest.xml",TRUE);

    //CopyFile()

    counter_mas[32]=0;

    Empty.clear();
    //Qt_Tel_Name = ui->lineEdit_4->text();
    Qt_Tel_Name.remove(Qt_Tel_Name.count()-5, 4);
    while(counter_mas[32]!=Qt_Tel_Name.count())
    {
        if(Qt_Tel_Name[counter_mas[32]]=='/')
        {
           Pos_Of_slash=counter_mas[32];

        }

        counter_mas[32]++;

    }



    Qt_Tel_Name.remove(0, Pos_Of_slash+1);

    Qt_SystemInf=Empty+"Protocol_"+Qt_Tel_Name+".ods";
    Empty.clear();

    if(IsFoldExist(qPrintable(Qt_SystemInf)))
    {
        //qDebug()<<"opa!";
        remove(qPrintable(Qt_SystemInf));
        //qDebug() << "OPA!";
        //system(qPrintable(Empty+"del "+Qt_SystemInf));
        //WinExec((qPrintable(Empty+"Ldel "+Qt_SystemInf)), SW_HIDE);
        //qDebug()<< qPrintable(Empty+"del "+Qt_SystemInf);


    }

    Qt_SystemInf.clear();

    /*Qt_SystemInf=Empty+"\"7za.exe\" "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+Qt_Tel_Name+".ods"+" META-INF/";
    Ch_Prot_Name=qPrintable(Qt_SystemInf);
    //cout<< Ch_Prot_Name <<endl;
    //ShowWindow(GetConsoleWindow(), SW_HIDE);
    WinExec(Ch_Prot_Name, SW_HIDE);*/
    //system(Ch_Prot_Name);


    counter_mas[32]=0;
    Empty.clear();
    Qt_SystemInf.clear();
    //Qt_Tel_Name = ui->lineEdit_4->text();
    Qt_Tel_Name.remove(Qt_Tel_Name.count()-5, 4);
    Qt_Tel_Name.remove(0, Pos_Of_slash+1);
    //const char* Ch_Prot_Name_2;

    //Qt_SystemInf=Empty+"\"7za.exe\" "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+Qt_Tel_Name+".ods"+" content.xml";
    Qt_SystemInf=Empty+"7za.exe "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+Qt_Tel_Name+".ods"+" content.xml";
    Qt_Prot_Name="Protocol_"+Qt_Tel_Name;
    //qDebug()<<Qt_Prot_Name;
    string stdString=Qt_SystemInf.toStdString();
    //cout << stdString;
    array_test=const_cast<char *>(stdString.c_str());
    Ch_Prot_Name=qPrintable(Qt_SystemInf);
    //qDebug()<< "LL!";
    //qDebug() << Qt_SystemInf;
    //cout<< Ch_Prot_Name <<endl;
    //ShowWindow(GetConsoleWindow(), SW_HIDE);
    //system(Ch_Prot_Name);
    //printf("%s", Ch_Prot_Name);
    /*string stdString;
    stdString=Qt_SystemInf.toStdString();

    LPSTR opa=const_cast<char *>(stdString.c_str());
    LPWSTR opa_2= (LPWSTR) opa;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;*/
    STARTUPINFOA cif;
    PROCESS_INFORMATION pi;
    ZeroMemory(&cif, sizeof(STARTUPINFOA));

    CreateProcessA(NULL, array_test, NULL, NULL, FALSE, DETACHED_PROCESS , NULL, NULL, &cif, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //WinExec(Ch_Prot_Name, SW_HIDE); !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //system(Ch_Prot_Name);
    //printf("AAAA!\n");

    //Sleep(2000);

    Qt_SystemInf.clear();

    //Qt_SystemInf=Empty+"\"7za.exe\" "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+Qt_Tel_Name+".ods"+" META-INF/";
    //Ch_Prot_Name=qPrintable(Qt_SystemInf);
    Qt_SystemInf=Empty+"7za.exe "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+Qt_Tel_Name+".ods"+" META-INF/";
    stdString=Qt_SystemInf.toStdString();

    array_test=const_cast<char *>(stdString.c_str());
    Ch_Prot_Name=qPrintable(Qt_SystemInf);
    //qDebug()<< "LL!";
    //cout<< Ch_Prot_Name <<endl;
    //ShowWindow(GetConsoleWindow(), SW_HIDE);
    ZeroMemory(&cif, sizeof(STARTUPINFOA));
    CreateProcessA(NULL, array_test, NULL, NULL, FALSE, DETACHED_PROCESS , NULL, NULL, &cif, &pi);
    WaitForSingleObject(pi.hProcess, INFINITE);
    //WinExec(Ch_Prot_Name, SW_HIDE);

    //system(Ch_Prot_Name);



    /*system("\"7za.exe\" a -tzip -mx=1 Protocol2.ods META-INF/");
    system("\"7za.exe\" a -tzip -mx=1 Protocol2.ods content.xml");*/

}




void Check_Quantity_CgSymbols(void)
{
    symbol='i';//Иниацилизация переменной symbol
    while(symbol!=EOF)

    {
        symbol=fgetc(input);
        //counter_mas[1]++;
        if(symbol=='C')
        {
            counter_mas[2]++;
            symbol=fgetc(input);
            if(symbol=='g')
            {
                counter_mas[2]++;
                symbol=fgetc(input);
               while(!(flag&(1<<7)))
               {
                   if(symbol==':')
                   {
                       flag|=(1<<7);
                   }

                   counter_mas[2]++;
                   if((symbol==' ')||(symbol=='!'))
                   {
                       flag|=(1<<7);
                       counter_mas[2]=0;
                   }
                   symbol=fgetc(input);
               }
               flag&=~(1<<7);
            }
            else
            {
                counter_mas[2]--;
            }
        }
        counter_mas[0]=counter_mas[0]+counter_mas[2];
        counter_mas[2]=0;
    }
}
void ReWrite_Value_pvv_InVector(void)
{
    counter_mas[1]=0;
    counter_mas[2]=0;
    counter_mas[14]=0;
    fseek(file, 0, SEEK_SET);
    symbol=(fgetc(file));
    //counter_mas[2]=file.tellg();
    while(counter_mas[2]!=quant_sym)
    {
        counter_read2=0;
        if(symbol=='v')
        {
            //
            mas_file.push_back(symbol);
            counter_read1++;
            counter_read2++;
            symbol=(fgetc(file));
            counter_mas[2]++;
            if(symbol=='a')
            {

                mas_file.push_back(symbol);
                counter_read1++;
                counter_read2++;
                symbol=(fgetc(file));
                counter_mas[2]++;
                if(symbol=='l')
                {

                    mas_file.push_back(symbol);
                    counter_read1++;
                    counter_read2++;
                    symbol=(fgetc(file));
                    counter_mas[2]++;
                    if(symbol=='u')
                    {

                        mas_file.push_back(symbol);
                        counter_read1++;
                        counter_read2++;
                        symbol=(fgetc(file));
                        counter_mas[2]++;
                        if(symbol=='e')
                        {
                            mas_file.push_back(symbol);
                            counter_read1++;
                            counter_read2++;
                            symbol=(fgetc(file));
                            counter_mas[2]++;
                            for(counter_mas[1]=0; counter_mas[1]<9; counter_mas[1]++)
                            {
                                mas_file.push_back(symbol);
                                counter_read1++;
                                counter_read2++;
                                symbol=(fgetc(file));
                            }
                            if(symbol=='=')
                            {
                                mas_file.push_back(symbol);

                                counter_read1++;
                                counter_read2++;

                                symbol=(fgetc(file));
                                counter_read1=counter_read1-4;//Попробовать по другому, как он сказал
                                //printf("counter_read1=%d\n", counter_read1);

                                chislo[0]=mas_file[counter_read1-1];
                                //printf("counter_read1=%d\n", counter_read1);

                                //printf("Chislo_0=%c\n", chislo[0]);
                                //printf("")
                                counter_read1=counter_read1+1;

                                chislo[1]=mas_file[counter_read1-1];

                                    //printf("Chislo_1=%c\n", chislo[1]);
                                    chislo[2]='\0';

                                    num_of_pvv[counter_mas[15]]=atoi(chislo);

                                counter_read1=counter_read1+3;
                                //num_of_pvv[counter_mas[15]]=Conv_Char_To_Int(chisl);
                                mas_file.push_back(symbol);
                                counter_read1++;
                                counter_read2++;
                                symbol=(fgetc(file));

                                /*if(symbol==' ')
                                {
                                    printf("gap\n");
                                }
                                printf("sym=%c\n", symbol);*/

                                //counter_read1++;
                                while(symbol!=' ')
                                {
                                    //printf("OPA!\n");
                                    mas_file.push_back(symbol);
                                    counter_read1++;
                                    counter_read2++;
                                    symbol=(fgetc(file));
                                }

                                //printf("mas_file=%c", mas_file[counter_read1-1]);


                                if(num_of_pvv[counter_mas[15]]==0)
                                {
                                    //printf("NUM_OF_PVV_FLAG=%d\n", num_of_pvv[counter_mas[15]]);
                                    //printf("AAAAAAAAAAAA!\n");

                                    //counter_read1=counter_read1+7;
                                    if((mas_file[counter_read1-4]=='4')&&(mas_file[counter_read1-2]=='4')&&(mas_file[counter_read1-1]=='0'))
                                    {
                                        //printf("OK!!!!!\n");
                                        flag|=(1<<5);
                                        //counter_read1=counter_read1-3;
                                        //printf("AAAAAAAAAAAA!\n");

                                    }
                                    else
                                    {
                                        flag&=~(1<<5);
                                    }
                                }
                                if(!(flag&(1<<5)))
                                {
                                   while(counter_read2!=0)
                                    {
                                        mas_file.pop_back();
                                        counter_read2--;
                                        counter_read1--;
                                    }


                                }
                                /*mas_file.push_back('?');
                                counter_read2++;
                                counter_read1++;*/

                            }
                            else
                            {
                                while(counter_read2!=0)
                                {
                                    mas_file.pop_back();
                                    counter_read2--;
                                    counter_read1--;
                                }
                                //mas_file.pop_back();
                            }
                        }
                        else
                        {
                            while(counter_read2!=0)
                            {
                                mas_file.pop_back();
                                counter_read2--;
                                counter_read1--;
                            }
                        }
                    }
                    else
                    {
                       while(counter_read2!=0)
                        {
                           mas_file.pop_back();
                           counter_read2--;
                           counter_read1--;
                        }
                    }
                }
            else
            {
               while(counter_read2!=0)
                {
                   mas_file.pop_back();
                   counter_read2--;
                   counter_read1--;


                }
            }
            }
            else
            {
               while(counter_read2!=0)
                {
                   mas_file.pop_back();
                   counter_read2--;
                   counter_read1--;
                }
            }
        }
        symbol=(fgetc(file));
        counter_mas[2]++;
    }

}
void Preparation_Results_and_Output(void)
{
    for(countt=0; countt<counter_read1; countt++)
    {
        flag&=~(1<<4);
        //printf("%d", countt);
        if(mas_file[countt]=='v')
        {
            countt++;
            if(mas_file[countt]=='a')
            {
            countt++;
                if(mas_file[countt]=='l')
                {
                countt++;
                    if(mas_file[countt]=='u')
                    {
                    countt++;
                        if(mas_file[countt]=='e')
                        {
                        countt=countt+6;
                        //printf("%c\n", mas[countt]);
                        countt=countt+4;
                        if(mas_file[countt]=='=')
                        {
                        //printf("PRIZNAK=%d\n", priznak0);
                        countt=countt-4;
                        chislo[0]=mas_file[countt];
                        countt=countt+1;
                        chislo[1]=mas_file[countt];
                        num_of_pvv[counter_mas[15]]=Conv_Char_To_Int(chislo);
                        if(num_of_pvv[counter_mas[15]]==0)
                        {
                            countt=countt+7;
                            if((mas_file[countt]=='4')&&(mas_file[countt=countt+2]=='4')&&(mas_file[countt=countt+1]=='0'))
                            {
                                flag|=(1<<4);
                                flag|=(1<<5);
                                //printf("\nGGGGG!!!!\n");
                            }
                            else
                            {
                                flag&=~(1<<5);
                            }
                            //countt--;


                            //countt
                        }
                        if((flag&(1<<5)))
                        {
                           // printf("OOPPAA!!!\n");

                        if(num_of_pvv[counter_mas[15]]!=0)
                        {
                            if(counter_mas[15]>=1)
                        {
                            znach1=num_of_pvv[counter_mas[15]];
                            //printf("--%d--\n", znach1);
                            counter_mas[15]--;
                            znach2=num_of_pvv[counter_mas[15]];
                            //printf("--%d--\n", znach2);
                            if((znach1%znach2)>1)
                            {
                                size_of_empty=znach1%znach2;
                                //printf("!!!!!\n");
                                empty_flag=1;
                            }
                            else
                            {
                                empty_flag=0;
                            }
                            counter_mas[15]++;
                        }
                        counter_mas[15]++;
                        }
                        if((empty_flag==1)&&(znach2!=24))
                        {
                            counter_mas[3]=0;
                            for(counter_mas[2]=0; counter_mas[2]<size_of_empty-1; counter_mas[2]++)
                            {
                                //printf("AAAAAAAAAA%d!!\n", znach2);


                                //priznak0++;
                                if(priznak0<=8)
                                {
                                    //printf("REMOVE=%d\n", priznak0);
                                    list_of_remove[counter_mas[3]]=priznak0;
                                    //printf("----%d----\n", list_of_remove[counter_mas[3]]);
                                    counter_mas[3]++;
                                }
                                priznak0++;
                                //counter_mas[3]=0;

                                //printf("PR=%d\n",priznak0);
                            }
                            for(counter_mas[3]=0; counter_mas[3]<9; counter_mas[3]++)
                            {
                                //printf("++++%d++++\n", list_of_remove[counter_mas[3]]);
                            }
                        }
                        if(!(flag&(1<<4)))
                        {
                            countt=countt+3;
                            countt=countt+4;
                            Num1=mas_file[countt];
                            countt++;
                            Num2=mas_file[countt];
                            countt++;
                            Num3=mas_file[countt];
                            countt++;
                            Num4=mas_file[countt];
                            res=Transl_To_Dec_System(Num1, Num2, Num3, Num4);
                            storage[priznak0]=res;
                            counter_mas[14]++;
                            //printf("r%d=%d", count5, storage[priznak0]);
                            //count5++;
                            //printf("value%d://%d//", priznak0, storage[priznak0]);

                        }





                            if(!(flag&(1<<1)))
                            {
                                flag|=(1<<1);
                                priznak0--;
                            }
                            counter_mas[3]=0;
                            if((quant_of_sides==3)&&(priznak0==24))
                            {
                                flag|=(1<<10);
                            }
                            if((quant_of_sides==2)&&(priznak0==16))
                            {
                                flag|=(1<<10);
                            }
                            if((quant_of_sides==1)&&(priznak0==8))
                            {
                                flag|=(1<<10);
                            }



                            if((flag&(1<<10))||(counter_mas[15]==max_flag))
                            {
                                //printf("VV\n");
                                for(counter_mas[4]=1; counter_mas[4]<9; counter_mas[4]++)
                                {
                                    if(compare2!=0)
                                    {
                                        start_time=(float)compare2;
                                    }

                                    if(counter_mas[4]!=list_of_remove[counter_mas[3]])
                                    {
                                    //printf("AA!\n");
                                    //printf("JJJJ---List=%d\n", list_of_remove[counter_mas[3]]);
                                    //printf("JJJJ---counter_mas[4]=%d\n", counter_mas[4]);
                                    if(quant_of_sides==1)
                                    {
                                        compare2=storage[priznak1];
                                    }
                                    if((quant_of_sides==2)||(quant_of_sides==3))
                                    {
                                    if(storage[priznak1]>storage[priznak2])
                                    {
                                        compare2=storage[priznak1];
                                    }
                                    else if(storage[priznak1]==storage[priznak2])
                                    {
                                        compare2=storage[priznak1];
                                    }
                                    else
                                    {
                                        compare2=storage[priznak2];
                                    }
                                    if(quant_of_sides==3)
                                    {
                                      if(storage[priznak3]>compare2)
                                    {
                                        compare2=storage[priznak3];
                                    }
                                    }
                                    }



                                    if(ind==quantity)
                                    {
                                        flag|=(1<<2);
                                        //goto exit;
                                        countt=counter_read1;
                                        //printf("OPA!!!\n");
                                        //printf("IND=%d\n", ind);
                                    }

                                    if(!(flag&(1<<2)))
                                    {




                                    compare2=compare2*10;



                                    //if()
                                    //{
                                        Var1_float=(float)vect_mas_inp_int_inf[counter_mas[6]];
                                        Var2_float=(float)compare2;
                                        /*if((Var2_float==0)&&(!(flag&(1<<15))))
                                        {

                                            Var2_float=300;

                                            flag|=1<<15;
                                        }*/

                                        //printf("*%f", Var2_float);
                                        //printf("/%d", vect_time_in_ZG[counter_mas[21]]);
                                        if((Var2_float!=0)&&(counter_mas[21]!=0))
                                        {
                                            Var2_float=Var2_float-vect_time_in_ZG[counter_mas[21]-1];
                                        }
                                        //printf("-%f\n", Var2_float);

                                        if((vect_time_in_ZG[counter_mas[21]-1]==0)&&(counter_mas[21]!=0)&&(Var2_float!=0))
                                        {
                                            counter_mas[22]=1;
                                            while((vect_time_in_ZG[counter_mas[21]-counter_mas[22]])==0)
                                            {
                                                counter_mas[22]++;
                                            }
                                            //printf("opa!\n");
                                            //printf("*%f", Var2_float);
                                            //printf("/%d", vect_time_in_ZG[counter_mas[21]-counter_mas[22]]);
                                            Var2_float=Var2_float-vect_time_in_ZG[counter_mas[21]-counter_mas[22]];
                                            //printf("vect_time_in_zg=%d/", vect_time_in_ZG[counter_mas[21]-counter_mas[22]]);


                                        }
                                        //printf("-%f\n", Var2_float);
                                        /*if((compare2==0)&&(!(flag&(1<<15))))
                                        {

                                            Var2_float=300;
                                            printf("opa!\n");

                                            flag|=1<<15;
                                        }*/
                                        if(vect_time_in_ZG[counter_mas[21]]==0)
                                        {
                                            if(quant_of_sides==1)
                                            {
                                                Var2_float=storage[priznak1]-storage[priznak1-1];

                                            }
                                            if(quant_of_sides==2)
                                            {
                                                if(storage[priznak2]>=storage[priznak1])
                                                {
                                                    Var2_float=(storage[priznak2]-storage[priznak2-1])*10;
                                                }
                                                if(storage[priznak1]>storage[priznak2])
                                                {
                                                    Var2_float=(storage[priznak1]-storage[priznak1-1])*10;
                                                }



                                            }
                                            if(quant_of_sides==3)
                                            {
                                                if(storage[priznak1]>storage[priznak2])
                                                {
                                                    if(storage[priznak1]>=storage[priznak3])
                                                    {
                                                        Var2_float=(storage[priznak1]-storage[priznak1-1])*10;
                                                    }
                                                    else
                                                    {
                                                        Var2_float=(storage[priznak3]-storage[priznak3-1])*10;

                                                    }
                                                    //Var2_float=(storage[priznak1]-storage[priznak1-1])*10;
                                                }
                                                else
                                                {
                                                    if(storage[priznak2]>=storage[priznak3])
                                                    {
                                                        Var2_float=(storage[priznak2]-storage[priznak2-1])*10;
                                                    }
                                                    else
                                                    {
                                                        Var2_float=(storage[priznak3]-storage[priznak3-1])*10;

                                                    }
                                                }

                                            }

                                        }
                                        if((!(flag&(1<<15))))
                                        {

                                            Var2_float=Var2_float-300;
                                            //printf("opa!\n");

                                            flag|=1<<15;
                                        }
                                        /*if((compare2==0)&&(!(flag&(1<<15))))
                                        {

                                            Var2_float=300;
                                            printf("opa!\n");

                                            flag|=1<<15;
                                        }*/

                                        //Show_Vector(vect_mas_inp_int_inf);

                                    /*printf("*%f", Var2_float);
                                        printf("/%d", vect_time_in_ZG[counter_mas[21]]);*/

                                        /*printf("Compare2=%d\n", compare2);
                                        printf("start_time=%d\n", start_time);*/

                                        //printf("value=%d\n", vect_mas_inp_int_inf[counter_mas[6]]);

                                        /*printf("Var1_float=%f\n", Var1_float);
                                        printf("Var2_float=%f\n", Var2_float);
                                        printf("countt_mas_6=%d\n", counter_mas[6]);*/


                                        if(vect_time_in_ZG[counter_mas[21]]==0)
                                        {
                                           stock_msk=vect_time_in_ZG[counter_mas[21]-1]-compare2;

                                        }
                                        else
                                        {
                                            stock_msk=Var1_float-Var2_float;
                                        }
                                        //printf("*%f\n", Var1_float);
                                        //printf("|%f\n", Var2_float);
                                        stock=((Var1_float-Var2_float)/Var1_float)*100;

                                        if((stock<30)&&(Var1_float!=0))
                                    {
                                        quant_point_less30per++;
                                    }
                                    //stock_msk=Var1_float-Var2_float;
                                    //stock=((Var1_float-Var2_float)/Var1_float)*100;

                                    //start_time=compare2;



                                    //}




                                    /*if(compare2>vect_mas_inp_int_inf[counter_mas[6]])
                                    {

                                        sign=-1;
                                        Var1_float=(float)vect_mas_inp_int_inf[counter_mas[6]];
                                        Var2_float=(float)compare2;
                                        stock=sign*(Var2_float/Var1_float)*100;
                                        quant_point_less30per++;
                                    }
                                    else
                                    {
                                    Var1_float=(float)vect_mas_inp_int_inf[counter_mas[6]];
                                    Var2_float=(float)compare2;
                                    stock=sign*(Var1_float/Var2_float)*100;
                                    if(stock<30)
                                    {
                                        quant_point_less30per++;
                                    }
                                    }*/
                                    counter_mas[14]=0;
                                    //printf("counter_mas[10]=%d", counter_mas[10]);
                                    while(vect_mas_inp_char_inf[counter_mas[11]]!='?')
                                    {
                                        buffer[counter_mas[2]]=vect_mas_inp_char_inf[counter_mas[11]];
                                        counter_mas[2]++;
                                        counter_mas[11]++;
                                    }
                                    buffer[counter_mas[2]]='\0';
                                    counter_mas[11]++;
                                    counter_mas[2]=0;




                                    //if(ind<num_of_point)
                                    //{
                                    //Запись результатов в файл протокола
                                    //printf("%d/", vect_mas_inp_int_inf[counter_mas[6]]);
                                    /*for(counter_mas[20]=0; counter_mas[20]<vect_mas_inp_int_inf.size(); counter_mas[20]++)
                                    {
                                        printf("%d/", vect_mas_inp_int_inf[counter_mas[20]]);
                                    }
                                    printf("\n");*/
                                    if(quant_of_sides==1)
                                    {
                                         if(!(flag&(1<<2)))
                                        {
                                       //fprintf(protocol, "%d;      %s;     %d;  %d;   %f;  %d;   %d;   %d;    %.2f\n", ind, buffer, storage[priznak1]*10, compare2, Var2_float, vect_time_in_ZG[counter_mas[21]], vect_mas_inp_int_inf[counter_mas[6]], stock_msk, stock);
                                       //printf("IND=%d\n", ind);
                                       Fill_Rows();
                                        }
                                    }
                                    if(quant_of_sides==3)
                                    {
                                         if(!(flag&(1<<2)))
                                        {
                                       //fprintf(protocol, "%d;      %s;     %d; %d;      %d;     %d;     %f;  %d;   %d;   %d;    %.2f\n", ind, buffer, storage[priznak1]*10, storage[priznak2]*10, storage[priznak3]*10, compare2, Var2_float, vect_time_in_ZG[counter_mas[21]], vect_mas_inp_int_inf[counter_mas[6]], stock_msk, stock);
                                       //printf("OPA!\n");
                                       //printf("IND=%d\n", ind);
                                       Fill_Rows();
                                        }
                                    }
                                     if(quant_of_sides==2)
                                    {
                                         if(!(flag&(1<<2)))
                                        {
                                       //fprintf(protocol, "%d;      %s;     %d;      %d;    %d;  %f;   %d;   %d;    %d;    %.2f\n", ind, buffer, storage[priznak1]*10, storage[priznak2]*10, compare2, Var2_float, vect_time_in_ZG[counter_mas[21]], vect_mas_inp_int_inf[counter_mas[6]], stock_msk, stock);
                                        //printf("OPA!\n");
                                       //sprintf(str, "%f", Var2_float);
                                       Fill_Rows();


                                       //printf("dghdfghfdghdgfh\n");


                                       /*str=(char*)ind;
                                       printf("%s\n", *str);*/
                                       //Fill_Rows();
                                       //printf("******/nIND=%d\n", ind);
                                       //printf("priznak1=%d\n", priznak1);
                                       //printf("priznak2=%d\n*********\n", priznak2);
                                       //printf("storage_priznak1=%d\n", storage[priznak1]);

                                       //printf("priznak2=%d\n", priznak2);
                                       //printf("priznak2=%d\n*********\n", priznak2);
                                       //printf("storage_priznak2=%d\n", storage[priznak2]);
                                        }
                                    }
                                    //printf("quantity=%d\n", quantity);
                                    counter_mas[21]++;
                                    }

                                    //---------------------------------------------
                                        /*if(flag4!=1)
                                        {
                                       fprintf(protocol, "%d;      %s;     %d;      %d;     %d;     %d;   %d;    %.2f\n", ind, buffer, storage[priznak1]*10, storage[priznak2]*10, storage[priznak3]*10, compare2,  mas_inp_int_inf[counter_mas[6]], stock);
                                       //printf("IND=%d\n", ind);
                                        }*/
                                        //if(flag4==1)
                                        //{
                                          //  goto exit;
                                        //}
                                        //else
                                        //{
                                          //  printf("OP!!!\n");
                                            //goto exit;
                                        //}
                                     if(!(flag&(1<<2)))
                                    {



                                    priznak1++;
                                    priznak2++;
                                    priznak3++;
                                    counter_mas[6]++;
                                    ind++;
                                    }
                                    }
                                    else
                                    {
                                        if(!(flag&(1<<2)))
                                    {
                                        //printf("BB!\n");
                                        //printf("JJJJ---List=%d\n", list_of_remove[counter_mas[3]]);
                                        //printf("JJJJ---counter_mas[4]=%d\n", counter_mas[4]);
                                        //printf("JJJJ---counter_mas[4]=%d\n", counter_mas[4]);
                                        counter_mas[3]++;
                                    }
                                    }
                                }//------------------
                                if(!(flag&(1<<2)))
                                    {
                                counter_mas[3]=0;
                                priznak1=1;
                                priznak2=9;
                                priznak3=17;
                                priznak0=1;
                                flag&=~(1<<10);
                                    }
                                //printf("PR=%d\n",priznak0);
                            }
                            else
                            {
                                if(!(flag&(1<<2)))
                                    {

                                priznak0++;
                                    }
                            }


                            }//---------------------------




                            //printf("symbol_mas=%c", mas_file[countt]);

                            }
                        }
                    }
                }

            }
        //printf("%c", mas[countt]);
        //break;
        }
        //
    }

}
void Install_Counter(void)
{
     while((Cg_Names[counter_mas[0]]!='\0')&&(!(flag&(1<<8))))
    {
        flag&=~(1<<9);
       while((Cg_Names[counter_mas[0]]!=':')&&((!(flag&(1<<9)))))
       {
           if(Cg_Names[counter_mas[0]]!=vect_Cg_name[counter_mas[2]])
           {
               flag|=(1<<9);
           }
           counter_mas[0]++;
           counter_mas[2]++;
       }
       if((!(flag&(1<<9))))
       {
           //printf("counter_mas[0]=%d\n", counter_mas[0]);
           flag|=(1<<8);
       }

       counter_mas[2]=0;
       counter_mas[0]++;
       /*if(Cg_Names[counter_mas[0]]=='\0')
       {
           printf("Ошибка в имени циклограммы\n");

           return 8;
       }*/



    }
    //printf("%s", Cg_Names);
    counter_mas[0]--;
    //запоминаем данную позицию в перименную pos_of_cg_name
    pos_of_cg_name=counter_mas[0];
    //printf("pos_of_cg_name=%d\n", pos_of_cg_name);
    pos_of_cg_name--;

    while((Cg_Names[pos_of_cg_name]!=':')&&(pos_of_cg_name!=0))
    {
        pos_of_cg_name--;
    }
    if(pos_of_cg_name!=0)
    {
        pos_of_cg_name++;
    }
    counter_mas[0]=pos_of_cg_name;
}
void Read_In_Mas_Module_Names(void)
{
    while(!(flag&(1<<3)))
                {
                    //Show_Vector(vect_mas_inp_inf);
                    //counter_mas[6]=0;
                    while(vect_mas_inp_inf[counter_mas[10]]!='?')
                    {
                      vect_mas_inp_char_inf.push_back(vect_mas_inp_inf[counter_mas[10]]);
                    //mas_inp_char_inf[counter_mas[6]]=vect_mas_inp_inf[counter_mas[10]];
                    //printf("%c", mas_inp_char_inf[counter_mas[6]]);
                    counter_mas[6]++;
                    counter_mas[10]++;
                    }
                    //printf("\n");
                    vect_mas_inp_char_inf.push_back('?');
                    //mas_inp_char_inf[counter_mas[6]]='?';
                    counter_mas[6]++;
                    //printf("+++++++++++++++++++++++++++++++++%c+++++++++++++++++++++++++++++++++\n", mas_inp_char_inf[counter_mas[7]]);
                    counter_mas[10]++;
                    if(vect_mas_inp_inf[counter_mas[10]]=='\0')
                    {
                        flag|=(1<<3);
                    }
                    counter_mas[7]++;
                    //printf("counter_mas[7]=%d", counter_mas[7]);
                }
                counter_mas[6]=0;
}
void Read_Stock_Inf_In_Mas(void)
{
    while(!(flag&(1<<3)))
                {
                    counter_mas[6]=0;
                    while(vect_mas_inp_inf[counter_mas[10]]!='?')
                    {
                    storage2[counter_mas[6]]=vect_mas_inp_inf[counter_mas[10]];
                    counter_mas[6]++;
                    counter_mas[10]++;
                    }
                    storage2[counter_mas[6]]='\0';
                    vect_mas_inp_int_inf.push_back(atoi(storage2));
                    vect_time_in_ZG.push_back((atoi(storage2))*10);

                    //printf("TIME=%d\n", vect_time_in_ZG[0]);
                    //mas_inp_int_inf[counter_mas[7]]=atoi(storage2);
                    //printf("%d\n", mas_inp_int_inf[counter_mas[7]]);
                    counter_mas[10]++;
                    if((vect_mas_inp_inf[counter_mas[10]]>'9')||(vect_mas_inp_inf[counter_mas[10]]<'0'))
                    {
                        flag|=(1<<3);
                    }
                    counter_mas[7]++;
                    num_of_point++;
                    quantity++;
                }
                //Show_Vector(vect_mas_inp_int_inf);
                /*for(counter_mas[20]=0; counter_mas[20]<vect_mas_inp_int_inf.size(); counter_mas[20]++)
                {
                    printf("%d/", vect_mas_inp_int_inf[counter_mas[20]]);
                }*/
                counter_mas[6]=0;
                counter_mas[7]=0;
                flag&=~(1<<3);
}
//Чтение из информации из массива
/*void Read_Zg_File(void)
{
    counter_mas[19]=0;
    while(!(flag&(1<<6)))
                {





                    //Show_Vector(vect_mas_inp_inf);
                    counter_mas[15]=0;
                    counter_mas[12]=0;

                    while(counter_mas[15]!=1)
                    {
                           while((mas_inp_file[counter_mas[5]]!=',')&&(mas_inp_file[counter_mas[5]]!=' '))
                        {

                           vect_mas_inp_inf.push_back(mas_inp_file[counter_mas[5]]);
                           //mas_inp_inf[counter_mas[10]]=mas_inp_file[counter_mas[5]];

                           //printf("%c", mas_inp_file[counter_mas[5]]);
                           if((mas_inp_file[counter_mas[5]]>'9')||(mas_inp_file[counter_mas[5]]<'0'))
                        {
                            flag|=1<<13;
                        }
                           counter_mas[5]++;
                           counter_mas[10]++;
                           //counter_mas[19]++;



                        }
                        //printf("counter_mas[15]=%d", counter_mas[15]);
                        //printf("\n");
                        vect_mas_inp_inf.push_back('?');

                        //mas_inp_inf[counter_mas[10]]='?';
                        //counter_mas[5]++;
                        counter_mas[10]++;
                        counter_mas[5]++;
                        if(!(flag&(1<<13)))
                        {
                           counter_mas[19]++;
                           //printf("countt_mas19=%d\n", counter_mas[19]);
                        }
                        else
                        {
                            counter_mas[19]--;
                        }
                        //printf("countt_mas19=%d\n", counter_mas[19]);

                        counter_mas[12]=0;

                        while((mas_inp_file[counter_mas[5]]==' ')||(mas_inp_file[counter_mas[5]]=='\n')||(mas_inp_file[counter_mas[5]]=='	'))
                        {
                            counter_mas[5]++;
                            //printf("opa!\n");
                            //counter_mas[12]++;
                            //counter_mas[15]=1;
                        }
                        //printf("counter_mas[12]=%d", counter_mas[12]);

                        //counter_mas[5]++;
                        //printf("\n\n");
                        //Show_Vector(vect_mas_inp_inf);
                        if(mas_inp_file[counter_mas[5]]==';')
                        {
                            //printf("FFFFFFFF!\n");
                            counter_mas[15]=1;
                        }
                    }
                //counter_mas[15]=0;
                counter_mas[13]++;

                while(mas_inp_file[counter_mas[5]]!='d')
                {
                    counter_mas[5]++;
                }
               counter_mas[5]=counter_mas[5]+4;
               while(mas_inp_file[counter_mas[5]]==' ')
               {

                  counter_mas[5]++;


               }
               counter_mas[4]++;
               if(counter_mas[19]==0)
               {
                   flag|=(1<<6);
               }







               //counter_mas[5]--;



                }
}*/
//Чтение информации из файла
void Read_Zg_File(void)
{
    //fseek(input, 0, SEEK_SET);
    counter_mas[19]=0;
    flag&=~(1<<13);
    char sym;
    sym=fgetc(input);
    //qDebug()<< sym;
    //qDebug()<< sym <<"ss";
    while((sym!=EOF)&&(!(flag&(1<<6))))
                {





                    //Show_Vector(vect_mas_inp_inf);
                    counter_mas[15]=0;
                    counter_mas[12]=0;

                    while((counter_mas[15]!=1)&&(sym!=EOF))
                    {
                           while((sym!=EOF)&&(sym!=',')&&(sym!=' ')&&(sym!='	'))
                        {

                           vect_mas_inp_inf.push_back(sym);
                          //qDebug()<< sym<<"bbb!";
                           //mas_inp_inf[counter_mas[10]]=sym;

                           //printf("%c", sym);
                           if((sym>'9')||(sym<'0'))
                        {
                            flag|=1<<13;
                        }
                           sym=fgetc(input);
                           counter_mas[10]++;
                           //counter_mas[19]++;
                           //qDebug()<< sym;



                        }
                        //printf("counter_mas[15]=%d", counter_mas[15]);
                        //printf("\n");
                        vect_mas_inp_inf.push_back('?');

                        //mas_inp_inf[counter_mas[10]]='?';
                        //sym=fgetc(input);++;
                        counter_mas[10]++;
                        sym=fgetc(input);
                        //qDebug()<< sym;
                        if(!(flag&(1<<13)))
                        {
                           counter_mas[19]++;

                           //printf("countt_mas19=%d\n", counter_mas[19]);
                        }
                        else
                        {
                            counter_mas[19]--;
                        }
                        //qDebug() << QString::number(counter_mas[19]);
                        //printf("countt_mas19=%d\n", counter_mas[19]);

                        counter_mas[12]=0;

                        while((sym==' ')||(sym=='\n')||(sym=='	'))
                        {
                            sym=fgetc(input);
                            //qDebug()<< sym<<"aaa!";
                            //printf("opa!\n");
                            //counter_mas[12]++;
                            //counter_mas[15]=1;
                        }
                        //printf("counter_mas[12]=%d", counter_mas[12]);

                        //sym=fgetc(input);++;
                        //printf("\n\n");
                        //Show_Vector(vect_mas_inp_inf);
                        if(sym==';')
                        {
                            //printf("FFFFFFFF!\n");
                            counter_mas[15]=1;
                        }
                    }
                //counter_mas[15]=0;
                counter_mas[13]++;

                while(sym!='d')
                {
                    sym=fgetc(input);
                    //qDebug()<< sym<<"pa!";
                }
               sym=fgetc(input);
               sym=fgetc(input);
               sym=fgetc(input);
               sym=fgetc(input);
               while(sym==' ')
               {

                  sym=fgetc(input);


               }
               //qDebug()<< sym<<"opa!";
               counter_mas[4]++;
               if(counter_mas[19]==0)
               {
                   flag|=(1<<6);
               }







               //sym=fgetc(input);--;



                }
}
void Create_XML_Doc(void)
{
    //TiXmlDocument doc;
    TiXmlDeclaration *dec1 = new TiXmlDeclaration("1.0", "UTF-8", "");//XML декларация
    doc.LinkEndChild(dec1);
    TiXmlElement *element= new TiXmlElement("office:document-content");
    //Объявление и описание пространств имён
    element->SetAttribute("xmlns:office", "urn:oasis:names:tc:opendocument:xmlns:office:1.0");
    element->SetAttribute("xmlns:style", "urn:oasis:names:tc:opendocument:xmlns:style:1.0");
    element->SetAttribute("xmlns:text", "urn:oasis:names:tc:opendocument:xmlns:text:1.0");
    element->SetAttribute("xmlns:table", "urn:oasis:names:tc:opendocument:xmlns:table:1.0");
    element->SetAttribute("xmlns:draw", "urn:oasis:names:tc:opendocument:xmlns:drawing:1.0");
    element->SetAttribute("xmlns:fo", "urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0");
    element->SetAttribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
    element->SetAttribute("xmlns:dc", "http://purl.org/dc/elements/1.1/");
    element->SetAttribute("xmlns:meta", "urn:oasis:names:tc:opendocument:xmlns:meta:1.0");
    element->SetAttribute("xmlns:number", "urn:oasis:names:tc:opendocument:xmlns:datastyle:1.0");
    element->SetAttribute("xmlns:presentation", "urn:oasis:names:tc:opendocument:xmlns:presentation:1.0");
    element->SetAttribute("xmlns:svg", "urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0");
    element->SetAttribute("xmlns:chart", "urn:oasis:names:tc:opendocument:xmlns:chart:1.0");
    element->SetAttribute("xmlns:dr3d", "urn:oasis:names:tc:opendocument:xmlns:dr3d:1.0");
    element->SetAttribute("xmlns:math", "http://www.w3.org/1998/Math/MathML");
    element->SetAttribute("xmlns:form", "urn:oasis:names:tc:opendocument:xmlns:form:1.0");
    element->SetAttribute("xmlns:script", "urn:oasis:names:tc:opendocument:xmlns:script:1.0");
    element->SetAttribute("xmlns:ooo", "http://openoffice.org/2004/office");
    element->SetAttribute("xmlns:ooow", "http://openoffice.org/2004/writer");
    element->SetAttribute("xmlns:oooc", "http://openoffice.org/2004/calc");
    element->SetAttribute("xmlns:dom", "http://www.w3.org/2001/xml-events");
    element->SetAttribute("xmlns:xforms", "http://www.w3.org/2002/xforms");
    element->SetAttribute("xmlns:xsd", "http://www.w3.org/2001/XMLSchema");
    element->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
    element->SetAttribute("xmlns:rpt", "http://openoffice.org/2005/report");
    element->SetAttribute("xmlns:of", "urn:oasis:names:tc:opendocument:xmlns:of:1.2");
    element->SetAttribute("xmlns:xhtml", "http://www.w3.org/1999/xhtml");
    element->SetAttribute("xmlns:grddl", "http://www.w3.org/2003/g/data-view#");
    element->SetAttribute("xmlns:tableooo", "http://openoffice.org/2009/table");
    element->SetAttribute("xmlns:field", "urn:openoffice:names:experimental:ooo-ms-interop:xmlns:field:1.0");
    element->SetAttribute("office:version", "1.2");
    TiXmlElement *of_scr = new TiXmlElement("office:scripts");
    element->LinkEndChild(of_scr);
    TiXmlElement *of_font_decl = new TiXmlElement("office:font-face-decls");
    TiXmlElement *of_font = new TiXmlElement("style:font-face");
    of_font->SetAttribute("style:name", "Arial");
    of_font->SetAttribute("svg:font-family", "Arial");
    of_font->SetAttribute("style:font-family-generic", "swiss");
    of_font->SetAttribute("style:font-pitch", "variable");
    of_font_decl->LinkEndChild(of_font);
    //delete of_font;
    TiXmlElement *of_font2 = new TiXmlElement("style:font-face");
    of_font2->SetAttribute("style:name", "Arial Unicode MS");
    of_font2->SetAttribute("svg:font-family", "'Arial Unicode MS'");
    of_font2->SetAttribute("style:font-family-generic", "system");
    of_font2->SetAttribute("style:font-pitch", "variable");
    of_font_decl->LinkEndChild(of_font2);
    //delete of_font;
    TiXmlElement *of_font3 = new TiXmlElement("style:font-face");
    of_font3->SetAttribute("style:name", "Mangal");
    of_font3->SetAttribute("svg:font-family", "Mangal");
    of_font3->SetAttribute("style:font-family-generic", "system");
    of_font3->SetAttribute("style:font-pitch", "variable");
    of_font_decl->LinkEndChild(of_font3);
    //delete of_font;
    TiXmlElement *of_font4 = new TiXmlElement("style:font-face");
    of_font4->SetAttribute("style:name", "Microsoft YaHei");
    of_font4->SetAttribute("svg:font-family", "'Microsoft YaHei'");
    of_font4->SetAttribute("style:font-family-generic", "system");
    of_font4->SetAttribute("style:font-pitch", "variable");
    of_font_decl->LinkEndChild(of_font4);
    TiXmlElement *of_font5 = new TiXmlElement("style:font-face");
    of_font5->SetAttribute("style:name", "Tahoma");
    of_font5->SetAttribute("svg:font-family", "Tahoma");
    of_font5->SetAttribute("style:font-family-generic", "system");
    of_font5->SetAttribute("style:font-pitch", "variable");
    //delete of_font5;
    of_font_decl->LinkEndChild(of_font5);
    //delete of_font5;
    //TiXmlElement *of_font5 = new TiXmlElement("style:font-face");
    element->LinkEndChild(of_font_decl);
    TiXmlElement *of_au_st = new TiXmlElement("office:automatic-styles");
    //Задание параметров столбцов
    /*char size_of_col[8];
    sprintf(size_of_col, "%s", "opa");
    printf("%s\n", size_of_col);
    sprintf(size_of_col, "%s", "gdfd");
    printf("%s\n", size_of_col);*/


    //Определение свойств столбцов
    //Для 1го столбца
    TiXmlElement *st_st = new TiXmlElement("style:style");
    st_st->SetAttribute("style:name", "co1");
    st_st->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr = new TiXmlElement("style:table-column-properties");
    col_pr->SetAttribute("fo:break-before", "auto");
    col_pr->SetAttribute("style:column-width", "2.995cm");//Задание ширины столбцов (1й столбей)
    st_st->LinkEndChild(col_pr);

    //Далее аналогично для каждого столбца
    TiXmlElement *st_st2 = new TiXmlElement("style:style");
    st_st2->SetAttribute("style:name", "co2");
    st_st2->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr2 = new TiXmlElement("style:table-column-properties");
    col_pr2->SetAttribute("fo:break-before", "auto");
    col_pr2->SetAttribute("style:column-width", "2.974cm");
    st_st2->LinkEndChild(col_pr2);

    TiXmlElement *st_st3 = new TiXmlElement("style:style");
    st_st3->SetAttribute("style:name", "co3");
    st_st3->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr3 = new TiXmlElement("style:table-column-properties");
    col_pr3->SetAttribute("fo:break-before", "auto");
    col_pr3->SetAttribute("style:column-width", "2.842cm");
    st_st3->LinkEndChild(col_pr3);

    /*switch(quant_of_sides)
    {
    case 1:
        size_of_col="2.995cm";
        break;
    case 2:
       size_of_col="2.621cm";
       break;
    case 3:
       size_of_col="3.621cm";
       break;
    }*/
    //В зависимости от числа граней число столбцов отличается, поэтому, начиная с четвёртого столбца,
    //их названия, а следовательно и их размеры могут отличаться. Поэтому необходимо релизовать выбор
    //ширины столбца в зависимости от их числа:
    switch(quant_of_sides)
    {
    case 1:
        sprintf(size_of_col, "%s", "2.928cm");
        break;
    case 2:
        sprintf(size_of_col, "%s", "3.334cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "4.334cm");
        break;
    default:
        break;
    }

    TiXmlElement *st_st4 = new TiXmlElement("style:style");
    st_st4->SetAttribute("style:name", "co4");
    st_st4->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr4 = new TiXmlElement("style:table-column-properties");
    col_pr4->SetAttribute("fo:break-before", "auto");
    col_pr4->SetAttribute("style:column-width", size_of_col);
    st_st4->LinkEndChild(col_pr4);

    switch(quant_of_sides)
    {
    case 1:
        sprintf(size_of_col, "%s", "7.251cm");
        break;
    case 2:
        sprintf(size_of_col, "%s", "2.928cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "3.334cm");
        break;
    default:
        break;
    }

    TiXmlElement *st_st5 = new TiXmlElement("style:style");
    st_st5->SetAttribute("style:name", "co5");
    st_st5->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr5 = new TiXmlElement("style:table-column-properties");
    col_pr5->SetAttribute("fo:break-before", "auto");
    col_pr5->SetAttribute("style:column-width", size_of_col);
    st_st5->LinkEndChild(col_pr5);

    switch(quant_of_sides)
    {
    case 1:
        sprintf(size_of_col, "%s", "4.314cm");
        break;
    case 2:
        sprintf(size_of_col, "%s", "7.251cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "2.928cm");
        break;
    default:
        break;
    }

    TiXmlElement *st_st6 = new TiXmlElement("style:style");
    st_st6->SetAttribute("style:name", "co6");
    st_st6->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr6 = new TiXmlElement("style:table-column-properties");
    col_pr6->SetAttribute("fo:break-before", "auto");
    col_pr6->SetAttribute("style:column-width", size_of_col);
    st_st6->LinkEndChild(col_pr6);

    switch(quant_of_sides)
    {
    case 1:
        sprintf(size_of_col, "%s", "3.12cm");
        break;
    case 2:
        sprintf(size_of_col, "%s", "4.314cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "7.251cm");
        break;
    default:
        break;
    }

    TiXmlElement *st_st7 = new TiXmlElement("style:style");
    st_st7->SetAttribute("style:name", "co7");
    st_st7->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr7 = new TiXmlElement("style:table-column-properties");
    col_pr7->SetAttribute("fo:break-before", "auto");
    col_pr7->SetAttribute("style:column-width", size_of_col);
    st_st7->LinkEndChild(col_pr7);

    switch(quant_of_sides)
    {
    case 1:
        sprintf(size_of_col, "%s", "2.244cm");
        break;
    case 2:
        sprintf(size_of_col, "%s", "3.12cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "4.314cm");
        break;
    default:
        break;
    }


    TiXmlElement *st_st8 = new TiXmlElement("style:style");
    st_st8->SetAttribute("style:name", "co8");
    st_st8->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr8 = new TiXmlElement("style:table-column-properties");
    col_pr8->SetAttribute("fo:break-before", "auto");
    col_pr8->SetAttribute("style:column-width", size_of_col);
    st_st8->LinkEndChild(col_pr8);

    switch(quant_of_sides)
    {
    case 1:
        sprintf(size_of_col, "%s", "3.304cm");
        break;
    case 2:
        sprintf(size_of_col, "%s", "2.244cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "3.12cm");
        break;
    default:
        break;
    }

    TiXmlElement *st_st9 = new TiXmlElement("style:style");
    st_st9->SetAttribute("style:name", "co9");
    st_st9->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr9 = new TiXmlElement("style:table-column-properties");
    col_pr9->SetAttribute("fo:break-before", "auto");
    col_pr9->SetAttribute("style:column-width", size_of_col);
    st_st9->LinkEndChild(col_pr9);

    switch(quant_of_sides)
    {
    case 1:
        sprintf(size_of_col, "%s", "3.267cm");
        break;
    case 2:
        sprintf(size_of_col, "%s", "3.304cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "2.244cm");
        break;
    default:
        break;
    }


    TiXmlElement *st_st10 = new TiXmlElement("style:style");
    st_st10->SetAttribute("style:name", "co10");
    st_st10->SetAttribute("style:family", "table-column");
    TiXmlElement *col_pr10 = new TiXmlElement("style:table-column-properties");
    col_pr10->SetAttribute("fo:break-before", "auto");
    col_pr10->SetAttribute("style:column-width", size_of_col);
    st_st10->LinkEndChild(col_pr10);

    TiXmlElement *st_st11 = new TiXmlElement("style:style");

    if(quant_of_sides>1)
    {
        switch(quant_of_sides)
    {
    case 2:
        sprintf(size_of_col, "%s", "3.267cm");
        break;
    case 3:
        sprintf(size_of_col, "%s", "3.304cm");
        break;
    default:
        break;
    }


        //TiXmlElement *st_st11 = new TiXmlElement("style:style");
        st_st11->SetAttribute("style:name", "co11");
        st_st11->SetAttribute("style:family", "table-column");
        TiXmlElement *col_pr11 = new TiXmlElement("style:table-column-properties");
        col_pr11->SetAttribute("fo:break-before", "auto");
        col_pr11->SetAttribute("style:column-width", size_of_col);
        st_st11->LinkEndChild(col_pr11);
    }
    TiXmlElement *st_stt11 = new TiXmlElement("style:style");
    if(quant_of_sides==3)
    {
        //TiXmlElement *st_stt11 = new TiXmlElement("style:style");
        st_stt11->SetAttribute("style:name", "co11");
        st_stt11->SetAttribute("style:family", "table-column");
        TiXmlElement *col_prr11 = new TiXmlElement("style:table-column-properties");
        col_prr11->SetAttribute("fo:break-before", "auto");
        col_prr11->SetAttribute("style:column-width", "2.267cm");
        st_stt11->LinkEndChild(col_prr11);
    }






    //Задание параметров строк

    TiXmlElement *st_st12 = new TiXmlElement("style:style");
    st_st12->SetAttribute("style:name", "ro1");
    st_st12->SetAttribute("style:family", "table-row");
    TiXmlElement *col_pr12 = new TiXmlElement("style:table-row-properties");
    col_pr12->SetAttribute("style:row-height", "0.453cm");
    col_pr12->SetAttribute("fo:break-before", "auto");
    col_pr12->SetAttribute("style:use-optimal-row-height", "false");
    st_st12->LinkEndChild(col_pr12);


    TiXmlElement *st_st13 = new TiXmlElement("style:style");
    st_st13->SetAttribute("style:name", "ta1");
    st_st13->SetAttribute("style:family", "table");
    st_st13->SetAttribute("style:master-page-name", "Default");
    TiXmlElement *col_pr13 = new TiXmlElement("style:table-properties");
    col_pr13->SetAttribute("table:display", "true");
    col_pr13->SetAttribute("style:writing-mode", "lr-tb");
    st_st13->LinkEndChild(col_pr13);

    //Определение возможных стилей ячеек

    TiXmlElement *st_st14 = new TiXmlElement("style:style");
    st_st14->SetAttribute("style:name", "ce1");
    st_st14->SetAttribute("style:family", "table-cell");
    st_st14->SetAttribute("style:parent-style-name", "Default");
    TiXmlElement *col_pr14 = new TiXmlElement("style:table-cell-properties");
    col_pr14->SetAttribute("fo:background-color", "#ccffff");
    TiXmlElement *text_pr = new TiXmlElement("style:text-properties");
    text_pr->SetAttribute("fo:font-weight", "bold");
    text_pr->SetAttribute("style:font-weight-asian", "bold");
    text_pr->SetAttribute("style:font-weight-complex", "bold");
    st_st14->LinkEndChild(col_pr14);
    st_st14->LinkEndChild(text_pr);

    TiXmlElement *st_st15 = new TiXmlElement("style:style");
    st_st15->SetAttribute("style:name", "ce2");
    st_st15->SetAttribute("style:family", "table-cell");
    st_st15->SetAttribute("style:parent-style-name", "Default");
    TiXmlElement *col_pr15 = new TiXmlElement("style:table-cell-properties");
    col_pr15->SetAttribute("fo:background-color", "#ccffcc");
    TiXmlElement *text_pr1 = new TiXmlElement("style:text-properties");
    text_pr1->SetAttribute("fo:font-weight", "normal");
    text_pr1->SetAttribute("style:font-weight-asian", "normal");
    text_pr1->SetAttribute("style:font-weight-complex", "normal");
    st_st15->LinkEndChild(col_pr15);
    st_st15->LinkEndChild(text_pr1);

    TiXmlElement *st_st16 = new TiXmlElement("style:style");
    st_st16->SetAttribute("style:name", "ce3");
    st_st16->SetAttribute("style:family", "table-cell");
    st_st16->SetAttribute("style:parent-style-name", "Default");
    TiXmlElement *col_pr16 = new TiXmlElement("style:table-cell-properties");
    col_pr16->SetAttribute("fo:background-color", "#ffffcc");
    TiXmlElement *text_pr2 = new TiXmlElement("style:text-properties");
    text_pr2->SetAttribute("fo:font-weight", "normal");
    text_pr2->SetAttribute("style:font-weight-asian", "normal");
    text_pr2->SetAttribute("style:font-weight-complex", "normal");
    st_st16->LinkEndChild(col_pr16);
    st_st16->LinkEndChild(text_pr2);

    TiXmlElement *st_st17 = new TiXmlElement("style:style");
    st_st17->SetAttribute("style:name", "ce4");
    st_st17->SetAttribute("style:family", "table-cell");
    st_st17->SetAttribute("style:parent-style-name", "Default");
    TiXmlElement *col_pr17 = new TiXmlElement("style:table-cell-properties");
    col_pr17->SetAttribute("fo:background-color", "#ffffff");
    TiXmlElement *text_pr3 = new TiXmlElement("style:text-properties");
    text_pr3->SetAttribute("fo:font-weight", "normal");
    text_pr3->SetAttribute("style:font-weight-asian", "normal");
    text_pr3->SetAttribute("style:font-weight-complex", "normal");
    st_st17->LinkEndChild(col_pr17);
    st_st17->LinkEndChild(text_pr3);

    TiXmlElement *st_st18 = new TiXmlElement("style:style");
    st_st18->SetAttribute("style:name", "ce5");
    st_st18->SetAttribute("style:family", "table-cell");
    st_st18->SetAttribute("style:parent-style-name", "Default");
    TiXmlElement *col_pr18 = new TiXmlElement("style:table-cell-properties");
    col_pr18->SetAttribute("fo:background-color", "#ffffff");
    TiXmlElement *text_pr4 = new TiXmlElement("style:text-properties");
    text_pr4->SetAttribute("fo:font-weight", "bold");
    text_pr4->SetAttribute("style:font-weight-asian", "bold");
    text_pr4->SetAttribute("style:font-weight-complex", "bold");
    st_st18->LinkEndChild(col_pr18);
    st_st18->LinkEndChild(text_pr4);


    //Добавляем красный цвет
    TiXmlElement *st_st19 = new TiXmlElement("style:style");
    st_st19->SetAttribute("style:name", "ce6");
    st_st19->SetAttribute("style:family", "table-cell");
    st_st19->SetAttribute("style:parent-style-name", "Default");
    TiXmlElement *col_pr19 = new TiXmlElement("style:table-cell-properties");
    col_pr19->SetAttribute("fo:background-color", "#ff0000");
    TiXmlElement *text_pr5 = new TiXmlElement("style:text-properties");
    text_pr5->SetAttribute("fo:font-weight", "bold");
    text_pr5->SetAttribute("style:font-weight-asian", "bold");
    text_pr5->SetAttribute("style:font-weight-complex", "bold");
    st_st19->LinkEndChild(col_pr19);
    st_st19->LinkEndChild(text_pr5);





    of_au_st->LinkEndChild(st_st);
    of_au_st->LinkEndChild(st_st2);
    of_au_st->LinkEndChild(st_st3);
    of_au_st->LinkEndChild(st_st4);
    of_au_st->LinkEndChild(st_st5);
    of_au_st->LinkEndChild(st_st6);
    of_au_st->LinkEndChild(st_st7);
    of_au_st->LinkEndChild(st_st8);
    of_au_st->LinkEndChild(st_st9);
    of_au_st->LinkEndChild(st_st10);
    of_au_st->LinkEndChild(st_st11);
    of_au_st->LinkEndChild(st_st12);
    of_au_st->LinkEndChild(st_st13);
    of_au_st->LinkEndChild(st_st14);
    of_au_st->LinkEndChild(st_st15);
    of_au_st->LinkEndChild(st_st16);
    of_au_st->LinkEndChild(st_st17);
    of_au_st->LinkEndChild(st_st18);
    of_au_st->LinkEndChild(st_st19);
    of_au_st->LinkEndChild(st_stt11);

    element->LinkEndChild(of_au_st);
    TiXmlElement *office_body = new TiXmlElement("office:body");
    TiXmlElement *office_spreadsheet = new TiXmlElement("office:spreadsheet");

    //TiXmlElement *table_table = new TiXmlElement("table:table");
    table_table->SetAttribute("table:name", "Sheet1");
    table_table->SetAttribute("table:style-name", "ta1");
    table_table->SetAttribute("table:print", "false");




    TiXmlElement *table_column1 = new TiXmlElement("table:table-column");
    table_column1->SetAttribute("table:style-name", "co1");
    table_column1->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column1);

    TiXmlElement *table_column2 = new TiXmlElement("table:table-column");
    table_column2->SetAttribute("table:style-name", "co2");
    table_column2->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column2);

    TiXmlElement *table_column3 = new TiXmlElement("table:table-column");
    table_column3->SetAttribute("table:style-name", "co3");
    table_column3->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column3);

    TiXmlElement *table_column4 = new TiXmlElement("table:table-column");
    table_column4->SetAttribute("table:style-name", "co4");
    table_column4->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column4);

    TiXmlElement *table_column5 = new TiXmlElement("table:table-column");
    table_column5->SetAttribute("table:style-name", "co5");
    table_column5->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column5);

    TiXmlElement *table_column6 = new TiXmlElement("table:table-column");
    table_column6->SetAttribute("table:style-name", "co6");
    table_column6->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column6);

    TiXmlElement *table_column7 = new TiXmlElement("table:table-column");
    table_column7->SetAttribute("table:style-name", "co7");
    table_column7->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column7);

    TiXmlElement *table_column8 = new TiXmlElement("table:table-column");
    table_column8->SetAttribute("table:style-name", "co8");
    table_column8->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column8);

    TiXmlElement *table_column9 = new TiXmlElement("table:table-column");
    table_column9->SetAttribute("table:style-name", "co9");
    table_column9->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column9);

    TiXmlElement *table_column10 = new TiXmlElement("table:table-column");
    table_column10->SetAttribute("table:style-name", "co10");
    table_column10->SetAttribute("table:default-cell-style-name", "ce2");
    table_table->LinkEndChild(table_column10);

    TiXmlElement *table_column11 = new TiXmlElement("table:table-column");
    table_column11->SetAttribute("table:style-name", "co11");
    table_column11->SetAttribute("table:number-columns-repeated", "5");
    table_column11->SetAttribute("table:default-cell-style-name", "Default");
    table_table->LinkEndChild(table_column11);








    office_spreadsheet->LinkEndChild(table_table);
    office_body->LinkEndChild(office_spreadsheet);


    element->LinkEndChild(office_body);





    doc.LinkEndChild(element);

    //doc.SaveFile("content.xml");

}
void Fill_Hat(void)
{
    vect_table_row.push_back(new TiXmlElement("table:table-row"));
    vect_table_row[vect_table_row.size()-1]->SetAttribute("table:style-name", "ro1");

    /*TiXmlElement *mas_text_p;
    mas_text_p=(TiXmlElement*)malloc(10*sizeof(TiXmlElement));*/


    /*mas_table_row[1]=new TiXmlElement("table:table-row");
    mas_table_row[1]->SetAttribute("table:style-name", "ro1");*/


    /*vector<TiXmlElement*> vect_text_p;
    vect_text_p.push_back(new TiXmlElement("table-oPPPA"));

    mas_table_row[1]->LinkEndChild(vect_text_p[vect_text_p.size()-1]);*/
    switch(quant_of_sides)
    {
    case 1:
        column_num=9;
        break;
    case 2:
        column_num=10;
        break;
    case 3:
        column_num=11;
        break;
    }
    //Заполнение шапки таблицы в цикле по столбцам

    for(counter_mas[25]=0; counter_mas[25]<column_num; counter_mas[25]++)
    {




    vect_table_cell.push_back(new TiXmlElement("table:table-cell"));//Задание тега ячейки
    //Задание стиля ячейки:
    vect_table_cell[vect_table_cell.size()-1]->SetAttribute("table:style-name", "ce1");

        //vect_table_cell[vect_table_cell.size()-1]->SetAttribute("table:style-name", "ce2");
        //Задание типа значения для записи в ячейку
    vect_table_cell[vect_table_cell.size()-1]->SetAttribute("office:value-type", "string");

    vect_text_p.push_back(new TiXmlElement("text:p"));
    //Формирование строк текста для записи в ячейку:
    if(column_num==10)
    {
    switch(counter_mas[25])
    {
    case 0:
        sprintf(str, "%s", "Number of point");
        break;
    case 1:
        sprintf(str, "%s", "Name of module");
        break;
    case 2:
        sprintf(str, "%s", "First side[mks]");
        break;
    case 3:
        sprintf(str, "%s", "Second side[mks]");
        break;
    case 4:
        sprintf(str, "%s", "Max value[mks]");
        break;
    case 5:
        sprintf(str, "%s", "Actual time of the work of the side[mks]");
        break;
    case 6:
        sprintf(str, "%s", "Ending time in CG[mks]");
        break;
    case 7:
        sprintf(str, "%s", "Time in CG[mks]");
        break;
    case 8:
        sprintf(str, "%s", "Stock[mks]");
        break;
    case 9:
        sprintf(str, "%s", "Stock, %");
        break;
    default:
        break;
    }
    }

    if(column_num==9)
    {
    switch(counter_mas[25])
    {
    case 0:
        sprintf(str, "%s", "Number of point");
        break;
    case 1:
        sprintf(str, "%s", "Number of module");
        break;
    case 2:
        sprintf(str, "%s", "First side[mks]");
        break;
    case 3:
        sprintf(str, "%s", "Max value[mks]");
        break;
    case 4:
        sprintf(str, "%s", "Actual time of work of the side[mks]");
        break;
    case 5:
        sprintf(str, "%s", "Ending time in CG[mks]");
        break;
    case 6:
        sprintf(str, "%s", "Time in CG[mks]");
        break;
    case 7:
        sprintf(str, "%s", "Stock[mks]");
        break;
    case 8:
        sprintf(str, "%s", "Stock, %");
        break;
    default:
        break;
    }
    }

    if(column_num==11)
    {
    switch(counter_mas[25])
    {
    case 0:
        sprintf(str, "%s", "Number of point");
        break;
    case 1:
        sprintf(str, "%s", "Name of module");
        break;
    case 2:
        sprintf(str, "%s", "First side[mks]");
        break;
    case 3:
        sprintf(str, "%s", "Second side[mks]");
        break;
    case 4:
        sprintf(str, "%s", "Third side[mks]");
        break;
    case 5:
        sprintf(str, "%s", "Max value[mks]");
        break;
    case 6:
        sprintf(str, "%s", "Actual time of work of the side[mks]");
        break;
    case 7:
        sprintf(str, "%s", "Ending time in CG[mks]");
        break;
    case 8:
        sprintf(str, "%s", "Time in CG[mks]");
        break;
    case 9:
        sprintf(str, "%s", "Stock[mks]");
        break;
    case 10:
        sprintf(str, "%s", "Stock, %");
        break;
    default:
        break;
    }
    }
    //Запись текста в ячейку
    vect_tixml_text.push_back(new TiXmlText(str));



    vect_text_p[vect_text_p.size()-1]->LinkEndChild(vect_tixml_text[vect_tixml_text.size()-1]);
    vect_table_cell[vect_table_cell.size()-1]->LinkEndChild(vect_text_p[vect_text_p.size()-1]);
    vect_table_row[vect_table_row.size()-1]->LinkEndChild(vect_table_cell[vect_table_cell.size()-1]);
    }
    table_table->LinkEndChild(vect_table_row[vect_table_row.size()-1]);







}
void Fill_Rows(void)
{
    //printf("quantity=%d\n", quantity);
    /*TiXmlElement *mas_table_row[10];
    TiXmlElement *mas_table_cell[10];
    TiXmlElement *mas_text_p[10];
    TiXmlText *mas_tixml_text[10];*/



    vect_table_row.push_back(new TiXmlElement("table:table-row"));
    vect_table_row[vect_table_row.size()-1]->SetAttribute("table:style-name", "ro1");

    /*TiXmlElement *mas_text_p;
    mas_text_p=(TiXmlElement*)malloc(10*sizeof(TiXmlElement));*/


    /*mas_table_row[1]=new TiXmlElement("table:table-row");
    mas_table_row[1]->SetAttribute("table:style-name", "ro1");*/


    /*vector<TiXmlElement*> vect_text_p;
    vect_text_p.push_back(new TiXmlElement("table-oPPPA"));

    mas_table_row[1]->LinkEndChild(vect_text_p[vect_text_p.size()-1]);*/
    /*switch(quant_of_sides)
    {
    case 1:
        column_num=9;
        break;
    case 2:
        column_num=10;
        break;
    case 3:
        column_num=11;
        break;
    }*/

    for(counter_mas[25]=0; counter_mas[25]<column_num; counter_mas[25]++)
    {
    vect_table_cell.push_back(new TiXmlElement("table:table-cell"));
    //Задание стиля ячеек в зависимости от того, чётная или нечётная строка (для улучшения восприятия).
    //В случае, когда запас меньше 30%, строка подсвечивается красным
    if((stock>30)||(vect_time_in_ZG[counter_mas[21]]==0))
    {
    if(((vect_table_row.size()-1)%2)==0)
    {
        vect_table_cell[vect_table_cell.size()-1]->SetAttribute("table:style-name", "ce3");
    }
    else
    {
        vect_table_cell[vect_table_cell.size()-1]->SetAttribute("table:style-name", "ce2");
    }
    }
    else
    {
        vect_table_cell[vect_table_cell.size()-1]->SetAttribute("table:style-name", "ce6");
    }

    vect_table_cell[vect_table_cell.size()-1]->SetAttribute("office:value-type", "string");

    vect_text_p.push_back(new TiXmlElement("text:p"));
    //Формирование строк текста для записи в ячейку:
    if(column_num==10)
    {
    switch(counter_mas[25])
    {
    case 0:
        sprintf(str, "%d", ind);
        break;
    case 1:
        sprintf(str, "%s", buffer);
        break;
    case 2:
        sprintf(str, "%d", storage[priznak1]*10);
        break;
    case 3:
        sprintf(str, "%d", storage[priznak2]*10);
        break;
    case 4:
        sprintf(str, "%d", compare2);
        break;
    case 5:
        sprintf(str, "%.0f", Var2_float);
        break;
    case 6:
        sprintf(str, "%d", vect_time_in_ZG[counter_mas[21]]);
        break;
    case 7:
        sprintf(str, "%d", vect_mas_inp_int_inf[counter_mas[6]]);
        break;
    case 8:
        sprintf(str, "%d", stock_msk);
        break;
    case 9:
        sprintf(str, "%.2f", stock);
        break;
    default:
        break;
    }
    }

    if(column_num==9)
    {
    switch(counter_mas[25])
    {
    case 0:
        sprintf(str, "%d", ind);
        break;
    case 1:
        sprintf(str, "%s", buffer);
        break;
    case 2:
        sprintf(str, "%d", storage[priznak1]*10);
        break;
    case 3:
        sprintf(str, "%d", compare2);
        break;
    case 4:
        sprintf(str, "%.0f", Var2_float);
        break;
    case 5:
        sprintf(str, "%d", vect_time_in_ZG[counter_mas[21]]);
        break;
    case 6:
        sprintf(str, "%d", vect_mas_inp_int_inf[counter_mas[6]]);
        break;
    case 7:
        sprintf(str, "%d", stock_msk);
        break;
    case 8:
        sprintf(str, "%.2f", stock);
        break;
    default:
        break;
    }
    }

    if(column_num==11)
    {
    switch(counter_mas[25])
    {
    case 0:
        sprintf(str, "%d", ind);
        break;
    case 1:
        sprintf(str, "%s", buffer);
        break;
    case 2:
        sprintf(str, "%d", storage[priznak1]*10);
        break;
    case 3:
        sprintf(str, "%d", storage[priznak2]*10);
        break;
    case 4:
        sprintf(str, "%d", storage[priznak3]*10);
        break;
    case 5:
        sprintf(str, "%d", compare2);
        break;
    case 6:
        sprintf(str, "%.0f", Var2_float);
        break;
    case 7:
        sprintf(str, "%d", vect_time_in_ZG[counter_mas[21]]);
        break;
    case 8:
        sprintf(str, "%d", vect_mas_inp_int_inf[counter_mas[6]]);
        break;
    case 9:
        sprintf(str, "%d", stock_msk);
        break;
    case 10:
        sprintf(str, "%.2f", stock);
        break;
    default:
        break;
    }
    }
    vect_tixml_text.push_back(new TiXmlText(str));



    vect_text_p[vect_text_p.size()-1]->LinkEndChild(vect_tixml_text[vect_tixml_text.size()-1]);
    vect_table_cell[vect_table_cell.size()-1]->LinkEndChild(vect_text_p[vect_text_p.size()-1]);
    vect_table_row[vect_table_row.size()-1]->LinkEndChild(vect_table_cell[vect_table_cell.size()-1]);
    }
    table_table->LinkEndChild(vect_table_row[vect_table_row.size()-1]);

}
void End_Xml_Doc(void)
{
    doc.SaveFile("content.xml");//Сохраняет и закрывае
}




void MainWindow::on_toolButton_clicked()
{
    QString string_file = QFileDialog::getOpenFileName(0, "Открыть", flpath_2, "*txt");
    if(!string_file.isEmpty())
    {
        //ui->lineEdit_4->setText(string_file);
    }
}



void MainWindow::on_toolButton_3_clicked()
{
    QString string_file_1 = QFileDialog::getOpenFileName(0, "Открыть", flpath, "*a96");
    //ui->comboBox->clear();
    Qt_Buf_LineEdit.clear();
    /*if(!Qt_Buf_LineEdit.isEmpty())
    {
        ui->comboBox->addItem(Qt_Buf_LineEdit);
    }*/
    if(!string_file_1.isEmpty())
    {
        ui->lineEdit_2->setText(string_file_1);
        Form_PopupCgNamesList();

    }
}

void Read_File_Inf(void)
{
    counter_mas[27]=0;
    if(counter_mas[26]!=0)
    {
         counter_mas[26]=counter_mas[26]+2;
    }

    while((test[counter_mas[26]]!='\x0')&&(test[counter_mas[26]]!='\xd'))
    {
        //qDebug() << test[counter_mas[26]];
        //Qt_Buf_LineEdit[counter_mas[26]]=test[counter_mas[26]];
        counter_mas[26]++;
        counter_mas[27]++;
    }

    Qt_Buf_LineEdit.resize(counter_mas[27]);
    counter_mas[26]=counter_mas[26]-counter_mas[27];
    counter_mas[27]=0;
    while((test[counter_mas[26]]!='\x0')&&(test[counter_mas[26]]!='\xd'))
    {
        //qDebug() << test[counter_mas[26]];
        Qt_Buf_LineEdit[counter_mas[27]]=test[counter_mas[26]];
        counter_mas[26]++;
        counter_mas[27]++;
    }

}
/*void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    printf("OPA!\n");
    QMainWindow::closeEvent(event);
}

void MainWindow::readSettings()
{
    QSettings settings("MyCompany", "MyApp");
    restoreGeometry(settings.value("myWidget/geometry").toByteArray());
    restoreState(settings.value("myWidget/windowState").toByteArray());
    printf("APA!\n");
}*/
void MainWindow::closeEvent(QCloseEvent *event)
 {
     Pos_x=QWidget::x();
     Pos_y=QWidget::y();

     Pos_File.setFileName("POS.txt");
     if(Pos_File.exists())
     {
         Pos_File.remove();
     }
     if(!Pos_File.open(QIODevice::WriteOnly))
     {
         printf("Mistake during opening the file!");
         QApplication::quit();
     }

     counter_mas[28]=1;
     counter_mas[29]=1;
     while(Pos_x/=10)
     {
         counter_mas[28]++;
     }
     while(Pos_y/=10)
     {
         counter_mas[29]++;
     }
     Pos_x=QWidget::x();
     Pos_y=QWidget::y();
     counter_mas[28]=counter_mas[28]+3+counter_mas[29];
     buf_to_pos_file=(char*) malloc(counter_mas[28]*sizeof (char));
     sprintf(buf_to_pos_file, "%d%c%d%c", Pos_x, ';', Pos_y, ';');
     Pos_File.write(buf_to_pos_file);
     //printf("buf=%s\n", buf_to_pos_file);
     //printf("num_in_X=%d\n", counter_mas[28]);
    // printf("num_in_X=%d\n", counter_mas[29]);

     //printf("Pos_X=%d", Pos_x);
     //printf("Pos_Y=%d", Pos_y);
     Pos_File.close();
     QWidget::closeEvent(event);
 }

/*void MainWindow::on_toolButton_2_clicked()
{
    QString string_file_1 = QFileDialog::getOpenFileName(0, "Открыть", "", "*ods");
    if(!string_file_1.isEmpty())
    {
        ui->lineEdit_3->setText(string_file_1);
    }
}*/

void MainWindow::Form_PopupCgNamesList(void)
{
    if(!ui->lineEdit_2->text().isEmpty())
    {
        Qt_Inf_Zg = ui->lineEdit_2->text();


        Ch_Inf_Zg=qPrintable(Qt_Inf_Zg);
        input=fopen(Ch_Inf_Zg, "r");
        //qDebug() << Qt_Inf_Zg;

        while((fgetc(input))!=EOF)
        {

            counter_mas[1]++;
        }
        counter_mas[1]++;
        quant_sym=counter_mas[1];

        /*mas_inp_file= (char*) malloc(counter_mas[1]*sizeof(char));
        if(mas_inp_file == NULL)
        {
            printf("Ошибка выделения памяти");
            //exit(5);
        }*/
        //-----------------------------------

        counter_mas[1]=0;
        fseek(input, 0, SEEK_SET);

        counter_mas[0]=0;
        //printf("Start\n");

        Check_Quantity_CgSymbols();
        //printf("Символов в именах циклограмм: %d\n", counter_mas[0]);
        Cg_Names= (char*) malloc(counter_mas[0]*sizeof(char));
        if(Cg_Names == NULL)
        {
            printf("Ошибка выделения памяти");
            exit(5);
        }

        fseek(input, 0, SEEK_SET);
        counter_mas[1]=0;
        counter_mas[0]=0;
        counter_mas[2]=0;

        Read_Cg_Names_In_Mas();

        //printf("%s\n", Cg_Names);
        counter_mas[33]=0;
        while(Cg_Names[counter_mas[33]]!='\0')
        {
            if(Cg_Names[counter_mas[33]]!=':')
            {
               ComboBox_Item.push_back(Cg_Names[counter_mas[33]]);
            }
            else
            {
                if(ComboBox_Item!=Qt_Buf_LineEdit)
                {
                    //ui->comboBox->addItem(ComboBox_Item);
                }

                ComboBox_Item.clear();
            }

            counter_mas[33]++;


        }


        fclose(input);
        free(Cg_Names);
        Qt_Inf_Zg.clear();
    }




}

bool MainWindow::IsFoldExist(const std::string &s)
{
    struct stat buffer;
    return(stat(s.c_str(), &buffer)==0);
}
void Inst_Count_To_Pos()
{
    char c;
    fseek(input, 0, SEEK_SET);
    while(!(flag&(1<<9)))
        {
            flag&=~(1<<9);
            if((c=fgetc(input))==Cg_Names[pos_of_cg_name])
            {
                pos_of_cg_name++;
                 //qDebug()<< c;
            }
            else
            {
                //printf("opa!\n");
                pos_of_cg_name=counter_mas[0];
            }
            if(Cg_Names[pos_of_cg_name]==':')
            {

                //if(mas_inp_file[counter_mas[5]+1]==':')
                //{
                   flag|=(1<<9);
                //}


                //printf("P_CG_N=%d", pos_of_cg_name);
            }
            //counter_mas[5]++;
        }
        //printf("%s", Cg_Names);
        //printf("mas_input_file=%s\n", mas_inp_file);

        //printf("EXIT!\n");
        //printf("counter_mas[5]=%d\n", counter_mas[5]);




        flag&=~(1<<9);
        counter_mas[0]=0;


                counter_mas[5]++;
                while(counter_mas[8]!=3)
                {
                    if((c=fgetc(input))=='d')
                    {
                        counter_mas[8]++;
                        //qDebug()<< c;
                    }
                    //counter_mas[5]++;
                }
                int cou;
                for(cou=0; cou<3; cou++)
                {
                    c=fgetc(input);
                    //qDebug()<< c;
                }

                //qDebug()<< fgetc(input);

}


bool Call_Worker()
{
    QString curdir, sbl, strproc, kdr_path, kdr, str, Empty_str, kdr_name;

        QStringList arg, dopArg;

        QProcess proc;

        ///curdir - путь к обработчику
        /// kdr имя кдр
        /// sbl - имя сбл-ника
        /// out - имя файла протокола
        /// dopArg - режим работы Worker




        curdir=QCoreApplication::applicationDirPath()+"\\envelope\\worker2.exe";//
        kdr_path=QCoreApplication::applicationDirPath()+"\\temp\\";



        Empty_str.clear();
        //qDebug()<<curdir;




         dopArg << "1" << "1" << "1" << "1";
         if(count_Call_worker==1)
         {

             dopArg << "2" << "1" << "1" << "1";


         }
         count_Call_worker++;

         kdr=Qt_kdr_file;
         sbl=Qt_sbl_file;
         //qDebug()<<"input files 2:";
         //qDebug()<<kdr;
         //qDebug()<<sbl;
         counter_mas[32]=0;
         while(counter_mas[32]!=kdr.count())
         {
             if(kdr[counter_mas[32]]=='/')
             {
                Pos_Of_slash=counter_mas[32];

             }

             counter_mas[32]++;

         }
         kdr_name=kdr;

         kdr_name.remove(kdr_name.count()-4, 4);
         kdr_name.remove(0, Pos_Of_slash+1);
         counter_mas[32]=0;
         //qDebug()<< "AA!";
         //qDebug()<<kdr_name;

         out=kdr_name+".txt";
         Qt_Tel_Name=QCoreApplication::applicationDirPath()+"/"+out;
         //qDebug()<<"Name of the file with TMI";
         //qDebug() << out;

        arg << kdr << sbl << out << dopArg;


        curdir = QDir::fromNativeSeparators(curdir);
        //qDebug()<<curdir;

        report_file.setFileName(QCoreApplication::applicationDirPath()+"/"+out);
        if(report_file.exists())
        {
            report_file.remove();
            //qDebug() << "AAAAA!!!!";
        }



        out = QDir::fromNativeSeparators(out);

        kdr_path = QDir::fromNativeSeparators(kdr_path);


        proc.setWorkingDirectory(QCoreApplication::applicationDirPath());

    #if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)

        arg.insert(0, strproc);

        proc.start("mono", arg);

    #else




        proc.start(curdir, arg);

    #endif

        //  Ожидается завершения работы Worker

        proc.waitForFinished(-1);

        //  Стутус завершения работы

        arg.clear();
        dopArg.clear();

        //ui->progressBar->setValue(25);



         out=kdr_name+"_new.txt";


         report_file_2.setFileName(QCoreApplication::applicationDirPath()+"/"+out);
         if(report_file_2.exists())
         {
             report_file_2.remove();
             //qDebug() << "AAAAA!!!!";
         }




         sbl.clear();


         sbl=QCoreApplication::applicationDirPath()+"/Cyclograms/"+"ArcM_BVU_BUK"+".sbl";



         dopArg << "2" << "1" << "1" << "1";

        arg << kdr << sbl << out << dopArg;

        //qDebug()<<arg;

       proc.start(curdir, arg);

        proc.waitForFinished(-1);


        if(proc.exitStatus() != QProcess::NormalExit)

        {
            return false;
        }

        return true;





}







/*bool Call_Worker()
{
    QString curdir, sbl, out, strproc, kdr_path, kdr, str, Empty_str, kdr_name;

        QStringList arg, dopArg;

        QProcess proc;

        ///curdir - путь к обработчику
        /// kdr имя кдр
        /// sbl - имя сбл-ника
        /// out - имя файла протокола
        /// dopArg - режим работы Worker




        curdir=QCoreApplication::applicationDirPath()+"\\envelope\\worker2.exe";//
        kdr_path=QCoreApplication::applicationDirPath()+"\\temp\\";



        Empty_str.clear();
        //qDebug()<<curdir;




         dopArg << "1" << "1" << "1" << "1";
         if(count_Call_worker==1)
         {

             dopArg << "2" << "1" << "1" << "1";

         }
         count_Call_worker++;

         kdr=Qt_kdr_file;
         sbl=Qt_sbl_file;
         //qDebug()<<"input files 2:";
         //qDebug()<<kdr;
         //qDebug()<<sbl;
         counter_mas[32]=0;
         while(counter_mas[32]!=kdr.count())
         {
             if(kdr[counter_mas[32]]=='/')
             {
                Pos_Of_slash=counter_mas[32];

             }

             counter_mas[32]++;

         }
         kdr_name=kdr;

         kdr_name.remove(kdr_name.count()-4, 4);
         kdr_name.remove(0, Pos_Of_slash+1);
         counter_mas[32]=0;
         //qDebug()<< "AA!";
         //qDebug()<<kdr_name;

         out=kdr_name+".txt";
         Qt_Tel_Name=QCoreApplication::applicationDirPath()+"/"+out;
         //qDebug()<<"Name of the file with TMI";
         //qDebug() << out;

        arg << kdr << sbl << out << dopArg;


        curdir = QDir::fromNativeSeparators(curdir);
        //qDebug()<<curdir;

        report_file.setFileName(QCoreApplication::applicationDirPath()+"/"+out);
        if(report_file.exists())
        {
            report_file.remove();
            //qDebug() << "AAAAA!!!!";
        }



        out = QDir::fromNativeSeparators(out);

        kdr_path = QDir::fromNativeSeparators(kdr_path);


        proc.setWorkingDirectory(QCoreApplication::applicationDirPath());

    #if defined(Q_OS_LINUX) || defined(Q_OS_UNIX)

        arg.insert(0, strproc);

        proc.start("mono", arg);

    #else




        proc.start(curdir, arg);

    #endif

        //  Ожидается завершения работы Worker

        proc.waitForFinished(-1);

        //  Стутус завершения работы

        if(proc.exitStatus() != QProcess::NormalExit)

        {
            return false;
        }

        return true;

}*/

/*void Create_Err_Message(void)
{
    Qt_OutFile_name="Обрабатываемый файл телеметрической информации содержит информацию об нескольких испытаниях. Р\n";



}*/







/*void Inst_Count_To_Pos(void)
{
    while(!(flag&(1<<9)))
        {
            flag&=~(1<<9);
            if(mas_inp_file[counter_mas[5]]==Cg_Names[pos_of_cg_name])
            {
                pos_of_cg_name++;
            }
            else
            {
                //printf("opa!\n");
                pos_of_cg_name=counter_mas[0];
            }
            if(Cg_Names[pos_of_cg_name]==':')
            {

                //if(mas_inp_file[counter_mas[5]+1]==':')
                //{
                   flag|=(1<<9);
                //}


                //printf("P_CG_N=%d", pos_of_cg_name);
            }
            counter_mas[5]++;
        }
        //printf("%s", Cg_Names);
        //printf("mas_input_file=%s\n", mas_inp_file);

        //printf("EXIT!\n");
        //printf("counter_mas[5]=%d\n", counter_mas[5]);




        flag&=~(1<<9);
        counter_mas[0]=0;


                counter_mas[5]++;
                while(counter_mas[8]!=3)
                {
                    if(mas_inp_file[counter_mas[5]]=='d')
                    {
                        counter_mas[8]++;
                    }
                    counter_mas[5]++;
                }







}*/





void MainWindow::on_toolButton_2_clicked()
{
    QString string_file_1 = QFileDialog::getOpenFileName(0, "Открыть", Qt_sbl_file, "*sbl");
    //ui->comboBox->clear();
    Qt_Buf_LineEdit.clear();
    /*if(!Qt_Buf_LineEdit.isEmpty())
    {
        ui->comboBox->addItem(Qt_Buf_LineEdit);
    }*/
    if(!string_file_1.isEmpty())
    {
        //ui->lineEdit_3->setText(string_file_1);
        //Form_PopupCgNamesList();

    }
}

void MainWindow::on_toolButton_5_clicked()
{
    QString string_file_1 = QFileDialog::getOpenFileName(0, "Открыть", Qt_kdr_file, "*kdr");
    //ui->comboBox->clear();
    Qt_Buf_LineEdit.clear();
    /*if(!Qt_Buf_LineEdit.isEmpty())
    {
        ui->comboBox->addItem(Qt_Buf_LineEdit);
    }*/
    if(!string_file_1.isEmpty())
    {
        ui->lineEdit_5->setText(string_file_1);
        //Form_PopupCgNamesList();

    }
}










void Test_of_others_features()
{
    int internal_counter=0;
    int internal_counter_2=0;
    //int quant_of_symb_in_Tel_file=0;
    QString Buffer;
    QString Buf_ValuePrpvv;
    //QDebug deb=qDebug();
    //fseek(file, 0, SEEK_SET);
    //counter_mas[35]=0;
    /*symbol=(fgetc(file));
    while(fgetc(file)!=EOF)
    {
        quant_of_symb_in_Tel_file++;
    }
    quant_of_symb_in_Tel_file++;
    fseek(file, 0, SEEK_SET);*/
    //qDebug()<<quant_of_symb_in_Tel_file;
    //qDebug()<<"first case"<<quant_of_symb_in_Tel_file_norm;
    while(quant_of_symb_in_Tel_file)
    {
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file--;
        //qDebug() << symbol;
        if(symbol==Nominal_features[internal_counter])
        {
            while((symbol==Nominal_features[internal_counter]))
            {
               //qDebug()<<symbol;
                //deb<<symbol;
               Buffer.append(symbol);
               internal_counter++;
               symbol=(fgetc(file));
               quant_of_symb_in_Tel_file--;
               if(symbol=='=')
               {
                   internal_counter_2++;
                   //qDebug()<<"RRRRR!!!!!";
               }
               if((symbol==' ')&&(internal_counter_2==1))
               {
                   internal_counter_2++;
                   //qDebug()<<"BBBBBB!!!!!";
               }
               if((symbol=='0')&&(internal_counter_2==2))
               {
                   internal_counter_2++;
                   //qDebug()<<"CCCCCCC!!!!!";
               }
               //Убираем трабл с pfi_reg
               if((symbol=='x')&&(internal_counter_2==3))
               {
                   internal_counter_2++;


                   if(Nominal_features.contains("prpvv1"))
                   {
                       flag|=(1<<23);
                       qDebug()<<"YYYYYY!!!!!!";
                   }
                   else
                   {
                       flag&=~(1<<23);
                   }


                   //qDebug()<<"CCCCCCC!!!!!";
               }
               //



            }
            //qDebug() << internal_counter;
            //Если проверили все Nominal_features
            if(Nominal_features.count()==internal_counter)
            {
               // qDebug()<<"ALL RIGHT!";
                Nominal_features.clear();
                Buffer.clear();
                break;
            }
            else
            {
                if(internal_counter_2>=4)//Поменял на 4
                {
                    /*if(Nominal_features=="prpvv1 = 0x0001")
                    {*/
                        //qDebug()<<Nominal_features;


                    //}

                    internal_counter=0;

                    while(symbol!=' ')
                    {
                        //qDebug()<<"CCCCCCC!!!!!";


                        if((flag&(1<<23))&&(symbol!=Nominal_features[internal_counter]))
                        {
                            flag|=(1<<30); //Признак того, что у нас вторая циклограмма

                            //qDebug()<<"SECOND CG";

                        }
                        //if(ui->)
                        //flag|=(1<<30); ДЛЯ ПРОВЕРКИ

                        internal_counter++;



                        Buffer.append(symbol);
                        symbol=(fgetc(file));
                        quant_of_symb_in_Tel_file--;

                    }
                    RealValues.append(Buffer);
                    RealValues.append(";");

                    //qDebug()<<"RealValues:"<<Buffer;
                    break;

                }
                else
                {
                    Buffer.clear();
                }




            }

            internal_counter=0;
        }
        internal_counter_2=0;
    }



}



void Analys_changing_values(void)
{
    int num_parameter=0;
    int internal_counter_2=0;
    int internal_counter_3=0;

    int internal_counter_4=0;
    int internal_counter_5=0;

    int internal_counter_6=0;






    int loop_count=0;
    int quant_PLCs_BUK=0;
    int num_vect_mult_feature=0;

    int temp_number=0;

    int count_total_output=0;

    QString temp_value;

    QString TempNomValue;


    QDebug deb = qDebug();



    QString TempBuffer;

    QString Res_Buffer;
    QString Buf_true_value;

    QString Buf_Value;
    QString Buf_Saver;

    QString WrongFeatures_BUK;
    QString RealValues_BUK;

    QString Real_Values_multpl_BVU;
    QString Wrong_Features_multpl_BVU;





    Quant_Of_Symbl_In_File();
    Init_Normative_values_BUK();

    while(quant_of_symb_in_Tel_file_norm>3)
    {
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file_norm--;
        //qDebug()<<"KKK";

        //Читаем по словам
        while(symbol!=' ')
        {
            Buffer.append(symbol);
            symbol=(fgetc(file));
            quant_of_symb_in_Tel_file_norm--;
        }


        if(Buffer.contains(":"))
        {
            TimeKeeper=Buffer;

        }


        //qDebug()<<Buffer;


            /*if(symbol!=' ')
            {
                Buffer.append(symbol);
            }
            else
            {
                //qDebug()<<Buffer;

                Buffer.clear();
            }*/



        while(num_parameter!=CheckingPar.size())
        {
            /*qDebug()<<"Buffer="<<Buffer;
            qDebug()<<"CheckingPar="<<CheckingPar[num_parameter];*/
            if(Buffer==CheckingPar[num_parameter])
            {
                //flag|=(1<<20);
                //qDebug()<<Buffer;



                Buffer.append(symbol);
                //deb<<Buffer;

                symbol=(fgetc(file));
                quant_of_symb_in_Tel_file_norm--;




                /*if(Buffer=="change")
                {
                    internal_counter_2=4;
                    qDebug()<<"QQQQQQQ";
                }*/


                if(symbol=='=')
                {
                    internal_counter_2++;
                    Buffer.append(symbol);
                    symbol=(fgetc(file));
                    quant_of_symb_in_Tel_file_norm--;
                }
                if((symbol==' ')&&(internal_counter_2==1))
                {
                    internal_counter_2++;
                    //
                    if(Buffer=="change =")
                    {
                        internal_counter_2=4;
                    }

                    Buffer.append(symbol);
                    symbol=(fgetc(file));
                    quant_of_symb_in_Tel_file_norm--;
                    //deb<<Buffer;



                    //deb<<Buffer;
                    //qDebug()<<"BBBBBB!!!!!";
                }
                if((symbol=='0')&&(internal_counter_2==2))
                {
                    internal_counter_2++;
                    Buffer.append(symbol);
                    symbol=(fgetc(file));
                    quant_of_symb_in_Tel_file_norm--;
                }
                //Убираем трабл с pfi_reg
                if((symbol=='x')&&(internal_counter_2==3))
                {
                    internal_counter_2++;
                    Buffer.append(symbol);
                    symbol=(fgetc(file));
                    quant_of_symb_in_Tel_file_norm--;

                    //flag|=(1<<20);
                    //qDebug()<<"Buf"<<Buffer;

                    //qDebug()<<"CCCCCCC!!!!!";
                }
                if(internal_counter_2<4)
                {
                    //qDebug()<<"1";
                    //Если не нашли информативный признак (со значением), то всё обнуляем

                    internal_counter_2=0;

                    Buffer.clear();

                }
                else
                {
                    //qDebug()<<"Buf========================"<<Buffer;

                    while(symbol!=' ')
                    {

                        /*qDebug()<<"Buffer="<<Buffer;
                        qDebug()<<"CheckingPar="<<CheckingPar[num_parameter];
                        qDebug()<<"Buf_Value="<<Buf_Value;*/
                        //deb<<symbol;
                        /*if((Buffer=="change ")&&(!(flag&(1<<29))))
                        {
                            for (loop_count=0;loop_count<2;loop_count++)
                            {
                                Buffer.append(symbol);
                                symbol=(fgetc(file));
                                quant_of_symb_in_Tel_file_norm--;
                                flag|=(1<<29);

                            }
                            qDebug()<<"CHANGE="<<Buffer;
                        }*/
                        Buffer.append(symbol);
                        Buf_Value.append(symbol);
                        //deb<<Buf_Value;
                        symbol=(fgetc(file));
                        quant_of_symb_in_Tel_file_norm--;

                    }
                    if((TrueValue[num_parameter]!=Buf_Value)&&(!(RealValues.contains(Buffer))))
                    {

                        ///Если нашли СЗО


                        /*ProtNomValues.push_back("*");
                        ProtNamesModules.push_back("*");
                        ProtTMIValues.push_back("*");*/


                        Write_SZO_vector();

                        ///

                        /*if(Buffer.contains("szo"))
                        {
                            szo_keeper.value=Buffer;
                            szo_keeper.SZO_time=TimeKeeper;
                            szo_keeper.SZO_description="222";


                            vect_SZO.push_back(szo_keeper);


                            flag_2|=(1<<9);

                        }*/




                        for(loop_count=0; loop_count<4; loop_count++)
                        {
                            Buf_Saver=Buffer;

                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="sch_gr("+QString::number(loop_count)+")")
                            {
                                if(Buf_Value.toInt()<=QString("00FF").toInt())
                                {
                                    //qDebug()<<"BUFFER="<<Buffer[Buffer.lastIndexOf(")")-1];

                                    flag|=(1<<20);



                                }
                                else
                                {
                                   flag_2|=(1<<1);
                                   flag_2|=(1<<2);



                                    temp_number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                    temp_value=Buf_Value;
                                    TempNomValue=TrueValue[num_parameter];

                                    //qDebug()<<"temp_number="<<temp_number;
                                    //qDebug()<<"temp_value="<<temp_value;
                                    //qDebug()<<"internal_counter_3="<<internal_counter_3;

                                    if(!(vect_multpl_feat_schgr.empty()))
                                    {

                                        if(vect_multpl_feat_schgr[internal_counter_3-1].number>temp_number)
                                        {
                                            //qDebug()<<"entrance";
                                            temp_number=vect_multpl_feat_schgr[internal_counter_3-1].number;
                                            temp_value=vect_multpl_feat_schgr[internal_counter_3-1].value;
                                            TempNomValue=vect_multpl_feat_schgr[internal_counter_3-1].nominal_value;
                                            vect_multpl_feat_schgr[internal_counter_3-1].number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                            vect_multpl_feat_schgr[internal_counter_3-1].value=Buf_Value;
                                            vect_multpl_feat_schgr[internal_counter_3-1].nominal_value=TrueValue[num_parameter];

                                        }


                                    }

                                    vect_multpl_feat_schgr.push_back({Buf_Saver.remove(Buffer.lastIndexOf("("), Buffer.count()-1),temp_value, temp_number, TempNomValue});


                                    //qDebug()<<"identf="<<vect_multpl_feat_schgr[internal_counter_3].identificator;
                                    //qDebug()<<"numb="<<vect_multpl_feat_schgr[internal_counter_3].number;
                                    //qDebug()<<"value="<<vect_multpl_feat_schgr[internal_counter_3].value;
                                    //qDebug()<<"nom_value="<<vect_multpl_feat_schgr[internal_counter_3].nominal_value;

                                   internal_counter_3++;
                                   temp_value.clear();

                                }
                                internal_counter_3=0;
                                while(internal_counter_3!=vect_multpl_feat_schgr.size())
                                {
                                    //qDebug()<<"identf="<<vect_multpl_feat_schgr[internal_counter_3].identificator;
                                    //qDebug()<<"numb="<<vect_multpl_feat_schgr[internal_counter_3].number;
                                    //qDebug()<<"value="<<vect_multpl_feat_schgr[internal_counter_3].value;
                                    internal_counter_3++;
                                }
                            }
                           Buf_Saver.clear();
                        }

                        Buf_Saver=Buffer;

                        if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="shift_kontr")
                        {
                            if(Buf_Value.toInt()<=QString("000F").toInt())
                            {
                                flag|=(1<<20);

                            }
                        }

                        if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="otk_pti")
                        {
                            if(Buf_Value.toInt()<=QString("000F").toInt())
                            {
                                flag|=(1<<20);

                            }
                        }


                        if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="config_vs")
                        {
                            if(Buf_Value.count("6")==2)
                            {
                                flag|=(1<<21);
                                //qDebug()<<Buffer;
                                //qDebug()<<"3 PLCs";
                            }
                            else
                            {
                                flag&=~(1<<21);
                                //qDebug()<<Buffer;
                                //qDebug()<<"2 PLCs";
                            }

                            flag|=(1<<20);
                        }

                        if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_reg")
                        {

                            if(((flag&(1<<21)))&&((Buf_Value=="0007")||(Buf_Value=="000B")||(Buf_Value=="000D")||(Buf_Value=="000E")))
                            {
                                flag|=(1<<20);

                            }
                            if((!(flag&(1<<21)))&&((Buf_Value=="0003")||(Buf_Value=="0005")||(Buf_Value=="0006")||(Buf_Value=="0009")||(Buf_Value=="000A")||(Buf_Value=="000C")))
                            {
                                flag|=(1<<20);

                            }
                        }



                        ///Далее нужно сделать для Supply_gr1...3
                        ///

                        for(loop_count=1; loop_count<4; loop_count++)
                        {
                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="SupplyGr_"+QString::number(loop_count))
                            {
                                if(((flag&(1<<21)))&&((Buf_Value=="04FF")||(Buf_Value=="02FF")||(Buf_Value=="01FF")))
                                {
                                    flag|=(1<<20);
                                }
                                else if ((flag&(1<<21)))
                                {
                                    TrueValue[num_parameter]="04FF,02FF,01FF";
                                }
                                if((!(flag&(1<<21)))&&((Buf_Value=="06FF")||(Buf_Value=="03FF")||(Buf_Value=="05FF")))
                                {
                                    flag|=(1<<20);

                                }
                                else if (!(flag&(1<<21)))
                                {
                                    TrueValue[num_parameter]="006F,03FF,05FF";
                                }
                            }
                        }









                        for(loop_count=0; loop_count<4; loop_count++)
                        {
                            Buf_Saver=Buffer;

                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti_mass("+QString::number(loop_count)+")")
                            {


                                   flag|=(1<<20);
                                   flag_2|=(1<<1);
                                   flag_2|=(1<<2);

                                    temp_number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                    temp_value=Buf_Value;
                                    TempNomValue=TrueValue[num_parameter];

                                    /*qDebug()<<"temp_number="<<temp_number;
                                    qDebug()<<"temp_value="<<temp_value;*/
                                    //qDebug()<<"internal_counter_3="<<internal_counter_3;

                                    if(!(vect_multpl_feat_ptimass.empty()))
                                    {
                                        if(vect_multpl_feat_ptimass[internal_counter_6-1].number>temp_number)
                                        {
                                            //qDebug()<<"entrance";

                                            temp_number=vect_multpl_feat_ptimass[internal_counter_6-1].number;
                                            temp_value=vect_multpl_feat_ptimass[internal_counter_6-1].value;
                                            TempNomValue=vect_multpl_feat_ptimass[internal_counter_6-1].nominal_value;
                                            vect_multpl_feat_ptimass[internal_counter_6-1].number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                            vect_multpl_feat_ptimass[internal_counter_6-1].value=Buf_Value;
                                            vect_multpl_feat_ptimass[internal_counter_6-1].nominal_value=TrueValue[num_parameter];
                                        }
                                        //qDebug()<<"LLLLLLLLLLLLLLLLLLL!!="<<internal_counter_6<<"size="<<vect_multpl_feat_ptimass.size();
                                        if(((vect_multpl_feat_ptimass[internal_counter_6-1].value==temp_value)&&(vect_multpl_feat_ptimass[internal_counter_6-1].number==temp_number)))
                                        {
                                           // vect_multpl_feat_ptimass.push_back({Buf_Saver.remove(Buffer.lastIndexOf("("), Buffer.count()-1),temp_value, temp_number, TempNomValue});
                                            qDebug()<<"temp_number="<<temp_number;
                                            qDebug()<<"temp_value="<<temp_value;
                                            qDebug()<<"numb_prev="<<vect_multpl_feat_ptimass[internal_counter_6-1].number;
                                            qDebug()<<"value_prev="<<vect_multpl_feat_ptimass[internal_counter_6-1].value;

                                            flag_2|=(1<<4);
                                             qDebug()<<"-----------------------------------------------";
                                        }
                                        else
                                        {
                                            vect_multpl_feat_ptimass.push_back({Buf_Saver.remove(Buffer.lastIndexOf("("), Buffer.count()-1),temp_value, temp_number, TempNomValue});
                                        }

                                        /*qDebug()<<"identf_prev="<<vect_multpl_feat_ptimass[internal_counter_6-1].identificator;
                                        qDebug()<<"numb_prev="<<vect_multpl_feat_ptimass[internal_counter_6-1].number;
                                        qDebug()<<"value_prev="<<vect_multpl_feat_ptimass[internal_counter_6-1].value;
                                        qDebug()<<"nom_value_prev="<<vect_multpl_feat_ptimass[internal_counter_6-1].nominal_value;*/


                                    }
                                    else
                                    {
                                        vect_multpl_feat_ptimass.push_back({Buf_Saver.remove(Buffer.lastIndexOf("("), Buffer.count()-1),temp_value, temp_number, TempNomValue});
                                        qDebug()<<"KKKKKKKKKKK!!";
                                    }

                                    if(!(flag_2&(1<<4)))
                                    {
                                        internal_counter_6++;
                                    }

                                    flag_2&=~(1<<4);

                                   temp_value.clear();

                            }
                           Buf_Saver.clear();
                        }
                        Buf_Saver=Buffer;



                        //qDebug()<<"BUFFER="<<Buffer;
                        if(flag_2&(1<<2))
                        {
                            //qDebug()<<"OPA!";
                        }






                        /*if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti_mass(0)")
                        {
                            flag|=(1<<20);
                        }
                        if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti_mass(3)")
                        {
                            flag|=(1<<20);
                        }*/

                        /*for(loop_count=0; loop_count<4; loop_count++)
                        {
                            Buf_Saver=Buffer;

                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti_mass("+QString::number(loop_count)+")")
                            {
                                //if()
                                //{
                                    flag|=(1<<20);
                                   // flag|=(1<<3);
                                    //TrueValue[num_parameter]="1,2,4,8";
                                //}
                            }

                            Buf_Saver.clear();

                        }*/



                        /*for(loop_count=0; loop_count<4; loop_count++)
                        {
                            Buf_Saver=Buffer;

                             if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti_mass("+QString::number(loop_count)+")")
                             {

                                     flag|=(1<<20);

                             }
                            Buf_Saver.clear();
                        }*/

                       //Работаем с массивами значений

                        /*if(flag_2&(1<<1))
                        {

                                Real_Values_multpl_BVU.push_back(CheckingPar[num_parameter]+QString(" = 0x")+TrueValue[num_parameter]+";");


                        }*/


                        if(((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="config_buk")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="zadacha_k")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pr_sb_mpo")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="ch_otk_ozu")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="ksl_dostd")
                                ||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="schd_gr(0)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="schd_gr(1)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="schd_gr(2)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="schd_gr(3)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="sch_act")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi")
                                ||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_mass(0)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_mass(1)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_mass(2)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_mass(3)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_mass(4)")
                                ||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_mass(5)")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="change")||((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="tir_buk_zap"))//Проверяем параметры БУК
                        {
                            if(((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="config_buk"))
                            {
                                quant_PLCs_BUK=Buf_Value.count("7")+Buf_Value.count("4");//Число работающих граней БУК
                                if((Buf_Value[0]=="7")||(Buf_Value[0]=="4"))
                                {
                                    flag|=(1<<24);
                                }
                                else
                                {
                                    flag&=~(1<<24);
                                }
                                if((Buf_Value[1]=="7")||(Buf_Value[1]=="4"))
                                {
                                    flag|=(1<<25);
                                }
                                else
                                {
                                    flag&=~(1<<25);
                                }
                                if((Buf_Value[2]=="7")||(Buf_Value[2]=="4"))
                                {
                                    flag|=(1<<26);
                                }
                                else
                                {
                                    flag&=~(1<<26);
                                }
                                if((Buf_Value[3]=="7")||(Buf_Value[3]=="4"))
                                {
                                    flag|=(1<<27);
                                }
                                else
                                {
                                    flag&=~(1<<27);
                                }


                                flag|=(1<<23);
                            }
                            //qDebug()<<"Num_BUK_PLCs="<<quant_PLCs_BUK;

                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti")
                            {

                                if(((flag&(1<<24)&&(Buf_Value[0]=='F'))||(!(flag&(1<<24))))&&((flag&(1<<25)&&(Buf_Value[1]=='F'))||(!(flag&(1<<25))))&&((flag&(1<<26)&&(Buf_Value[2]=='F'))||(!(flag&(1<<26))))&&((flag&(1<<27)&&(Buf_Value[3]=='F'))||(!(flag&(1<<27)))))
                                {
                                    flag|=(1<<28);
                                }
                            }


                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="change")
                            {
                                if(Buf_Value.toInt()<15)
                                {
                                    flag|=(1<<28);

                                }
                                else
                                {
                                    TrueValue[num_parameter]="0-15";
                                    flag|=(1<<29);

                                }
                            }


                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi")
                            {
                                if((quant_PLCs_BUK==1)&&((Buf_Value=="0001")||(Buf_Value=="0002")||(Buf_Value=="0004")||(Buf_Value=="0008")))
                                {
                                    flag|=(1<<28);
                                    //TrueValue[num_parameter]="1,2,4,8";
                                }
                                else if((quant_PLCs_BUK==3)&&((Buf_Value=="0007")||(Buf_Value=="000B")||(Buf_Value=="000D")||(Buf_Value=="000E")))
                                {
                                    flag|=(1<<28);
                                    //TrueValue[num_parameter]="7,B,D,E";
                                }
                                else if((quant_PLCs_BUK==2)&&((Buf_Value=="0003")||(Buf_Value=="0005")||(Buf_Value=="0006")||(Buf_Value=="0009")||(Buf_Value=="000A")||(Buf_Value=="000C")))
                                {
                                    flag|=(1<<28);
                                    //TrueValue[num_parameter]="3,5,6,9,A,C";
                                }
                                else if(quant_PLCs_BUK==1)
                                {






                                    TrueValue[num_parameter]="1,2,4,8";
                                    flag|=(1<<29);
                                }
                                else if(quant_PLCs_BUK==2)
                                {

                                    TrueValue[num_parameter]="3,5,6,9,A,C";
                                    flag|=(1<<29);
                                }
                                else if(quant_PLCs_BUK==3)
                                {

                                    TrueValue[num_parameter]="7,B,D,E";
                                    flag|=(1<<29);
                                }
                            }

                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="ksl_dostd")
                            {
                                if((Buf_Value[3]=="6")||(Buf_Value[3]=="7"))
                                {
                                    flag|=(1<<28);

                                }
                                else
                                {
                                    flag|=(1<<29);

                                }
                            }


                            //qDebug()<<


                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="sch_act")
                            {
                                if((quant_PLCs_BUK==1)&&((Buf_Value=="0001")||(Buf_Value=="0002")||(Buf_Value=="0004")||(Buf_Value=="0008")))
                                {
                                    flag|=(1<<28);
                                    //TrueValue[num_parameter]="1,2,4,8";
                                }
                                else if((quant_PLCs_BUK==3)&&((Buf_Value=="0007")||(Buf_Value=="000B")||(Buf_Value=="000D")||(Buf_Value=="000E")))
                                {
                                    flag|=(1<<28);
                                    //TrueValue[num_parameter]="7,B,D,E";
                                }
                                else if((quant_PLCs_BUK==2)&&((Buf_Value=="0003")||(Buf_Value=="0005")||(Buf_Value=="0006")||(Buf_Value=="0009")||(Buf_Value=="000A")||(Buf_Value=="000C")))
                                {
                                    flag|=(1<<28);
                                    //TrueValue[num_parameter]="3,5,6,9,A,C";
                                }
                                else if(quant_PLCs_BUK==1)
                                {

                                    TrueValue[num_parameter]="1,2,4,8";
                                    flag|=(1<<29);
                                }
                                else if(quant_PLCs_BUK==2)
                                {

                                    TrueValue[num_parameter]="3,5,6,9,A,C";
                                    flag|=(1<<29);
                                }
                                else if(quant_PLCs_BUK==3)
                                {

                                    TrueValue[num_parameter]="7,B,D,E";
                                    flag|=(1<<29);
                                }
                            }

                            for(loop_count=0; loop_count<6; loop_count++)
                            {
                                Buf_Saver=Buffer;

                                if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pfi_mass("+QString::number(loop_count)+")")
                                {
                                    if((quant_PLCs_BUK==1)&&((Buf_Value=="0001")||(Buf_Value=="0002")||(Buf_Value=="0004")||(Buf_Value=="0008")))
                                    {
                                        flag|=(1<<28);
                                       // flag|=(1<<3);
                                        //TrueValue[num_parameter]="1,2,4,8";
                                    }
                                    else if((quant_PLCs_BUK==3)&&((Buf_Value=="0007")||(Buf_Value=="000B")||(Buf_Value=="000D")||(Buf_Value=="000E")))
                                    {
                                        flag|=(1<<28);
                                        //flag|=(1<<3);
                                        //TrueValue[num_parameter]="7,B,D,E";
                                    }
                                    else if((quant_PLCs_BUK==2)&&((Buf_Value=="0003")||(Buf_Value=="0005")||(Buf_Value=="0006")||(Buf_Value=="0009")||(Buf_Value=="000A")||(Buf_Value=="000C")))
                                    {
                                        flag|=(1<<28);
                                        //flag|=(1<<3);
                                        //TrueValue[num_parameter]="3,5,6,9,A,C";
                                    }
                                    else if(quant_PLCs_BUK==1)
                                    {

                                        TrueValue[num_parameter]="1,2,4,8";


                                        flag_2|=(1<<3);

                                        flag|=(1<<29);
                                    }
                                    else if(quant_PLCs_BUK==2)
                                    {

                                        TrueValue[num_parameter]="3,5,6,9,A,C";
                                        flag_2|=(1<<3);

                                        flag|=(1<<29);
                                    }
                                    else if(quant_PLCs_BUK==3)
                                    {

                                        TrueValue[num_parameter]="7,B,D,E";

                                        flag_2|=(1<<3);

                                        flag|=(1<<29);
                                    }
                                    if(flag_2&(1<<3))
                                    {




                                        flag_2|=(1<<1);
                                        flag_2|=(1<<2);
                                        flag|=(1<<28);



                                         temp_number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                         temp_value=Buf_Value;
                                         TempNomValue=TrueValue[num_parameter];


                                         //qDebug()<<"---------------BUUUUUUUUUUUUUUUUUUK---------------";

                                         //qDebug()<<"temp_number="<<temp_number;
                                         //qDebug()<<"temp_value="<<temp_value;
                                         //qDebug()<<"internal_counter_4="<<internal_counter_4;

                                         if(!(vect_multpl_feat_pfimass.empty()))
                                         {

                                             if(vect_multpl_feat_pfimass[internal_counter_4-1].number>temp_number)
                                             {
                                                 //qDebug()<<"entrance";
                                                 temp_number=vect_multpl_feat_pfimass[internal_counter_4-1].number;
                                                 temp_value=vect_multpl_feat_pfimass[internal_counter_4-1].value;
                                                 TempNomValue=vect_multpl_feat_pfimass[internal_counter_4-1].nominal_value;
                                                 vect_multpl_feat_pfimass[internal_counter_4-1].number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                                 vect_multpl_feat_pfimass[internal_counter_4-1].value=Buf_Value;
                                                 vect_multpl_feat_pfimass[internal_counter_4-1].nominal_value=TrueValue[num_parameter];

                                             }


                                         }

                                         vect_multpl_feat_pfimass.push_back({Buf_Saver.remove(Buffer.lastIndexOf("("), Buffer.count()-1),temp_value, temp_number, TempNomValue});


                                         //qDebug()<<"identf="<<vect_multpl_feat_pfimass[internal_counter_4].identificator;
                                         //qDebug()<<"numb="<<vect_multpl_feat_pfimass[internal_counter_4].number;
                                         //qDebug()<<"value="<<vect_multpl_feat_pfimass[internal_counter_4].value;
                                         //qDebug()<<"nom_value="<<vect_multpl_feat_pfimass[internal_counter_4].nominal_value;

                                        internal_counter_4++;
                                        temp_value.clear();
                                        //flag_2&=~(1<<3);

                                    }
                                }
                               Buf_Saver.clear();
                            }


                            for(loop_count=0; loop_count<4; loop_count++)
                            {
                                Buf_Saver=Buffer;

                                if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="schd_gr("+QString::number(loop_count)+")")
                                {
                                    if(Buf_Value.toInt()<=QString("00FF").toInt())
                                    {
                                        flag|=(1<<28);

                                    }
                                    else
                                    {

                                        if(flag_2&(1<<3))
                                        {


                                            flag_2|=(1<<1);
                                            flag_2|=(1<<2);
                                            flag|=(1<<28);

                                             temp_number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                             temp_value=Buf_Value;
                                             TempNomValue=TrueValue[num_parameter];


                                             //qDebug()<<"---------------BUUUUUUUUUUUUUUUUUUK---------------";

                                             //qDebug()<<"temp_number="<<temp_number;
                                             //qDebug()<<"temp_value="<<temp_value;
                                             //qDebug()<<"internal_counter_4="<<internal_counter_5;

                                             if(!(vect_multpl_feat_schd.empty()))
                                             {

                                                 if(vect_multpl_feat_schd[internal_counter_5-1].number>temp_number)
                                                 {
                                                     //qDebug()<<"entrance";
                                                     temp_number=vect_multpl_feat_schd[internal_counter_5-1].number;
                                                     temp_value=vect_multpl_feat_schd[internal_counter_5-1].value;
                                                     TempNomValue=vect_multpl_feat_schd[internal_counter_5-1].nominal_value;
                                                     vect_multpl_feat_schd[internal_counter_5-1].number=QString(Buffer[Buffer.lastIndexOf(")")-1]).toInt();
                                                     vect_multpl_feat_schd[internal_counter_5-1].value=Buf_Value;
                                                     vect_multpl_feat_schd[internal_counter_5-1].nominal_value=TrueValue[num_parameter];

                                                 }


                                             }

                                             vect_multpl_feat_schd.push_back({Buf_Saver.remove(Buffer.lastIndexOf("("), Buffer.count()-1),temp_value, temp_number, TempNomValue});


                                             //qDebug()<<"identf="<<vect_multpl_feat_schd[internal_counter_5].identificator;
                                             //qDebug()<<"numb="<<vect_multpl_feat_schd[internal_counter_5].number;
                                             //qDebug()<<"value="<<vect_multpl_feat_schd[internal_counter_5].value;
                                             //qDebug()<<"nom_value="<<vect_multpl_feat_schd[internal_counter_5].nominal_value;

                                            internal_counter_5++;
                                            temp_value.clear();
                                            //flag_2&=~(1<<3);

                                        }


                                    }
                                }
                               Buf_Saver.clear();
                            }


                            if((!(RealValues_BUK.contains(Buffer)))&&(!(flag&(1<<23)))&&(!(flag&(1<<28))))
                            {
                                //qDebug()<<"--------------------------------------------------------";
                                if(!(flag&(1<<29)))
                                {

                                    WrongFeatures_BUK.append(CheckingPar[num_parameter]+QString(" = 0x")+TrueValue[num_parameter]+";");
                                    //qDebug()<<"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKOUT="<<CheckingPar[num_parameter]+QString(" = ")+TrueValue[num_parameter]+";";
                                }
                                else
                                {
                                    WrongFeatures_BUK.append(CheckingPar[num_parameter]+QString(" = ")+TrueValue[num_parameter]+";");
                                    //qDebug()<<"KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKOUT="<<CheckingPar[num_parameter]+QString(" = ")+TrueValue[num_parameter]+";";
                                    flag&=~(1<<29);
                                }


                                RealValues_BUK.append(Buffer+";");
                            }


                            flag|=(1<<20);
                            flag&=~(1<<23);
                            flag&=~(1<<28);
                        }



                        /*for(loop_count=0; loop_count<4; loop_count++)
                        {
                            Buf_Saver=Buffer;

                            if((Buf_Saver.remove(Buffer.lastIndexOf("=")-1, Buffer.count()-1))=="pti_mass("+QString::number(loop_count)+")")
                            {
                                if(Buf_Value.toInt()<=TrueValue[num_parameter].toInt())
                                {
                                    flag|=(1<<20);

                                }
                            }
                           Buf_Saver.clear();
                        }*/


                       Buf_Saver.clear();

                        if((!(flag&(1<<20)))&(!(flag_2&(1<<9))))
                        {

                            if(!(flag&(1<<22)))
                            {
                                WrongFeatures.append("?");

                                flag|=(1<<22);

                            }

                        /*if(flag&(1<<30))
                        {*/
                            if(!(flag_2&(1<<1)))
                            {
                                WrongFeatures.append(CheckingPar[num_parameter]+QString(" = 0x")+TrueValue[num_parameter]+";");
                                RealValues.append(Buffer+";");

                            }
                           // flag_2&=~(1<<1);

                        //}


                        /*if(quant_of_symb_in_Tel_file_norm<6)
                        {
                             WrongFeatures.append(WrongFeatures_BUK);
                             RealValues.append(RealValues_BUK);
                             qDebug()<<"JJJJJJJJJJJJ!!!!!!!!!";
                             WrongFeatures_BUK.clear();
                             RealValues.clear();
                        }*/

                        }
                        flag_2&=~(1<<1);

                    flag&=~(1<<20);

                    flag_2&=~(1<<9);

                    Buf_Saver.clear();


                    }
                    internal_counter_2=0;

                }

            }


            num_parameter++;



            //flag&=~(1<<20);
            //Buffer.clear();
            Buf_Value.clear();

        }



        num_parameter=0;
        Buffer.clear();


        //qDebug()<<quant_of_symb_in_Tel_file_norm;


    }



    vect_multpl_feat_output.push_back(vect_multpl_feat_schgr);
    vect_multpl_feat_output.push_back(vect_multpl_feat_ptimass);
    num_vect_mult_feature=0;

    qDebug()<<"SIZE="<<vect_multpl_feat_output.size();

    if(flag_2&(1<<2))
    {


        //qDebug()<<"IDENT="<<vect_multpl_feat_schgr[internal_counter_3].number;
        //qDebug()<<"IDENT="<<;

        while(num_vect_mult_feature!=vect_multpl_feat_output.size())
        {

            internal_counter_3=0;

            while(internal_counter_3!=vect_multpl_feat_output[num_vect_mult_feature].size())
            {
                //qDebug()<<"internal_counter_3="<<internal_counter_3;
                if(!RealValues.contains(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = ")+"0x"+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].value+";"))
                {
                    WrongFeatures.append(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = ")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].nominal_value+";");
                    RealValues.append(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = 0x")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].value+";");
                    qDebug()<<"WrFEAT="<<vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = ")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].value+";";
                    /*qDebug()<<"RealVALUE="<<vect_multpl_feat_schgr[internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_schgr[vect_multpl_feat_output][internal_counter_3].number)+")"+QString(" = 0x")+vect_multpl_feat_schgr[vect_multpl_feat_output][internal_counter_3].value+";";
                    qDebug()<<"VQALUE="<<vect_multpl_feat_schgr[internal_counter_3].value+";";*/
                }
                else
                {


                    qDebug()<<"HHHHHHH";
                }

                internal_counter_3++;
            }

            num_vect_mult_feature++;

        }

    }
    num_vect_mult_feature=0;

    if(flag&(1<<30))
    {
        WrongFeatures.append("|");
        WrongFeatures.append(WrongFeatures_BUK);
        RealValues.append(RealValues_BUK);
    }
    vect_multpl_feat_output.clear();
    //internal_counter_3=0;

    vect_multpl_feat_output.push_back(vect_multpl_feat_pfimass);
    vect_multpl_feat_output.push_back(vect_multpl_feat_schd);

    while(num_vect_mult_feature!=vect_multpl_feat_output.size())
    {


        internal_counter_3=0;



        while(internal_counter_3!=vect_multpl_feat_output[num_vect_mult_feature].size())
        {
            if(!WrongFeatures.contains(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = ")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].nominal_value+";"))
            {
                //qDebug()<<"IDENTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT";
                WrongFeatures.append(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = ")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].nominal_value+";");
                RealValues.append(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = 0x")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].value+";");
                //qDebug()<<"WrFEAT="<<vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = ")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].nominal_value+";";
                //qDebug()<<"RealVALUE="<<vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].identificator+QString("(")+QString::number(vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].number)+")"+QString(" = 0x")+vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].value+";";
                //qDebug()<<"VQALUE="<<vect_multpl_feat_output[num_vect_mult_feature][internal_counter_3].value+";";
            }


            internal_counter_3++;
        }




        num_vect_mult_feature++;

    }


    /*qDebug()<<"Wrong_Features_multpl_BVU="<<Wrong_Features_multpl_BVU;
    qDebug()<<"Real_Values_multpl_BVU="<<Real_Values_multpl_BVU;*/



    //qDebug()<<"LLLLKKKF";



}
/*void Analys_changing_values(void)
{
    int num_symbol_trueValue=0;
    int num_symbol_checkPar=0;
    int num_parameter=0;
    int internal_counter_2=0;
    QDebug deb = qDebug();


    //int quant_of_symb_in_Tel_file=0;

    QString Res_Buffer;
    QString Buf_true_value;

    Quant_Of_Symbl_In_File();

    qDebug()<<"second case"<<quant_of_symb_in_Tel_file_norm;


    while(quant_of_symb_in_Tel_file_norm)
    {
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file_norm--;





        ///Проверяем символ на совпадение с символом из имени параметров:
        while(num_parameter!=CheckingPar.size())
        {
            if((symbol==CheckingPar[num_parameter][num_symbol_checkPar])&&(flag&(1<<21)))
            {
                //qDebug()<<"num_symbol_checkPar="<<num_symbol_checkPar;
                while((((symbol==CheckingPar[num_parameter][num_symbol_checkPar])&&(num_symbol_checkPar!=CheckingPar[num_parameter].count()))||(symbol=='=')||(symbol==' ')||((symbol=='0')&&(Buffer[Buffer.count()-1]==' '))||(symbol=='x'))&&(!(flag&(1<<20))))
                {
                   //qDebug()<<symbol;
                    //deb<<symbol;
                   Buffer.append(symbol);

                   deb<<symbol;


                   if(symbol=='=')
                   {
                       internal_counter_2++;
                       //deb<<Buffer;
                       //qDebug()<<"RRRRR!!!!!";
                   }
                   if((symbol==' ')&&(internal_counter_2==1))
                   {
                       internal_counter_2++;
                       //deb<<Buffer;
                       //qDebug()<<"BBBBBB!!!!!";
                   }
                   if((symbol=='0')&&(internal_counter_2==2))
                   {
                       internal_counter_2++;
                       //qDebug()<<"CCCCCCC!!!!!";
                   }
                   //Убираем трабл с pfi_reg
                   if((symbol=='x')&&(internal_counter_2==3))
                   {
                       internal_counter_2++;
                       flag|=(1<<20);

                       //qDebug()<<"CCCCCCC!!!!!";
                   }
                   num_symbol_checkPar++;

                   symbol=(fgetc(file));
                   quant_of_symb_in_Tel_file_norm--;
                }




                if(internal_counter_2<4)
                {
                    //qDebug()<<"1";
                    //Если не нашли информативный признак (со значением), то всё обнуляем
                    num_symbol_trueValue=0;
                    num_symbol_checkPar=0;
                    num_parameter=0;
                    internal_counter_2=0;
                    flag&=~(1<<20);

                    ///сбрось 20 флаг здесь

                    Buffer.clear();

                }
                else
                {

                    //qDebug()<<"1";
                    while(symbol!=' ')
                    {
                        //qDebug()<<"num_symbol_trueValue="<<num_symbol_trueValue;

                        //qDebug()<<"CCCCCCC!!!!!";
                        if((QString(symbol)!=TrueValue[num_parameter][num_symbol_trueValue])&&(symbol!='x'))
                        {
                            flag|=(1<<22);

                        }


                        Buffer.append(symbol);

                        if(symbol!='x')
                        {
                            num_symbol_trueValue++;

                        }



                        symbol=(fgetc(file));
                        quant_of_symb_in_Tel_file_norm--;





                    }
                    if(flag&(1<<22))
                    {
                        if(!Res_Buffer.contains(Buffer))
                        {
                           Buf_Right_value.append(CheckingPar[num_parameter]+QString(" = 0x")+TrueValue[num_parameter]);
                           WrongFeatures.append(CheckingPar[num_parameter]+QString(" = 0x")+TrueValue[num_parameter]+";");

                           Res_Buffer.append(Buffer);
                           RealValues.append(Buffer+";");
                        }


                    }

                    ///qDebug()<<"Wrong="<<WrongFeatures;//номинальные
                    ///qDebug()<<"Real="<<RealValues;//реально по ТМИ

                    flag&=~(1<<20);
                    flag&=~(1<<22);


                    Buffer.clear();

                }

            }



            internal_counter_2=0;
            num_symbol_checkPar=0;
            num_symbol_trueValue=0;




            num_parameter++;
        }
        if(symbol==' ')
        {
           flag|=(1<<21);
        }
        else
        {
            flag&=~(1<<21);

        }

        num_symbol_trueValue=0;
        num_symbol_checkPar=0;
        num_parameter=0;
        internal_counter_2=0;
    }



}*/


/*void Analys_changing_values(void)
{
    int num_symbol_trueValue=0;
    int num_symbol_checkPar=0;
    int num_parameter=0;
    int internal_counter_2=0;
    //int internal_counter_3=0;
    int internal_counter_4=0;
    int count_file=0;

    //char *mas_file=NULL;
    vector <char> vect_mas_file;

    //int quant_of_symb_in_Tel_file=0;
    QString Buffer;
    QString Res_Buffer;
    QString Buf_true_value;
    QString Buf_Right_value;
    Quant_Of_Symbl_In_File();




     symbol=(fgetc(file));
     quant_of_symb_in_Tel_file_norm--;
     count_file++;
    while(quant_of_symb_in_Tel_file_norm!=0)
    {
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file_norm--;
        count_file++;
        vect_mas_file.push_back(symbol);
    }
    //qDebug()<<vect_mas_file;

    while(internal_counter_4!=count_file)
    {

        //symbol=(fgetc(file));
        //internal_counter_4++;

        //qDebug() << symbol;

        //&&(flag&(1<<21))
        //qDebug()<<"hkjh";
        if((vect_mas_file[internal_counter_4]==CheckingPar[num_parameter][num_symbol_checkPar])&&(flag&(1<<21)))
        {
            //flag&=~(1<<21);
            //qDebug()<<"AA";


            while((((vect_mas_file[internal_counter_4]==CheckingPar[num_parameter][num_symbol_checkPar])&&(num_symbol_checkPar!=CheckingPar[num_parameter].count()))||(symbol=='=')||(symbol==' ')||(symbol=='0')||(symbol=='x'))&&(~flag&(1<<20)))
            {
                //qDebug()<<"hkjh";
               qDebug()<<symbol;
                //deb<<symbol;
               Buffer.append(vect_mas_file[internal_counter_4]);
               num_symbol_checkPar++;

               //symbol=(fgetc(file));
              // internal_counter_4++;
               if(vect_mas_file[internal_counter_4]=='=')
               {
                   internal_counter_2++;
                   qDebug()<<"RRRRR!!!!!";
               }
               if((vect_mas_file[internal_counter_4]==' ')&&(internal_counter_2==1))
               {
                   internal_counter_2++;
                   //qDebug()<<"BBBBBB!!!!!";
               }
               if((vect_mas_file[internal_counter_4]=='0')&&(internal_counter_2==2))
               {
                   internal_counter_2++;
                   qDebug()<<"CCCCCCC!!!!!";
               }
               //Убираем трабл с pfi_reg
               if((vect_mas_file[internal_counter_4]=='x')&&(internal_counter_2==3))
               {
                   internal_counter_2++;
                   flag|=(1<<20);
                   qDebug()<<"CCCCCCC!!!!!";
               }
               internal_counter_4++;
            }


            if(internal_counter_2<4)
            {
                //qDebug()<<"1";
                num_symbol_trueValue=0;
                num_symbol_checkPar=0;
                num_parameter=0;
                internal_counter_2=0;

                Buffer.clear();

            }
            else
            {
                //qDebug()<<"1";
                while(vect_mas_file[internal_counter_4]!=' ')
                {
                    qDebug()<<"CCCCCCC!!!!!";
                    if(vect_mas_file[internal_counter_4]!=TrueValue[num_parameter][num_symbol_trueValue])
                    {
                        flag|=(1<<20);
                    }


                    Buffer.append(symbol);


                    //symbol=(fgetc(file));
                    internal_counter_4++;
                }
                if(flag&(1<<20))
                {
                   Buf_Right_value.append(CheckingPar+QString(" = ")+TrueValue[num_parameter]);
                   flag&=~(1<<20);
                }

                qDebug()<<Buf_Right_value;

                //qDebug()<<"Buf="<<Buffer;
                Buffer.clear();

            }


        }

        if(vect_mas_file[internal_counter_4]==' ')
        {
           flag|=(1<<21);
        }
        else
        {
            flag&=~(1<<21);

        }

        num_symbol_trueValue=0;
        num_symbol_checkPar=0;
        num_parameter=0;
        internal_counter_2=0;
        internal_counter_4++;
    }
    qDebug()<<"11111111:"<<Res_Buffer;
}*/





void Quant_Of_Symbl_In_File(void)
{


    quant_of_symb_in_Tel_file_norm=0;
    fseek(file, 0, SEEK_SET);


    symbol=(fgetc(file));
    while(fgetc(file)!=EOF)
    {
        quant_of_symb_in_Tel_file_norm++;
    }
    quant_of_symb_in_Tel_file_norm++;
    fseek(file, 0, SEEK_SET);
}
void Test_Rtvk_Vkl(void)
{
    int internal_counter=0;
    int internal_counter_3=0;
    //int quant_of_symb_in_Tel_file=0;
    QString Buffer;
    QDebug deb=qDebug();
    fseek(file, 0, SEEK_SET);

    Test_Rtvk_Init();//Инициализация значений массива rtvk




    /////////////////////////////////////////////////////////////


    if((flag&(1<<30)))
    {
        Nominal_features="rtvk_vkl(00) = 0x0001";
    }
    else
    {
        Nominal_features="rtvk_vkl(00) = 0x0003";
    }






    Test_Rtvk_Vkl_Mov_Point_to_Pos();




    while(internal_counter_3!=Nominal_rtvk_vkl.size())
    {
        //quant_of_symb_in_Tel_file=quant_of_symb_in_Tel_file_norm;
        Nominal_features=Nominal_rtvk_vkl[internal_counter_3];
        Test_of_others_features();
        if(!Nominal_features.isEmpty()&&(!(flag&(1<<18)))&&(!(flag&(1<<30))))
        {
            if(internal_counter_3<18)
            {
                WrongFeatures.append(":3:");
                //RealValues.append(":3:");

            }
            if((18<=internal_counter_3)&&(internal_counter_3<45))
            {
                WrongFeatures.append(":4:");
                //RealValues.append(":4:");

            }
            if((45<=internal_counter_3)&&(internal_counter_3<72))
            {
                WrongFeatures.append(":5:");
                //RealValues.append(":5:");
            }

            flag|=(1<<18);
        }
        if(!Nominal_features.isEmpty()&&(!(flag&(1<<18)))&&(flag&(1<<30)))
        {
            if(internal_counter_3<27)
            {
                WrongFeatures.append(":1:");
                //RealValues.append(":3:");

            }
            if((28<=internal_counter_3)&&(internal_counter_3<54))
            {
                WrongFeatures.append(":2:");
                //RealValues.append(":4:");

            }
            if((54<=internal_counter_3)&&(internal_counter_3<81))
            {
                WrongFeatures.append(":3:");
                //RealValues.append(":5:");
            }
            if((81<=internal_counter_3)&&(internal_counter_3<108))
            {
                WrongFeatures.append(":4:");
                //RealValues.append(":5:");
            }
            if((108<=internal_counter_3)&&(internal_counter_3<135))
            {
                WrongFeatures.append(":5:");
                //RealValues.append(":5:");
            }

            flag|=(1<<18);
        }


        if(Nominal_features.isEmpty()&&((internal_counter_3==16)||(internal_counter_3==43))&&(!(flag&(1<<30))))
        {
            flag&=~(1<<18);
        }
        if(/*Nominal_features.isEmpty()||*/((internal_counter_3==26)||(internal_counter_3==53)||(internal_counter_3==80)||(internal_counter_3==107)||(internal_counter_3==134))&&(flag&(1<<30)))
                {
                    flag&=~(1<<18);
                }
        WrongFeatures.append(Nominal_features);
        if(!Nominal_features.isEmpty())
        {
            WrongFeatures.append(";");
        }
        internal_counter_3++;
    }


}



/*void Test_Rtvk_Vkl(void)
{
    int internal_counter=1;

    //int quant_of_symb_in_Tel_file=0;
    QString Buffer;
    QDebug deb=qDebug();
    fseek(file, 0, SEEK_SET);

    Test_Rtvk_Init();//Инициализация значений массива rtvk

    while(count_quant_mas!=4)
    {
        Nominal_features="rtvk_vkl(00) = 0x";
        //Выясняем, что в шапке

        Test_Rtvk_Vkl_Mov_Point_to_Pos();
        Explore_rtvk_mas();

        while(internal_counter!=28)
        {
            cur_kadr=number_mas[0]-1;
            Check_rtvk_vkl_value(internal_counter);
            qDebug()<<"cur_kadr11="<<cur_kadr;
            if(quant_mas==2)
            {
                cur_kadr=number_mas[1]-1;
                Check_rtvk_vkl_value(internal_counter);
                qDebug()<<"cur_kadr11="<<cur_kadr;

            }

            internal_counter++;
        }
       // internal_counter=1;
        qDebug()<<"count_quant_mas="<<count_quant_mas;

    }
    qDebug()<<WrongValuesRTVK[0];
    qDebug()<<WrongValuesRTVK[1];
    qDebug()<<WrongValuesRTVK[2];
    qDebug()<<WrongValuesRTVK[3];
    qDebug()<<WrongValuesRTVK[4];

}*/


/*void Explore_rtvk_mas(void)
{
    QString TempMas;

    while(symbol!=' ')
    {

        TempMas.append(symbol);
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file--;
    }

    number_mas[0]=TempMas.left(4).toInt();
    qDebug()<<"num_mas_0="<<number_mas[0];
    TempMas.clear();
    count_quant_mas++;
    quant_mas=1;

    Nominal_features="rtvk_vkl(";



    Test_Rtvk_Vkl_Mov_Point_to_Pos();

    if(symbol=='0')
    {
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file--;
        if(symbol=='0')
        {
            while(symbol!='x')
            {
                symbol=(fgetc(file));
                quant_of_symb_in_Tel_file--;
            }
            while(symbol!=' ')
            {
                symbol=(fgetc(file));
                quant_of_symb_in_Tel_file--;
                TempMas.append(symbol);
            }
            quant_mas=2;
            count_quant_mas++;
            //qDebug()<<TempMas.left(4);

            number_mas[1]=TempMas.left(4).toInt();
            qDebug()<<"num_mas_1="<<number_mas[1];
            TempMas.clear();

        }
        else
        {
            fseek(file, -20, SEEK_CUR);
        }
    }
    else
    {
        fseek(file, -20, SEEK_CUR);
    }



}*/






void Check_rtvk_vkl_value(int num_of_par)
{
    QString Buffer_value;

    Nominal_features="rtvk_vkl(";

    Test_Rtvk_Vkl_Mov_Point_to_Pos();

    while(symbol!='x')
    {
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file--;
    }

    while(symbol!=' ')
    {
        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file--;
        if(symbol!=' ')
        {
            Buffer_value.append(symbol);

        }

    }

    if(Buffer_value!=Nominal_rtvk_vkl[num_of_par][cur_kadr])
    {
        //qDebug()<<"cur_kadr="<<cur_kadr;
        WrongValuesRTVK[cur_kadr].append(Buffer_value);

        //qDebug()<<"cur_kadr="<<cur_kadr;
        //qDebug()<<"num_of_par="<<num_of_par;

        //qDebug()<<"nominal="<<Nominal_rtvk_vkl[num_of_par][cur_kadr];
        //qDebug()<<"fact="<<Buffer_value;


    }
    Buffer_value.clear();

}



//////////////////////////////////////////////////////////////////









void Test_Rtvk_Vkl_Mov_Point_to_Pos(void)
{
    int internal_counter=0;
    //int internal_counter_2=0;
    //int quant_of_symb_in_Tel_file=0;

    QDebug deb=qDebug();
    //fseek(file, 0, SEEK_SET);




    while(quant_of_symb_in_Tel_file)
    {

        symbol=(fgetc(file));
        quant_of_symb_in_Tel_file--;
        //qDebug() << symbol;
        if(symbol==Nominal_features[internal_counter])
        {
            while((symbol==Nominal_features[internal_counter]))
            {
               //qDebug()<<symbol;
                //deb<<symbol;

               internal_counter++;
               symbol=(fgetc(file));
               quant_of_symb_in_Tel_file--;
            }
            //qDebug() << internal_counter;
            if(Nominal_features.count()==internal_counter)
            {
                //qDebug()<<"ALL RIGHT!HHHHHh";
                Nominal_features.clear();

                break;
            }


            internal_counter=0;
        }
        //internal_counter_2=0;
    }
}

void Test_Rtvk_Init(void)
{
    //qDebug()<<"AAAAAAAAAAAAAAAAAAA!!!!!!";

    if((flag&(1<<30)))
    {


        //qDebug()<<"JJJJJJJJJJJJJJ!!!!!!";

        //1й кадр
        Nominal_rtvk_vkl.push_back("rtvk_vkl(01) = 0xC031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(02) = 0x0031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(03) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(04) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(05) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(06) = 0x00C1");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(07) = 0xF0C0");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(08) = 0xC000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(09) = 0xC031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(10) = 0x0031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(11) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(12) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(13) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(14) = 0x00C5");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(15) = 0xF0C8");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(16) = 0xC000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(17) = 0xC031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(18) = 0x0031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(19) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(20) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(21) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(22) = 0x00C9");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(23) = 0xF0D0");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(24) = 0xC000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(25) = 0xC031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(26) = 0x0031");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(27) = 0x0001");



        //2й кадр
        Nominal_rtvk_vkl.push_back("rtvk_vkl(01) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(02) = 0x0000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(03) = 0x00CD");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(04) = 0xF0D8");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(05) = 0xC000");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(06) = 0x5131");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(07) = 0x3291");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(08) = 0x0404");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(09) = 0x0452");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(10) = 0x9204");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(11) = 0x0404");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(12) = 0x8002");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(13) = 0x0432");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(14) = 0x3104");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(15) = 0xA161");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(16) = 0x6204");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(17) = 0x0404");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(18) = 0x04A2");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(19) = 0x8002");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(20) = 0x5204");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(21) = 0x0404");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(22) = 0x0462");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(23) = 0x6151");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(24) = 0x04C1");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(25) = 0xC204");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(26) = 0x8002");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(27) = 0x0404");

        //3й кадр 1-10 элементы
        Nominal_rtvk_vkl.push_back("rtvk_vkl(01) = 0x0492");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(02) = 0xA204");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(03) = 0x0404");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(04) = 0x91C2");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(05) = 0xC1A1");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(06) = 0x8002");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(07) = 0x070F");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(08) = 0x070F");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(09) = 0x070F");
        Nominal_rtvk_vkl.push_back("rtvk_vkl(10) = 0x070F");

    }

    //3й кадр с 11го элемента
    Nominal_rtvk_vkl.push_back("rtvk_vkl(11) = 0xC031");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(12) = 0x0031");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(13) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(14) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(15) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(16) = 0x00C3");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(17) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(18) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(19) = 0xC031");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(20) = 0x0031");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(21) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(22) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(23) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(24) = 0x00C7");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(25) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(26) = 0x0000");//0000
    Nominal_rtvk_vkl.push_back("rtvk_vkl(27) = 0xC031");//27


    //4й кадр


    Nominal_rtvk_vkl.push_back("rtvk_vkl(01) = 0x0031");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(02) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(03) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(04) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(05) = 0x00CB");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(06) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(07) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(08) = 0xC031");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(09) = 0x0031");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(10) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(11) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(12) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(13) = 0x00CF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(14) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(15) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(16) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(17) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(18) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(19) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(20) = 0xC000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(21) = 0x000F");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(22) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(23) = 0xC000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(24) = 0x000F");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(25) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(26) = 0xC000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(27) = 0x000F");

    //5й кадр


    Nominal_rtvk_vkl.push_back("rtvk_vkl(01) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(02) = 0xC000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(03) = 0x000F");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(04) = 0x00FF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(05) = 0xFFFF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(06) = 0x0001");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(07) = 0x000F");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(08) = 0x5131");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(09) = 0x3291");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(10) = 0xB474");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(11) = 0x7452");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(12) = 0x92D4");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(13) = 0xD4B4");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(14) = 0x1111");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(15) = 0x7777");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(16) = 0xFFFF");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(17) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(18) = 0x000F");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(19) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(20) = 0x0001");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(21) = 0x0100");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(22) = 0x0007");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(23) = 0x2669");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(24) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(25) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(26) = 0x0000");
    Nominal_rtvk_vkl.push_back("rtvk_vkl(27) = 0x0000");

}



/*void Test_Rtvk_Init(void)
{
    //3й кадр с 11го элемента
    Nominal_rtvk_vkl[1]="rtvk_vkl(11) = 0xC031";
    Nominal_rtvk_vkl[2]="rtvk_vkl(12) = 0x0031";
    Nominal_rtvk_vkl[3]="rtvk_vkl(13) = 0x0000";
    Nominal_rtvk_vkl[4]="rtvk_vkl(14) = 0x0000";
    Nominal_rtvk_vkl[5]="rtvk_vkl(15) = 0x0000";
    Nominal_rtvk_vkl[6]="rtvk_vkl(16) = 0x00C3";
    Nominal_rtvk_vkl[7]="rtvk_vkl(17) = 0x00FF";
    Nominal_rtvk_vkl[8]="rtvk_vkl(18) = 0x0000";
    Nominal_rtvk_vkl[9]="rtvk_vkl(19) = 0xC031";
    Nominal_rtvk_vkl[10]="rtvk_vkl(20) = 0x0031";
    Nominal_rtvk_vkl[11]="rtvk_vkl(21) = 0x0000";
    Nominal_rtvk_vkl[12]="rtvk_vkl(22) = 0x0000";
    Nominal_rtvk_vkl[13]="rtvk_vkl(23) = 0x0000";
    Nominal_rtvk_vkl[14]="rtvk_vkl(24) = 0x00C7";
    Nominal_rtvk_vkl[15]="rtvk_vkl(25) = 0x00FF";
    Nominal_rtvk_vkl[16]="rtvk_vkl(26) = 0x0000";
    Nominal_rtvk_vkl[17]="rtvk_vkl(27) = 0xC031";
    //4й кадр
    //Nominal_rtvk_vkl[0]="rtvk_vkl(00) = 0xC031";
    Nominal_rtvk_vkl[18]="rtvk_vkl(01) = 0x0031";
    Nominal_rtvk_vkl[19]="rtvk_vkl(02) = 0x0000";
    Nominal_rtvk_vkl[20]="rtvk_vkl(03) = 0x0000";
    Nominal_rtvk_vkl[21]="rtvk_vkl(04) = 0x0000";
    Nominal_rtvk_vkl[22]="rtvk_vkl(05) = 0x00CB";
    Nominal_rtvk_vkl[23]="rtvk_vkl(06) = 0x00FF";
    Nominal_rtvk_vkl[24]="rtvk_vkl(07) = 0x0000";
    Nominal_rtvk_vkl[25]="rtvk_vkl(08) = 0xC031";
    Nominal_rtvk_vkl[26]="rtvk_vkl(09) = 0x0031";
    Nominal_rtvk_vkl[27]="rtvk_vkl(10) = 0x0000";

    Nominal_rtvk_vkl[28]="rtvk_vkl(11) = 0x0000";
    Nominal_rtvk_vkl[29]="rtvk_vkl(12) = 0x0000";
    Nominal_rtvk_vkl[30]="rtvk_vkl(13) = 0x00CF";
    Nominal_rtvk_vkl[31]="rtvk_vkl(14) = 0x00FF";
    Nominal_rtvk_vkl[32]="rtvk_vkl(15) = 0x0000";
    Nominal_rtvk_vkl[33]="rtvk_vkl(16) = 0x0000";
    Nominal_rtvk_vkl[34]="rtvk_vkl(17) = 0x0000";
    Nominal_rtvk_vkl[35]="rtvk_vkl(18) = 0x0000";
    Nominal_rtvk_vkl[36]="rtvk_vkl(19) = 0x0000";
    Nominal_rtvk_vkl[37]="rtvk_vkl(20) = 0xC000";
    Nominal_rtvk_vkl[38]="rtvk_vkl(21) = 0x000F";
    Nominal_rtvk_vkl[39]="rtvk_vkl(22) = 0x00FF";
    Nominal_rtvk_vkl[40]="rtvk_vkl(23) = 0xC000";
    Nominal_rtvk_vkl[41]="rtvk_vkl(24) = 0x000F";
    Nominal_rtvk_vkl[42]="rtvk_vkl(25) = 0x00FF";
    Nominal_rtvk_vkl[43]="rtvk_vkl(26) = 0xC000";
    Nominal_rtvk_vkl[44]="rtvk_vkl(27) = 0x000F";

    //5й кадр

    //Nominal_rtvk_vkl[0]="rtvk_vkl(00) = 0xC031";
    Nominal_rtvk_vkl[45]="rtvk_vkl(01) = 0x00FF";
    Nominal_rtvk_vkl[46]="rtvk_vkl(02) = 0xC000";
    Nominal_rtvk_vkl[47]="rtvk_vkl(03) = 0x000F";
    Nominal_rtvk_vkl[48]="rtvk_vkl(04) = 0x00FF";
    Nominal_rtvk_vkl[49]="rtvk_vkl(05) = 0xFFFF";
    Nominal_rtvk_vkl[50]="rtvk_vkl(06) = 0x0001";
    Nominal_rtvk_vkl[51]="rtvk_vkl(07) = 0x000F";
    Nominal_rtvk_vkl[52]="rtvk_vkl(08) = 0x5131";
    Nominal_rtvk_vkl[53]="rtvk_vkl(09) = 0x3291";
    Nominal_rtvk_vkl[54]="rtvk_vkl(10) = 0xB474";

    Nominal_rtvk_vkl[55]="rtvk_vkl(11) = 0x7452";
    Nominal_rtvk_vkl[56]="rtvk_vkl(12) = 0x92D4";
    Nominal_rtvk_vkl[57]="rtvk_vkl(13) = 0xD4B4";
    Nominal_rtvk_vkl[58]="rtvk_vkl(14) = 0x1111";
    Nominal_rtvk_vkl[59]="rtvk_vkl(15) = 0x7777";
    Nominal_rtvk_vkl[60]="rtvk_vkl(16) = 0xFFFF";
    Nominal_rtvk_vkl[61]="rtvk_vkl(17) = 0x0000";
    Nominal_rtvk_vkl[62]="rtvk_vkl(18) = 0x000F";
    Nominal_rtvk_vkl[63]="rtvk_vkl(19) = 0x0000";
    Nominal_rtvk_vkl[64]="rtvk_vkl(20) = 0x0001";
    Nominal_rtvk_vkl[65]="rtvk_vkl(21) = 0x0100";
    Nominal_rtvk_vkl[66]="rtvk_vkl(22) = 0x0007";
    Nominal_rtvk_vkl[67]="rtvk_vkl(23) = 0x2669";
    Nominal_rtvk_vkl[68]="rtvk_vkl(24) = 0x0001";
    Nominal_rtvk_vkl[69]="rtvk_vkl(25) = 0x0000";
    Nominal_rtvk_vkl[70]="rtvk_vkl(26) = 0x0000";
    Nominal_rtvk_vkl[71]="rtvk_vkl(27) = 0x0000";
}*/


void Init_Normative_values(void)
{

    //Номинальные значения признаков

    Mas_Nominal_features.push_back("config_vs = 0x2669");
    Mas_Nominal_features.push_back("prpvv1 = 0x0001");
    Mas_Nominal_features.push_back("supplyd = 0x0007");
    Mas_Nominal_features.push_back("ss_bcvs = 0xFFFF");
    Mas_Nominal_features.push_back("vkl_gr = 0x0007");
    Mas_Nominal_features.push_back("pfi_reg = 0x0007");
    Mas_Nominal_features.push_back("pti_mass(0) = 0x00FF");
    Mas_Nominal_features.push_back("pti_mass(1) = 0x00FF");
    Mas_Nominal_features.push_back("pti_mass(2) = 0x00FF");
    Mas_Nominal_features.push_back("pti_mass(3) = 0x0000");
    Mas_Nominal_features.push_back("mpo_mas_ks_err = 0x0000");




    /*Mas_Nominal_features[0]="config_vs = 0x2669";
    Mas_Nominal_features[1]="prpvv1 = 0x0001";
    Mas_Nominal_features[2]="supplyd = 0x0007";
    Mas_Nominal_features[3]="ss_bcvs = 0xFFFF";
    Mas_Nominal_features[4]="vkl_gr = 0x0008";
    Mas_Nominal_features[5]="pfi_reg = 0x0007";
    Mas_Nominal_features[6]="pti_mass(0) = 0x00FF";
    Mas_Nominal_features[7]="pti_mass(1) = 0x00FF";
    Mas_Nominal_features[8]="pti_mass(2) = 0x00FF";
    Mas_Nominal_features[9]="pti_mass(3) = 0x0000";
    Mas_Nominal_features[10]="mpo_mas_ks_err = 0x0000";*/

    /*CheckingPar.push_back("config_vs");
    TrueValue.push_back("0004");*/


    CheckingPar.push_back("config_vs");
    TrueValue.push_back("0000");
    CheckingPar.push_back("pr_tir");
    TrueValue.push_back("0000");
    CheckingPar.push_back("zadacha");
    TrueValue.push_back("FFFF");
    CheckingPar.push_back("rtvk_mko1(2)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("rtvk_mko1(0)");
    TrueValue.push_back("C031");
    CheckingPar.push_back("zap_vikl");
    TrueValue.push_back("0000");
    CheckingPar.push_back("rtvk_mko1(1)");
    TrueValue.push_back("0031");
    CheckingPar.push_back("rtvk_mko1(3)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("rtvk_mko1(3)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("otk_reconf");
    TrueValue.push_back("0000");
    CheckingPar.push_back("pr_otk_mpo");
    TrueValue.push_back("0000");
    CheckingPar.push_back("sch_gr(0)");
    TrueValue.push_back("0x0-FF");
    CheckingPar.push_back("sch_gr(1)");
    TrueValue.push_back("0x0-FF");
    CheckingPar.push_back("sch_gr(2)");
    TrueValue.push_back("0x0-FF");
    CheckingPar.push_back("sch_gr(3)");
    TrueValue.push_back("0x0-FF");
    CheckingPar.push_back("shift_kontr");
    TrueValue.push_back("0->F");
    CheckingPar.push_back("otk_pti");
    TrueValue.push_back("0->F");
    CheckingPar.push_back("pfi_reg");
    TrueValue.push_back("0000");
    CheckingPar.push_back("zp_reconf");
    TrueValue.push_back("0000");
    CheckingPar.push_back("pti_mass(0)");
    TrueValue.push_back("00FF");
    CheckingPar.push_back("pti_mass(1)");
    TrueValue.push_back("00FF");
    CheckingPar.push_back("pti_mass(2)");
    TrueValue.push_back("00FF");
    CheckingPar.push_back("pti_mass(3)");
    TrueValue.push_back("00FF");
    CheckingPar.push_back("SupplyGr_1");
    TrueValue.push_back("0000");
    CheckingPar.push_back("SupplyGr_2");
    TrueValue.push_back("0000");
    CheckingPar.push_back("SupplyGr_3");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoonat_1f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoonat_2f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szokudm_1f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szokudm_1f(1)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szokudm_1f(2)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szokudm_2f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szokudm_2f(1)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szokudm_2f(2)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoou_4f");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoona_2f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoakizm_2f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoakizm_2f(1)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoakstat_2f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoakstat_2f(1)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoak_1f(0)");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoasn_1f");
    TrueValue.push_back("0000");
    CheckingPar.push_back("szoasn_2f_0");
    TrueValue.push_back("0000");





    //Параметры БУК:
    /*if(flag&(1<<30))
    {
        CheckingPar.push_back("pr_cnt_buk");
        TrueValue.push_back("0000");
        CheckingPar.push_back("pti");
        TrueValue.push_back("F-активная грань");
        CheckingPar.push_back("config_buk");
        TrueValue.push_back("0000");
        CheckingPar.push_back("zadacha_k");
        TrueValue.push_back("4FFF");
        CheckingPar.push_back("pr_sb_mpo");
        TrueValue.push_back("0000");
        CheckingPar.push_back("ch_otk_ozu");
        TrueValue.push_back("0000");
        CheckingPar.push_back("ksl_dostd");
        TrueValue.push_back("06,07");


        CheckingPar.push_back("schd_gr(0)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("schd_gr(1)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("schd_gr(2)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("schd_gr(3)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("sch_act");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(0)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(1)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(2)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(3)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(4)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(5)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("change");
        TrueValue.push_back("XXXX");
    }*/






    /*CheckingPar.push_back("mpo_flg_dks");
    TrueValue.push_back("00FF");*/

    /*CheckingPar[1]="SupplyGr_2";
    CheckingPar[2]="pti_mass(0)";*/

}
void Init_Normative_values_BUK(void)
{

    if(flag&(1<<30))
    {
        CheckingPar.push_back("pr_cnt_buk");
        TrueValue.push_back("0000");
        CheckingPar.push_back("pti");
        TrueValue.push_back("F-активная грань");
        CheckingPar.push_back("config_buk");
        TrueValue.push_back("0000");
        CheckingPar.push_back("zadacha_k");
        TrueValue.push_back("3FFF");
        CheckingPar.push_back("pr_sb_mpo");
        TrueValue.push_back("0000");
        CheckingPar.push_back("ch_otk_ozu");
        TrueValue.push_back("0000");
        CheckingPar.push_back("ksl_dostd");
        TrueValue.push_back("06,07");

        CheckingPar.push_back("schd_gr(0)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("schd_gr(1)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("schd_gr(2)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("schd_gr(3)");
        TrueValue.push_back("0-FF");
        CheckingPar.push_back("sch_act");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(0)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(1)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(2)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(3)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(4)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("pfi_mass(5)");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("change");
        TrueValue.push_back("XXXX");
        CheckingPar.push_back("tir_buk_zap");
        TrueValue.push_back("0000");
    }

}
void Set_Table_Head(void)
{
    Qt_OutFile_name=Qt_OutFile_name+"<table border=\"1\"><tr><th>Номинальное значение</th><th>Значение по ТМИ</th>";

}


void Create_Report_allPar_File(void)
{

        //TiXmlDocument doc;


        QString test_2;
        test_2=Qt_Tel_Name;
        qDebug()<<test_2.remove(0, test_2.lastIndexOf("/")+1);
        qDebug()<<test_2.remove(test_2.lastIndexOf("."), 4);
        test_2.append("_KDR");

        qDebug()<<"QT_TEL_NAME="<<Qt_Tel_Name;



        TiXmlDeclaration *dec1 = new TiXmlDeclaration("1.0", "UTF-8", "");//XML декларация
        Report_allPar.LinkEndChild(dec1);
        TiXmlElement *element= new TiXmlElement("office:document-content");
        //Объявление и описание пространств имён
        element->SetAttribute("xmlns:office", "urn:oasis:names:tc:opendocument:xmlns:office:1.0");
        element->SetAttribute("xmlns:style", "urn:oasis:names:tc:opendocument:xmlns:style:1.0");
        element->SetAttribute("xmlns:text", "urn:oasis:names:tc:opendocument:xmlns:text:1.0");
        element->SetAttribute("xmlns:table", "urn:oasis:names:tc:opendocument:xmlns:table:1.0");
        element->SetAttribute("xmlns:draw", "urn:oasis:names:tc:op endocument:xmlns:drawing:1.0");
        element->SetAttribute("xmlns:fo", "urn:oasis:names:tc:opendocument:xmlns:xsl-fo-compatible:1.0");
        element->SetAttribute("xmlns:xlink", "http://www.w3.org/1999/xlink");
        element->SetAttribute("xmlns:dc", "http://purl.org/dc/elements/1.1/");
        element->SetAttribute("xmlns:meta", "urn:oasis:names:tc:opendocument:xmlns:meta:1.0");
        element->SetAttribute("xmlns:number", "urn:oasis:names:tc:opendocument:xmlns:datastyle:1.0");
        element->SetAttribute("xmlns:svg", "urn:oasis:names:tc:opendocument:xmlns:svg-compatible:1.0");
        element->SetAttribute("xmlns:chart", "urn:oasis:names:tc:opendocument:xmlns:chart:1.0");
        element->SetAttribute("xmlns:dr3d", "urn:oasis:names:tc:opendocument:xmlns:dr3d:1.0");
        element->SetAttribute("xmlns:math", "http://www.w3.org/1998/Math/MathML");
        element->SetAttribute("xmlns:form", "urn:oasis:names:tc:opendocument:xmlns:form:1.0");
        element->SetAttribute("xmlns:script", "urn:oasis:names:tc:opendocument:xmlns:script:1.0");
        element->SetAttribute("xmlns:ooo", "http://openoffice.org/2004/office");
        element->SetAttribute("xmlns:ooow", "http://openoffice.org/2004/writer");
        element->SetAttribute("xmlns:oooc", "http://openoffice.org/2004/calc");
        element->SetAttribute("xmlns:dom", "http://www.w3.org/2001/xml-events");
        element->SetAttribute("xmlns:xforms", "http://www.w3.org/2002/xforms");
        element->SetAttribute("xmlns:xsd", "http://www.w3.org/2001/XMLSchema");
        element->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
        element->SetAttribute("xmlns:rpt", "http://openoffice.org/2005/report");
        element->SetAttribute("xmlns:of", "urn:oasis:names:tc:opendocument:xmlns:of:1.2");
        element->SetAttribute("xmlns:xhtml", "http://www.w3.org/1999/xhtml");
        element->SetAttribute("xmlns:grddl", "http://www.w3.org/2003/g/data-view#");
        element->SetAttribute("xmlns:tableooo", "http://openoffice.org/2009/table");
        element->SetAttribute("xmlns:textooo", "http://openoffice.org/2013/office");
        element->SetAttribute("xmlns:field", "urn:openoffice:names:experimental:ooo-ms-interop:xmlns:field:1.0");
        element->SetAttribute("office:version", "1.2");
        TiXmlElement *of_scr = new TiXmlElement("office:scripts");
        element->LinkEndChild(of_scr);
        TiXmlElement *of_font_decl = new TiXmlElement("office:font-face-decls");
        TiXmlElement *of_font = new TiXmlElement("style:font-face");
        of_font->SetAttribute("style:name", "Tahoma1");
        of_font->SetAttribute("svg:font-family", "Tahoma");
        of_font_decl->LinkEndChild(of_font);
        //delete of_font;
        TiXmlElement *of_font2 = new TiXmlElement("style:font-face");
        of_font2->SetAttribute("style:name", "Times New Roman");
        of_font2->SetAttribute("svg:font-family", "'Times New Roman'");
        of_font2->SetAttribute("style:font-family-generic", "roman");
        of_font2->SetAttribute("style:font-pitch", "variable");
        of_font_decl->LinkEndChild(of_font2);
        //delete of_font;

        TiXmlElement *of_font3 = new TiXmlElement("style:font-face");
        of_font3->SetAttribute("style:name", "Arial Unicode MS");
        of_font3->SetAttribute("svg:font-family", "'Arial Unicode MS'");
        of_font3->SetAttribute("style:font-family-generic", "system");
        of_font3->SetAttribute("style:font-pitch", "variable");
        of_font_decl->LinkEndChild(of_font3);
        //delete of_font;

        TiXmlElement *of_font4 = new TiXmlElement("style:font-face");
        of_font4->SetAttribute("style:name", "Andale Sans UI");
        of_font4->SetAttribute("svg:font-family", "'Andale Sans UI'");
        of_font4->SetAttribute("style:font-family-generic", "system");
        of_font4->SetAttribute("style:font-pitch", "variable");
        of_font_decl->LinkEndChild(of_font4);
        TiXmlElement *of_font5 = new TiXmlElement("style:font-face");
        of_font5->SetAttribute("style:name", "Tahoma");
        of_font5->SetAttribute("svg:font-family", "Tahoma");
        of_font5->SetAttribute("style:font-family-generic", "system");
        of_font5->SetAttribute("style:font-pitch", "variable");
        //delete of_font5;
        of_font_decl->LinkEndChild(of_font5);
        //delete of_font5;
        //TiXmlElement *of_font5 = new TiXmlElement("style:font-face");
        element->LinkEndChild(of_font_decl);

        TiXmlElement *of_au_st = new TiXmlElement("office:automatic-styles");
        //Задание параметров столбцов
        /*char size_of_col[8];
        sprintf(size_of_col, "%s", "opa");
        printf("%s\n", size_of_col);
        sprintf(size_of_col, "%s", "gdfd");
        printf("%s\n", size_of_col);*/


        Write_Styles(of_au_st);

        //qDebug()<<"AAAAAAAAAAAAA";


        //Определение свойств столбцов
        //Для 1го столбца



        //////////////////Add styles here



        element->LinkEndChild(of_au_st);

        TiXmlElement *office_body = new TiXmlElement("office:body");
        TiXmlElement *office_text = new TiXmlElement("office:text");
        TiXmlElement *sequence_decls = new TiXmlElement("text:sequence-decls");





        TiXmlElement *sequence_decl_1 = new TiXmlElement("text:sequence-decl");
        sequence_decl_1->SetAttribute("text:display-outline-level", "0");
        sequence_decl_1->SetAttribute("text:name", "Illustration");
        sequence_decls->LinkEndChild(sequence_decl_1);

        TiXmlElement *sequence_decl_2 = new TiXmlElement("text:sequence-decl");
        sequence_decl_2->SetAttribute("text:display-outline-level", "0");
        sequence_decl_2->SetAttribute("text:name", "Table");
        sequence_decls->LinkEndChild(sequence_decl_2);

        TiXmlElement *sequence_decl_3 = new TiXmlElement("text:sequence-decl");
        sequence_decl_3->SetAttribute("text:display-outline-level", "0");
        sequence_decl_3->SetAttribute("text:name", "Text");
        sequence_decls->LinkEndChild(sequence_decl_3);

        TiXmlElement *sequence_decl_4 = new TiXmlElement("text:sequence-decl");
        sequence_decl_4->SetAttribute("text:display-outline-level", "0");
        sequence_decl_4->SetAttribute("text:name", "Drawing");
        sequence_decls->LinkEndChild(sequence_decl_4);


        /*TiXmlElement *text_p = new TiXmlElement("text:p");
        text_p->SetAttribute("text:style-name", "P1");

        text_p->LinkEndChild(new TiXmlText("Протокол обработки"));*/

        office_text->LinkEndChild(sequence_decls);

        qDebug()<<"AAAAAAAAAAAAA";

        Form_Content_Prot(office_text);



        //office_text->LinkEndChild(text_p);

        office_body->LinkEndChild(office_text);


        element->LinkEndChild(office_body);



        Report_allPar.LinkEndChild(element);
        remove("content.xml");

        Report_allPar.SaveFile("content.xml");



        if(IsFoldExist_2(qPrintable("Protocol_"+test_2+".odt")))
            {
                remove(qPrintable("Protocol_"+test_2+".odt"));

            }







        Qt_SystemInf=Empty+"7za.exe "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+test_2+".odt"+" content.xml";
        stdString=Qt_SystemInf.toStdString();

        array_test=const_cast<char *>(stdString.c_str());
        //Ch_Prot_Name=qPrintable(Qt_SystemInf);
        //qDebug()<<"AAAAAAAAAAAAA";



        ZeroMemory(&cif, sizeof(STARTUPINFOA));
        CreateProcessA(NULL, array_test, NULL, NULL, FALSE, DETACHED_PROCESS , NULL, NULL, &cif, &pi);
        WaitForSingleObject(pi.hProcess, INFINITE);

        Create_Odt_XML_manifest();

        if(!IsFoldExist_2("META-INF"))
            {
                if(mkdir("META-INF")==0)
                {
                    CopyFile(L"manifest.xml",L"META-INF/manifest.xml",TRUE);
                }
            }





        Qt_SystemInf.clear();



        //Qt_SystemInf=Empty+"\"7za.exe\" "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+test_2+Qt_Tel_Name+".ods"+" META-INF/";
        //Ch_Prot_Name=qPrintable(Qt_SystemInf);
        Qt_SystemInf=Empty+"7za.exe "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+test_2+".odt"+" META-INF/";
        stdString=Qt_SystemInf.toStdString();

        array_test=const_cast<char *>(stdString.c_str());
        Ch_Prot_Name=qPrintable(Qt_SystemInf);
        //qDebug()<< "LL!";
        //cout<< Ch_Prot_Name <<endl;
        //ShowWindow(GetConsoleWindow(), SW_HIDE);
        ZeroMemory(&cif, sizeof(STARTUPINFOA));
        CreateProcessA(NULL, array_test, NULL, NULL, FALSE, DETACHED_PROCESS , NULL, NULL, &cif, &pi);
        WaitForSingleObject(pi.hProcess, INFINITE);



        //qDebug()<<"AAAAAAAAAAAAA";

}

void Create_Odt_XML_manifest(void)
{
    TiXmlDeclaration *dec1 = new TiXmlDeclaration("1.0", "ISO-8859-1", "");//XML декларация
    manifest_odt.LinkEndChild(dec1);
    TiXmlElement *element= new TiXmlElement("manifest:manifest");
    element->SetAttribute("xmlns:manifest", "urn:oasis:names:tc:opendocument:xmlns:manifest:1.0");
    element->SetAttribute("manifest:version", "1.2");
    TiXmlElement *element_2= new TiXmlElement("manifest:file-entry");

    element_2->SetAttribute("manifest:version", "1.2");
    element_2->SetAttribute("manifest:full-path", "/");
    element_2->SetAttribute("manifest:media-type", "application/vnd.oasis.opendocument.text");


    TiXmlElement *element_3= new TiXmlElement("manifest:file-entry");
    element_3->SetAttribute("manifest:full-path", "Configurations2/accelerator/current.xml");
    element_3->SetAttribute("manifest:media-type", "");


    TiXmlElement *element_4= new TiXmlElement("manifest:file-entry");
    element_4->SetAttribute("manifest:full-path", "Configurations2/");
    element_4->SetAttribute("manifest:media-type", "application/vnd.sun.xml.ui.configuration");


    TiXmlElement *element_5= new TiXmlElement("manifest:file-entry");
    element_5->SetAttribute("manifest:full-path", "Thumbnails/thumbnail.png");
    element_5->SetAttribute("manifest:media-type", "image/png");


    TiXmlElement *element_6= new TiXmlElement("manifest:file-entry");
    element_6->SetAttribute("manifest:full-path", "content.xml");
    element_6->SetAttribute("manifest:media-type", "text/xml");


    TiXmlElement *element_7= new TiXmlElement("manifest:file-entry");
    element_7->SetAttribute("manifest:full-path", "settings.xml");
    element_7->SetAttribute("manifest:media-type", "text/xml");

    TiXmlElement *element_8= new TiXmlElement("manifest:file-entry");
    element_8->SetAttribute("manifest:full-path", "styles.xml");
    element_8->SetAttribute("manifest:media-type", "text/xml");

    TiXmlElement *element_9= new TiXmlElement("manifest:file-entry");
    element_9->SetAttribute("manifest:full-path", "manifest.rdf");
    element_9->SetAttribute("manifest:media-type", "application/rdf+xml");

    TiXmlElement *element_10= new TiXmlElement("manifest:file-entry");
    element_10->SetAttribute("manifest:full-path", "meta.xml");

    element_10->SetAttribute("manifest:media-type", "text/xml");




    element->LinkEndChild(element_2);
    element->LinkEndChild(element_3);
    element->LinkEndChild(element_4);
    element->LinkEndChild(element_5);
    element->LinkEndChild(element_6);
    element->LinkEndChild(element_7);
    element->LinkEndChild(element_8);
    element->LinkEndChild(element_9);
    element->LinkEndChild(element_10);


    manifest_odt.LinkEndChild(element);
    manifest_odt.SaveFile("manifest.xml");

}
bool IsFoldExist_2(const std::string &s)
{
    struct stat buffer;
    return(stat(s.c_str(), &buffer)==0);
}
void Write_Styles(TiXmlElement *auto_styles)
{


    TiXmlElement *style_style_table = new TiXmlElement("style:style");





    style_style_table->SetAttribute("style:name", "Таблица1");
    style_style_table->SetAttribute("style:family", "table");

    TiXmlElement *style_par_prop_table = new TiXmlElement("style:table-properties");
    style_par_prop_table->SetAttribute("style:width", "16.999cm");
    style_par_prop_table->SetAttribute("table:align", "margins");


    style_style_table->LinkEndChild(style_par_prop_table);

    auto_styles->LinkEndChild(style_style_table);

    TiXmlElement *style_style_table_2 = new TiXmlElement("style:style");





    style_style_table_2->SetAttribute("style:name", "Таблица1.A");
    style_style_table_2->SetAttribute("style:family", "table-column");

    TiXmlElement *style_par_prop_table_2 = new TiXmlElement("style:table-column-properties");
    style_par_prop_table_2->SetAttribute("style:width", "16.999cm");
    style_par_prop_table_2->SetAttribute("style:rel-column-width", "21845*");


    style_style_table_2->LinkEndChild(style_par_prop_table_2);

    auto_styles->LinkEndChild(style_style_table_2);





    TiXmlElement *style_style_table_3 = new TiXmlElement("style:style");


    style_style_table_3->SetAttribute("style:name", "Таблица1.A1");
    style_style_table_3->SetAttribute("style:family", "table-cell");

    TiXmlElement *style_par_prop_table_3 = new TiXmlElement("style:table-cell-properties");
    style_par_prop_table_3->SetAttribute("fo:padding", "0.097cm");
    style_par_prop_table_3->SetAttribute("fo:border-left", "0.002cm solid #000000");
    style_par_prop_table_3->SetAttribute("fo:border-night", "none");
    style_par_prop_table_3->SetAttribute("fo:border-top", "0.002cm solid #000000");
    style_par_prop_table_3->SetAttribute("fo:border-bottom", "0.002cm solid #000000");


    style_style_table_3->LinkEndChild(style_par_prop_table_3);

    auto_styles->LinkEndChild(style_style_table_3);


    TiXmlElement *style_style_table_4 = new TiXmlElement("style:style");


    style_style_table_4->SetAttribute("style:name", "Таблица1.C1");
    style_style_table_4->SetAttribute("style:family", "table-cell");

    TiXmlElement *style_par_prop_table_4 = new TiXmlElement("style:table-cell-properties");
    style_par_prop_table_4->SetAttribute("fo:padding", "0.097cm");
    style_par_prop_table_4->SetAttribute("fo:border", "0.002cm solid #000000");


    style_style_table_4->LinkEndChild(style_par_prop_table_4);

    auto_styles->LinkEndChild(style_style_table_4);




    TiXmlElement *style_style_table_5 = new TiXmlElement("style:style");


    style_style_table_5->SetAttribute("style:name", "Таблица1.A2");
    style_style_table_5->SetAttribute("style:family", "table");

    TiXmlElement *style_par_prop_table_5 = new TiXmlElement("style:table-properties");
    style_par_prop_table_5->SetAttribute("style:width", "16.999cm");
    style_par_prop_table_5->SetAttribute("table:align", "margins");


    style_style_table_5->LinkEndChild(style_par_prop_table_5);

    auto_styles->LinkEndChild(style_style_table_5);



    TiXmlElement *style_style_table_6 = new TiXmlElement("style:style");


    style_style_table_6->SetAttribute("style:name", "Таблица2.C1");
    style_style_table_6->SetAttribute("style:family", "table");

    TiXmlElement *style_par_prop_table_6 = new TiXmlElement("style:table-properties");
    style_par_prop_table_6->SetAttribute("style:width", "16.999cm");
    style_par_prop_table_6->SetAttribute("table:align", "margins");


    style_style_table_6->LinkEndChild(style_par_prop_table_6);

    auto_styles->LinkEndChild(style_style_table_6);





    TiXmlElement *style_style = new TiXmlElement("style:style");

    style_style->SetAttribute("style:name", "P1");
    style_style->SetAttribute("style:family", "paragraph");
    style_style->SetAttribute("style:parent-style-name", "Standard");

    TiXmlElement *style_par_prop = new TiXmlElement("style:paragraph-properties");
    style_par_prop->SetAttribute("fo:text-align", "center");
    style_par_prop->SetAttribute("style:justify-single-word", "false");

    TiXmlElement *style_text_prop = new TiXmlElement("style:text-properties");
    style_text_prop->SetAttribute("fo:font-size", "18pt");
    style_text_prop->SetAttribute("fo:language", "ru");
    style_text_prop->SetAttribute("fo:country", "RU");
    style_text_prop->SetAttribute("fo:font-weight", "bold");
    style_text_prop->SetAttribute("style:font-weight-asian", "bold");
    style_text_prop->SetAttribute("style:font-weight-complex", "bold");

    style_style->LinkEndChild(style_par_prop);
    style_style->LinkEndChild(style_text_prop);

    auto_styles->LinkEndChild(style_style);




    TiXmlElement *style_style_2 = new TiXmlElement("style:style");


    style_style_2->SetAttribute("style:name", "P2");
    style_style_2->SetAttribute("style:family", "paragraph");
    style_style_2->SetAttribute("style:parent-style-name", "Table_20_Contents");
    TiXmlElement *style_par_prop_2 = new TiXmlElement("style:paragraph-properties");
    style_par_prop_2->SetAttribute("fo:text-align", "justify");
    style_par_prop_2->SetAttribute("style:justify-single-word", "false");

    style_style_2->LinkEndChild(style_par_prop_2);


    auto_styles->LinkEndChild(style_style_2);



    TiXmlElement *style_style_3 = new TiXmlElement("style:style");


    style_style_3->SetAttribute("style:name", "P3");
    style_style_3->SetAttribute("style:family", "paragraph");
    style_style_3->SetAttribute("style:parent-style-name", "Table_20_Contents");
    TiXmlElement *style_par_prop_3 = new TiXmlElement("style:paragraph-properties");
    style_par_prop_3->SetAttribute("fo:text-align", "center");
    style_par_prop_3->SetAttribute("style:justify-single-word", "false");
    TiXmlElement *style_text_prop_3 = new TiXmlElement("style:text-properties");
    style_text_prop_3->SetAttribute("fo:font-size", "14 pt");
    style_text_prop_3->SetAttribute("fo:language", "ru");
    style_text_prop_3->SetAttribute("fo:country", "RU");
    style_text_prop_3->SetAttribute("fo:font-weight", "bold");
    style_text_prop_3->SetAttribute("style:font-size-asian", "14pt");
    style_text_prop_3->SetAttribute("style:font-weight-asian", "bold");
    style_text_prop_3->SetAttribute("style:font-size-complex", "14pt");
    style_text_prop_3->SetAttribute("style:fount-weight-complex", "bold");

    style_style_3->LinkEndChild(style_par_prop_3);
    style_style_3->LinkEndChild(style_text_prop_3);

    auto_styles->LinkEndChild(style_style_3);




    TiXmlElement *style_style_4 = new TiXmlElement("style:style");


    style_style_4->SetAttribute("style:name", "P4");
    style_style_4->SetAttribute("style:family", "paragraph");
    style_style_4->SetAttribute("style:parent-style-name", "Table_20_body");
    TiXmlElement *style_par_prop_4 = new TiXmlElement("style:paragraph-properties");
    style_par_prop_4->SetAttribute("fo:text-align", "juastify");
    style_par_prop_4->SetAttribute("style:justify-single-word", "false");


    TiXmlElement *style_text_prop_4 = new TiXmlElement("style:text-properties");
    style_text_prop->SetAttribute("fo:language", "ru");
    style_text_prop->SetAttribute("fo:country", "RU");



    style_style_4->LinkEndChild(style_par_prop_4);
    style_style_4->LinkEndChild(style_text_prop_4);


    auto_styles->LinkEndChild(style_style_4);





    TiXmlElement *style_style_5 = new TiXmlElement("style:style");


    style_style_5->SetAttribute("style:name", "P5");
    style_style_5->SetAttribute("style:family", "paragraph");
    style_style_5->SetAttribute("style:parent-style-name", "Table_20_body");
    TiXmlElement *style_par_prop_5 = new TiXmlElement("style:paragraph-properties");
    style_par_prop_5->SetAttribute("fo:margin-left", "0cm");
    style_par_prop_5->SetAttribute("fo:margin-right", "0cm");
    style_par_prop_5->SetAttribute("fo:margin-top", "0cm");
    style_par_prop_5->SetAttribute("fo:margin-bottom", "0cm");
    style_par_prop_5->SetAttribute("fo:text-indent", "0cm");
    style_par_prop_5->SetAttribute("style:auto-text-indent", "false");

    style_style_5->LinkEndChild(style_par_prop_5);


    auto_styles->LinkEndChild(style_style_5);



    TiXmlElement *style_style_6 = new TiXmlElement("style:style");


    style_style_6->SetAttribute("style:name", "P6");
    style_style_6->SetAttribute("style:family", "paragraph");
    style_style_6->SetAttribute("style:parent-style-name", "Table_20_Contents");
    TiXmlElement *style_par_prop_6 = new TiXmlElement("style:paragraph-properties");
    style_par_prop_6->SetAttribute("fo:text-align", "center");
    style_par_prop_6->SetAttribute("fo:justify-singlw-word", "false");
    TiXmlElement *style_text_prop_6 = new TiXmlElement("style:text-properties");
    style_text_prop_6->SetAttribute("fo:font-size", "14 pt");
    style_text_prop_6->SetAttribute("fo:language", "en");
    style_text_prop_6->SetAttribute("fo:country", "US");
    style_text_prop_6->SetAttribute("fo:font-size-asian", "14pt");
    style_text_prop_6->SetAttribute("fo:font-size-complex", "14pt");

    style_style_6->LinkEndChild(style_par_prop_6);
    style_style_6->LinkEndChild(style_text_prop_6);


    auto_styles->LinkEndChild(style_style_6);





    TiXmlElement *style_style_7 = new TiXmlElement("style:style");

    style_style_7->SetAttribute("style:name", "P7");
    style_style_7->SetAttribute("style:family", "paragraph");
    style_style_7->SetAttribute("style:parent-style-name", "Standard");

    TiXmlElement *style_par_prop_7 = new TiXmlElement("style:paragraph-properties");
    style_par_prop_7->SetAttribute("fo:text-align", "justify");
    style_par_prop_7->SetAttribute("style:justify-single-word", "false");

    TiXmlElement *style_text_prop_7 = new TiXmlElement("style:text-properties");
    style_text_prop_7->SetAttribute("fo:font-size", "14pt");
    style_text_prop_7->SetAttribute("fo:language", "ru");
    style_text_prop_7->SetAttribute("fo:country", "RU");
    //style_text_prop_7->SetAttribute("fo:font-weight", "bold");
    //style_text_prop_7->SetAttribute("style:font-weight-asian", "bold");
    //style_text_prop_7->SetAttribute("style:font-weight-complex", "bold");

    style_style_7->LinkEndChild(style_par_prop_7);
    style_style_7->LinkEndChild(style_text_prop_7);

    auto_styles->LinkEndChild(style_style_7);





    TiXmlElement *style_style_9 = new TiXmlElement("style:style");


    style_style_9->SetAttribute("style:name", "T1");
    style_style_9->SetAttribute("style:family", "text");
    TiXmlElement *style_text_prop_9 = new TiXmlElement("style:text-properties");
    style_text_prop_9->SetAttribute("fo:language", "en");
    style_text_prop_9->SetAttribute("fo:country", "US");

    style_style_9->LinkEndChild(style_text_prop_9);

    auto_styles->LinkEndChild(style_style_9);


    TiXmlElement *style_style_8 = new TiXmlElement("style:style");

    style_style_8->SetAttribute("style:name", "T2");
    style_style_8->SetAttribute("style:family", "text");
    TiXmlElement *style_text_prop_8 = new TiXmlElement("style:text-properties");
    style_text_prop_8->SetAttribute("fo:language", "ru");
    style_text_prop_8->SetAttribute("fo:country", "RU");

    style_style_8->LinkEndChild(style_text_prop_8);


    auto_styles->LinkEndChild(style_style_8);

}
void Form_Content_Prot(TiXmlElement* Office_Text)
{
    int vect_count=0;
    vector <QString> NamePar;
    vector <QString> NormValue;
    vector <QString> TMI_Value;



    while(vect_count!=ProtNomValues.size())
    {
        /*qDebug()<<"ProtNomValues="<<ProtNomValues[vect_count];
        qDebug()<<"ProtNamesModules="<<ProtNamesModules[vect_count];
        qDebug()<<"ProtTMIValues="<<ProtTMIValues[vect_count];*/

        vect_count++;
    }

    vect_count=0;

    /*NamePar.push_back("апарап");
    NamePar.push_back("длор");
    NormValue.push_back("орлдддддд");
    NormValue.push_back("олд");
    TMI_Value.push_back("лдорд");
    TMI_Value.push_back("ордложло");*/

    /*ProtNamesModules.clear();
    ProtNomValues.clear();
    ProtTMIValues.clear();


    ProtNamesModules.push_back("апарап");
    ProtNamesModules.push_back("длор");
    ProtNomValues.push_back("орлдддддд");
    ProtNomValues.push_back("олд");
    ProtTMIValues.push_back("лдорд");
    ProtTMIValues.push_back("ордложло");

    ProtNamesModules.push_back("апарап");
    ProtNamesModules.push_back("длор");
    ProtNomValues.push_back("орлдддддд");
    ProtNomValues.push_back("олд");
    ProtTMIValues.push_back("лдорд");
    ProtTMIValues.push_back("ордложло");*/



    /*NamePar.push_back(qPrintable(ProtNamesModules[vect_count]));
    NormValue.push_back(qPrintable(ProtNomValues[vect_count]));
    TMI_Value.push_back(qPrintable(ProtTMIValues[vect_count]));*/

   /* NamePar.clear();

    NamePar.push_back(ProtNamesModules[vect_count]);
    NormValue.push_back(ProtNomValues[vect_count]);
    TMI_Value.push_back(ProtTMIValues[vect_count]);*/


    /*qDebug()<<"qPrintNamePar="<<ProtNamesModules[vect_count].toStdString().c_str();
    qDebug()<<"qPrintNormValue="<<ProtNomValues[vect_count].toStdString().c_str();
    qDebug()<<"qPrintTMI_Value="<<ProtTMIValues[vect_count].toStdString().c_str();*/

    /*qDebug()<<"NamePar="<<NamePar[0];
    qDebug()<<"NormValue="<<NormValue[0];
    qDebug()<<"TMI_Value="<<TMI_Value[0];



    */

    /*ProtNamesModules.push_back("?");
    ProtNamesModules.push_back("?");
    ProtNomValues.push_back("?");*/

    SetTextProt("Протокол обработки", "P1", Office_Text);



   while(vect_count!=ProtNomValues.size())
    {
       //SetTextProt("Протокол обработки", "P1", Office_Text);
       if(ProtNomValues[vect_count]=="%")
       {
           SetTextProt("Следующие параметры ТМИ СОВП БВУ при начальном включении не соответствуют номинальным:", "P7", Office_Text);
           flag_2|=(1<<6);


           while((!ProtNomValues[vect_count].contains(":"))&&(!ProtNomValues[vect_count].contains("?"))&&(!ProtNomValues[vect_count].contains("|")))
          {
              NamePar.push_back(ProtNamesModules[vect_count].toStdString().c_str());
              NormValue.push_back(ProtNomValues[vect_count].toStdString().c_str());
              TMI_Value.push_back(ProtTMIValues[vect_count].toStdString().c_str());
              /*qDebug()<<"NamePar="<<NamePar[NamePar.size()-1];
              qDebug()<<"NormValue="<<NormValue[NormValue.size()-1];
              qDebug()<<"TMI_Value="<<TMI_Value[TMI_Value.size()-1];*/
              qDebug()<<vect_count;
              vect_count++;
          }
           SetTable(Office_Text, NamePar, NormValue, TMI_Value, 0);
           NamePar.clear();
           NormValue.clear();
           TMI_Value.clear();
       }







       //if(ProtNomValues[vect_count].contains(":"))
       while(ProtNomValues[vect_count].contains(":"))
       {

           if(!(flag_2&(1<<6)))
           {
               SetTextProt("Следующие параметры ТМИ СОВП БВУ при начальном включении не соответствуют номинальным:", "P7", Office_Text);
               flag_2|=(1<<6);
           }




           SetTextProt("Массив РТВК "+QString(ProtNomValues[vect_count][1])+"-го кадра", "P3", Office_Text);

           vect_count++;




           while((!ProtNomValues[vect_count].contains(":"))&&(!ProtNomValues[vect_count].contains("?"))&&(!ProtNomValues[vect_count].contains("|")))
          {
               //qDebug()<<"AAAAAAAAAAAAAAAAAAAAAAA!!!!!!!!!!!";

              NamePar.push_back(ProtNamesModules[vect_count].toStdString().c_str());
              NormValue.push_back(ProtNomValues[vect_count].toStdString().c_str());
              TMI_Value.push_back(ProtTMIValues[vect_count].toStdString().c_str());
              /*qDebug()<<"NamePar="<<NamePar[NamePar.size()-1];
              qDebug()<<"NormValue="<<NormValue[NormValue.size()-1];
              qDebug()<<"TMI_Value="<<TMI_Value[TMI_Value.size()-1];*/
              //qDebug()<<vect_count;
              vect_count++;
          }
           SetTable(Office_Text, NamePar, NormValue, TMI_Value, 0);
           NamePar.clear();
           NormValue.clear();
           TMI_Value.clear();
       }










       if(ProtNomValues[vect_count]=="?")
       {
           SetTextProt("Значения следующих параметров ТМИ, характеризующих работу БВУ, не соответствуют номинальным:", "P7", Office_Text);
           //flag_2|=(1<<6);

           vect_count++;


           qDebug()<<"NamePar="<<ProtNamesModules[vect_count].toStdString().c_str();
           qDebug()<<"NormValue="<<ProtNomValues[vect_count].toStdString().c_str();
           qDebug()<<"TMI_Value="<<ProtTMIValues[vect_count].toStdString().c_str();





           //Здесь ошибка:////////////


           while((!(flag_2&(1<<7)))&&(!ProtNomValues[vect_count].contains(":"))&&(!ProtNomValues[vect_count].contains("?"))&&(!ProtNomValues[vect_count].contains("|")))
          {
               if(vect_count==ProtNomValues.size()-1)
               {
                   flag_2|=(1<<7);

               }
              NamePar.push_back(ProtNamesModules[vect_count].toStdString().c_str());
              NormValue.push_back(ProtNomValues[vect_count].toStdString().c_str());
              TMI_Value.push_back(ProtTMIValues[vect_count].toStdString().c_str());
              /*qDebug()<<"NamePar="<<NamePar[NamePar.size()-1];
              qDebug()<<"NormValue="<<NormValue[NormValue.size()-1];
              qDebug()<<"TMI_Value="<<TMI_Value[TMI_Value.size()-1];*/
              qDebug()<<vect_count;

              if(!(flag_2&(1<<7)))
              {
                  vect_count++;
              }


              //vect_count++;
          }



           //////////////

           SetTable(Office_Text, NamePar, NormValue, TMI_Value, 0);

           NamePar.clear();
           NormValue.clear();
           TMI_Value.clear();
       }









       if(ProtNomValues[vect_count]=="|")
       {
           SetTextProt("Значения следующих параметров ТМИ, характеризующих работу БУК, не соответствуют номинальным:", "P7", Office_Text);
           //flag_2|=(1<<6);

           vect_count++;



               while((!(flag_2&(1<<7)))&&(!ProtNomValues[vect_count].contains(":"))&&(!ProtNomValues[vect_count].contains("?"))&&(!ProtNomValues[vect_count].contains("|")))
              {

                       if(vect_count==ProtNomValues.size()-1)
                       {
                           flag_2|=(1<<7);

                       }
                       NamePar.push_back(ProtNamesModules[vect_count].toStdString().c_str());
                       NormValue.push_back(ProtNomValues[vect_count].toStdString().c_str());
                       TMI_Value.push_back(ProtTMIValues[vect_count].toStdString().c_str());
                       /*qDebug()<<"NamePar="<<NamePar[NamePar.size()-1];
                       qDebug()<<"NormValue="<<NormValue[NormValue.size()-1];
                       qDebug()<<"TMI_Value="<<TMI_Value[TMI_Value.size()-1];*/
                       qDebug()<<vect_count;

                       if(!(flag_2&(1<<7)))
                       {
                           vect_count++;
                       }
              }
               SetTable(Office_Text, NamePar, NormValue, TMI_Value, 0);
               NamePar.clear();
               NormValue.clear();
               TMI_Value.clear();
       }






       vect_count++;
    }


   ///Выводим информацию о СЗО в протокол

   vect_count=0;





   if(!vect_SZO.empty())
   {


       qDebug()<<"VVVEEECCCTTOORR_szo="<<vect_SZO.size();
       SetTextProt("В ТМИ обнаружены следующие СЗО:", "P7", Office_Text);


       while(vect_count!=vect_SZO.size())
       {



         NamePar.push_back(vect_SZO[vect_count].SZO_time.replace(QString("<br />"), QString(";")).toStdString().c_str());
         NormValue.push_back(vect_SZO[vect_count].value.toStdString().c_str());
         TMI_Value.push_back(vect_SZO[vect_count].SZO_description.replace(QString("<br />"), QString(";")).toStdString().c_str());






         vect_count++;


       }

       SetTable(Office_Text, NamePar, NormValue, TMI_Value, 1);
       NamePar.clear();
       NormValue.clear();
       TMI_Value.clear();

   }


















    //SetTable(Office_Text, NamePar, NormValue, TMI_Value);

    //SetTable(Office_Text, NamePar, NormValue, TMI_Value);


}





void SetTextProt(QString necessary_text, QString name_style, TiXmlElement* Office_Text)
{

    vect_ptot_text.push_back(new TiXmlElement("text:p"));

    //TiXmlElement *text_p = new TiXmlElement("text:p");


    //qDebug()<<"TEXT="<<necessary_text.toStdString().c_str();


    vect_ptot_text[vect_ptot_text.size()-1]->SetAttribute("text:style-name", qPrintable(name_style));

    vect_ptot_text[vect_ptot_text.size()-1]->LinkEndChild(new TiXmlText(necessary_text.toStdString().c_str()));


    Office_Text->LinkEndChild(vect_ptot_text[vect_ptot_text.size()-1]);

}
void SetTable(TiXmlElement* Office_Text, vector <QString> NamePar, vector <QString> NormValue, vector <QString> TMI_Value, int style)
{
    int row_counter=0;
    int count_vect=0;

    QString NamePar_str;
    QString NormValue_str;
    QString TMI_Value_str;

    QDebug debug =qDebug();


    QString Buf_description;
    vector <QString> vect_Buf_description;
    int count_buf_descr=0;

    const char* StyleName;

    vector <TiXmlElement*> vector_table;

    vector <TiXmlElement*> vector_table_column;

    vector <TiXmlElement*> vector_table_row;

    vector <TiXmlElement*> vector_table_cell;

    vector <TiXmlElement*> vector_text_p;

    vector_table.push_back(new TiXmlElement("table:table"));

    vector_table[vector_table.size()-1]->SetAttribute("table:name", "Таблица1");
    vector_table[vector_table.size()-1]->SetAttribute("table:style-name", "Таблица1");


    vector_table_column.push_back(new TiXmlElement("table:table-column"));

    vector_table_column[vector_table_column.size()-1]->SetAttribute("table:style-name", "Таблица1.A");
    vector_table_column[vector_table_column.size()-1]->SetAttribute("table:number-columns-repeated", "3");

    vector_table[vector_table.size()-1]->LinkEndChild(vector_table_column[vector_table_column.size()-1]);


    /*while(count_vect!=NamePar.size())
    {
        qDebug()<<"=================";
        qDebug()<<"NamePar="<<NamePar[0];
        qDebug()<<"NormValue="<<NormValue[0];
        qDebug()<<"TMI_Value="<<TMI_Value[0];
        count_vect++;
    }*/






    /*vect_ptot_text[vect_ptot_text.size()-1]->SetAttribute("text:style-name", qPrintable(name_style));

    vect_ptot_text[vect_ptot_text.size()-1]->LinkEndChild(new TiXmlText(necessary_text));*/



    //qDebug()<<vect_count;

    //qDebug()<<"NAME_PAR_SIZE="<<NamePar.size();

    while(row_counter!=NamePar.size())
    {
        if(flag_2&(1<<5))
        {
            NamePar_str=NamePar[row_counter];
            NormValue_str=NormValue[row_counter];
            TMI_Value_str=TMI_Value[row_counter];
            StyleName="P6";
        }
        else if(style==1)
        {
            NamePar_str="Время";
            NormValue_str="Значение";
            TMI_Value_str="Описание";
            StyleName="P3";
            flag_2|=(1<<5);
            flag_2|=(1<<11);

        }
        else
        {
            NamePar_str="Имя параметра";
            NormValue_str="Нормативное значение";
            TMI_Value_str="Значение по ТМИ";
            StyleName="P3";
            flag_2|=(1<<5);
            flag_2|=(1<<11);
        }

        /*qDebug()<<"NamePar="<<NamePar[NamePar.size()-1];
        qDebug()<<"NormValue="<<NormValue[NormValue.size()-1];
        qDebug()<<"TMI_Value="<<TMI_Value[TMI_Value.size()-1];*/



       vector_table_row.push_back(new TiXmlElement("table:table-row"));

        ///////////////////////////











       vector_table_cell.push_back(new TiXmlElement("table:table-cell"));

       vector_table_cell[vector_table_cell.size()-1]->SetAttribute("table:style-name", "Таблица1.A1");
       vector_table_cell[vector_table_cell.size()-1]->SetAttribute("office:value-type", "string");




       ///////////////////////////////////////

       count_buf_descr=0;


        while(count_buf_descr!=NamePar_str.size())
        {
            while((NamePar_str[count_buf_descr]!=";")&&(count_buf_descr!=NamePar_str.size()-1))
            {


                Buf_description.append(NamePar_str[count_buf_descr]);


                count_buf_descr++;


            }


            if(NamePar_str[count_buf_descr]!=";")
            {

                Buf_description.append(NamePar_str[count_buf_descr]);
            }

            //qDebug()<<"ASD";

            count_buf_descr++;


            vect_Buf_description.push_back(Buf_description);


            Buf_description.clear();



        }



        count_buf_descr=0;


        ////////////////////////////////////////////////////

       /// count_buf_descr=0;



        if(flag_2&(1<<11))
        {
            vector_text_p.push_back(new TiXmlElement("text:p"));
            vector_text_p[vector_text_p.size()-1]->SetAttribute("text:style-name", StyleName);
            //TMI_Value_str


             vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(NamePar_str.toStdString().c_str()));

             vector_table_cell[vector_table_cell.size()-1]->LinkEndChild(vector_text_p[vector_text_p.size()-1]);



        }
        else
        {

            while(count_buf_descr!=vect_Buf_description.size())
            {


                qDebug()<<"KKKKLLLL";

                vector_text_p.push_back(new TiXmlElement("text:p"));
                vector_text_p[vector_text_p.size()-1]->SetAttribute("text:style-name", StyleName);
                //TMI_Value_str


                vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(vect_Buf_description[count_buf_descr].toStdString().c_str()));

                vector_table_cell[vector_table_cell.size()-1]->LinkEndChild(vector_text_p[vector_text_p.size()-1]);


                count_buf_descr++;
            }




        }


        vect_Buf_description.clear();




        vector_table_row[vector_table_row.size()-1]->LinkEndChild(vector_table_cell[vector_table_cell.size()-1]);










       /*vector_text_p.push_back(new TiXmlElement("text:p"));
       vector_text_p[vector_text_p.size()-1]->SetAttribute("text:style-name", StyleName);
        //NamePar_str
       //vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(qPrintable(NamePar_str)));
        vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(NamePar_str.toStdString().c_str()));
       vector_table_cell[vector_table_cell.size()-1]->LinkEndChild(vector_text_p[vector_text_p.size()-1]);

       vector_table_row[vector_table_row.size()-1]->LinkEndChild(vector_table_cell[vector_table_cell.size()-1]);*/





       vector_table_cell.push_back(new TiXmlElement("table:table-cell"));

       vector_table_cell[vector_table_cell.size()-1]->SetAttribute("table:style-name", "Таблица1.A1");
       vector_table_cell[vector_table_cell.size()-1]->SetAttribute("office:value-type", "string");

       vector_text_p.push_back(new TiXmlElement("text:p"));
       vector_text_p[vector_text_p.size()-1]->SetAttribute("text:style-name", StyleName);
//NormValue_str
       //vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(qPrintable(NormValue_str)));
        vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(NormValue_str.toStdString().c_str()));
       vector_table_cell[vector_table_cell.size()-1]->LinkEndChild(vector_text_p[vector_text_p.size()-1]);

       vector_table_row[vector_table_row.size()-1]->LinkEndChild(vector_table_cell[vector_table_cell.size()-1]);





       vector_table_cell.push_back(new TiXmlElement("table:table-cell"));

       vector_table_cell[vector_table_cell.size()-1]->SetAttribute("table:style-name", "Таблица1.C1");
       vector_table_cell[vector_table_cell.size()-1]->SetAttribute("office:value-type", "string");

       ///////////////////////////////////////

       count_buf_descr=0;


        while(count_buf_descr!=TMI_Value_str.size())
        {
            while((TMI_Value_str[count_buf_descr]!=";")&&(count_buf_descr!=TMI_Value_str.size()-1))
            {


                Buf_description.append(TMI_Value_str[count_buf_descr]);


                count_buf_descr++;


            }


            if(TMI_Value_str[count_buf_descr]!=";")
            {

                Buf_description.append(TMI_Value_str[count_buf_descr]);
            }

            //qDebug()<<"ASD";

            count_buf_descr++;


            vect_Buf_description.push_back(Buf_description);


            Buf_description.clear();



        }



        count_buf_descr=0;



        /*while(count_buf_descr!=vect_Buf_description.size())
        {


            qDebug()<<"vect_Buf_description="<<vect_Buf_description[count_buf_descr];



            count_buf_descr++;
        }*/


        //vect_Buf_description.clear();


        //WriteTableCell(TMI_Value_str, style, vector_table_cell, vector_text_p);

        //WriteTableCell(TMI_Value_str, style, vector_table_cell, vector_text_p);

        //vector_table_cell[vector_table_cell.size()-1]=Test(TMI_Value_str, StyleName, vector_table_cell, vector_text_p);



        ////////////////////////////////////////////////////

        count_buf_descr=0;



        if(flag_2&(1<<11))
        {
            vector_text_p.push_back(new TiXmlElement("text:p"));
            vector_text_p[vector_text_p.size()-1]->SetAttribute("text:style-name", StyleName);
            //TMI_Value_str


             vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(TMI_Value_str.toStdString().c_str()));

             vector_table_cell[vector_table_cell.size()-1]->LinkEndChild(vector_text_p[vector_text_p.size()-1]);



        }
        else
        {

            while(count_buf_descr!=vect_Buf_description.size())
            {


                qDebug()<<"KKKKLLLL";

                vector_text_p.push_back(new TiXmlElement("text:p"));
                vector_text_p[vector_text_p.size()-1]->SetAttribute("text:style-name", StyleName);
                //TMI_Value_str


                vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(vect_Buf_description[count_buf_descr].toStdString().c_str()));

                vector_table_cell[vector_table_cell.size()-1]->LinkEndChild(vector_text_p[vector_text_p.size()-1]);


                count_buf_descr++;
            }




        }




        vector_table_row[vector_table_row.size()-1]->LinkEndChild(vector_table_cell[vector_table_cell.size()-1]);


        vector_table[vector_table.size()-1]->LinkEndChild(vector_table_row[vector_table_row.size()-1]);







       /*vector_text_p.push_back(new TiXmlElement("text:p"));
       vector_text_p[vector_text_p.size()-1]->SetAttribute("text:style-name", StyleName);
       //TMI_Value_str


        vector_text_p[vector_text_p.size()-1]->LinkEndChild(new TiXmlText(TMI_Value_str.toStdString().c_str()));
       vector_table_cell[vector_table_cell.size()-1]->LinkEndChild(vector_text_p[vector_text_p.size()-1]);

       vector_table_row[vector_table_row.size()-1]->LinkEndChild(vector_table_cell[vector_table_cell.size()-1]);


       vector_table[vector_table.size()-1]->LinkEndChild(vector_table_row[vector_table_row.size()-1]);*/




       //vector_table[vector_table.size()-1]->LinkEndChild(vector_table_row[vector_table_row.size()-1]);

       if(flag_2&(1<<5))
       {

           row_counter++;

       }


       flag_2&=~(1<<11);

       vect_Buf_description.clear();

    }

    Office_Text->LinkEndChild(vector_table[vector_table.size()-1]);
    flag_2&=~(1<<5);

}
void Write_SZO_vector(void)
{

    int func_count=0;


    qDebug()<<"BUF="<<Buffer;

    if(Buffer.contains("szo"))
    {




        for(func_count=0; func_count<vect_SZO.size(); func_count++)
        {


            if(vect_SZO[func_count].value==Buffer)
            {
                vect_SZO[func_count].SZO_time.append(";"+TimeKeeper);

                flag_2|=(1<<10);

            }

        }

        if(!(flag_2&(1<<10)))
        {

            szo_keeper.value=Buffer;


            szo_keeper.SZO_time=TimeKeeper;
            szo_keeper.SZO_description=Form_SZO_Descr(Buffer);

            vect_SZO.push_back(szo_keeper);

        }



        flag_2|=(1<<9);


        flag_2&=~(1<<10);

    }

}
void SZO_Out(void)
{
    int SZO_count=0;

    QString Buf_time;


    Qt_OutFile_name=Qt_OutFile_name+"В ТМИ обнаружены \n следующие СЗО:";

    Qt_OutFile_name=Qt_OutFile_name+"<table border=\"1\"><tr><th>Время появления</th><th>Идентификатор и значение</th><th>Описание</th></tr>";






    for(SZO_count=0; SZO_count<vect_SZO.size(); SZO_count++)
    {


        Qt_OutFile_name=Qt_OutFile_name+"<tr><td>"+vect_SZO[SZO_count].SZO_time.replace(QString(";"), QString("<br />"))+"</td>"+"<td>"+vect_SZO[SZO_count].value+"</td>"+"<td>"+vect_SZO[SZO_count].SZO_description+"</td></tr>";

    }




    Qt_OutFile_name=Qt_OutFile_name+"</table>";

}
QString Form_SZO_Descr(QString Value)
{
    QString description;
    QString szo_value;

    bool ok;

    int digit_value=0;


    qDebug()<<"HHHGFDSA="<<Value.remove(0, Value.lastIndexOf("=")+2);

    digit_value=Value.remove(0, Value.lastIndexOf("=")+3).toInt(&ok, 16);

    if(digit_value&0x2)
    {

        description.append("Принято управление интерфейсом (18 разряд ОС)<br />");

    }
    if(digit_value&0x4)
    {

        description.append("Неисправность абонента (17 разряд ОС)<br />");

    }
    if(digit_value&0x8)
    {

        description.append("Абонент занят (16 разряд ОС)<br />");

    }
    if(digit_value&0x10)
    {

         description.append("Принята групповая команда (15 разряд ОС)<br />");

    }
    if(digit_value&0x20)//5й разряд
    {

         description.append("Отказ обмена по МПО в грани \"Монитор\"<br />");

    }
    if(digit_value&0x40)
    {

         description.append("Несовпадение ДКС в грани \"Контроллер\"<br />");

    }
    if(digit_value&0x80)
    {

         description.append("Несовпадение ДКС в грани \"Монитор\"<br />");

    }
    if(digit_value&0x100)
    {

         description.append("Запрос на обслуживание (11 разряд ОС)<br />");

    }
    if(digit_value&0x200)
    {

         description.append("Передача ОС (10 разряд ОС)<br />");

    }
    if(digit_value&0x400)
    {

         description.append("Ошибка в сообщении (9 разряд ОС)<br />");

    }
    if(digit_value&0x800)
    {

         description.append("Комбинированный отказ по СС м/с<br />");

    }
    if(digit_value&0x4000)
    {

         description.append("Признак повтора по резервной линии<br />");

    }



    qDebug()<<"DIGIT_VALUE="<<digit_value;



    return description;
}






















