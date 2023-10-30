#include <iostream>
#include <string>

using namespace std;

const string monthList[12] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };
const string dayList[7] = { "ПН", "ВТ", "СР", "ЧТ", "ПТ", "СБ", "ВС" };

int getDaysCount(int month, int year)
{
    int result = -1;
    static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    result = days[month-1];
    if ((year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) && month == 2)
        ++result;

    return result;
}

int getStartDay(int month, int year)
{
    int result = -1;
    static const int months[] = { 13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    if (month == 1 || month == 2) --year;

    int y = year / 100;
    int c = year % 100;

    result = (1 + 13 * (months[month - 1] + 1) / 5 + c + c / 4 + y / 4 + 5 * y)%7;

    if (result == 0)
        return 6;

    return --result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("cls");
    int month = 0, year = 0, day = 1;

    cout << "Ведите месяц (1-12): ";
    while (month - 1 < 0 || month - 1 > 11) cin >> month;

    cout << "\nВведите год (1919-2069): ";
    while (year < 1919 || year > 2069) cin >> year;

    cout << "\n\n" << monthList[month - 1] << " " << year << " год";
    cout << "\nПН\tВТ\tСР\tЧТ\tПТ\tСБ\tВС";
    if (getStartDay(month, year) == 0)
    {
        cout << "\n--\t--\t--\t--\t--\t--\t1\n";
        ++day;
    }
    else
    {
        cout << "\n";
        for (int i = 0; i < getStartDay(month, year)-1; i++)
        {
            cout << "--\t";
        }
        for (int i = 7; getStartDay(month, year) - 1 < i; i--)
        {
            cout << day << "\t";
            ++day;
        }
        cout << "\n";
    }

    while (day <= getDaysCount(month, year))
    {
        for (int i = 0; i < 7; i++)
        {
            if(day <= getDaysCount(month, year))
                cout << day << "\t";
            ++day;
        }
        cout << "\n";
    }
}