#include "stdafx.h"
using namespace std;

void numtodate(int num) {
    int daysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    for (int i=0;i<12;i++) {
        if (num>31) {
            num-=daysInMonths[i];
        } else {
            i++;
            printf("%02d%02dYYYY",num,i);
            break;
        }
    }
}