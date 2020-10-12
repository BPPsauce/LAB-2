//main.cpp, put your driver code here, 
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include "time.hpp"
#include "date.hpp"
#include "calendar.hpp"

int main(){


  calendar calendarobject;
  Date User_data1;
  Date bookedAppts;
  TimeRange user_input;
  const string slot[48] ={//timeslot print
 "00:00 - 00:30","00:30 - 01:00","01:00 - 01:30","01:30 - 02:00","02:00 - 02:30"
,"02:30 - 03:00","03:00 - 03:30","03:30 - 04:00","04:00 - 04:30","04:30 - 05:00"
,"05:00 - 05:30","05:30 - 06:00","06:00 - 06:30","06:30 - 07:00","07:00 - 07:30"
,"07:30 - 08:00","08:00 - 08:30","08:30 - 09:00","09:00 - 09:30","09:30 - 10:00"
,"10:00 - 10:30","10:30 - 11:00","11:00 - 11:30","11:30 - 12:00","12:00 - 12:30"
,"12:30 - 13:00","13:00 - 13:30","13:30 - 14:00","14:00 - 14:30","14:30 - 15:00"
,"15:00 - 15:30","15:30 - 16:00","16:00 - 16:30","16:30 - 17:00","17:00 - 17:30"
,"17:30 - 18:00","18:00 - 18:30","18:30 - 19:00","19:00 - 19:30","19:30 - 20:00"
,"20:00 - 20:30","20:30 - 21:00","21:00 - 21:30","21:30 - 22:00","22:00 - 22:30"
,"22:30 - 23:00","23:00 - 23:30","23:30 - 24:00"};
  int user_month, user_date = 0;
  int user_start_hr =0;
  int user_start_min =0;
  int user_end_hr =0;
  int user_end_min =0;
  int primaryInput;
  cout<<"Welcome to the appointment system\n";
  cout<<"Press 1 to view all booked appointments \n";
  cout<<"Press 2 to view all available appointment time slots that have not been booked \n";
  cout<<"Press 3 to book an appointment\n";
  cout<<"Press 4 to check the status of an an appointment time slot\n";
  cout<<"Press 5 to delete a booked appointment time\n";
  cout<<"We will not be open on weekend or the holidays, please be aware of this.\n";
  cin >> primaryInput;

switch (primaryInput)
 {

 case 1:
 // display all booked appointments

if (time.isValid(time.getbeginHour(),time.getbeginMinute(),time.getendHour(),time.getendMinute() == 0)){
		cout<<"Appointment cannot be booked! Wrong time is given!\n";
		return false;
	}
 
  /* cout<<"Appointment summary:\n"; //printing the summary of the appointment
  User_data1.output(user_month,user_date);
  user_input.output(user_start_hr,user_start_min,user_end_hr,user_end_min); */
 break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
 case 2: 
 // display all AVAILABLE appointments

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
  break;
 break;
////////////////////////////////////////////////////////////////////////
 case 3: 
  
  char user_choice_date;//loop for keep asking month if user enters invalid number
  while (1)
  {
  cout<<"Please enter the of month you would like to book as a number (January = 1, December = 12): \n";
  cout<<"Starting from 2020 fall Calender...(Sep - Dec)\n";
  cin >> user_month;
  cout<<"Please enter the date would you like to view/book: \n";
  cin >> user_date;
  if(User_data1.isValid(user_month,user_date) == 1){
    break;
  }
  else
  {
    cout<<"Please ensure your information is correct!\n";
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


  char user_answer;
  while (1)
  {
  cout<<"Would you like to see some infomation about this date?\n"<<"Enter 'A' to see appointed and free slots, 'N' for nothing\n";
  cin>>user_answer;
  if(user_answer == 'A'||user_answer == 'N'){
    break;
  }
  else
  {
    cout<< "Sorry, please enter the right letter for the options\n";
  }
  }
    
  if(user_answer== 'A'){
    User_data1.printAppointedTimeSlots(user_month,user_date,user_start_hr,user_start_min,user_end_hr,user_end_min);
    User_data1.printFreeTimeSlots(user_month,user_date,user_start_hr,user_start_min,user_end_hr,user_end_min);
  }
  else if(user_answer == 'N'){
    cout<<"Processing...\n";
  }
  break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  case 4:
  
  while (1)
  {
  cout<<"Please enter the of month you would like to view as a number (January = 1, December = 12): \n";
  cout<<"Starting from 2020 fall Calender...(Sep - Dec)\n";
  cin >> user_month;
  cout<<"Please enter the date would you like to view: \n";
  cin >> user_date;
  if(User_data1.isValid(user_month,user_date) == 1){
    break;
  }
  else
  {
    cout<<"Please ensure your information is correct!\n";
    cout<<"------------------------------\n";
  }
}
  do
  {
      cout << "Please enter the start hour of the appointment: ";
      cin >> user_start_hr;
      cout << "Please enter the starting minute of the appointment(increment of half an hour):" ;
      cin >> user_start_min;
      cout << "Please enter the ending hour of the appointment ";
      cin >> user_end_hr;
      cout << "Please enter the ending minute of the appointment (increment of half an hour): ";
      cin >> user_end_min;
  } while (user_input.isValid(user_start_hr, user_start_min, user_end_hr, user_end_min) == 0);//loop for keep asking the time if user enters invalid numbers
  
  // implement query function here, similar to time slots function but no printing, bool return value
    calendarobject.query(User_data1, user_input);
  
  //Check status of appointment time slot
  break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
  case 5:
 while (1)
  {
  cout<<"Please enter the of month you would like to delete as a number (January = 1, December = 12): \n";
  cout<<"Starting from 2020 fall Calender...(Sep - Dec)\n";
  cin >> user_month;
  cout<<"Please enter the date of the appointment would you like to delete: \n";
  cin >> user_date;
  if(User_data1.isValid(user_month,user_date) == 1){
    break;
  }
  else
  {
    cout<<"Please ensure your information is correct!\n";
    cout<<"------------------------------\n";
  }
}
  do
  {
      cout << "Please enter the start hour of the appointment: ";
      cin >> user_start_hr;
      cout << "Please enter the starting minute of the appointment(increment of half an hour):" ;
      cin >> user_start_min;
      cout << "Please enter the ending hour of the appointment ";
      cin >> user_end_hr;
      cout << "Please enter the ending minute of the appointment (increment of half an hour): ";
      cin >> user_end_min;
  } while (user_input.isValid(user_start_hr, user_start_min, user_end_hr, user_end_min) == 0);//loop for keep asking the time if user enters invalid numbers
   // use option 4 to first check if the appointment is booked, check validity then delete if it is valid
  calendarobject.Delete(User_data1, user_input);

  // delete a scheduled appointment
  break;

  cout<<"Appointment summary:\n";//printing the summary of the appointment
  User_data1.output(user_month,user_date);
  user_input.output(user_start_hr,user_start_min,user_end_hr,user_end_min);
  
  cout<<"OK with your choice?\n";//confirmation 
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




}