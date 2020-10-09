#include "calender.hpp"
#include "date.hpp"
#include "time.hpp"
#include <iostream>
using namespace std;

calendar::calendar(){
    cal_month = 9; //fall semester starts from Sep
    cal_day = 1; //first day of class starts on 12th
    cal_year = 2020;
}

void calendar::setMonth(int input_month){//set functions
    cal_month = input_month;
}
void calendar::setday(int input_day){
    cal_day = input_day;
}
void calendar::setyear(int input_year){
    cal_year = input_year;
}
int calendar::getMonth(){return cal_month;} //get functions
int calendar::getday(){return cal_day;}
int calendar::getyear(){return cal_year;}

int calendar::dayNumber(int input_day, int input_month, int input_year){
static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 
					4, 6, 2, 4 }; 
	input_year -= input_month < 3; 
	return ( input_year + input_year/4 - input_year/100 + 
			input_year/400 + t[input_month-1] + input_day) % 7; 
 }

string calendar::getMonthName (int input_month){
    string months[] = {"January", "February", "March", 
					"April", "May", "June", 
					"July", "August", "September", 
					"October", "November", "December"
					}; 

	return (months[input_month]); 
}

int calendar::numberOfDays (int input_month){
	// September 
	if (input_month == 8) 
		return (30); 

	// October 
	if (input_month == 9) 
		return (31); 

	// November 
	if (input_month == 10) 
		return (30); 

	// December 
	if (input_month == 11) 
		return (31); 
}

void calendar::printcalendar(int input_year){
    printf ("		 Calendar - %d\n\n", input_year); 
	int days; 
	int current = dayNumber (1, 9, input_year); 
	for (int i = 8; i < 12; i++) 
	{ 
		days = numberOfDays (i); 
		printf("\n ------------%s-------------\n", 
			getMonthName (i).c_str()); 
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n"); 
		int k; 
		for (k = 0; k < current; k++) 
			printf("	 "); 
		for (int j = 1; j <= days; j++) 
		{ 
			if (i == 8 && j <= 8){
        cout<<"    X";      }
      else
      printf("%5d", j); 
			if (++k > 6) 
			{ 
				k = 0; 
				printf("\n"); 
			} 
		} 
		if (k) 
			printf("\n"); 
		current = k; 
	} 
	return; 
}

bool calendar::book(Date date, TimeRange time){//test
}

bool calendar::query(Date date, TimeRange time){
}

bool calendar::Delete(Date date, TimeRange time){
}

void calendar::printFreeTimeSolts_days(Date date, TimeRange time){
    
}