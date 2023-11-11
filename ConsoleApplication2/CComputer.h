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
	double CPUFreq = 0;		
	int    NumOfCores = 0;		
	double RAM = 0;			
	double ROM = 0;			
	double ROMBusy = 0;		
	static double TotalROM; 	
	static double TotalROMBusy;
public:
	CComputer(double = 0, int = 0, double = 0, double = 0, double = 0);
	~CComputer();

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

	double GetROMFree();

	bool TryCopyFile(double file);

	string Info();
	void UpdateROM(double file);
	void UpdateROM(double file, double up_rom);

	bool operator > (CComputer pc);
	bool operator < (CComputer pc);
	static double GetTotalROM();
	static double GetTotalROMBusy();
	static double GetTotalROMFree();

	void CIn();
};
