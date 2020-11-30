 #include "mainwindow.h"
#include <QTextCodec>
//#include <QtGui/QApplication>
#include <QApplication>
#include <QLabel>
#include <vector>
//#include "windows.h"
#include <windows.h>
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
#include <QFileInfo.h>
#include "tinyxml.h"
#include <fstream>
//#include "windows.h"

void ProgramCode(void);
bool IsFoldExist(const std::string &s);
void Create_ODS_File(void);
void Form_inf_file(void);

TiXmlDocument info;

//QString Qt_kdr_file;
//QString Qt_sbl_file;
//int counter_mas[37];
//QDir dir;
QString First_arg;
QString Second_arg;
QString Qt_Dir_Folder;
QString Qt_Kdr_name_file;
QString line;




int main(int argc, char *argv[])
{
   //QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    //ShowWindow(GetConsoleWindow(), SW_HIDE);
    int f=0;
    int b=9/f;
    QCoreApplication::addLibraryPath("./");
    QApplication a(argc, argv);


    if(argc!=1)
    {
        QString SpacecraftNames[10];
        //qDebug() << "!!!!!!!!!!!!!!!!!!!!!";
        qDebug()<<QString(argv[0]);
        qDebug()<<QString(argv[2]);
        SpacecraftNames[0]="ArcM";
        First_arg=QString(argv[1]);
        Second_arg=QString(argv[2]);

        ProgramCode();


    }
    else
    {









    if(argc==1)
    {
        //qDebug() << "ffffff!!!";
    }

    QFile Pos_File;
    QByteArray buf_file;
    char *Pos_x;
    char *Pos_y;
    int Int_Pos_x;
    int Int_Pos_y;
    char *ch_buf_file;
    int counter_mas[2];
    counter_mas[0]=0;
    MainWindow w;

    //w.readSettings();
    w.setFixedSize(448, 331);

       w.show();



        Pos_File.setFileName("Pos.txt");
        if(Pos_File.exists())
        {

            if(!Pos_File.open(QIODevice::ReadOnly))
            {
                printf("Mistake during opening the file!");
                QApplication::quit();
            }
            buf_file=Pos_File.readAll();
            ch_buf_file=buf_file.data();
            //printf("ch_buf_mas=%s\n", ch_buf_file);

            while(ch_buf_file[counter_mas[0]]!=';')
            {
               counter_mas[0]++;
            }
            Pos_x=(char*) malloc(counter_mas[0]*sizeof (char));
            counter_mas[0]=0;
            counter_mas[1]=0;
            while(ch_buf_file[counter_mas[0]]!=';')
            {
                Pos_x[counter_mas[0]]=ch_buf_file[counter_mas[0]];
                counter_mas[0]++;
                counter_mas[1]++;
            }
            //printf("Pos_x=%s\n", Pos_x);
            counter_mas[0]=0;
            counter_mas[1]++;


            //printf("symb=%c\n", ch_buf_file[counter_mas[1]]);
            while(ch_buf_file[counter_mas[1]]!=';')
            {
               counter_mas[0]++;
               counter_mas[1]++;
            }
            //printf("numb:=%d\n", counter_mas[0]);
            Pos_y=(char*) malloc(counter_mas[0]*sizeof (char));
            counter_mas[1]=counter_mas[1]-counter_mas[0];
            counter_mas[0]=0;
            //counter_mas[1]=0;
            while(ch_buf_file[counter_mas[1]]!=';')
            {
                Pos_y[counter_mas[0]]=ch_buf_file[counter_mas[1]];
                counter_mas[0]++;
                counter_mas[1]++;
            }
            //printf("Pos_y=%s\n", Pos_y);


            Int_Pos_x=atoi(Pos_x);
            Int_Pos_y=atoi(Pos_y);


            //printf("Int_Pos_x=%d\n", Int_Pos_x);
            //printf("Int_Pos_y=%d\n", Int_Pos_y);
            w.move(Int_Pos_x, Int_Pos_y);

            free(Pos_x);
            free(Pos_y);

            Pos_File.close();
        }




    //w.move(100, 100);Pos_File.setFileName("POS.txt");
    //MainWindow::readSettings();

    //printf("y=%d\n", w.y());


        return a.exec();
       }

     //QApplication::quit();
}

void ProgramCode(void)
{

    counter_mas[34]=0;
    counter_mas[35]=0;

    //Call_Worker();
    //Номинальные значения признаков

    // qDebug()<<"@@@@@@@@@@@@";

   Mas_Nominal_features[0]="config_vs = 0x2669";
    Mas_Nominal_features[1]="prpvv1 = 0x0001";
    Mas_Nominal_features[2]="supplyd = 0x0007";
    Mas_Nominal_features[3]="ss_bcvs = 0xFFFF";
    Mas_Nominal_features[4]="vkl_gr = 0x0007";
    Mas_Nominal_features[5]="pfi_reg = 0x0007";
    Mas_Nominal_features[6]="pti_mass(0) = 0x00FF";
    Mas_Nominal_features[7]="pti_mass(1) = 0x00FF";
    Mas_Nominal_features[8]="pti_mass(2) = 0x00FF";
    Mas_Nominal_features[9]="pti_mass(3) = 0x0000";
    Mas_Nominal_features[10]="mpo_mas_ks_err = 0x0000";

    Qt_Zg_Name="Cg2";

    Qt_sbl_file.clear();
    Qt_kdr_file.clear();

    Qt_sbl_file=QCoreApplication::applicationDirPath()+"/Cyclograms/"+First_arg+".sbl";


    Qt_Dir_Folder=QDir::fromNativeSeparators(Second_arg);
    //dir.dirName()

    QDir dir(Qt_Dir_Folder);
    dir.setSorting(QDir::Name);
    QFileInfoList list=dir.entryInfoList();
    int r=0;
    for(r=0; r<list.size(); ++r)
    {
        QFileInfo fileInfo=list.at(r);
        line+=fileInfo.fileName()+"#";

    }
    qDebug()<<"dd"<<line;

    while(counter_mas[35]!=line.count())
    {
        if(line[counter_mas[35]]!='#')
        {
            Qt_Kdr_name_file.append(line[counter_mas[35]]);
            counter_mas[35]++;
        }
        else
        {
            if(Qt_Kdr_name_file.contains(".kdr"))
            {
                break;
            }
            else
            {
                Qt_Kdr_name_file.clear();
            }
            counter_mas[35]++;

        }
       //qDebug()<<"letter:"<<Qt_kdr_file;
    }

    Qt_kdr_file=Second_arg+"\\"+Qt_Kdr_name_file;
    qDebug()<<"line:"<<Qt_kdr_file;
    //Qt_kdr_file=Second_arg+"/TMI"+".kdr";
    //Qt_sbl_file="C:\\Users\\User\\Desktop\\QT_Zikl2\\build-Ziklogramma2-Desktop_Qt_5_6_1_MinGW_32bit-Release\\release\\Cyclograms\\Elk3.sbl";
    //Qt_kdr_file="C:\\Users\\User\\Desktop\\QT_Zikl2\\build-Ziklogramma2-Desktop_Qt_5_6_1_MinGW_32bit-Release\\release\\temp\\TMI.kdr";
    Qt_sbl_file = QDir::fromNativeSeparators(Qt_sbl_file);
    Qt_kdr_file = QDir::fromNativeSeparators(Qt_kdr_file);
    Call_Worker();


    Qt_Inf_Zg=QCoreApplication::applicationDirPath()+"/Cyclograms/"+First_arg+".a96";//= ui->lineEdit_2->text();
    Ch_Inf_Zg=qPrintable(Qt_Inf_Zg);

    qDebug()<<"input files:";

    qDebug()<< Qt_sbl_file;
    qDebug()<< Qt_kdr_file;

    if((flag&=(1<<16)))
        {
            vect_Cg_name.clear();
            flag&=~(1<<16);
        }
    /*flpath=ui->lineEdit_2->text();
    flpath.remove(flpath.lastIndexOf("/"),flpath.count()-flpath.lastIndexOf("/"));

    flpath_2=ui->lineEdit_4->text();
    flpath_2.remove(flpath_2.lastIndexOf("/"),flpath_2.count()-flpath_2.lastIndexOf("/"));




    Qt_Inf_Zg = ui->lineEdit_2->text();


    if(!Qt_Inf_Zg.isEmpty())
    {
       flag|=(1<<19);
       Qt_Zg_Name=ui->comboBox->currentText();

    }*/



    //Qt_Prot_Name = ui->lineEdit_3->text();



    //Qt_Tel_Name=out
   /*Qt_Tel_Name.clear();//

    Qt_Tel_Name = ui->lineEdit_4->text();*/ //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    //QString Qt_OPA_Name = ui->lineEdit_5->text();
    /*ui->label->setText(Qt_Zg_Name);
    ui->label_2->setText(Qt_Inf_Zg);
    ui->label_3->setText(Qt_Prot_Name);
    ui->label_4->setText(Qt_Tel_Name);*/


    //qDebug() << Qt_Zg_Name;
    /*Qt_Zg_Name=Qt_Zg_Name+"\0";
    Ch_Zg_Name = Qt_Zg_Name.toStdString().data();*/
    /*Qt_Tel_Name=Qt_Tel_Name+"\0";
    Ch_Tel_Name = Qt_Tel_Name.toStdString().data();*/
    //Ch_Zg_Name = Qt_Zg_Name.toStdString().data();
    /*Qt_Inf_Zg=Qt_Inf_Zg+"\0";
    Ch_Inf_Zg = Qt_Inf_Zg.toStdString().data();
    Qt_Prot_Name=Qt_Prot_Name+"\0";
    Ch_Prot_Name = Qt_Prot_Name.toStdString().data();*/

    /*qDebug() << Qt_Zg_Name;

    Ch_Zg_Name=qPrintable(Qt_Zg_Name);

    Ch_Tel_Name=qPrintable(Qt_Tel_Name);
    Ch_Inf_Zg=qPrintable(Qt_Inf_Zg);
    Ch_Prot_Name=qPrintable(Qt_Prot_Name);

    qDebug() << Ch_Zg_Name;*/



    /*Ch_Zg_Name=(char*)malloc((Qt_Zg_Name.count())*sizeof(char));


    for(counter_mas[31]=0; counter_mas[31]<12; counter_mas[31]++)
    {
        Ch_Zg_Name[counter_mas[31]]=Qt_Zg_Name[counter_mas[31]];


    }*/

    //qDebug() << Ch_Zg_Name;

    /*int coun;
    while(Ch_Prot_Name[coun]!='\0')
    {
        coun++;

    }*/
    //const char* Ch_OPA_Name = Qt_OPA_Name.toStdString().data();
    /*File_Info.setFileName("LAST.txt");
    if(!File_Info.open(QIODevice::WriteOnly))
    {
        printf("Mistake during opening the file!");
        QApplication::quit();
    }

     File_Info.write(Ch_Tel_Name);
     File_Info.write("\r\n");
     File_Info.write(Ch_Prot_Name);
     File_Info.write("\r\n");
     File_Info.write(Ch_Inf_Zg);
     File_Info.write("\r\n");
     File_Info.write(Ch_Zg_Name);



    File_Info.close();*/


    /*ui->label_2->setText(Qt_Zg_Name);
    ui->label_3->setText(Qt_Prot_Name);*/


   // printf("hjkjj");
   // ui->label->setText("ририииииииииии!");
    //ui->textEdit->setText("fgfdsgdgfsdgdsgdsfdfffffffffffffffffffsssss");




    /*QDebug()<<Qt_Zg_Name;
    QDebug()<<Qt_Inf_Zg;
    QDebug()<<Qt_Prot_Name;
    QDebug()<<Qt_Tel_Name;*/




    /*ui->lineEdit->deleteLater();
    ui->lineEdit_2->deleteLater();
    ui->lineEdit_3->deleteLater();
    ui->lineEdit_4->deleteLater();*/

    /*printf("file_inf_zg=%s\n", Ch_Inf_Zg);
    printf("name_zg=%s\n", Ch_Zg_Name);
    printf("file_tel_inf=%s\n", Ch_Tel_Name);
    printf("name_of_prot=%s\n", Ch_Prot_Name);*/
    //qDebug() << "1!\n";
    //printf("OPA=%s\n", Ch_OPA_Name);





//setlocale(LC_ALL, "Rus");
    //Create_XML_Doc();

    /*if(argc==1)
    {
        Instruction();
        return 1;
    }
    if(argc==2)
    {
        printf("Слишком мало аргументов!\n");
        return 2;
    }*/
    //Sleep(2000);
    qDebug() << "Qt_Tel_Name:";

    qDebug() << Qt_Tel_Name;

    //Qt_Zg_Name="";

     Ch_Tel_Name=qPrintable(Qt_Tel_Name);
     qDebug() << "Ch_Tel_Name:";
     qDebug() << Qt_Tel_Name;
    file=fopen(Ch_Tel_Name, "r");
    /*Ch_Prot_Name=qPrintable(Qt_Prot_Name);
    protocol=fopen(Ch_Prot_Name, "w");*/
    //printf("Ch_Pr_Name=%s\n", Ch_Prot_Name);
    flag|=(1<<19);




   if(flag&(1<<19))
    {
       qDebug()<<"AAAAAAAAAAAAAAAAAAAAAAAAAAA!!!!!!";
       Ch_Inf_Zg=qPrintable(Qt_Inf_Zg);
       qDebug()<<Ch_Inf_Zg;
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
           //QMessageBox::critical(this, "Ошибка!", "Ошибка при открытии файла с информацией циклограммы");
           flag|=(1<<16);
           qDebug()<<"LLLLLL!!!!!!!!";
           //ui->comboBox->clear();
          // QApplication::quit();
       }
           //printf("AAAAAAAAAA!\n");

      }

       if(file==NULL)
   {
       printf("Не удалось открыть файл %s!\n", Ch_Tel_Name);
       qDebug()<<"JJJ!!!";
       //QMessageBox::critical(this, "Ошибка!", "Ошибка при открытии файла телеметрической информации");
       flag|=(1<<16);
       //exit(2);
   }







        /////////////////////
        Quant_Of_Symbl_In_File();
        //qDebug()<<quant_of_symb_in_Tel_file;

        quant_of_symb_in_Tel_file=quant_of_symb_in_Tel_file_norm;
        while(count_features!=11)
        {
            fseek(file, 0, SEEK_SET);
            Nominal_features=Mas_Nominal_features[count_features];
            Test_of_others_features();
            WrongFeatures.append(Nominal_features);
            if(!Nominal_features.isEmpty())
            {
              WrongFeatures.append(";");
            }
            //qDebug()<<Nominal_features;
            quant_of_symb_in_Tel_file=quant_of_symb_in_Tel_file_norm;
            count_features++;
            fseek(file, 0, SEEK_SET);
        }
        //qDebug()<<quant_of_symb_in_Tel_file;






        ////////////////////
        quant_of_symb_in_Tel_file=quant_of_symb_in_Tel_file_norm;

        Test_Rtvk_Vkl();

        fseek(file, 0, SEEK_SET);
        qDebug()<<"WrongFeatures:"<<WrongFeatures;
        qDebug()<<"RealValues:"<<RealValues;






if(flag&(1<<19))
{


    vect_Cg_name.clear();
    qDebug() << "111";

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
            //QMessageBox::critical(this, "Ошибка!", "Ошибка в имени циклограммы!");
            qDebug() << "!!!";
            flag|=(1<<16);
            //qApp->quit();
            //exit(4);
        }

    }
    else
    {
        //QMessageBox::critical(this, "Ошибка!", "Ошибка в имени циклограммы!");
        flag|=(1<<16);
    }

    //--------------------------------------------------------------------------
    counter_mas[0]=0;

    for(support_var=0; support_var<25; support_var++)
    {
        counter_mas[support_var]=0;
    }
    //--------------------------------





     qDebug()<<"11111";

    //------------------------------------------------------------------
    if(!(flag&=(1<<16)))
    {

        qDebug()<<"00000";
    if(!(flag&=(1<<16)))
        {
            //printf("BBBBBBBB!\n");

        }


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



    qDebug() << "222";
    ///


    Inst_Count_To_Pos();


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




                //---------------------------------------------------------------------------

                //Treatment_of_Mistakes();
                if(flag&=(1<<16))
                {
                   //QMessageBox::critical(this, "Ошибка!", "Ошибка в имени циклограммы!");
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
    qDebug() << "333";
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
    //qDebug() << "Counter_mas[34]:"<<counter_mas[34];
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

    /*SecondWindow window;
    window.setModal(true);
    window.exec();*/

    //QMainWindow::close();
    Form_inf_file();


    fclose(file);
    fclose(input);
    QApplication::quit();

    }

    else
    {
        //QMessageBox::critical(this, "Ошибка!", "Файл с телеметрической информацией содержит данные больше чем одного испытания");
        Print_Out_Inf_To_Dialog();
        /*SecondWindow window;
        window.setModal(true);
        window.exec();*/

        //QMainWindow::close();
        Form_inf_file();

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
    else
    {
        //QMessageBox::critical(this, "Ошибка!", "Файл с телеметрической информацией содержит данные больше чем одного испытания");
       /* Print_Out_Inf_To_Dialog();
        SecondWindow window;
        window.setModal(true);
        window.exec();*/


        //QMainWindow::close();
        Form_inf_file();
        fclose(file);
        //fclose(input);
        qDebug()<<"KKKKKK!!!";
        QApplication::quit();

    }

 }
 else
 {
     //QMessageBox::critical(this, "Ошибка!", "Файл с телеметрической информацией содержит данные больше чем одного испытания");
    /* Print_Out_Inf_To_Dialog();
     SecondWindow window;
     window.setModal(true);
     window.exec();*/


     //QMainWindow::close();
     Form_inf_file();
     fclose(file);
     //fclose(input);
     qDebug()<<"KKKKKK!!!";
     QApplication::quit();

 }







}
void Form_inf_file(void)
{
    QString Path_to_Res;
    Path_to_Res=Second_arg+"/result.rez";
    Path_to_Res = QDir::fromNativeSeparators(Path_to_Res);
    QFile res(Path_to_Res);
    const char* Qt_Prot_Name_Char;
    if(res.exists())
    {
        res.remove();
    }
    char const* WrongFeaturesChar;
    char *norm;
    //qDebug()<<"!!!:"<<WrongFeatures;
    if(WrongFeatures.contains(":5:"))
    {
        //
        if(WrongFeatures.lastIndexOf("rtvk_vkl(19) = 0x0000")>WrongFeatures.indexOf(":5:"))
        {

            if(WrongFeatures.lastIndexOf("rtvk_vkl(20) = 0x0001")>WrongFeatures.indexOf(":5:"))
            {
                WrongFeatures.remove(WrongFeatures.lastIndexOf("rtvk_vkl(19) = 0x0001")-21, 22);
                WrongFeatures.remove(WrongFeatures.lastIndexOf("rtvk_vkl(20) = 0x0000")-21, 22);
                if(WrongFeatures.contains("prpvv1 = 0x0001"))
                {
                    WrongFeatures.remove("prpvv1 = 0x0001;");
                }

                //qDebug()<<"!!!sfddddsggggggggggg";
                //

                if((WrongFeatures.lastIndexOf("rtvk_vkl")<WrongFeatures.indexOf(":5:"))||(!WrongFeatures.contains("rtvk_vkl")))
                {
                   WrongFeatures.remove(":5:");

                }
            }



        }

    }
    //WrongFeatures.remove("prpvv1 = 0x0001;");
    if((quant_point_less30per>0)||(!WrongFeatures.isEmpty()))
    {
        norm="Не норма";
    }
    else
    {
        norm="Норма";
    }
    WrongFeatures="Значения следующих признаков не верны: "+WrongFeatures;
    WrongFeaturesChar=qPrintable(WrongFeatures);
    TiXmlDeclaration *dec1 = new TiXmlDeclaration("1.0", "utf-8", "");//XML декларация
    TiXmlComment *Comment= new TiXmlComment("Результаты работы ОТМИ в части таймирования");
    //TiXmlText *name_prot_file = new TiXmlText("test");
    info.LinkEndChild(dec1);
    info.LinkEndChild(Comment);

    TiXmlElement *ResAnaliz = new TiXmlElement("RezAnaliz");

    TiXmlElement *Res = new TiXmlElement("Rez");
    TiXmlElement *VersSPO = new TiXmlElement("VersSPO");
    TiXmlText *VerSPO=new TiXmlText("Cyclogram_17_03_2020");
    TiXmlElement *PodSist = new TiXmlElement("PodSist");
    TiXmlElement *Files = new TiXmlElement("Files");
    TiXmlElement *files = new TiXmlElement("file");
    TiXmlElement *Komm = new TiXmlElement("Komm");
    TiXmlText *Komment=new TiXmlText(WrongFeatures.toUtf8().constData());
    qDebug()<<"WrFeat"<<WrongFeatures;
    if(!WrongFeatures.remove("Значения следующих признаков не верны: ").isEmpty())
    {
        //qDebug()<<"reefghfcgh";
        Komm->LinkEndChild(Komment);

    }
    Qt_Prot_Name=Qt_Prot_Name+".ods";
    Qt_Prot_Name_Char=qPrintable(Qt_Prot_Name);
    if(!Qt_Prot_Name.remove(".ods").isEmpty())
    {
        files->LinkEndChild(new TiXmlText(Qt_Prot_Name_Char));
    }

    VersSPO->LinkEndChild(VerSPO);

    Res->LinkEndChild(new TiXmlText(norm));




    ResAnaliz->LinkEndChild(Res);

    ResAnaliz->LinkEndChild(Komm);
    ResAnaliz->LinkEndChild(VersSPO);
    ResAnaliz->LinkEndChild(PodSist);
    Files->LinkEndChild(files);
    ResAnaliz->LinkEndChild(Files);

   info.LinkEndChild(ResAnaliz);


   qDebug()<<"YYYY";



    info.SaveFile("result.rez");
    QFile::copy("result.rez", Second_arg+"/result.rez");


}
void Create_ODS_File(void)
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

    /*if(!MainWindow::IsFoldExist("META-INF"))
        {
        QMessageBox::critical(this, "Ошибка!", "Ошибка при создании файла протокола!");
        exit(1);

        }*/
    CopyFile(L"manifest.xml",L"META-INF/manifest.xml",TRUE);

    //CopyFile()

    counter_mas[32]=0;

    Empty.clear();
    Qt_Tel_Name = "TMI.txt";
    Qt_Tel_Name.remove(Qt_Tel_Name.count()-4, 4);
    while(counter_mas[32]!=Qt_Tel_Name.count())
    {
        if(Qt_Tel_Name[counter_mas[32]]=='/')
        {
           Pos_Of_slash=counter_mas[32];

        }

        counter_mas[32]++;

    }



    //Qt_Tel_Name.remove(0, Pos_Of_slash+1);

    Qt_SystemInf=Empty+"Protocol_"+Qt_Tel_Name+".ods";
    qDebug()<<"Qt_SystemInf:";
    qDebug()<<Qt_SystemInf;
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
    Qt_Tel_Name = "TMI.txt";

    Qt_Tel_Name.remove(Qt_Tel_Name.count()-4, 4);

    //Qt_Tel_Name.remove(0, Pos_Of_slash+1);

    //const char* Ch_Prot_Name_2;

    //Qt_SystemInf=Empty+"\"7za.exe\" "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+Qt_Tel_Name+".ods"+" content.xml";
    Qt_SystemInf=Empty+"7za.exe "+"a "+"-tzip "+"-mx=1 "+"Protocol_"+Qt_Tel_Name+".ods"+" content.xml";
    qDebug()<<Qt_SystemInf;
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
    //cout << stdString;
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
bool IsFoldExist(const std::string &s)
{
    struct stat buffer;
    return(stat(s.c_str(), &buffer)==0);
}










