#pragma once
#include <ctime>
#include <iostream>
#include <cstdlib>
template <class T>
class sorting
{
protected:

	virtual bool smaller(const T& a, const T& b) = 0;
	virtual void Swap(T& a, T& b) = 0;
public:
	virtual void sort_it(T* arr, const int& n) = 0;
};


// Statistika osztaly + metodusok definicioja
class Stat
{
private:
	unsigned int time, nComparison, nSwaps;
	std::clock_t Clock; //stopperora
public:
	void init()
	{
		time = 0;
		nComparison = 0;
		nSwaps = 0;
		Clock = 0;
	}
	void start();
	void finish();
	void incComparisons();
	void incSwaps();
public:
	Stat() { init(); };
	unsigned int getCsere();   ///getterek
	unsigned int getHasonlit();
	unsigned int getIdo();
};
void Stat::start()
{
	Clock = clock();
}
void Stat::finish()
{
	Clock = clock() - Clock;
	time = static_cast<unsigned>(static_cast<double>(Clock * 1000 / CLOCKS_PER_SEC));
}
void Stat::incComparisons()
{
	nComparison++;
}
void Stat::incSwaps()
{
	nSwaps++;
}
unsigned int Stat::getCsere()
{
	return nSwaps;
}
unsigned int Stat::getHasonlit()
{
	return nComparison;
}
unsigned int Stat::getIdo()
{
	return time;
}




//Bubble sort
template <class T>
class BubbleSort : public sorting<T>
{
protected:
	void Swap(T& a, T& b);
	bool smaller(const T& a, const T& b);
public:
	void sort_it(T* arr, const int& n);
};
template<class T>
bool BubbleSort<T>::smaller(const T& a, const T& b)
{
	return a < b;
}
template<class T>
void BubbleSort<T>::Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}



template<class T>
void BubbleSort<T>::sort_it(T* arr, const int& n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (smaller(arr[j + 1], arr[j]))
			{
				Swap(arr[j + 1], arr[j]);
			}
		}
	}
}



template<class T>
class BubbleSorT : public BubbleSort<T>, public Stat
{
protected:
	void Swap(T& a, T& b);
	bool smaller(const T& a, const T& b);
public:
	void sort_it(T* arr, const int& n);
};
template <class T>
bool BubbleSorT<T>::smaller(const T& a, const T& b)
{
	incComparisons();
	return BubbleSort<T>::smaller(a, b);
}

template <class T>
void BubbleSorT<T>::Swap(T& a, T& b)
{
	incSwaps();
	BubbleSort<T>::Swap(a, b);
}

template <class T>
void BubbleSorT<T>::sort_it(T* arr, const int& n)
{
	init();
	start();
	BubbleSort<T>::sort_it(arr, n);
	finish();
}

//QuickSort
template <class T>
class QuickSort : public sorting<T>
{
protected:
	void Swap(T& a, T& b);
	bool smaller(const T& a, const T& b);
private:
	void qsort(T* a, const int& left, const int& right);
	int particional(T* a, const int& left, const int& right);
public:
	void sort_it(T* arr, const int& n);
};
template <class T>
void QuickSort<T>::Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}



template <class T>
void QuickSort<T>::qsort(T* a, const int& left, const int& right)
{
	if (left < right)
	{
		T pivot_index = particional(a, left, right);
		qsort(a, left, pivot_index - 1);
		qsort(a, pivot_index + 1, right);
	}
}
template <class T>
int QuickSort<T>::particional(T* a, const int& left, const int& right) {
	int last_change = left;
	int search = right;
	int Last = 0;
	int Search = -1;
	while (last_change < search) {
		if (smaller(a[right], a[left])) {
			Swap(a[last_change], a[search]);
			int tmp = Last;
			Last = -Search;
			Search = -tmp;
		}
		last_change += Last;
		search += Search;
	}
	return last_change;
}


template <class T>
bool QuickSort<T>::smaller(const T& a, const T& b)
{
	return a < b;
}

template <class T>
void QuickSort<T>::sort_it(T* arr, const int& n)
{
	qsort(arr, 0, n - 1);
}

template <class T>

class QuickSortT : public QuickSort<T>, public Stat
{
protected:
	bool smaller(const T& a, const T& b);
	void Swap(T& a, T& b);
public:
	void sort_it(T* arr, const int& n);
};


template <class T>
bool QuickSortT<T>::smaller(const T& a, const T& b)
{
	incComparisons();
	return QuickSort<T>::smaller(a, b);
}

template <class T>
void QuickSortT<T>::Swap(T& a, T& b)
{
	incSwaps();
	return QuickSort<T>::Swap(a, b);
}

template<class T>
void QuickSortT<T>::sort_it(T* arr, const int& n)
{
	init();
	start();
	QuickSort<T>::sort_it(arr, n);
	finish();
}
