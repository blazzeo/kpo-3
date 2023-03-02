#include "stdafx.h"

using namespace std;

int errorcatch(int day, int month, int year) {
	if (day > 31 || day<1 || month < 1 || month > 12 || year<0) {
		cout << "error";
		system("pause");
		exit(EXIT_FAILURE);
	}
	return 1;
}