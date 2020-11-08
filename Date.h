#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include<iostream>
#include<string.h>

class Date
{
    private:
    int day;
    int month;
    int year;

    int toInt()const;

    public:

    Date();
    Date(const Date&);
    std::string toString() const;


    int getYear()  const;
    int getDay()   const;
    int getMonth() const;


    void setDay(const int&);
    void setYear(const int&);
    void setMonth(const int&);

    bool operator == (const Date&) const;
    Date& operator = (const Date&);
};
#endif //DATE_H_INCLUDED

