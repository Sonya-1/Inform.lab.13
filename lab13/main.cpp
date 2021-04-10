#include <iostream> 
#include "Date.h"

int main() {
    int shift;

    Date date1;
    std::cin >> date1;
    Date date2 = date1;
    Date date3 = date1;
    Date date4 = date1;
    Date date5 = date1;
    Date date6 = date1; 
    Date date7 = date1;


    std::cout << "Input day shift: ";
    std::cin >> shift;
    if (std::cin.fail()) {
        std::cout << "Incorrect value\n";
        std::exit(1);
    }
    std::cout << "Data: " << date1 << '\n';
    
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
    
    bool result = date1 == date_bool;
    std::cout << date1 << " == " << date_bool << " result: " << (result ? "true" : "false") << '\n';

    result = date1 != date_bool;
    std::cout << date1 << " != " << date_bool << " result: " << (result ? "true" : "false") << '\n';

    result = date1 > date_bool;
    std::cout << date1 << " > " << date_bool << " result: " << (result ? "true" : "false") << '\n';

    result = date1 < date_bool;
    std::cout << date1 << " < " << date_bool << " result: " << (result ? "true" : "false") << '\n';

    result = date1 >= date_bool;
    std::cout << date1 << " >= " << date_bool << " result: " << (result ? "true" : "false") << '\n';

    result = date1 <= date_bool;
    std::cout << date1 << " <= " << date_bool << " result: " << (result ? "true" : "false") << '\n';

    return 0;
}