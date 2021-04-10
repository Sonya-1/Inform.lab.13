#include <iostream> 

#ifndef A_H
#define A_H

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date();
    Date(int y, int m, int d);
    void set(int y, int m, int d);
    int get_year();
    int get_month();
    int get_day();
    friend Date operator+(Date& d, const int n);
    Date operator+=(const int n);
    Date& operator=(Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator>(const Date& d);
    bool operator<(const Date& d);
    bool operator>=(const Date& d);
    bool operator<=(const Date& d);
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    void shift(int n);
    friend std::ostream& operator<<(std::ostream& out, const Date& d);
    friend std::istream& operator>>(std::istream& in, Date& d);
};

#endif
