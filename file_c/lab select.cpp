#include<iostream>

using namespace std;
int main(){int year,week,days;
int number_of_days,DAYS_IN_WEEK;
     days=1532;
     year = number_of_days / 365;
    week = (number_of_days % 365) /
            DAYS_IN_WEEK;
    days = (number_of_days % 365) %
            DAYS_IN_WEEK;
             
    cout << "years = " << year;
    cout << "\nweeks = " << week;
    cout << "\ndays =  " << days;   
}


