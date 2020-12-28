// ConsoleApplication22.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <clocale>
#include <windows.h>
#include <wincrypt.h>
#include <stdio.h>
#include <bcrypt.h>
#include <string>

using namespace std;

struct MyStruct
{
	char name[51] = "name";
	char lastname[51] = "lastname";
	char otch[51] = "otch";
	char bdate[13] = "bdate";
	char yp[5] = "yp";
	char fac[51] = "fac";
	char kaf[51] = "kaf";
	char group[12] = "group";
	char zach[9] = "zach";
	int int_zach;
	int kses;
	int mas_ses[9];
	char pr_name[9][10][51];
	int pr_mark[9][10];
	bool mark = true;
};

class A
{
public:
	A();
	void cin_all();
	void cin_all(char command);
	void cout_all();
	int fin_all(char file[50], int l);
	void fout_all(char file[50]);
	bool get_mark()
	{
		return student.mark;
	}
	void set_int_zach(int t)
	{
		student.int_zach = t;
	}
	virtual int get_zach();
	friend void zach_to_int(A& list);
	int operator+(int i)
	{
		return i + 1;
	}
private:
	MyStruct student;
};

A::A()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			student.pr_mark[i][j] = 0;
		}
	}
	student.kses = 0;
	student.mark = true;
}

void A::cin_all()
{
	bool flag = false;
	cout << "Введите фамилию " << endl;
	cin.getline(student.lastname, 51, '\n');
	cout << "Введите имя: " << endl;
	cin.getline(student.name, 51, '\n');
	cout << "Введите отчество: " << endl;
	cin.getline(student.otch, 51, '\n');
	cout << "Введите день рождения: " << endl;
	cin.getline(student.bdate, 13, '\n');
	cout << "Введите год поступления: " << endl;
	cin.getline(student.yp, 5, '\n');
	cout << "Введите факультет: " << endl;
	cin.getline(student.fac, 51, '\n');
	cout << "Введите кафедру: " << endl;
	cin.getline(student.kaf, 51, '\n');
	cout << "Введите группу: " << endl;
	cin.getline(student.group, 12, '\n');
	cout << "Введите номер зачетной книжки: " << endl;
	cin.getline(student.zach, 9, '\n');
	cout << "Введите количество сессий: " << endl;
	cin >> student.kses;
	cin.ignore(1, '\n');
	for (int i = 0; i < student.kses; i++)
	{
		cout << "Введите количество оценок в сесии " << i + 1 << ": " << endl;
		cin >> student.mas_ses[i];
		cin.ignore(1, '\n');
	}
	for (int i = 0; i < student.kses; i++)
	{
		for (int j = 0; j < student.mas_ses[i]; j++)
		{
			cout << "Введите название предмета " << j + 1 << " в сессии " << i + 1 << ": " << endl;
			cin.getline(student.pr_name[i][j], 51, '\n');
			while (flag == false)
			{
				cout << "Введите оценку: " << endl;
				cin >> student.pr_mark[i][j];
				cin.ignore(1, '\n');
				if ((student.pr_mark[i][j] > 0) && (student.pr_mark[i][j] < 6))
				{
					flag = true;
					if ((student.pr_mark[i][j] == 1) || (student.pr_mark[i][j] == 2) || (student.pr_mark[i][j] == 3))
					{
						student.mark = false;
					}
				}
				else
				{
					cout << "Оценка должна быть в интервале от 1 до 5" << endl;
				}
			}
			flag = false;
		}
	}
}
void A::cin_all(char command)
{
	bool flag = false;
	if (command == '1')
	{
		cout << "Введите фамилию " << endl;
		cin.getline(student.lastname, 51, '\n');
		cout << "Введите имя: " << endl;
		cin.getline(student.name, 51, '\n');
		cout << "Введите отчество: " << endl;
		cin.getline(student.otch, 51, '\n');
	}
	else
		if (command == '2')
		{
			cout << "Введите день рождения: " << endl;
			cin.getline(student.bdate, 13, '\n');
		}
		else
			if (command == '3')
			{
				cout << "Введите год поступления: " << endl;
				cin.getline(student.yp, 5, '\n');
			}
			else
				if (command == '4')
				{
					cout << "Введите факультет: " << endl;
					cin.getline(student.fac, 51, '\n');
				}
				else
					if (command == '5')
					{
						cout << "Введите кафедру: " << endl;
						cin.getline(student.kaf, 51, '\n');
					}
					else
						if (command == '6')
						{
							cout << "Введите группу: " << endl;
							cin.getline(student.group, 12, '\n');
						}
						else
							if (command == '7')
							{
								cout << "Введите номер зачетной книжки: " << endl;
								cin.getline(student.zach, 9, '\n');
							}
							else
								if (command == '8')
								{

									cout << "Введите количество сессий: " << endl;
									cin >> student.kses;
									cin.ignore(1, '\n');
									for (int i = 0; i < student.kses; i++)
									{
										cout << "Введите количество оценок в сесии " << i + 1 << ": " << endl;
										cin >> student.mas_ses[i];
										cin.ignore(1, '\n');
									}
									for (int i = 0; i < student.kses; i++)
									{
										for (int j = 0; j < student.mas_ses[i]; j++)
										{
											cout << "Введите название предмета " << j + 1 << " в сессии " << i + 1 << ": " << endl;
											cin.getline(student.pr_name[i][j], 51, '\n');
											while (flag == false)
											{
												cout << "Введите оценку: " << endl;
												cin >> student.pr_mark[i][j];
												cin.ignore(1, '\n');
												if ((student.pr_mark[i][j] > 0) && (student.pr_mark[i][j] < 6))
												{
													flag = true;
													if ((student.pr_mark[i][j] == 1) || (student.pr_mark[i][j] == 2) || (student.pr_mark[i][j] == 3))
													{
														student.mark = false;
													}
												}
												else
												{
													cout << "Оценка должна быть в интервале от 1 до 5" << endl;
												}
											}
											flag = false;
										}
									}
								}
}
void A::cout_all()
{
	cout << "Фамилия: " << student.lastname << " | " << "Имя: " << student.name << " | " << "Отчество: " << student.otch << endl;
	cout << "Дата рождения: " << student.bdate << " | " << "Дата поступления: " << student.yp << endl;
	cout << "Факультет: " << student.fac << " | " << "Кафедра: " << student.kaf << endl;
	cout << "Номер группы: " << student.group << " | " << "Номер зачетной книжки: " << student.zach << endl;
	for (int i = 0; i < student.kses; i++)
	{
		cout << "Сессия " << i + 1 << ": " << endl;
		for (int j = 0; j < student.mas_ses[i]; j++)
		{
			cout << student.pr_name[i][j] << " " << student.pr_mark[i][j] << " | ";
		}
		cout << endl;
	}
	cout << endl;
}
int A::fin_all(char file[50], int l)
{
	ifstream f;
	f.open(file);
	f.seekg(l);
	f.getline(student.lastname, 51, '|');
	//cin.ignore('\n');
	f.getline(student.name, 51, '|');
	//cin.ignore('\n');
	f.getline(student.otch, 51, '|');
	//cin.ignore('\n');
	f.getline(student.bdate, 13, '|');
	//cin.ignore('\n');
	f.getline(student.yp, 5, '|');
	//cin.ignore('\n');
	f.getline(student.fac, 51, '|');
	//cin.ignore('\n');
	f.getline(student.kaf, 51, '|');
	//cin.ignore('\n');
	f.getline(student.group, 12, '|');
	//cin.ignore('\n');
	f.getline(student.zach, 9, '|');
	//cin.ignore('\n');
	f >> student.kses;
	f.ignore(1, '|');
	for (int i = 0; i < student.kses; i++)
	{
		f >> student.mas_ses[i];
		f.ignore(1, '|');
	}
	for (int i = 0; i < student.kses; i++)
	{
		for (int j = 0; j < student.mas_ses[i]; j++)
		{
			//f.ignore(1, '|');
			f.getline(student.pr_name[i][j], 51, '|');
			f >> student.pr_mark[i][j];
			f.ignore(2, '|');
			if ((student.pr_mark[i][j] == 1) || (student.pr_mark[i][j] == 2) || (student.pr_mark[i][j] == 3))
			{
				student.mark = false;
			}
		}
	}
	l = f.tellg();
	f.close();
	return l;
}
void A::fout_all(char file[50])
{
	ofstream f;
	f.open(file, ofstream::app);
	f << student.lastname << "|" << student.name << "|" << student.otch << "|";
	f << student.bdate << "|" << student.yp << "|";
	f << student.fac << "|" << student.kaf << "|";
	f << student.group << "|" << student.zach << "|";
	f << student.kses << "|";
	for (int i = 0; i < student.kses; i++)
	{
		f << student.mas_ses[i] << " ";
	}
	f << "|";
	for (int i = 0; i < student.kses; i++)
	{
		for (int j = 0; j < student.mas_ses[i]; j++)
		{
			f << student.pr_name[i][j] << " | " << student.pr_mark[i][j] << " ";
		}
		f << "|";
	}
	f.close();
}
int A::get_zach()
{
	return student.int_zach;
}
void zach_to_int(A& list)
{
	char zam[9];
	for (int i = 0; i < 9; i++)
	{
		zam[i] = list.student.zach[i];
	}
	int d = strlen(zam);
	int count = 0;
	for (int i = 0; i < d; i++)
	{
		if ((zam[i] == '0') || (zam[i] == '1') || (zam[i] == '2') || (zam[i] == '3') || (zam[i] == '4') || (zam[i] == '5') || (zam[i] == '6') || (zam[i] == '7') || (zam[i] == '8') || (zam[i] == '9'))
		{
			zam[count] = zam[i];
			count++;
		}
	}
	list.student.int_zach = atoi(zam);
}
DWORD dwIndex = 0;
DWORD dwType;
DWORD cbName;
LPTSTR pszName, x;

int main()
{
	setlocale(LC_ALL, "ru");
	HCRYPTPROV hProv;
	HCRYPTKEY hSessionKey;
	int count = 0;
	int l = 0;
	int temp;
	int numb;
	int* sort = new int[count];
	char command = '~';
	char sf[50] = "save.txt";
	char keyf[50] = "cryptkey.txt";
	char outf[50] = "out.txt";
	char outcryptf[50] = "outcrypt.txt";
	char checkf[50] = "check.txt";
	char pf[50];
	bool check = false;
	char string[256];
	A test;
	A* list = new A[count];
	ofstream file;
	ifstream cryptoin;
	ofstream cryptoout;
	file.open(sf);
	file.clear();
	file.close();
	while (command == '~')
	{
		cout << "Доступные команды: " << endl << "1) Добавить студента.\n2) Изменить данные о студентах.\n3) Осортировать и вывести список студетов.\n4) Расшифровать зашифрованный файл.\n5) Выход." << endl;
		cin >> command;
		if (command == '1')
		{
			cout << "Как вы хотите добавить студента?\n1)C клавиатуры.\n2)Загрузить из файла." << endl;
			//cin.ignore();
			cin >> command;
			if (command == '1')
			{
				while (command == '1')
				{
					cin.ignore(1, '\n');
					test.cin_all();
					test.fout_all(sf);
					cin.ignore();
					count++;
					check = true;
					cout << "Для добавления след студента нажмите 1. Для выхода в меню нажмите 2." << endl;
					cin >> command;
				}
				command = '~';
				list = new A[count];
				for (int i = 0; i < count; i++)
				{
					list[i].fin_all(sf, l);
					l = list[i].fin_all(sf, l);
				}
				for (int i = 0; i < count; i++)
				{
					zach_to_int(list[i]);
				}
				sort = new int[count];
				for (int i = 0; i < count; i++)
				{
					sort[i] = i;
				}
				for (int i = 0; i < count; i++)
				{
					for (int j = 0; j < count; j++)
					{
						if (list[i].get_zach() > list[j].get_zach())
						{
							temp = sort[i];
							sort[i] = sort[j];
							sort[j] = temp;
						}
					}
				}
			}
			else
				if (command == '2')
				{
					cout << "Введите количество студентов в файле: " << endl;
					cin >> count;
					cin.ignore(1, '\n');
					cout << "Студенты должны быть введены в данном формате:\nGusarov|Ivan|Vladimirovich|19.10.2000(год рождения)|2019(год поступления)|Inf bez(факультет)|KB-1(кафдера)|BBBBO-06-19(группа)|19b0215(зачетная книжка)|2(колво сессий)|1(колво оценок в сессии 1) 2(колво оценок в сессии 2)| matan(предмет)|5(оценка за предмет)| linal|3| fiz| 4|" << endl;
					cout << "Введите название файла: " << endl;
					cin >> pf;
					fstream checkf(pf);
					if (checkf.is_open())
					{
						l = 0;
						list = new A[count];
						for (int i = 0; i < count; i++)
						{
							list[i].fin_all(pf, l);
							l = list[i].fin_all(pf, l);
						}
						for (int i = 0; i < count; i++)
						{
							zach_to_int(list[i]);
						}
						check = true;
						sort = new int[count];
						for (int i = 0; i < count; i++)
						{
							sort[i] = i;
						}
						for (int i = 0; i < count; i++)
						{
							for (int j = 0; j < count; j++)
							{
								if (list[sort[i]].get_zach() < list[sort[j]].get_zach())
								{
									temp = sort[i];
									sort[i] = sort[j];
									sort[j] = temp;
								}
							}
						}
						command = '~';
					}
					else
					{
						cout << "Ошибка открытия файла." << endl;
						command = '~';
					}
				}
				else
				{
					cout << "Не корректная команда. " << endl;
					command = '~';
				}

		}
		else
			if (command == '2')
			{
				cout << "Введите номер студента: " << endl;
				cin >> numb;
				if ((numb > 0) && (numb <= count))
				{
					cout << "Что вы хотите изменить?" << endl << "1) ФИО" << endl << "2) День рождения" << endl << "3) Год поступления" << endl << "4) Факультет" << endl << "5) Кафедру" << endl << "6) Группу" << endl << "7) Зачетную книжки" << endl << "8) Оценки" << endl;
					cin >> command;
					cin.ignore(1, '\n');
					list[numb].cin_all(command);
				}
				else
				{
					cout << "Нет такого студента." << endl;
				}
				command = '~';
			}
			else
				if (command == '3')
				{
					if (count > 0)
					{
						cout << "1) Вывод в консоль.\n2) Вывод в файл." << endl;
						cin >> command;
						if (command == '1')
						{
							cout << "Студенты без троек:" << endl << endl;
							for (int i = 0; i < count; i++)
							{
								if (list[sort[i]].get_mark() == true)
								{
									cout << list->operator+(i) << ") ";
									list[sort[i]].cout_all();
								}
							}
							cout << "Студенты c тройками" << endl << endl;
							for (int i = 0; i < count; i++)
							{
								if (list[sort[i]].get_mark() == false)
								{
									cout << list->operator+(i) << ") ";
									list[sort[i]].cout_all();
								}
							}
							command = '~';
						}
						else
							if (command == '2')
							{
								cout << "Зашифовать данные в файле?\n1) Нет\n2) Да." << endl;
								cin >> command;
								cin.ignore(1, '\n');
								if (command == '1')
								{
									cout << "Введите имя файла" << endl;
									cin >> pf;
									for (int i = 0; i < count; i++)
									{
										if (list[i].get_mark() == true)
										{
											list[sort[i]].fout_all(pf);
										}
									}
									for (int j = 0; j < count; j++)
									{
										if (list[j].get_mark() == false)
										{
											list[sort[j]].fout_all(pf);
										}
									}
									command = '~';
								}
								else
									if (command == '2')
									{
										for (int i = 0; i < count; i++)
										{
											if (list[sort[i]].get_mark() == true)
											{
												list[sort[i]].fout_all(outf);
											}
										}
										for (int i = 0; i < count; i++)
										{
											if (list[sort[i]].get_mark() == false)
											{
												list[sort[i]].fout_all(outf);
											}
										}
										if (CryptAcquireContext(&hProv, NULL, NULL,
											PROV_RSA_FULL, CRYPT_VERIFYCONTEXT))
										{
											if (CryptGenKey(hProv, CALG_RC4,
												CRYPT_EXPORTABLE, &hSessionKey))
											{
												cryptoin.open(outf, ifstream::binary);
												cryptoout.open(outcryptf);
												while (!cryptoin.eof())
												{
													cryptoin >> string;
													DWORD count = strlen(string);
													CryptEncrypt(hSessionKey, 0, true, 0, (BYTE*)string, &count, strlen(string));
													cryptoout << string;
												}
												cryptoin.close();
												cryptoout.close();
												cryptoout.open(keyf);
												cryptoout << hSessionKey;
												cryptoout.close();
												cout << "Откройте файл outcrypt.txt " << endl;
												cryptoout.open(checkf);
												cryptoout << "123";
												cryptoout.close();
												file.open(outf);
												file.clear();
												file.close();
											}
										}
										command = '~';
									}
									else
									{
										cout << "Не корректная команда. " << endl;
										command = '~';
									}
							}
					}
					else
					{
						cout << "Введите хотя бы одного студента." << endl;
						command = '~';
					}


				}
				else
					if (command == '4')
					{
						cryptoin.open(checkf);
						cryptoin >> string;
						cryptoin.close();
						if (strcmp(string, "123") == 0)
						{
							cout << "Расшифрованныe данные будет в файле out.txt" << endl;
							cryptoin.open(keyf);
							cryptoin >> hSessionKey;
							cryptoin.close();
							cryptoin.open(outcryptf, ifstream::binary);
							cryptoout.open(outf);
							while (!cryptoin.eof())
							{
								cryptoin >> string;
								DWORD count = strlen(string);
								CryptDecrypt(hSessionKey, 0, true, 0, (BYTE*)string, &count);
								cryptoout << string;
							}
							cryptoin.close();
							cryptoout.close();
						}
						else
						{
							cout << "Сначала необходимо зашифровать хотя бы один файл." << endl;
						}
						command = '~';
					}
					else
						if (command == '5')
						{
							command = '&';
						}
						else
							command = '~';
	}
	delete[]sort;
	delete[]list;
}