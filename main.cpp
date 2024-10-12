#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

bool IsYearLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int FirstWeekDay(int week_day, int days) {
    return (week_day + days) % 7;
}

string PrintMonthYear(int month, int year) {
    vector <string> months_list = { "ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ", "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ", "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ" };
    return months_list[month - 1] + " " + to_string(year);
}

int main() {

    setlocale(LC_ALL, "Russian");

    int month, year;
    while (true) {
        cin >> month >> year;
        if (cin.fail() || month < 1 || month > 12 || year < 1919 || year > 2069) {
            cin.clear();
            cin.ignore(numeric_limits <streamsize>::max(), '\n');
            cout << "Неверное значение месяца или года. Попробуйте снова. Пример: 10 2024" << endl;
        }
        else break;
    }

    cout << PrintMonthYear(month, year) << endl;
    cout << "  ПН  ВТ  СР  ЧТ  ПТ  СБ  ВС" << endl;

    vector <int> days_in_month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int week_day = 2; // Начинаем с Понедельника 1 Января 1919

    for (int i = 1919; i < year; i++)
        week_day = FirstWeekDay(week_day, IsYearLeap(i) ? 366 : 365);

    for (int i = 0; i < month - 1; i++)
        week_day = FirstWeekDay(week_day, (i == 1 && IsYearLeap(year)) ? 29 : days_in_month[i]);

    for (int i = 0; i < week_day; i++) cout.width(4), cout << ""; // Создаём пустые клетки в календаре, до первого дня недели

    int days = (month == 2 && IsYearLeap(year)) ? 29 : days_in_month[month - 1];
    for (int i = 1; i <= days; i++) {
        cout.width(4), cout << i;
        if (week_day == 6) cout << endl, week_day = 0;
        else week_day++;
    }

    return 0;
}