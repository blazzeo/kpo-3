#include "stdafx.h"

using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");
    int iDay, iMonth, iYear;
    int fullYear = 365;
    char input[9];
    string listOfMonth[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

    cin >> input;

    sscanf(input, "%2d%2d%4d", &iDay, &iMonth, &iYear);

    //error check
    errorcatch(iDay, iMonth, iYear);

    // year
    if (leap(iYear)) {
        cout << "Год високосный" << endl;
    } else cout << "Год не високосный" << endl;

    // name of month
    cout << "Месяц: " << listOfMonth[iMonth-1] << endl;

    // number of day
    int number = numOfDay(iDay, iMonth, leap(iYear));
    cout << "Порядковый номер: " << number << endl;

    // birthday
    int birthDay, birthMonth, birthYear;

    // input birth date
    cout << "Введите дату рождения: ";
    cin >> input;

    sscanf(input, "%2d%2d%4d", &birthDay, &birthMonth, &birthYear);
    
    //error check
    errorcatch(birthDay, birthMonth, birthYear);

    int myBirthday = numOfDay(birthDay, birthMonth, leap(birthYear));

    int nearestBirthday;
    if (myBirthday >= number) {
        nearestBirthday = myBirthday - number;
    }
    else nearestBirthday = fullYear + (myBirthday - number);

    cout << "Ближайший др через: " << nearestBirthday << " дней" << endl;

    // number to date
    int date;

    cin >> date;
    
    numtodate(date);

    // difference between two days
    timedifference();

    system("pause");
    return 0;
}