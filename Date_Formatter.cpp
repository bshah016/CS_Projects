#include <iostream>
#include <string>

using namespace std;

class Date {
private:
    unsigned int day;
    unsigned int month;
    string monthName;
    unsigned int year;

public:
    // creates the date January 1st, 2000.
    Date(); //***************


    /* parameterized constructor: month number, day, year
        - e.g. (3, 1, 2010) will construct the date March 1st, 2010

        If any of the arguments are invalid (e.g. 15 for month or 32 for day)
        then the constructor will construct instead a valid Date as close
        as possible to the arguments provided - e.g. in above example,
        Date(15, 32, 2010), the Date would be corrected to Dec 31st, 2010.
        In case of such invalid input, the constructor will issue a console error message:

        Invalid date values: Date corrected to 12/31/2010.
        (with a newline at the end).
    */
    Date(unsigned m, unsigned d, unsigned y); //*********************


    /* parameterized constructor: month name, day, year
       - e.g. (December, 15, 2012) will construct the date December 15th, 2012

        If the constructor is unable to recognize the string argument as a valid month name,
        then it will issue a console error message:

        Invalid month name: the Date was set to 1/1/2000.
        (with a newline at the end).

        If the day argument is invalid for the given month (but the month name was valid),
        then the constructor will handle this error in the same manner as the other
        parameterized constructor.

        This constructor will recognize both "december" and "December"
        as month name.
    */
    Date(const string& mn, unsigned d, unsigned y); // ************************


    /* Outputs to the console (cout) a Date exactly in the format "3/15/2012".
       Does not output a newline at the end.
    */
    void printNumeric() const; //*******************************


    /* Outputs to the console (cout) a Date exactly in the format "March 15, 2012".
       The first letter of the month name is upper case, and the month name is
       printed in full - January, not Jan, jan, or january.
       Does not output a newline at the end.
    */
    void printAlpha() const; //*****************

private:

    /* Returns true if the year passed in is a leap year, otherwise returns false.
    */
    bool isLeap(unsigned y); //*********************


    /* Returns number of day allowed in a given month
       -  e.g. dayPerMonth(9, 2000) returns 30.
       Calculates February's day for leap and non-leap years,
       thus, the reason year is also a parameter.
    */
    unsigned dayPerMonth(unsigned m, unsigned y); //**********************

    /* Returns the name of a given month
       - e.g. name(12) returns the string "December"
    */
    string name(unsigned m); //***********************

    /* Returns the number of a given named month
       - e.g. number("March") returns 3
    */
    unsigned number(const string& mn); //*********************
};


// Implement the Date member functions here
Date::Date() {
    day = 1;
    month = 1;
    monthName = "January";
    year = 2000;
}
Date::Date(unsigned int m, unsigned int d, unsigned int y) {
    if (m < 1) {
        m = 1;
    }
    if (d < 1 || d > Date::dayPerMonth(m, y)) {
        if (m > 12) {
            m = 12;
            month = 12;
            monthName = "December";
        }
        if (m < 1) {
            m = 1;
            month = 1;
            monthName = "January";
        }
        if (m == 2) {
            if (d > 28) {
                d = 28;
            }
            else if (d < 1) {
                d = 1;
            }

        }
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (d > 31) {
                d = 31;
            }
            else if (d < 1) {
                d = 1;
            }

        }
        else if (m == 9 || m == 11 || m == 4 || m == 6) {
            if (d > 30) {
                d = 30;
            }
            else if (d < 1) {
                d = 1;
            }
        }
        cout << "Invalid date values: Date corrected to " << m << "/" << d << "/" << y << "." << endl;
    }
    day = d;
    month = m;
    monthName = name(m);
    year = y;

}
Date::Date(const string& mn, unsigned int d, unsigned int y) {
    if (number(mn) == 0) {
        cout << "Invalid month name: the Date was set to 1/1/2000." << endl;
        monthName = "January";
        month = 1;
        day = 1;
        year = 2000;
        return;
    }
    if (d < 1 || d > Date::dayPerMonth(number(mn), y)) {
        if (number(mn) > 12) {
            month = 12;
            if (d > 31) {
                d = 31;
            }
            else if (d < 1) {
                d = 1;
            }
            //mn = "December";
        }
        if (number(mn) < 1) {
            month = 1;
            if (d > 31) {
                d = 31;
            }
            else if (d < 1) {
                d = 1;
            }
            //mn = "January";
        }
        if (number(mn) == 2) {
            if (d > 28) {
                d = 28;
            }
            else if (d < 1) {
                d = 1;
            }

        }
        if (number(mn) == 1 || number(mn) == 3 || number(mn) == 5 || number(mn) == 7 || number(mn) == 8 || number(mn) == 10 || number(mn) == 12) {
            if (d > 31) {
                d = 31;
            }
            else if (d < 1) {
                d = 1;
            }

        }
        else if (number(mn) == 9 || number(mn) == 11 || number(mn) == 4 || number(mn) == 6) {
            if (d > 30) {
                d = 30;
            }
            else if (d < 1) {
                d = 1;
            }
        }
        cout << "Invalid date values: Date corrected to " << number(mn) << "/" << d << "/" << y << "." << endl;
    }
    day = d;
    month = number(mn);
    monthName = mn;
    year = y;

    
    if(true) {
        if (mn == "January" || mn == "january") {
            monthName = "January";
        }
        else if (mn == "February" || mn == "february") {
            monthName = "February";
        }
        else if (mn == "March" || mn == "march") {
            monthName = "March";
        }
        else if (mn == "April" || mn == "april") {
            monthName = "April";
        }
        else if (mn == "May" || mn == "may") {
            monthName = "May";
        }
        else if (mn == "June" || mn == "june") {
            monthName = "June";
        }
        else if (mn == "July" || mn == "july") {
            monthName = "July";
        }
        else if (mn == "August" || mn == "august") {
            monthName = "August";
        }
        else if (mn == "September" || mn == "september") {
            monthName = "September";
        }
        else if (mn == "October" || mn == "october") {
            monthName = "October";
        }
        else if (mn == "November" || mn == "november") {
            monthName = "November";
        }
        else if (mn == "December" || mn == "december") {
            monthName = "December";
        }
        month = number(mn);
        day = d;
        year = y;
    }
    /*
    else  {
    if (d == 1 || d == 21 || d == 31) {
    cout << mn << " " << d << "st, " << y;
    }
    else if (d == 2 || d == 22) {
    cout << mn << " " << d << "nd, " << y;
    }
    else if (d == 3 || d == 23) {
    cout << mn << " " << d << "rd, " << y;
    }
    else if (d != 1 || d != 21 || d != 31 || d != 2 || d != 22 || d != 3 || d != 23) {
    cout << mn << " " << d << "th, " << y;
    }
    }*/
}
void Date::printNumeric() const {
    cout << month << "/" << day << "/" << year;
}
void Date::printAlpha() const {
    cout << monthName << " " << day << ", " << year;
}
string Date::name(unsigned int m) {
    //string month;
    if (m == 1) {
        monthName = "January";
    }
    else if (m == 2) {
        monthName = "February";
    }
    else if (m == 3) {
        monthName = "March";
    }
    else if (m == 4) {
        monthName = "April";
    }
    else if (m == 5) {
        monthName = "May";
    }
    else if (m == 6) {
        monthName = "June";
    }
    else if (m == 7) {
        monthName = "July";
    }
    else if (m == 8) {
        monthName = "August";
    }
    else if (m == 9) {
        monthName = "September";
    }
    else if (m == 10) {
        monthName = "October";
    }
    else if (m == 11) {
        monthName = "November";
    }
    else if (m == 12) {
        monthName = "December";
    }
    else {
        monthName = "Invalid";
    }
    return monthName;
}
bool Date::isLeap(unsigned int y) {
    bool isit;
    if ((y % 100 == 0) && (y % 400 == 0)) {
        isit = true;
    }
    else if ((y % 4 == 0) && (y % 100 != 0)) {
        //cout << inputYear << " is a leap year." << endl;
        isit = true;
    }
    else {
        //cout << inputYear << " is not a leap year." << endl;  
        isit = false;
    }

    return isit;
}
unsigned int Date::dayPerMonth(unsigned int m, unsigned int y) {

    bool isit = false;
    if (isLeap(y)) {
        isit = true;
    }
    if (m == 1) {
        day = 31;
    }
    else if (m == 2) {
        if (isit) {
            day = 29;
        }
        else if (!isit) {
            day = 28;
        }
    }
    else if (m == 3) {
        day = 31;
    }
    else if (m == 4) {
        day = 30;
    }
    else if (m == 5) {
        day = 31;
    }
    else if (m == 6) {
        day = 30;
    }
    else if (m == 7) {
        day = 31;
    }
    else if (m == 8) {
        day = 31;
    }
    else if (m == 9) {
        day = 30;
    }
    else if (m == 10) {
        day = 31;
    }
    else if (m == 11) {
        day = 30;
    }
    else if (m == 12) {
        day = 31;
    }
    return day;
}
unsigned int Date::number(const string& mn) {
    int num = 0;
    if (mn == "January" || mn == "january") {
        num = 1;
    }
    else if (mn == "February" || mn == "february") {
        num = 2;
    }
    else if (mn == "March" || mn == "march") {
        num = 3;
    }
    else if (mn == "April" || mn == "april") {
        num = 4;
    }
    else if (mn == "May" || mn == "may") {
        num = 5;
    }
    else if (mn == "June" || mn == "june") {
        num = 6;
    }
    else if (mn == "July" || mn == "july") {
        num = 7;
    }
    else if (mn == "August" || mn == "august") {
        num = 8;
    }
    else if (mn == "September" || mn == "september") {
        num = 9;
    }
    else if (mn == "October" || mn == "october") {
        num = 10;
    }
    else if (mn == "November" || mn == "november") {
        num = 11;
    }
    else if (mn == "December" || mn == "december") {
        num = 12;
    }
    else {
        num = 0;
    }
    return num;
}
// Don't change the code below this line.
// You may comment them out if you want to build your own test harness
// while in develope mode, but you will need these to pass tets in submit mode.

Date getDate();

int main() {

    Date testDate;
    testDate = getDate();
    cout << endl;
    cout << "Numeric: ";
    testDate.printNumeric();
    cout << endl;
    cout << "Alpha:   ";
    testDate.printAlpha();
    cout << endl;

    return 0;
}

Date getDate() {
    int choice;
    unsigned monthNumber, day, year;
    string monthName;

    cout << "Which Date constructor? (Enter 1, 2, or 3)" << endl
        << "1 - Month Number" << endl
        << "2 - Month Name" << endl
        << "3 - default" << endl;
    cin >> choice;
    cout << endl;

    if (choice == 1) {
        cout << "month number? ";
        cin >> monthNumber;
        cout << endl;
        cout << "day? ";
        cin >> day;
        cout << endl;
        cout << "year? ";
        cin >> year;
        cout << endl;
        return Date(monthNumber, day, year);
    }
    else if (choice == 2) {
        cout << "month name? ";
        cin >> monthName;
        cout << endl;
        cout << "day? ";
        cin >> day;
        cout << endl;
        cout << "year? ";
        cin >> year;
        cout << endl;
        return Date(monthName, day, year);
    }
    else {
        return Date();
    }
}
