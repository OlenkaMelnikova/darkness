// Struct My_Time.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>

#define DELAY 315360000

struct my_time{
	int hours;
	int minutes;
	int seconds;
	int days;
};

void display(struct my_time *t);
void update(struct my_time *t);
void delay(void);


int main(void)
{
	struct my_time systime;

	systime.hours = 0;
	systime.minutes = 0;
	systime.seconds = 0;
	systime.days = 0;

	for (;;) {
		update(&systime);
		display(&systime);
	}

	return 0;
}

void update(struct my_time *t)
{
	t->seconds++;
	if (t->seconds == 60){
		t->seconds = 0;
		t->minutes++;
	}
	if (t->minutes == 60){
		t->minutes = 0;
		t->hours++;
	}
	if (t->hours == 24){
		t->hours = 0;
		t->days++;
	}
	if (t->days == 365) t->days = 0;
	delay();
}
void display(struct my_time *t)
{
	printf_s("%02d:", t->days);
	printf_s("%02d:", t->hours);
	printf_s("%02d:", t->minutes);
	printf_s("%02d\n", t->seconds);
}
void delay(void)
{
	long int t;
	for (t = 1; t < DELAY; ++t);
}
