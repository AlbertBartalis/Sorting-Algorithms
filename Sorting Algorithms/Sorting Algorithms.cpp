#include <iostream>
#include "sortingAlgorithms.h"
#include<ctime>
using namespace std;
template <class T>
void print(const char* s, T* a, const int n)
{
	cout << s << endl;
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void  main() {
	int t1[1000], t2[1000];
	for (int i = 0; i < 1000; i++) {
		t1[i] = 1000 - i;
		t2[i] = 1000 - i;
	}
	sorting <int>* r[] = { new BubbleSorT<int>, new QuickSortT<int> };
	r[0]->sort_it(t1, 1000);
	cout << "Bubble sort:" << endl;
	cout << "===================" << endl;
	cout << "Number of comparisons: " << (dynamic_cast<BubbleSorT<int>*>(r[0]))->getHasonlit() << endl;
	cout << "Number of swaps: " << (dynamic_cast<BubbleSorT<int>*>(r[0]))->getCsere() << endl;
	cout << "Time (ms): " << (dynamic_cast<BubbleSorT<int>*>(r[0]))->getIdo() << endl;
	cout << endl;
	cout << "QuickSort:" << endl;
	cout << "==========" << endl;
	r[1]->sort_it(t2, 1000);
	cout << "Number of comparisons: " << (dynamic_cast<QuickSortT<int>*>(r[1]))->getHasonlit() << endl;
	cout << "Number of swaps: " << (dynamic_cast<QuickSortT<int>*>(r[1]))->getCsere() << endl;
	cout << "Time (ms): " << (dynamic_cast<QuickSortT<int>*>(r[1]))->getIdo() << endl;

	int cmd = 3;
	cout << endl;
	while (cmd != 0)
	{
		cout << "Which array do you want to print? \n";
		cout << "1. Array sorted with Bubble Sort\n";
		cout << "2. Array sorted with Quick Sort \n";
		cout << "0. Neither, I want to exit the program \n";
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			print("Bubble sort", t1, 1000);
			break;
		case 2:
			print("Quick sort", t2, 1000);
		default:
			break;
		}
	}
	return;
}

