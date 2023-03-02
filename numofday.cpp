#include "stdafx.h"

int numOfDay(int day, int month, bool leap) {
    int daysInMonths[12] = { 31,(leap?29:28),31,30,31,30,31,31,30,31,30,31 };
    int result = day;
    for (int i = 0; i < month-1; i++) {
        result += daysInMonths[i];
    }
    return result;
}