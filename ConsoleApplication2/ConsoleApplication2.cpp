#include "CComputer.h"
#include <iostream>
using namespace std;

double CComputer::TotalROM = 0;
double CComputer::TotalROMBusy = 0;
int main()
{
    setlocale(LC_ALL, "Russian");
    char ch = input<char>("Что вы хотите сделать?\n\t1 Создать массив компьютеров\n\tE Завершить работу программы\n\t> ");
    if (ch == '1') {
        int n = input<int>("Укажите размер массива: ");
        CComputer* club = new CComputer[n];
        while (1)
        {
            int idx, idx1, idx2;
            char ch1 = input<char>(
                "Что вы хотите сделать?\n"
                "\t1 Заполнить данные компьютера по индексу\n"
                "\t2 Добавить файл\n"
                "\t3 Добавить файл и изменить дисковое пространство\n"
                "\t4 Проверить club[i1] > club[i2]\n"
                "\t5 Проверить club[i1] < club[i2]\n"
                "\t6 Получить информацию о компьютере по индексу\n"
                "\t7 Получить общий объём постоянной памяти\n"
                "\t8 Получить общий объём занятой постоянной памяти\n"
                "\t9 Получить общий объём свободной постоянной памяти\n"
                "\tC Очистить информацию о компьютерах\n"
                "\tE Завершить работу программы\n"
                "\t> "
            );
            switch (ch1)
            {
            case '1':
                idx = input<int>("Укажите индекс: ");
                club[idx].CIn();
                break;
            case '2':
                idx = input<int>("Укажите индекс: ");
                club[idx].UpdateROM(
                    input<double>("Укажите размер добавляемого файла: ")
                );
                break;
            case '3':
                idx = input<int>("Укажите индекс: ");
                club[idx].UpdateROM(
                    input<double>("Укажите размер добавляемого файла: "),
                    input<double>("Укажите изменение жёсткого диска: ")
                );
                break;
            case '4':
                idx1 = input<int>("Укажите индекс первого элемента: ");
                idx2 = input<int>("Укажите индекс второго элемента: ");
                cout << "Утверждение " << ((club[idx1] > club[idx2]) ? "Истинно" : "Ложно") << endl;
                break;
            case '5':
                idx1 = input<int>("Укажите индекс первого элемента: ");
                idx2 = input<int>("Укажите индекс второго элемента: ");
                cout << "Утверждение " << ((club[idx1] < club[idx2]) ? "Истинно" : "Ложно") << endl;
                break;
            case '6':
                idx = input<int>("Укажите индекс: ");
                cout << club[idx].Info() << endl;
                break;
            case '7':
                cout << "Общий объём памяти: " << CComputer::GetTotalROM() << endl;
                break;
            case '8':
                cout << "Общий объём занятой памяти: " << CComputer::GetTotalROMBusy() << endl;
                break;
            case '9':
                cout << "Общий объём свободной памяти: " << CComputer::GetTotalROMFree() << endl;
                break;
            case 'C':
                delete[] club;
                club = new CComputer[n];
                break;
            case 'E':
                return 1;
                break;
            default:
                cout << "Команда не распознана.";
            }
        }
    }
}
