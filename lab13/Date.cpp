#include <iostream> 
#include "Date.h"


int get_days_in_month(int y, int m) {
    if (m == 2) {
        if (y % 1000 == 0) { return 29; }
        else if (y % 100 == 0) { return 28; }
        else if (y % 4 == 0) { return 29; }
        else { return 28; }
    }
    if (m == 4 || m == 6 || m == 9 || m == 11) { return 30; }
    return 31;
}

void Date::shift(int n) {
    int days_in_month, day_in_prev_month;
    this->day += n;

    for (;;) {
        days_in_month = get_days_in_month(this->year, this->month);

        if (this->day > days_in_month) {
            this->month += 1;

            if (this->month > 12) {
                this->month = 1;
                this->year += this->year == -1 ? 2 : 1;
            }
            this->day -= days_in_month;
        }
        else if (this->day < 1) {
            this->month -= 1;

            if (this->month < 1) {
                this->month = 12;
                this->year -= this->year == 1 ? 2 : 1;
            }
            day_in_prev_month = get_days_in_month(this->year, this->month);

            this->day += day_in_prev_month;
        }
        else {
            break;
        }
    }
}

Date::Date(int y, int m, int d) {
    this->year = y;
    this->month = m;
    this->day = d;
}

Date::Date() {
    this->year = 2021;
    this->month = 3;
    this->day = 26;
}

void Date::set(int y, int m, int d) {
    this->year = y;
    this->month = m;
    this->day = d;
}

int Date::get_year() {
    return this->year;
}

int Date::get_month() {
    return this->month;
}

int Date::get_day() {
    return this->day;
}

Date operator+(Date& d, const int n) {
    d.shift(n);
    return d;
}

Date Date::operator+=(const int n) {
    this->shift(n);
    return *this;
}

Date& Date::operator=(Date& d) {
    if (&d == this) { return *this; }
    this->year = d.year;
    this->month = d.month;
    this->day = d.day;
    return *this;
}

bool Date::operator==(const Date& d) {
    return this->year == d.year && this->month == d.month && this->day == d.day;
}

bool Date::operator!=(const Date& d) {
    return !(*this == d);
}

bool Date::operator>(const Date& d) {
    if (this->year > d.year) {
        return true;
    }
    if (this->year == d.year) {
        if (this->month > d.month) {
            return true;
        }
        if (this->month == d.month) {
            if (this->day > d.day) {
                return true;
            }
        }
    }
    return false;
}

bool Date::operator<(const Date& d) {
    return *this != d && !(*this > d);
}

bool Date::operator>=(const Date& d) {
    return *this == d || *this > d;
}

bool Date::operator<=(const Date& d) {
    return *this == d || *this < d;
}

Date& Date::operator++() {
    this->shift(1);
    return *this;
}

Date Date::operator++(int) {
    Date tmp = *this;
    ++(*this);
    return tmp;
}

Date& Date::operator--() {
    this->shift(-1);
    return *this;
}

Date Date::operator--(int) {
    Date tmp = *this;
    --(*this);
    return tmp;
}

std::ostream& operator<< (std::ostream& out, const Date& d) {
    out << d.day << '.' << d.month << '.' << d.year;
    return out;
}

std::istream& operator>>(std::istream& in, Date& d) {

    std::cout << "Input year: ";
    in >> d.year;
    if (d.year == 0 || std::cin.fail()) {
        std::cout << "Incorrect year\n";
        std::exit(1);
    }

    std::cout << "Input month: ";
    in >> d.month;
    if (d.month > 12 || d.month < 1 || std::cin.fail()) {
        std::cout << "Incorrect month\n";
        std::exit(1);
    }

    std::cout << "Input day: ";
    in >> d.day;
    if (d.day > get_days_in_month(d.year, d.month) || d.day < 1 || std::cin.fail()) {
        std::cout << "Incorrect day\n";
        std::exit(1);
    }

    return in;
}