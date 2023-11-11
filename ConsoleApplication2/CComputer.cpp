#include "CComputer.h"



// Блок свойств полей класса
double CComputer::GetCPUFreq() 
{
	return CPUFreq;
}
void CComputer::SetCPUFreq(double freq)
{
	if (freq < 0)
		throw "ERROR!!! Incorrect CPUFreq";
	CPUFreq = freq;
}

int CComputer::GetNumOfCores()
{
	return NumOfCores;
}
void CComputer::SetNumOfCores(int num)
{
	if (num < 0)
		throw "ERROR!!! Incorrect NumOfCores";
	NumOfCores = num;
}

int CComputer::GetRAM()
{
	return RAM;
}
void CComputer::SetRAM(double ram)
{
	if (ram < 0)
		throw "ERROR!!! Incorrect RAM";
	RAM = ram;
}

double CComputer::GetROM()
{
	return ROM;
}
void CComputer::SetROM(double rom)
{
	if (rom < 0 || rom < ROMBusy)
		throw "ERROR!!! Incorrect ROM";
	TotalROM += rom;
	ROM = rom;
}

double CComputer::GetROMBusy()
{
	return ROMBusy;
}
void CComputer::SetROMBusy(double romb)
{
	if (romb < 0 || romb > ROM)
		throw "ERROR!!! Incorrect ROMBusy";
	ROMBusy = romb;
	TotalROMBusy += romb;
}

// Получение свободного объёма ПЗУ
double CComputer::GetROMFree()
{
	return ROM - ROMBusy;
}

// Проверить возможность добавления файла определённого размера
bool CComputer::TryCopyFile(double file)
{
	return (file + ROMBusy <= ROM);
}

// Вывод информации о компьютере
string CComputer::Info()
{
	return
	 	  "Частота процессора         : " + toString(CPUFreq)	+ " ГГц\n"
	 	+ "Кол - во ядер процессора   : " + toString(NumOfCores)+ " ШТ\n" 
	 	+ "Объём ОЗУ                  : " + toString(RAM)		+ " ГБ\n" 
	 	+ "Объём ПЗУ                  : " + toString(ROM)		+ " ГБ\n" 
	 	+ "Занятый объём от объёма ПЗУ: " + toString(ROMBusy)	+ " ГБ";
}

// Внесение изменеий в жёсткий диск
void CComputer::UpdateROM(double file)
{
	if (TryCopyFile(file))
		ROMBusy += file;
	else
		cout << "Ошибка!!! Недостаточно места на диске";
}
void CComputer::UpdateROM(double file, double up_rom)
{
	if (TryCopyFile(file - up_rom))
	{
		ROMBusy += file;
		TotalROMBusy += file;
		ROM += up_rom;
		TotalROM += up_rom;
	}
	else
		cout << "Ошибка!!! Недостаточно места на диске";
}

bool CompareC(CComputer c1, CComputer c2)
{
	return c1.GetROMFree() > c2.GetROMFree();
}

// Перегрузка операторов больше и меньше для сравнения кол-ва ядер
bool CComputer::operator > (CComputer pc)
{
	return NumOfCores > pc.NumOfCores;
}
bool CComputer::operator < (CComputer pc)
{
	return NumOfCores < pc.NumOfCores;
}

// Получение общего объёма жёсткого диска
double CComputer::GetTotalROM()
{
	return TotalROM;
}

double CComputer::GetTotalROMBusy()
{
	return TotalROMBusy;
}

double CComputer::GetTotalROMFree()
{
	return TotalROM - TotalROMBusy;
}

void CComputer::CIn()
{
	SetCPUFreq(input<double>("Укажите частоту процессора:        "));
	SetNumOfCores(input<int>("Укажите кол-во ядер процессора:    "));
	SetRAM(input<double>	("Укажите оперативную память:        "));
	SetROM(input<double>	("Укажите постоянную память:         "));
	SetROMBusy(input<double>("Укажите занятую постоянную память: "));
}

// Конструктор
CComputer::CComputer(double freq, int num, double ram, double rom, double romb)
{
	SetCPUFreq(freq);
	SetNumOfCores(num);
	SetRAM(ram);
	SetROM(rom);
	SetROMBusy(romb);
}

// Деструктор
CComputer::~CComputer()
{
	TotalROM -= ROM;
	TotalROMBusy -= ROMBusy;
}
