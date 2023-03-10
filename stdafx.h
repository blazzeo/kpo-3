#pragma once

#include <iostream>
#include "stdlib.h"
#include <stdio.h>
#include <string>

using namespace std;

bool leap(int year);
int numOfDay(int day, int month, bool leap);
int errorcatch(int day, int month, int year);
void numtodate(int num);
void timedifference();