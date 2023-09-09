#include "Array.h"

int main() {
	cout << "Name: Dinh Duc\t\t Class: 22T_DT2\n";
	cout << "MSSV: 102220098\n\n";
	int s;
	cout << "Enter the size of Array: ";
	cin >> s;

	//Initialize array with size s
	Array a(s);

	//Get inforation of array
	a.Input();
	cout << "\nArray is:\n";
	a.Output();

	//Get size of array
	cout << "\n\nSize of array is: " << a.get_Size();

	//Get element
	int e;
	cout << "\n\nEnter the number you want to search: ";
	cin >> e;
	if (a.get_Element(e) != -1) {
		cout << "\nFind the number " << e << " in the array!\n";
	}
	else {
		cout << "\nNumber " << e << " was not found in the array!\n";
	}

	//Search method
	a.get_Search(a);

	//Sort method
	a.get_Sorted(a);

	return 0;
}