#include "CComputer.h"



// ���� ������� ����� ������
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

// ��������� ���������� ������ ���
double CComputer::GetROMFree()
{
	return ROM - ROMBusy;
}

// ��������� ����������� ���������� ����� ������������ �������
bool CComputer::TryCopyFile(double file)
{
	return (file + ROMBusy <= ROM);
}

// ����� ���������� � ����������
string CComputer::Info()
{
	return
	 	  "������� ����������         : " + toString(CPUFreq)	+ " ���\n"
	 	+ "��� - �� ���� ����������   : " + toString(NumOfCores)+ " ��\n" 
	 	+ "����� ���                  : " + toString(RAM)		+ " ��\n" 
	 	+ "����� ���                  : " + toString(ROM)		+ " ��\n" 
	 	+ "������� ����� �� ������ ���: " + toString(ROMBusy)	+ " ��";
}

// �������� �������� � ������ ����
void CComputer::UpdateROM(double file)
{
	if (TryCopyFile(file))
		ROMBusy += file;
	else
		cout << "������!!! ������������ ����� �� �����";
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
		cout << "������!!! ������������ ����� �� �����";
}

bool CompareC(CComputer c1, CComputer c2)
{
	return c1.GetROMFree() > c2.GetROMFree();
}

// ���������� ���������� ������ � ������ ��� ��������� ���-�� ����
bool CComputer::operator > (CComputer pc)
{
	return NumOfCores > pc.NumOfCores;
}
bool CComputer::operator < (CComputer pc)
{
	return NumOfCores < pc.NumOfCores;
}

// ��������� ������ ������ ������� �����
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
	SetCPUFreq(input<double>("������� ������� ����������:        "));
	SetNumOfCores(input<int>("������� ���-�� ���� ����������:    "));
	SetRAM(input<double>	("������� ����������� ������:        "));
	SetROM(input<double>	("������� ���������� ������:         "));
	SetROMBusy(input<double>("������� ������� ���������� ������: "));
}

// �����������
CComputer::CComputer(double freq, int num, double ram, double rom, double romb)
{
	SetCPUFreq(freq);
	SetNumOfCores(num);
	SetRAM(ram);
	SetROM(rom);
	SetROMBusy(romb);
}

// ����������
CComputer::~CComputer()
{
	TotalROM -= ROM;
	TotalROMBusy -= ROMBusy;
}
