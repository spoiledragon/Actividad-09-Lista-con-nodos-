#include "Date.h"

using namespace std;



Date::Date(){}



Date::Date(const Date& d) : year(d.year),month(d.month),day(d.day){}
Date& Date::operator=(const Date& d){
    year= d.year;
    day=d.day;
    month=d.month;

    return *this;
}

//getters
int Date::toInt() const {
    return year * 10000 + month * 100 + day;
}
int Date::getDay()      const{return day;}
int Date::getMonth()    const{return month;}
int Date::getYear()     const{return year;}
string Date::toString() const{
        string fecha;
        fecha+= to_string(day);
        fecha+="/";
        fecha+=to_string(month);
        fecha+="/";
        fecha+=to_string(year);
        return fecha;}

//setters
void Date::setDay(const int& d)      {day=d;}
void Date::setMonth(const int& m)    {month=m;}
void Date::setYear(const int& y)     {year = y;}


