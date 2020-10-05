#include <iostream>
using namespace std;

class calender{
    calender();
    public:
    bool book(Date date, TimeRange time);
    bool query(Date date, TimeRange time);
    bool Delete(Date date, TimeRange time);
    void printFreeTimeSolts_days(Date date, TimeRange time);
    //print all free days and timeslots in the calendar that can be booked

    private:
    bool dayinnumber[91];//numbers of day, including weekends and holidays
    //the first day to start is sep 8th to dec 8th
    


};