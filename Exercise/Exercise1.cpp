#include "Cdate.h"

int main() {
    cout << "Name: Dinh Duc\t\t Class: 22T_DT2\n";
    cout << "MSSV: 102220098\n\n";
    Cdate date1, date2;
    //Date 1:
    cout << "Enter the date 1:\n";
    cin >> date1;
    cout << "The date of date 1 is " << date1.calculateDayOfWeek(date1) << " " << date1 << endl;
    ++date1;
    cout << "The next date of date 1 is " << date1 << endl;
    --date1;
    --date1;
    cout << "The previous date of date 1 is: " << date1 << endl;

    //Date 2:
    cout << "Enter the date 2:\n";
    cin >> date2;
    cout << "The date of date 2 is: " << date2.calculateDayOfWeek(date2) << " " << date2 << endl;
    ++date2;
    cout << "The next date of date 2 is: " << date2 << endl;
    --date2;
    --date2;
    cout << "The previous date of date 2 is: " << date2 << endl;

    //Compare two date
    if (date1 < date2) {
        cout << "date1 < date2" << endl;
    }
    else if (date1 > date2) {
        cout << "date1 > date2" << endl;
    }
    else {
        cout << "date1 == date2" << endl;
    }

    if (date1 == date2) {
        cout << "date1 == date2" << endl;
    }
    else {
        cout << "date1 != date2" << endl;
    }

    return 0;
}