#include <stdio.h>

static char day_tbl[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int DayOfYear(int year, int month, int day) {
	int leap, i;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	if (month > 12 || month < 1 || day < 1 || day > 31 || (leap && month == 2 && day > 29)
			|| (!leap && month == 2 && day > 28)) {
		printf("error: wrong date");
		return 0;
	}

	for (i = 1; i < month; i++) {
		day += day_tbl[leap][i];
	}

	return day;
}

void MonthDay(int year, int yearday, int *pmonth, int *pday) {
	int leap, i;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	if ((leap && yearday > 366) || (!leap && yearday > 365)) {
		printf("error: too many days!");
		return ;
	}
	for (i = 1; yearday > day_tbl[leap][i]; i++) {
		yearday -= day_tbl[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
}


int main()
{
	int year, month, day, yearday;
	int new_month, new_day;

	printf("Enter year month day: ");
	scanf("%d%d%d", &year, &month, &day);
	yearday = DayOfYear(year, month, day);
	printf("%d\n", yearday);
	
	MonthDay(year, yearday, &new_month, &new_day);
	printf("%d %d %d\n", year, new_month, new_day);

	return 0;
}
