#include "Array.h"

void Array::Input() {
	for (int i = 0; i < this->size; i++) {
		cout << "A[" << i << "] = ";
		cin >> this->a[i];
	}
}

void Array::Output() {
	for (int i = 0; i < this->size; i++) {
		cout << "A[" << i << "] = " << this->a[i] << "\t";
	}
}

int Array::get_Size() {
	return this->size;
}

int Array::get_Element(int x) {
	for (int i = 0; i < this->size; i++) {
		if (this->a[i] == x) {
			return this->a[i];
		}
	}
	return -1;
}

//Linear Search
int Array::linear_Search(int x) {
	int vt = 0;
	while (vt < this->size && a[vt] != x) {
		vt++;
	}
	if (vt == this->size)
		return -1;
	return vt;
}

//Binary Search
int Array::binary_Search(int x) {
	int left = 0, right = this->size - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] > x) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return -1;	// Not found.
}

//Interpolation search
int Array::interpolation_Search(int x) {
	int left = 0;
	int right = this->size - 1;

	while (left <= right && x >= this->a[left] && x <= this->a[right]) {
		int pos = left + ((x - this->a[left]) * (right - left)) / (this->a[right] - this->a[left]);

		if (this->a[pos] == x) {
			return pos;
		}
		if (this->a[pos] < x) {
			left = pos + 1;
		}
		else {
			right = pos - 1;
		}
	}
	return -1;
}

//Swap & Asc - Dsc
void Array::Swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

bool Ascending(int l, int r) {
	return l > r;
}

bool Descending(int l, int r) {
	return l < r;
}


//Sorted Method
void Array::selection_Sort(Compfunc Sort) {
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = i + 1; j < this->size; j++) {
			if (Sort(this->a[i], this->a[j])) {
				Swap(this->a[i], this->a[j]);
			}
		}
	}
}

void Array::insertion_Sort(Compfunc Sort) {
	int key, j;
	for (int i = 1; i < this->size; i++) {
		key = this->a[i];
		j = i - 1;
		while (j >= 0 && Sort(this->a[j], key)) {
			this->a[j + 1] = this->a[j];
			j -= 1;
		}
		this->a[j + 1] = key;
	}
}

void Array::bubble_Sort(Compfunc Sort) {
	for (int i = 0; i < this->size - 1; i++) {
		for (int j = this->size - 1; j > i; j--) {
			if (Sort(this->a[j - 1], this->a[j])) {
				Swap(this->a[j], this->a[j - 1]);
			}
		}
	}
}

void Array::quick_Sort(int left, int right, bool check_type, Compfunc Sort) {
	int pivot = this->a[(left + right) / 2];
	int i = left, j = right;
	while (i <= j) {
		//If check_type is true -> Ascending
		if (check_type == true) {
			while (this->a[i] < pivot) {
				i++;
			}
			while (this->a[j] > pivot) {
				j--;
			}
		}
		else {
			while (this->a[i] > pivot) {
				i++;
			}
			while (this->a[j] < pivot) {
				j--;
			}
		}
		if (i <= j) {
			Swap(this->a[i], this->a[j]);
			i++;
			j--;
		}
	}
	if (left < j) {
		quick_Sort(left, j, check_type, Sort);
	}
	if (i < right) {
		quick_Sort(i, right, check_type, Sort);
	}
}

void Array::heapify(Array& a, int n, int root, bool check_type) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	//If check_type == true -> Ascending
	if (check_type == true) {
		if (left < n && this->a[left] > this->a[largest])
			largest = left;
		if (right < n && this->a[right] > this->a[largest])
			largest = right;
	}
	else {
		if (left < n && this->a[left] < this->a[largest])
			largest = left;
		if (right < n && this->a[right] < this->a[largest])
			largest = right;
	}
	if (largest != root) {
		Swap(this->a[root], this->a[largest]);
		heapify(a, n, largest, check_type);
	}
}

void Array::heap_Sort(Array& a, bool check_type) {
	int n = this->size;
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(a, n, i, check_type);
	}
	for (int i = n - 1; i > 0; i--) {
		Swap(this->a[0], this->a[i]);
		heapify(a, i, 0, check_type);
	}
}

void Array::shell_Sort(Array& a, bool check_type) {
	int n = this->size;
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = this->a[i];
			int j;
			if (check_type == true) {
				for (j = i; j >= gap && this->a[j - gap] > temp; j -= gap) {
					this->a[j] = this->a[j - gap];
				}
			}
			else {
				for (j = i; j >= gap && this->a[j - gap] < temp; j -= gap) {
					this->a[j] = this->a[j - gap];
				}
			}
			this->a[j] = temp;
		}
	}
}

int Array::findMax(Array& a) {
	int max = this->a[0];
	for (int i = 1; i < this->size; i++) {
		if (this->a[i] > max) {
			max = this->a[i];
		}
	}
	return max;
}

void Array::radix_Sort(Array& a, bool check_type) {
	const int n = a.get_Size();
	int max = findMax(a);
	for (int exp = 1; max / exp > 0; exp *= 10) {
		std::vector<int> output(n);
		int count[10] = { 0 };

		for (int i = 0; i < n; i++) {
			int index = (check_type == true) ? ((this->a[i] / exp) % 10) : (9 - ((this->a[i] / exp) % 10));
			count[index]++;
		}

		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}

		for (int i = n - 1; i >= 0; i--) {
			int index = (check_type == true) ? ((this->a[i] / exp) % 10) : (9 - ((this->a[i] / exp) % 10));
			output[count[index] - 1] = this->a[i];
			count[index]--;
		}

		for (int i = 0; i < n; i++) {
			this->a[i] = output[i];
		}
	}
}

//Selection Search & Sorted method
void Array::search_Location(Array& a, int x,const string& type, bool check_type = true) {	// check_type == true ->ascending
	if (check_type == true) {
		a.radix_Sort(a, true);
	}
	else {
		a.radix_Sort(a, false);0
	}
	if (type == "Linearsearch") {
		cout << "\nSearch " << x << " by Linear search:\n";
		if (a.linear_Search(x) == -1) {
			cout << "Element " << x << " was not found in the array!\n";
		}
		else {
			cout << "Find the number " << x << " at position " << a.linear_Search(x) << " in the array!\n";
		}
	}
	else if (type == "Binarysearch") {
		cout << "\nSearch " << x << " by Binary search:\n";
		if (a.binary_Search(x) == -1) {
			cout << "Element " << x << " was not found in the array!\n";
		}
		else {
			cout << "Find the number " << x << " at position " << a.binary_Search(x) << " in the array!\n";
		}
	}
	else if (type == "Interpolationsearch") {
		cout << "\nSearch " << x << " by Interpolation search:\n";
		if (a.interpolation_Search(x) == -1) {
			cout << "Element " << x << " was not found in the array!\n";
			
		}
		else {
			cout << "Find the number " << x << " at position " << a.interpolation_Search(x) << " in the array!\n";
		}
	}
	else {
		cout << "\nInvalid method!" << endl;
	}
}

void sort_Array(Array& a, const string& method, const string& type) {
	int s = a.get_Size();
	if (method == "Selectionsort") {
		if (type == "Ascending") {
			a.selection_Sort(Ascending);
		}
		else {
			a.selection_Sort(Descending);
		}
	}
	else if (method == "Insertionsort") {
		if (type == "Ascending") {
			a.insertion_Sort(Ascending);
		}
		else {
			a.insertion_Sort(Descending);
		}
	}
	else if (method == "Bubblesort") {
		if (type == "Ascending") {
			a.bubble_Sort(Ascending);
		}
		else {
			a.bubble_Sort(Descending);
		}
	}
	else if (method == "Quicksort") {
		if (type == "Ascending") {
			a.quick_Sort(0, s - 1, true, Ascending);
		}
		else {
			a.quick_Sort(0, s - 1, false, Descending);
		}
	}
	else if (method == "Heapsort") {
		if (type == "Ascending") {
			a.heap_Sort(a, true);
		}
		else {
			a.heap_Sort(a, false);
		}
	}
	else if (method == "Shellsort") {
		if (type == "Ascending") {
			a.shell_Sort(a, true);
		}
		else {
			a.shell_Sort(a, false);
		}
	}
	else if (method == "Radixsort") {
		if (type == "Ascending") {
			a.radix_Sort(a, true);
		}
		else {
			a.radix_Sort(a, false);
		}
	}
	else {
		cout << "\nInvalid method!" << endl;
	}
}

void Array::get_Search(Array& a) {
	Search_Method();
	int l;
	cout << "\nEnter the position of the element you want to find in the array: ";
	cin >> l;
	int inp;
	do {
		fflush(stdin);
		cout << "\nSelection:";
		cin >> inp;
		switch (inp) {
			int select;
			fflush(stdin);
		case 1: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				a.search_Location(a, l, "Linearsearch", true);
				break;
			}
			else if (select == 2) {
				a.search_Location(a, l, "Linearsearch", false);
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 2: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				a.search_Location(a, l, "Binarysearch", true);
				break;
			}
			else if (select == 2) {
				a.search_Location(a, l, "Binarysearch", false);
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 3: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				a.search_Location(a, l, "Interpolationsearch", true);
				break;
			}
			else if (select == 2) {
				a.search_Location(a, l, "Interpolationsearch", false);
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		default:
			printf("Please try again!!!!\n");
			return;
		}
	} while (inp == 1 || inp == 2 || inp == 3);
}

void Array::get_Sorted(Array& a) {
	Sorted_Method();
	int inp;
	do {
		fflush(stdin);
		cout << "\nSelection:";
		cin >> inp;
		switch (inp) {
			int select;
			fflush(stdin);
		case 1: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				sort_Array(a, "Selectionsort", "Ascending");
				cout << "\n\nArray after Ascending with Selection sort is:\n";
				a.Output();
				break;
			}
			else if(select == 2) {
				sort_Array(a, "Selectionsort", "Descending");
				cout << "\n\nArray after Descending with Selection sort is:\n";
				a.Output();
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 2: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				sort_Array(a, "Insertionsort", "Ascending");
				cout << "\n\nArray after Ascending with Insertion sort is:\n";
				a.Output();
				break;
			}
			else if (select == 2) {
				sort_Array(a, "Insertionsort", "Descending");
				cout << "\n\nArray after Descending with Insertion sort is:\n";
				a.Output();
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 3: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				sort_Array(a, "Bubblesort", "Ascending");
				cout << "\n\nArray after Ascending with Bubble sort is:\n";
				a.Output();
				break;
			}
			else if (select == 2) {
				sort_Array(a, "Bubblesort", "Descending");
				cout << "\n\nArray after Descending with Bubble sort is:\n";
				a.Output();
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 4: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				sort_Array(a, "Quicksort", "Ascending");
				cout << "\n\nArray after Ascending with Quick sort is:\n";
				a.Output();
				break;
			}
			else if (select == 2) {
				sort_Array(a, "Quicksort", "Descending");	//
				cout << "\n\nArray after Descending with Quick sort is:\n";
				a.Output();
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 5: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				sort_Array(a, "Heapsort", "Ascending");
				cout << "\n\nArray after Ascending with Heap sort is:\n";
				a.Output();
				break;
			}
			else if (select == 2) {
				sort_Array(a, "Heapsort", "Descending");
				cout << "\n\nArray after Descending with Heap sort is:\n";
				a.Output();
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 6: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				sort_Array(a, "Shellsort", "Ascending");
				cout << "\n\nArray after Ascending with Shell sort is:\n";
				a.Output();
				break;
			}
			else if (select == 2) {
				sort_Array(a, "Shellsort", "Descending");
				cout << "\n\nArray after Descending with Shell sort is:\n";
				a.Output();
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		case 7: {
			cout << "\n(1). Ascending\t\t\t(2).Descending\n";
			cin >> select;
			if (select == 1) {
				sort_Array(a, "Radixsort", "Ascending");
				cout << "\n\nArray after Ascending with Radix sort is:\n";
				a.Output();
				break;
			}
			else if (select == 2) {
				sort_Array(a, "Radixsort", "Descending");
				cout << "\n\nArray after Descending with Radix sort is:\n";
				a.Output();
				break;
			}
			else {
				cout << "Please try again!\n";
			}
		}
		default:
			printf("Please try again!!!!\n");
			return;
		}
	} while (inp == 1 || inp == 2 || inp == 3 || inp == 4 || inp == 5 || inp == 6 || inp == 7);
}

void Search_Method() {
	cout << "\t===============SEARCH METHOD===================\n";
	cout << "\t|            1. Linear Search                 |\n";
	cout << "\t|            2. Binary Search                 |\n";
	cout << "\t|            3. Interpolation Search          |\n";
	cout << "\t=====================The end===================\n";
}

void Sorted_Method() {
	cout << "\t===============SORTED METHOD===================\n";
	cout << "\t|            1. Selection Sort                |\n";
	cout << "\t|            2. Insertion Sort                |\n";
	cout << "\t|            3. Bubble Sort                   |\n";
	cout << "\t|            4. Quick Sort                    |\n";
	cout << "\t|            5. Heap Sort                     |\n";
	cout << "\t|            6. Shell Sort                    |\n";
	cout << "\t|            7. Radix Sort                    |\n";
	cout << "\t=====================The end===================\n";
}