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
using namespace std;

class division
{
	//     Имя подразделения, Количество персонала, Месячный фонд заработной платы, годовой фонд заработной платы
private:
	string subdivision, staff_quantity, mfund, yfund;
	string all;
public:


	~division() {};


	//----------------------------------------------------------------------
	void Adddivision()
	{
		ofstream file;
		file.open("Beta.txt", ios_base::app); // открываем файл

		if (!file) //Проверка на открытие файла
		{
			cout << "Файл не открыт\n\n";
		}
		else
		{
			cout << "Файл открыт корректно!\n\n";
		}
		//Ввод данных в поля
		cout << "Введите наименование подразделения: ";   cin.get(); getline(cin, subdivision);
		cout << "Введите количество персонала ";  getline(cin, staff_quantity);
		cout << "Введите месячный фонд заработной платы: "; getline(cin, mfund);
		cout << "Введите годовой фонд заработной платы: ";  getline(cin, yfund);
		//Запись всех полей в одну строку. Это нужно для записи в файл
		all = "Подразделение: " + subdivision + "; " + "количество персонала в нём: " + staff_quantity + "; " + "месячный фонд заработной платы: " + mfund + "; " + "годовой фонд заработной платы " + yfund;
		// Запись в файл данных
		file << all;
		file << "\n";
		file.close();
	};
	//----------------------------------------------------------------------
	void outdivision()
	{
		ifstream file;
		file.open("Beta.txt"); // открываем файл

		if (!file)//проверка на открытие файла
		{
			cout << "Файл не открыт\n\n";
		}
		else
		{
			cout << "Файл открыт коректно!\n\n";
		}

		char St[1024];

		while (1)
		{ //Считывание данных из файла и запись в массив St с последующим его выводом на экран внутри цикла
			if (file.eof()) break;
			file.getline(St, sizeof(St));
			cout << St << endl;
		}
		file.close();
	};
	//----------------------------------------------------------------------
	void out_onediv()
	{
		ifstream file;
		file.open("Beta.txt");//открытие файла на чтение

		char Mass[1024];
		int StringNumber = 0;//хранит номер строки
		cout << "Введите номер строки для вывода: "; cin >> StringNumber;

		/*считываем файл до конца*/
		while (1)
		{
			file.getline(Mass, sizeof(Mass));
			StringNumber--;
			if (StringNumber == 0)break;
		}
		cout << Mass;
		file.close();

	};
	//----------------------------------------------------------------------
	void delall()
	{
		ofstream file;
		file.open("Beta.txt", ios::trunc); // открываем файл
		file.close();
		cout << endl << "Все записи удалены успешно." << endl;
	};
	//----------------------------------------------------------------------
	void del_div()
	{
		ifstream file;
		file.open("Beta.txt"); // Открытие файла

		if (!file)//проверка на открытие файла
		{
			cout << "Файл не открыт\n\n";
		}
		else
		{
			cout << "Файл открыт коректно!\n\n";
		}

		int s = 0; // Номер строки которую необходимо удалить
		int k = 0; // Счетчик строк
		string Line;
		string Line_File; // Хранение текста файла

		cout << "Введите номер строки для удаления: ";
		cin >> s;

		while (getline(file, Line))
		{
			k++;
			if (!(k == s))
			{
				Line_File.insert(Line_File.size(), Line); //добавление строки
				Line_File.insert(Line_File.size(), "\r\n");	//добавление переноса на следующую строку
			}
		}

		file.close();
		std::ofstream file_out;
		file_out.open("Beta.txt", std::ios::trunc | std::ios::binary);
		file_out.write(Line_File.c_str(), Line_File.size());
		file_out.clear();
		cout << "Строка успешно удалена \n";
	};
};
class employee // Класс информации о работнике и членах его семьи
{
private:
	//     Имя,  Фамилия, Отчество,   адрес, Дата рождения, должность, дата найма, стаж работы, оклад
	string Name, surname, patronymic, adres, bdate, position, hdate, workexp, fee;
	string ALL;
public:

	~employee() {}; // деструктор (используется для удаления объекта класса)


//--------------------------------------------------------------------------
	void AddEmployee() //Добавить личную информацию
	{
		ofstream file;
		file.open("Alfa.txt", ios_base::app); // открываем файл

		if (!file) //Проверка на открытие файла
		{
			cout << "Файл не открыт\n\n";
		}
		else
		{
			cout << "Файл открыт корректно!\n\n";
		}
		//Запись данных о сотруднике в поля
		cout << "Введите фамилию сотрудника: "; cin.get(); getline(cin, surname);
		cout << "Введите имя сотрудника "; getline(cin, Name);
		cout << "Введите отчество сотрудника: "; getline(cin, patronymic);
		cout << "Введите адрес сотрудника: "; getline(cin, adres);
		cout << "Введите дату рождения: "; getline(cin, bdate);
		cout << "Введите должность сотрудника: "; getline(cin, position);
		cout << "Введите дату найма сотрудника: "; getline(cin, hdate);
		cout << "Введите стаж работы сотрудника: "; getline(cin, workexp);
		cout << "Введите оклад: "; getline(cin, fee);
		//Запись полей в одну строку
		ALL = "Фамилия: " + surname + "; " + "Имя: " + Name + "; " + "отчество: " + patronymic + "; " + "адрес: " + adres + "; " + "Дата рождения: " +
			bdate + "; " + "должность: " + position + "; " + "дата найма: " + hdate + "; " + "стаж: " + workexp + "; " + "оклад: " + fee;

		file << ALL; // Запись в файл данных
		file << "\n";
		file.close();
	};
	//---------------------------------------------------------------------------------------
	void OutEmployee() // Вывести данные из файла
	{
		ifstream file;
		file.open("Alfa.txt"); // открываем файл

		if (!file)//проверка на открытие файла
		{
			cout << "Файл не открыт\n\n";
		}
		else
		{
			cout << "Файл открыт коректно!\n\n";
		}

		char St[1024];

		while (1)
		{ //Считывание данных из файла и запись в массив St с последующим его выводом на экран внутри цикла
			if (file.eof()) break;
			file.getline(St, sizeof(St));
			cout << St << endl;
		}
		file.close();
	};
	//------------------------------------------------------------------------------------
	void Out_String() // Вывести данные из файла
	{
		ifstream file;
		file.open("Alfa.txt");//открытие файла на чтение

		char Mass[1024];
		int StringNumber = 0;//хранит номер строки
		cout << "Введите номер строки для вывода: "; cin >> StringNumber;

		/*считываем файл до конца*/
		while (1)
		{
			file.getline(Mass, sizeof(Mass));
			StringNumber--;
			if (StringNumber == 0)break;
		}
		cout << Mass;
		file.close();

	}
	//----------------------------------------------------------------------------
	void Delete_employee() // Удалить все записи из файла
	{
		ofstream file;
		file.open("Alfa.txt", ios::trunc); // открываем файл
		file.close();
		cout << endl << "Все записи удалены успешно." << endl;
	};
	//-----------------------------------------------------------------------------
	void Delete_String() // Удалить конкретную запись из файла
	{
		ifstream file;
		file.open("Alfa.txt"); // Открытие файла

		if (!file)//проверка на открытие файла
		{
			cout << "Файл не открыт\n\n";
		}
		else
		{
			cout << "Файл открыт коректно!\n\n";
		}

		int s = 0; // Номер строки которую необходимо удалить
		int k = 0; // Счетчик строк
		string Line;
		string Line_File; // Хранение текста файла

		cout << "Введите номер строки для удаления: ";
		cin >> s;

		while (getline(file, Line))
		{
			k++;
			if (!(k == s))
			{
				Line_File.insert(Line_File.size(), Line); //добавление строки
				Line_File.insert(Line_File.size(), "\r\n");	//добавление переноса на следующую строку
			}
		}

		file.close();
		std::ofstream file_out;
		file_out.open("Alfa.txt", std::ios::trunc | std::ios::binary);
		file_out.write(Line_File.c_str(), Line_File.size());
		file_out.clear();
		cout << "Строка успешно удалена \n";
	}
};