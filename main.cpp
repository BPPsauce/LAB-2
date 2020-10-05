//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include "time.hpp"
#include "date.hpp"

int main(){
  cout<<"Welcome to the appointment booking system, you can book your appointment here\n";
  cout<<"You can book your appointment from Monday to Friday, from 0:00AM to 24:00PM\n";
  cout<<"We will not open our services on weekend or the holidays, please be aware of this.\n";
  Date User_data1;
  TimeRange user_input;
  int user_month, user_date = 0;
  int user_start_hr =0;
  int user_start_min =0;
  int user_end_hr =0;
  int user_end_min =0;

  char user_choice_date;//loop for keep asking month if user enters invalid number
  while (1)
  {
  cout<<"Please enter the of month you would like to book as a number (January = 1, December = 12): \n";
  cout<<"Starting from 2020 fall Calender...(Sep - Dec)\n";
  cin >> user_month;
  cout<<"Please enter the date would you like to book: \n";
  cin >> user_date;
  if(User_data1.isValid(user_month,user_date) == 1){
    break;
  }
  else
  {
    cout<<"Please checkt your infomation!\n";
    cout<<"------------------------------\n";
  }
}
 
  do
  {
      cout << "Please enter the start hour of your desired appointment: ";
      cin >> user_start_hr;
      cout << "Please enter the starting minute of your desired appointment \nBe advised we only offer appointments in increments of half an hour: ";
      cin >> user_start_min;
      cout << "Please enter the hour you would like your appointment to end: ";
      cin >> user_end_hr;
      cout << "Please enter the minute you would like your appointment to end (must be an increment of half an hour): ";
      cin >> user_end_min;
  } while (user_input.isValid(user_start_hr, user_start_min, user_end_hr, user_end_min) == 0);//loop for keep asking the time if user enters invalid numbers

  //set and get
  User_data1.setMonth(user_month);
  User_data1.getMonth();
  User_data1.setDate(user_date);
  User_data1.getDate();
  User_data1.setStartTime_hr(user_start_hr);
  User_data1.getStartTime_hr();
  User_data1.setStartTime_min(user_start_min);
  User_data1.getStartTime_min();
  User_data1.setEndTime_hr(user_end_hr);
  User_data1.getEndTime_hr();
  User_data1.setEndTime_min(user_end_min);
  User_data1.getEndTime_min();
  user_input.setbeginHour(user_start_hr);
	user_input.getbeginHour();
	user_input.setbeginMinute(user_start_min);
	user_input.getbeginMinute();
	user_input.setendHour(user_end_hr);
	user_input.getendHour();
	user_input.setendMinute(user_end_min);
	user_input.getendMinute();


  char user_choice;
  while (1)
  {
  cout<<"Would you like to see some infomation about this date?\n"<<"Enter 'A' to see appointed and free slots, 'N' for nothing\n";
  cin>>user_choice;
  if(user_choice == 'A'||user_choice == 'N'){
    break;
  }
  else
  {
    cout<< "Sorry, please enter the right letter for the options\n";
  }
  }
    
  if(user_choice == 'A'){
    User_data1.printAppointedTimeSlots(user_month,user_date,user_start_hr,user_start_min,user_end_hr,user_end_min);
    User_data1.printFreeTimeSlots(user_month,user_date,user_start_hr,user_start_min,user_end_hr,user_end_min);
  }
  else if(user_choice == 'N'){
    cout<<"Processing...\n";
  }
  
  cout<<"Appointment summary:\n";//printing the summary of the appointment
  User_data1.output(user_month,user_date);
  user_input.output(user_start_hr,user_start_min,user_end_hr,user_end_min);
  
  cout<<"OK with your choice?\n";//confrimation 
  cout<<"Press '1' for yes\n";
  int answer;
  cin>>answer;
  if (answer == 1){
    cout<<"GREAT! See you then!\n";
  }
  if (answer != 1){
    cout<<"Sorry, try again next time :(\n";
  }
  return 0;
}
