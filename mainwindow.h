#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLayout>
#include <QtGui>
#include "ui_mainwindow.h"
#include <QtDebug>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <vector>
#include <iostream>
#include "tinyxml.h"
#include "secondwindow.h"
#include <QProgressBar>

using namespace std;

int Transl_To_Dec_System(char Num1, char Num2, char Num3, char Num4);
int Conv_Of_Types(char num);
int Conv_Char_To_Int(char *chislo);
int power(int number, int indicator);
//int Search_Cg(int flag_cg, char *mas_inp_file, int quantity);
void Show_Vector(vector <char> vect);
void Instruction(void);
//void Treatment_of_Mistakes(void);//Функция обработки ошибок во вводе имён циклограмм
void Install_Counter(void);//Выставление счётчика на нужную позицию для считывания необходимого имени циклограммы из массива Cg_Names
void Check_Quantity_CgSymbols(void);//Считает символы в именах циклограмм в файле с циклограммами
void Read_Zg_File(void);//Для чтения информации о циклограмме (из файла)
void Read_Stock_Inf_In_Mas(void);//Выводит информацию о времени по циклограмме в отдельный массив
void Read_Cg_Names_In_Mas(void);//Для чтения имён циклограмм которые присутствуют во входном файле циклограммы в отдельный массив
void Read_In_Mas_Module_Names(void);//Для чтения в массив имён программных модулей
void Find_Quant_Of_Sides_And_Size_Of_Pass(void);//Для определения количества граней и размера пропусков в массиве значений value_pvv
void ReWrite_Value_pvv_InVector(void);//Переписывание value_pvv из файла с телеметрией в вектор mas_file
void Preparation_Results_and_Output(void);//Полготовка массивов с результатами и вывод значений данных массивов на экран
void Create_XML_Doc(void);//Создаёт и XML документ и заполняет шапку таблицы
void Fill_Hat(void);//Заполняет шапку таблицы
void Fill_Rows(void);//Заполняет строки таблицы
void End_Xml_Doc(void);//Завершает Xml документ
void Inst_Count_To_Pos(void);//Устанавливает счётчик на позицию для считывания информации циклограммы
//void Form_PopupCgNamesList(void);//Создаёт всплывающий список с именами циклограмм
void Print_Out_Inf_To_Dialog(void);//Печатает выходную информацию программы в диалоговое окно
void Print_Out_Inf_On_Screen(const char *argv, vector <char> vect_Cg_Name, int quantity, int pvv_quantity, int quant_of_sides, int quant_point_less30per);
//void Create_ODS_File(void);//Создаёт ODS файл
void Read_File_Inf(void);
//void Create_Err_Message(void);//Создаёт сообщение об ошибке в случае, если файл с телеметрической информацией содержит данные об нескольких испытаниях
bool Call_Worker(void);//Вызывает обработчик Worker.exe
void Quant_Of_Symbl_In_File(void);//Подсчитывает число символов в file
void Test_of_others_features(void);//Проверяет остальные признаки
void Test_Rtvk_Vkl(void);//Проверка значений массивов rtvk_vkl, начиная с 11 элемента третьего кадра (признаки, касающиеся БВУ)
void Test_Rtvk_Vkl_Mov_Point_to_Pos(void);//Перемещает указатель в файле для чтения rtvk_vkl в кадрах
void Test_Rtvk_Init(void);//Инициализирует массив номинальных значений rtvk_vkl
void Value_pvv_analysis(void);//Осуществляет анализ в части признаков value_pvv
void Analys_changing_values();//Осуществляет анализ в части изменяющихся в файле ТМИ значений признаков
void Explore_rtvk_mas();//Выясняет количество кадров rtvk, выдаваемых одновременно
void Check_rtvk_vkl_value(int number_of_par);//Проверяет значение конкретного rtvk_vkl
void Init_Normative_values(void);//Инциализирует нормативные значения признаков для БВУ
void Init_Normative_values_BUK(void);//Инциализирует нормативные значения признаков для БВУ
void Set_Table_Head(void);//Формирует шапку таблицы для вывода в QDialog
void Create_Report_allPar_File(void);//Формирует файл протокола со сведениями о ненормативных значениях признаков, характеризующих работу БВУ и БУК
void Create_Odt_XML_manifest(void);//Создаёт файл manifest.xml для формирования протокола
void Write_Styles(TiXmlElement *el);//Записывает стили в content.xml протокола
bool IsFoldExist_2(const std::string &s);
void Form_Content_Prot(TiXmlElement* Office_Text);//Формирует содержание протокола
void SetTextProt(QString necessary_text, QString name_style, TiXmlElement* Office_text);//Вставляет необходимый текст в протокол
void SetTable(TiXmlElement* Office_Text, vector <QString> NamePar, vector <QString> NormValue, vector <QString> TMI_Value, int style);//Формирует таблицы в протоколе
void Write_SZO_vector();//Формирует запись в векторе СЗО
void SZO_Out();//Выводит информацию о обнаруженных СЗО в диалоговое окно
QString Form_SZO_Descr(QString Value);//Формирует описание СЗО исходя из его значения


extern int Perem;

extern QString Qt_OutFile_name;
extern QString Qt_kdr_file;
extern QString Qt_sbl_file;
extern int counter_mas[36];
//////////
///
///
extern char *Cg_Names;

extern int flag;
//extern int counter_mas[35];
extern vector <char> vect_Cg_name;
extern char *Cg_Name;
extern char symbol;
extern FILE *input;
extern FILE *file;
extern FILE *protocol;
extern int support_var;
extern int priznak0;
extern int priznak1;
extern int priznak2;
extern int priznak3;
extern int res;
extern int ind;
extern int sign;
extern float start_time;
extern int quant_point_less30per;
extern float stock;
extern int stock_msk;
extern int znach1;
extern int znach2;
extern int column_num;
//int fix_value=0;
extern int compare2;
extern int max_flag;
extern int list_of_remove[9];
extern int size_of_empty;
extern int empty_flag;
extern int time_of_work_side;
extern int quant_of_sides;
extern int num_of_pvv[1000];
extern int pvv_quantity;
extern int pos_of_cg_name;
extern int num_of_point;
extern int storage[25];
extern int Num;
extern int Perem;
extern int Var1_on_time;
extern int Var2_on_time;
extern int quantity;
extern int Pos_Of_slash;
    //char *mas=NULL;
//char *mas_inp_file=NULL;
extern char str[100];
extern char size_of_col[8];
    //char *Cg_Names=NULL;
    //int mas_inp_int_inf[10000];
    //char mas_inp_char_inf[10000];
    //char mas_inp_inf[100000];

extern vector <char> mas_file;
    //vector <char> vect_Cg_name;
extern vector <char> vect_mas_inp_inf;
extern vector <char> vect_mas_inp_char_inf;
extern vector <int> vect_mas_inp_int_inf;
extern vector <int> vect_time_in_ZG;
extern vector <int> fix_value;
extern vector <char> vect_mas_inp_file;
extern vector<TiXmlElement*> vect_table_row;
extern vector<TiXmlElement*> vect_table_cell;
extern vector<TiXmlElement*> vect_text_p;
extern vector<TiXmlText*> vect_tixml_text;
extern vector <TiXmlElement> vector_TiXml;
extern TiXmlDocument doc;
extern TiXmlDocument ods;
extern char storage2[20];
extern int quant_sym;
extern char chislo[3];
extern int counter_read1;
extern int counter_read2;
extern char buffer[30];
extern char Num1, Num2, Num3, Num4;
    //char symbol;
extern int countt;
extern float Var1_float;
extern float Var2_float;

extern QString Qt_Inf_Zg;
extern QString Qt_Zg_Name;
extern QString Qt_Prot_Name;
extern QString Qt_Tel_Name;
extern QString Qt_sbl_file;
extern QString Qt_kdr_file;
extern QString Qt_Buf_LineEdit;
extern QString flpath;
extern QString flpath_2;

extern QString Qt_OutFile_name;
extern QString Qt_SystemInf;
extern QString test;
extern QString Empty;

extern QString ComboBox_Item;


//QFile File_Info;
extern QFile Pos_File;
extern QFile report_file;


extern ifstream Inf_file;
extern QByteArray buf;
extern const char* Ch_Tel_Name;
extern const char* Ch_Zg_Name;
extern const char* Ch_Inf_Zg;
extern const char* Ch_Prot_Name;
//extern QSettings settings("MARS", "TMIWatcher");
extern char *buf_to_pos_file;
extern int counter;

extern int Pos_y;
extern int Pos_x;
extern LPSTR array_test;
extern STARTUPINFOA cif;
extern PROCESS_INFORMATION pi;
extern string stdString;

//extern QString Mas_Nominal_features[20];

extern vector <QString> Mas_Nominal_features;

extern int quant_of_symb_in_Tel_file;
extern int quant_of_symb_in_Tel_file_norm;

extern QString Nominal_features;
extern int count_features;
//extern QString Mas_Nominal_features[20];
extern QString WrongFeatures;
extern QString RealValues;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool IsFoldExist(const std::string &s);
    void Create_ODS_File(void);//Создаёт ODS файл
    void Form_PopupCgNamesList(void);//Создаёт всплывающий список с именами циклограмм




private slots:
    void on_pushButton_clicked();


    void on_toolButton_clicked();

    void on_toolButton_3_clicked();

    void closeEvent(QCloseEvent *event);


    //void readSettings();

    //void on_toolButton_2_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QProgressBar *progressBar;
    MainWindow *Window;
};

#endif // MAINWINDOW_H
