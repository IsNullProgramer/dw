// CW.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <list>
//Библиотека для использования кириллицы
#include "clocale"
#include <locale>
#include "Windows.h"
#include <iostream>
#include <fstream>// библиотека для работы с файлами
#include <string>
#include "class.cpp"
using namespace std;
// В с++ методы доступа являются формальностью. Не существует жетского определения set и get. Любой член класса, возращающий значение private будет get

//Описание класса Меню
class Menu 
{
private:
	int number;
public:
	void output_mainmenu()
	{
		cout << "Главное меню программы, для выбора пункта введите его номер \n";
		cout << "\n 1. Работа с сотрудниками";
		cout << "\n 2. Работа с подразделениями";
		cout << "\n    Для выхода из программы введите любой другой символ";
	}
	// ---------------------------------------------------------- 
	void output_Emenu() // Функция вывода меню на экран
	{
		cout << "Управление сотрудниками \n\n";
		cout << "\n 1. Нанять работника";
		cout << "\n 2. Вывод информации об одном сотруднике:";
		cout << "\n 3. Вывод информации обо всех сотрудниках";
		cout << "\n 4. Удаление одного сотрудника из файла";
		cout << "\n 5. Удаление всех сотрудников из файла";
	}
	// ---------------------------------------------------------- 
	void output_Dmenu()
	{
		cout << "\n    Управление подразделениями";
		cout << "\n 1. Добавить подразделение";
		cout << "\n 2. Вывод информации об одном подразделении";
		cout << "\n 3. Вывод информации обо всех подразделений";
		cout << "\n 4. Удаление одного подразделения";
		cout << "\n 5. Удаление всех подразделений";
	}
	// ---------------------------------------------------------- 
	int choose_number() // Функция выбора паремтра меню
	{
		cout << "\nВведите параметр меню: "; cin >> number;
		return number;
	}

};

//-----------------------------------------------------------------------------


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);

	int flag = 1;
	while (flag = 1)
	{
		Menu M1;
		
			M1.output_mainmenu();
			int mainnum = M1.choose_number();
			//Выбор пункта главного меню
			if (mainnum == 1)
			{//работа с подменю управления сотрудникками
				employee Employee_base;
				M1.output_Emenu();
				int nnumber = M1.choose_number();
				switch (nnumber)
				{
				case 1:
					Employee_base.AddEmployee();
					break;
				case 2:
					Employee_base.Out_String();
					break;
				case 3:
					Employee_base.OutEmployee();
					break;
				case 4:
					Employee_base.Delete_String();
					break;
				case 5:
					Employee_base.Delete_employee();
					break;
				default:
					cout << "Действие не выбрано";
				}
			}
			//работа с подменю управления подразделениями
			else if (mainnum==2)
			{
				division Subdivision_base;
				M1.output_Dmenu();
			int snumber = M1.choose_number();
			switch (snumber)
				{
			case 1:
				Subdivision_base.Adddivision();
				break;
			case 2:
				Subdivision_base.out_onediv();
				break;
			case 3:
				Subdivision_base.outdivision();
				break;
			case 4:
				Subdivision_base.del_div();
				break;
			case 5:
				Subdivision_base.delall();
				break;
				}
			}
			else exit(0);
			
		cout << endl;
		//Организация повторного использования программы
		cout << "Еще раз? 1 - ДА / 0 - Нет: "; cin >> flag;
		cout << endl;

		if (flag == 0)exit(0);
	}

	system("pause");
	return 0;
}
