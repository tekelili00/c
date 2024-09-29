#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int leapyear(int a)
{
	if (a % 400 == 0) { return 1; }
	else if  (a % 4 == 0 && a % 100 != 0) { return 1; }
	else { return 0; }
}

int main()
{
	int year, month, day, days, daysofyear = 0;

	printf("year:\n");
	scanf("%d", &year);
	printf("month:\n");
	scanf("%d", &month);
	printf("day:\n");
	scanf("%d", &day);


	int daysinmonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leapyear(year)) { daysinmonth[1] = 29; }



	for (int i = 0; i < month - 1; i++)
	{
		daysofyear += daysinmonth[i];
	}
	daysofyear += day;

	printf("这是今年第%d天\n", daysofyear);

	switch(month) 
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		days = 31;
		break;
	case 4: case 6: case 9: case 11:
		days = 30;
		break;
	case 2: 
		if (leapyear(year)) 
		{
			days = 29;
		}
		else 
		{ 
			days = 28;
		}
		break;

	default:printf("月份输入错误");
		return 1;
	}

	printf("这个月有%d天\n", days);

	return 0;
}