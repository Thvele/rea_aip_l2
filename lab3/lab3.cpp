#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct fraction
{
    int num = -1;
    int denum = -1;
};

string checkForSimple(int digit)
{
    int halfDigit = digit / 2;
    for (int i = 2; i < halfDigit; i++)
    {
        if (digit % i == 0)
            return ("Число " + to_string(digit) + " НЕ простое");
    }

    return ("Число " + to_string(digit) + " простое");
}

string checkForAbsolute(int digit)
{
    int divisorsSum = 1, halfDigit = digit/2;

    for (int i = 2; i < halfDigit+1; i++)
    {
        if (digit % i == 0)
            divisorsSum += i;
    }

    if (divisorsSum == digit)
        return ("Число " + to_string(digit) + " совершенное");

    return ("Число " + to_string(digit) + " НЕ совершенное");
}

int greatestCommonDivisor(int a, int b)
{
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return greatestCommonDivisor(a % b, b);
    return greatestCommonDivisor(a, b % a);
}

int leastCommonMultiple(int a, int b)
{
    return (a * b)/greatestCommonDivisor(a, b);
}

void divisibilityAnalyzer()
{
    int a = -1, b = -1;
    while (a < 0 || b < 0)
    {
        system("cls");
        cout << "Введите 2 числа: ";
        cin >> a >> b;
    }
    
    cout << endl << checkForSimple(a) << endl << checkForAbsolute(a);
    cout << endl << checkForSimple(b) << endl << checkForAbsolute(b);
    cout << endl << "Наибольший общий делитель \t=> \t" << greatestCommonDivisor(a, b);
    cout << endl << "Наименьшее общее кратное \t=> \t" << leastCommonMultiple(a, b);
    

    cout << "\n\nНажмите что-то для продолжения";
    _getch();
}

void summationAndSubstraction()
{
    fraction fstFrac, secFrac;
    int action = -1, finNum;

    while (fstFrac.num < 0 || fstFrac.denum < 0 || secFrac.num < 0 || secFrac.denum < 0)
    {
        system("cls");
        cout << "Введите числитель и знаменатель первой дроби (целые и положительные числа): ";
        cin >> fstFrac.num >> fstFrac.denum;
        cout << "Введите числитель и знаменатель второй дроби (целые и положительные числа): ";
        cin >> secFrac.num >> secFrac.denum;
    }

    while (action < 0 || action > 2)
    {
        system("cls");
        int leastCM = leastCommonMultiple(fstFrac.denum, secFrac.denum);

        cout << "Первая дробь: " << fstFrac.num << "/" << fstFrac.denum << " Вторая дробь: " << secFrac.num << "/" << secFrac.denum;
        cout << "\n\nВыберите действие: \n\t1. Сложение\n\t2. Вычитание\n\t3. Назад\nВыбор:";
        cin >> action;
        switch (action)
        {
        case 1:
            finNum = (fstFrac.num * secFrac.denum) + (secFrac.num * fstFrac.denum);
            cout << "\n\nПример: \t" << fstFrac.num << "/" << fstFrac.denum << " + " << secFrac.num << "/" << secFrac.denum;
            cout << "\nРезультат: \t" << (finNum) / greatestCommonDivisor(finNum, leastCM) << "/" << leastCM / greatestCommonDivisor(finNum, leastCM);
            break;
        case 2:
            finNum = (fstFrac.num * secFrac.denum) - (secFrac.num * fstFrac.denum);
            cout << "\n\nПример: \t" << fstFrac.num << "/" << fstFrac.denum << " - " << secFrac.num << "/" << secFrac.denum;
            cout << "\nРезультат: \t" << (finNum) / greatestCommonDivisor(finNum, leastCM) << "/" << leastCM / greatestCommonDivisor(finNum, leastCM);
            break;
        case 3:
            summationAndSubstraction();
            break;
        default:
            break;
        }
    }

    cout << "\n\nНажмите что-то для продолжения";
    _getch();
}

int main()
{
    setlocale(LC_ALL, "Russian"); //Эта строка не считается так как она просто для исправления неверной локализации
    int act = 0;
    while (act != 3)
    {
        system("cls");
        cout << "Выберите действие: \n\t1. Анализатор делимости;\n\t2. Сложение и вычитание дробей\n\t3. Выход\nВыбор: "; cin >> act;
        switch (act)
        {
            case 1:
                divisibilityAnalyzer(); break;
            case 2:
                summationAndSubstraction(); break;
            case 3:
                return 0; break;
        }
    }
}
