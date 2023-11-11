#include "CComputer.h"

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
double CComputer::GetROMFree()
{
	return ROM - ROMBusy;
}
bool CComputer::TryCopyFile(double file)
{
	return (file + ROMBusy <= ROM);
}

string CComputer::Info()
{
	return
	 	  "×àñòîòà ïðîöåññîðà         : " + toString(CPUFreq)	+ " ÃÃö\n"
	 	+ "Êîë - âî ÿäåð ïðîöåññîðà   : " + toString(NumOfCores)+ " ØÒ\n" 
	 	+ "Îáú¸ì ÎÇÓ                  : " + toString(RAM)		+ " ÃÁ\n" 
	 	+ "Îáú¸ì ÏÇÓ                  : " + toString(ROM)		+ " ÃÁ\n" 
	 	+ "Çàíÿòûé îáú¸ì îò îáú¸ìà ÏÇÓ: " + toString(ROMBusy)	+ " ÃÁ";
}

void CComputer::UpdateROM(double file)
{
	if (TryCopyFile(file))
		ROMBusy += file;
	else
		cout << "Îøèáêà!!! Íåäîñòàòî÷íî ìåñòà íà äèñêå";
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
		cout << "Îøèáêà!!! Íåäîñòàòî÷íî ìåñòà íà äèñêå";
}

bool CompareC(CComputer c1, CComputer c2)
{
	return c1.GetROMFree() > c2.GetROMFree();
}

bool CComputer::operator > (CComputer pc)
{
	return NumOfCores > pc.NumOfCores;
}
bool CComputer::operator < (CComputer pc)
{
	return NumOfCores < pc.NumOfCores;
}

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
	SetCPUFreq(input<double>("Óêàæèòå ÷àñòîòó ïðîöåññîðà:        "));
	SetNumOfCores(input<int>("Óêàæèòå êîë-âî ÿäåð ïðîöåññîðà:    "));
	SetRAM(input<double>	("Óêàæèòå îïåðàòèâíóþ ïàìÿòü:        "));
	SetROM(input<double>	("Óêàæèòå ïîñòîÿííóþ ïàìÿòü:         "));
	SetROMBusy(input<double>("Óêàæèòå çàíÿòóþ ïîñòîÿííóþ ïàìÿòü: "));
}
CComputer::CComputer(double freq, int num, double ram, double rom, double romb)
{
	SetCPUFreq(freq);
	SetNumOfCores(num);
	SetRAM(ram);
	SetROM(rom);
	SetROMBusy(romb);
}
CComputer::~CComputer()
{
	TotalROM -= ROM;
	TotalROMBusy -= ROMBusy;
}
