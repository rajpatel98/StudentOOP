#include <iostream>
#include <string>
#include "date.h"


using namespace std;

Date::Date(int d, int m, int y): day(d), month(m), year(y){}

ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.day << "/" << date.month << "/" << date.year << " ";
    return os;
}
