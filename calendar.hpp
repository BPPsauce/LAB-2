#include <iostream>
using namespace std;

class calendar{
    calendar();
    public:
    bool book(Date date, TimeRange time);
    bool query(Date date, TimeRange time);
    bool Delete(Date date, TimeRange time);
    void printFreeTimeSlots_days(Date date, TimeRange time);
    //print all free days and timeslots in the calendar that can be booked
    void printFreeTimeSolts_days(Date date, TimeRange time);//print all free days and timeslots in the calendar that can be booked
    void printcalendar(int input_year);
    int dayNumber(int input_day, int input_month, int input_year);
    string getMonthName (int input_month);
    int numberOfDays (int input_month);

    void setMonth (int);
    void setday (int); 
    void setyear(int);
    int getMonth ();
    int getday ();
    int getyear();

    
    private:
    bool dayinnumber[91];//numbers of day, including weekends and holidays
    //the first day to start is sep 8th to dec 8th



    Date availableDates[91];
    
    Date date;
    TimeRange time;
    
    int cal_month;
    int cal_day;
    int cal_year;


};