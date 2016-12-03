static char day_tbl[2][13] {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int DayOfYear(int year, int month, int day) {
	int leap, i;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++) {
		day += day_tbl[leap][i];
	}

	return day;
}

void MonthDay(int year, int yearday, int *pmonth, int *pday) {
	int leap, i;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > day_tbl[leap][i]; i++) {
		yearday -= day_tbl[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}
