#include <iostream> 
#include "date.h"

int main() {
    int shift;

    Date date1;
    std::cin >> date1;
    
    Date date_julian = date1.julian_date();
    std::cout << "Date: " << date1 << '\n';
    std::cout << "Julian date: " << date_julian << '\n';

    Date date2 = date_julian;
    Date date3 = date_julian;
    Date date4 = date_julian;
    Date date5 = date_julian;
    Date date6 = date_julian;
    Date date7 = date_julian;

    std::cout << "Input day shift: ";
    std::cin >> shift;
    if (std::cin.fail()) {
        std::cout << "Incorrect value\n";
        std::exit(1);
    }

    date2 + shift;
    date3 += shift;
    Date date41 = ++date4;
    Date date61 = date6++;
    Date date51 = --date5;
    Date date71 = date7--;
    std::cout << "date + " << shift << " : " << date2 << '\n';
    std::cout << "date += " << shift << " : " << date3 << '\n';
    std::cout << "++date : " << date4 << '\n';
    std::cout << "date++ : " << date6 << '\n';
    std::cout << "--date : " << date5 << '\n';
    std::cout << "date-- : " << date7 << '\n';

    std::cout << "Date to test bool operators\n";
    Date date_bool;
    std::cin >> date_bool;
    std::cout << "Data: " << date_bool << '\n';
    Date date_bool_julian = date_bool.julian_date();
    std::cout << "Julian date: " << date_bool_julian << '\n';

    bool result = date_julian == date_bool_julian;
    std::cout << date_julian << " == " << date_bool_julian << " result: " << (result ? "true" : "false") << '\n';

    result = date_julian != date_bool_julian;
    std::cout << date_julian << " != " << date_bool_julian << " result: " << (result ? "true" : "false") << '\n';

    result = date_julian > date_bool_julian;
    std::cout << date_julian << " > " << date_bool_julian << " result: " << (result ? "true" : "false") << '\n';

    result = date_julian < date_bool_julian;
    std::cout << date_julian << " < " << date_bool_julian << " result: " << (result ? "true" : "false") << '\n';

    result = date_julian >= date_bool_julian;
    std::cout << date_julian << " >= " << date_bool_julian << " result: " << (result ? "true" : "false") << '\n';

    result = date_julian <= date_bool_julian;
    std::cout << date_julian << " <= " << date_bool_julian << " result: " << (result ? "true" : "false") << '\n';
    
    return 0;
}