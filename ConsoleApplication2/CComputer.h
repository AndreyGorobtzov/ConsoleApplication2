#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


template<class T>
T input(string s = "")
{
	T var;
	cout << s; cin >> var;
	return var;
}

// Преобразователь в строку
template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

class CComputer
{
private:
	double CPUFreq = 0;			// Частота процессора в ГГц
	int    NumOfCores = 0;		// Кол-во ядер процессора в ШТ
	double RAM = 0;				// Объём ОЗУ в ГБ
	double ROM = 0;				// Объём ПЗУ в ГБ
	double ROMBusy = 0;			// Занятый объём от объёма ПЗУ в ГБ
	static double TotalROM; 	// Суммарный объём жёстких всех компьютеров в ГБ
	static double TotalROMBusy;
public:
	// Конструктор
	CComputer(double = 0, int = 0, double = 0, double = 0, double = 0);

	// Деструктор
	~CComputer();

	// Блок свойств полей класса
	double GetCPUFreq();
	void SetCPUFreq(double freq);

	int GetNumOfCores();
	void SetNumOfCores(int num);

	int GetRAM();
	void SetRAM(double ram);

	double GetROM();
	void SetROM(double rom);

	double GetROMBusy();
	void SetROMBusy(double romb);

	// Получение свободного объёма ПЗУ
	double GetROMFree();

	// Проверить возможность добавления файла определённого размера
	bool TryCopyFile(double file);

	// Вывод информации о компьютере
	string Info();

	// Внесение изменеий в жёсткий диск
	void UpdateROM(double file);
	void UpdateROM(double file, double up_rom);

	// Перегрузка операторов больше и меньше для сравнения кол-ва ядер
	bool operator > (CComputer pc);
	bool operator < (CComputer pc);

	// Получение общего объёмов жёсткого диска
	static double GetTotalROM();
	static double GetTotalROMBusy();
	static double GetTotalROMFree();

	void CIn();
};
