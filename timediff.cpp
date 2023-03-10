#include "stdafx.h"

struct date {
    unsigned int day;
    unsigned int month;
    unsigned int year;
        unsigned int hours;
        unsigned int minutes;
        unsigned int seconds;
};

//https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0#%D0%92%D1%8B%D1%87%D0%B8%D1%81%D0%BB%D0%B5%D0%BD%D0%B8%D0%B5_%D1%8E%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%BE%D0%B9_%D0%B4%D0%B0%D1%82%D1%8B_%D0%BF%D0%BE_%D0%B4%D0%B0%D1%82%D0%B5_%D0%BA%D0%B0%D0%BB%D0%B5%D0%BD%D0%B4%D0%B0%D1%80%D1%8F
int dayJDN(int day, int month, int year) {
    int a = (14 - month)/12;
    int m = month + 12*a - 3;
    int y = year + 4800 - a;

    int jdn = day + (153*m+2)/5 + 365*y + (y/4) - (y/100) + (y/400) - 32045;
    return jdn;
}

void timedifference() {
    date date1,date2;
    char input[9],time[7];

    cout << "\nПервая дата и время: ";
    cin >> input >> time;
    sscanf(input, "%2d%2d%4d", &date1.day, &date1.month, &date1.year);
    sscanf(time, "%2d%2d%2d", &date1.hours, &date1.minutes, &date1.seconds);

    cout << "\nВторая дата и время: ";
    cin >> input >> time;
    sscanf(input, "%2d%2d%4d", &date2.day, &date2.month, &date2.year);
    sscanf(time, "%2d%2d%2d", &date2.hours, &date2.minutes, &date2.seconds);

    int iDate1 = date1.day + date1.month * 31 + date1.year * 365; 
    int iDate2 = date2.day + date2.month * 31 + date2.year * 365; 

    if (iDate2 < iDate1) {
        swap(iDate2,iDate1);
    }

    unsigned long timediff = (86400-date1.hours*3600-date1.minutes*60-date1.seconds)+
                date2.hours*3600+date2.minutes*60+date2.seconds;

    int daysdiff = dayJDN(date2.day,date2.month,date2.year) - dayJDN(date1.day,date1.month,date1.year);
    timediff += daysdiff*86400;

    cout << "Разница в днях между 2 датами: " << daysdiff << " дней" << endl;
    cout << "Разница в секундах между 2 датами: " << timediff << " секунд" << endl;
    cout << "Разница во времени между 2 датами: " << timediff/60/60 << " часов " << timediff/60%60 << " минут " << timediff%60 << " секунд" << endl;
}