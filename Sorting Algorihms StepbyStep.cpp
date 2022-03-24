// SortingAlgorithmsStepbyStep.cpp : Defines the entry point for the console application.
// Developed by Maurya Sharma, B.Tech. (CSE) 3rd Sem

#include "iostream"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "ctype.h"

using namespace std;
class Sorting
{
	int *List;
	int *List1;
	int Low;
	int High;

public:
	Sorting()
	{
		List = NULL;
		Low = High = 0;
	}
	Sorting(int n)
	{
		List = new int[n];
		List1 = new int[n];
		Low = 0;
		High = n;
	}
	~Sorting()
	{
		delete[] List;
		delete[] List1;
	}
	void InitList();
	void CopyList();
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	void RadixSort();
	void RadixSortForWords();
	void Heapify();
	void SiftDown(int start, int count);
	void HeapSort();
	void QuickSort();
	void QSort(int low, int high);
	void MergeSort();
	void MSort(int low, int high);
	void Merge(int low1, int high1, int low2, int high2);
	void ShellSort();
	void Interchange(int &x, int &y);
	void CombSort();

};

void Sorting::InitList()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < High; i++)
		List1[i] = rand() % 100;
}

void Sorting::CopyList()
{
	for (int i = 0; i < High; i++)
		List[i] = List1[i];
}

void Sorting::BubbleSort()
{
	int i, j, k, comparisons, interchanges;
	CopyList();
	comparisons = 0;
	interchanges = 0;
	cout << "Bubble Sort ->\n";
	cout << "\nActual array is ->\n";
	for (k = 0; k < High; k++)
		cout << List[k] << "\t";
	for (i = 0; i < High - 1; i++)
	{
		for (j = High - 1; j > i; j--)
		{
			comparisons++;
			if (List[j - 1] > List[j])
			{
				interchanges++;
				Interchange(List[j - 1], List[j]);
			}
		}
		cout << "\nList after <" << i + 1 << "> iteration ->\n";
		for (k = 0; k < High; k++)
			cout << List[k] << "\t";
		cout << endl;
		system("PAUSE");
	}
	cout << "\nTotal comparisons <" << comparisons << "> Total Interchanges <" << interchanges << ">\n";
}

void Sorting::SelectionSort()
{
	int i, j, k, min, comparisons, interchanges;
	CopyList();
	comparisons = 0;
	interchanges = 0;
	cout << "Selection Sort ->\n";
	cout << "\nActual array is ->\n";
	for (k = 0; k < High; k++)
		cout << List[k] << "\t";

	for (i = 0; i < High - 1; i++)
	{
		min = i;
		for (j = High - 1; j > i; j--)
		{
			comparisons++;
			if (List[j] < List[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			interchanges++;
			Interchange(List[i], List[min]);
		}
		cout << "\nList after <" << i + 1 << "> iteration ->\n";
		for (k = 0; k < High; k++)
			cout << List[k] << "\t";
		cout << endl;
		system("PAUSE");
	}

	cout << "\nTotal comparisons <" << comparisons << "> Total Interchanges <" << interchanges << ">\n";
}

void Sorting::InsertionSort()
{
	int i, j, t, loc, min, comparisons, interchanges;
	CopyList();
	comparisons = 0;
	interchanges = 0;
	cout << "Insertion Sort ->\n";
	cout << "\nActual array is ->\n";
	for (i = 0; i < High; i++)
		cout << List[i] << "\t";

	for (i = 1; i < High; i++)
	{
		if (List[i] < List[i - 1])
		{
			interchanges++;
			t = List[i];
			loc = i;
			do
			{
				List[loc] = List[loc - 1];
				loc--;
			} while (loc > 0 && List[loc - 1] > t);
			List[loc] = t;
		}
		cout << "\nList after <" << i << "> iteration ->\n";
		for (j = 0; j < High; j++)
			cout << List[j] << "\t";
		cout << endl;
		system("PAUSE");
	}
	cout << "\nTotal comparisons <" << comparisons << "> Total Interchanges <" << interchanges << ">\n";
}

void Sorting::Interchange(int &x, int &y)
{
	int t = x;
	x = y;
	y = t;
}

void Sorting::RadixSort()
{
	int Buckets[10][10], BCount[10];
	int i, j, k, c, index, largest, dcount = 0, x, pcount, pass;
	// Buckets = new int[10*sizeof(int)];
	// Get the largest no
	CopyList();
	cout << "Radix Sort ->\n";
	cout << "\nActual array is ->\n";
	for (k = 0; k < High; k++)
		cout << List[k] << "\t";

	largest = List[0];
	for (i = 1; i < High; i++)
		if (List[i] > largest)
			largest = List[i];

	// Count digits of the largest number
	while (largest > 0)
	{
		dcount++;
		largest /= 10;
	}

	for (pass = 0; pass < dcount; pass++)
	{
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				Buckets[i][j] = 0;
		for (i = 0; i < 10; i++)
			BCount[i] = 0;
		for (i = 0; i < High; i++)
		{
			x = List[i];
			pcount = 0;
			while (pcount < pass)
			{
				x /= 10;
				pcount++;
			}
			c = x % 10;
			Buckets[BCount[c]][c] = List[i];
			BCount[c]++;
		}
		cout << "\nContents of bucket in pass <" << pass + 1 << ">\n";
		for (i = 0; i < 10; i++)
			cout << BCount[i] << "\t";
		cout << endl
			 << endl;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				cout << Buckets[i][j] << "\t";
			}
			cout << endl;
		}
		index = 0;
		for (i = 0; i < 10; i++)
			for (j = 0; j < BCount[i]; j++)
			{
				int ttt = Buckets[j][i];
				List[index++] = ttt;
			}
		cout << "List after <" << pass + 1 << "> pass ->\n";
		for (k = 0; k < High; k++)
			cout << List[k] << "\t";
		if (pass < dcount - 1)
		{
			cout << endl;
			system("PAUSE");
			system("cls");
		}
	}
}

void Sorting::RadixSortForWords()
{
	char Buckets[26][14][10];
	int BCount[26];
	int i, j, k, c, index, largest, passes = 0, x, pcount, pass;
	char WordsList[14][10] = {"A", "Very", "Simple", "Word", "Sorting", "Algorithm", "Based", "On", "Radix", "Sort", "try", "and", "Enjoy", "it"};
	CopyList();
	int WordsCount = 14;
	cout << "Radix Sort ->\n";
	cout << "\nActual array is ->\n";
	for (k = 0; k < WordsCount; k++)
		cout << WordsList[k] << "\t";

	largest = strlen(WordsList[0]);
	for (i = 1; i < WordsCount; i++)
		if (strlen(WordsList[i]) > largest)
			largest = strlen(WordsList[i]);

	passes = largest;

	for (pass = 0; pass < passes; pass++)
	{
		for (i = 0; i < 26; i++)
			for (j = 0; j < 14; j++)
				Buckets[i][j][0] = NULL;
		for (i = 0; i < 26; i++)
			BCount[i] = 0;
		for (i = 0; i < WordsCount; i++)
		{
			if (strlen(WordsList[i]) > passes - pass)
				c = toupper(WordsList[i][passes - pass]) - 'A';
			else
				c = 0;
			strcpy_s(Buckets[BCount[c]][c], WordsList[i]);
			BCount[c]++;
		}
		cout << "\nContents of bucket in pass <" << pass + 1 << ">\n";
		for (i = 0; i < 26; i++)
			cout << BCount[i] << "\t";
		cout << endl
			 << endl;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				cout << Buckets[i][j] << "\t";
			}
			cout << endl;
		}
		index = 0;
		for (i = 0; i < 10; i++)
			for (j = 0; j < BCount[i]; j++)
			{
				char *ttt;
				strcpy_s(ttt, strlen(Buckets[j][i]), Buckets[j][i]);
				strcpy_s(WordsList[index++], ttt);
			}
		cout << "List after <" << pass + 1 << "> pass ->\n";
		for (k = 0; k < High; k++)
			cout << List[k] << "\t";
		if (pass < passes - 1)
		{
			cout << endl;
			system("PAUSE");
			system("cls");
		}
	}
}

void Sorting::QuickSort()
{
	CopyList();
	cout << "Quick Sort ->\n";
	cout << "\nActual array is ->\n";
	for (int k = 0; k < High; k++)
		cout << List[k] << "\t";

	QSort(Low, High - 1);
}

void Sorting::QSort(int low, int high)
{
	int p = List[low];
	int tmp;
	int l = low, h = high;
	if (low >= high)
		return;
	while (1)
	{
		if (l >= h)
			break;
		while (p <= List[h])
		{
			h--;
			if (l == h)
				break;
		}
		Interchange(List[l], List[h]);

		while (p > List[l])
			l++;
		Interchange(List[l], List[h]);
	}
	cout << "Pivot element is <" << p << ">\n\nList after partition is ->\n";
	for (int i = 0; i < High; i++)
		cout << List[i] << "\t";
	cout << endl;
	system("PAUSE");

	QSort(low, l - 1);
	QSort(h + 1, high);
}

void Sorting::MergeSort()
{
	CopyList();
	cout << "Merge Sort ->\n";
	cout << "\nActual array is ->\n";
	for (int k = 0; k < High; k++)
		cout << List[k] << "\t";

	MSort(Low, High - 1);
}

void Sorting::MSort(int low, int high)
{
	int mid;
	if (high - low <= 0)
		return;
	mid = low + (high - low) / 2;
	MSort(low, mid);
	MSort(mid + 1, high);
	Merge(low, mid, mid + 1, high);
}

void Sorting::Merge(int low1, int high1, int low2, int high2)
{

	static int x;
	int i, j, t, index;
	i = low1;
	j = high2;
	for (i = low1; i <= high1; i++)
	{
		for (j = high2; j >= low2; j--)
		{
			if (List[i] > List[j])
			{
				Interchange(List[i], List[j]);
				/*t = List[i];
				List[i] = List[j];
				List[j] = t;*/
			}
		}
	}
	cout << endl
		 << endl
		 << "List after " << x++ << "th merger" << endl;
	for (i = low1; i <= high2; i++)
		cout << List[i] << "\t";
	cout << endl;
	system("PAUSE");
}

void Sorting::ShellSort()
{
	int i, j, k, increment, temp, comparisons, interchanges;
	CopyList();
	comparisons = 0;
	interchanges = 0;
	cout << "Shell Sort ->\n";
	cout << "\nActual array is ->\n";
	for (k = 0; k < High; k++)
		cout << List[k] << "\t";
	increment = 3;
	while (increment > 0)
	{
		for (i = 0; i < High; i++)
		{
			j = i;
			temp = List[i];
			while ((j >= increment) && (List[j - increment] > temp))
			{
				interchanges++;
				List[j] = List[j - increment];
				j = j - increment;
			}
			List[j] = temp;
			cout << "\nList after <" << i + 1 << "> iteration -> of increment value <" << increment << ">\n";
			for (k = 0; k < High; k++)
				cout << List[k] << "\t";
			cout << endl;
			system("PAUSE");
		}
		system("PAUSE");
		if (increment > 1)
			system("cls");
		if (increment / 2 != 0)
			increment = increment / 2;
		else if (increment == 1)
			increment = 0;
		else
			increment = 1;
	}
	cout << "\nTotal comparisons <" << comparisons << "> Total Interchanges <" << interchanges << ">\n";
}

void Sorting::SiftDown(int start, int end)
{
	int root = start;
	while (root * 2 + 1 <= end)
	{
		int child = root * 2 + 1;
		if (child + 1 <= end && List[child] < List[child + 1])
			child = child + 1;
		if (List[root] < List[child])
		{
			Interchange(List[root], List[child]);
			root = child;
		}
		else
			return;
	}
}

void Sorting::Heapify()
{
	int start = (High - 2) / 2;
	while (start >= 0)
	{
		SiftDown(start, High - 1);
		start--;
	}
}

void Sorting::HeapSort()
{
	int k, end = High - 1;
	CopyList();
	cout << "Heap Sort ->\n";
	cout << "\nActual array is ->\n";
	for (k = 0; k < High; k++)
		cout << List[k] << "\t";

	Heapify();
	cout << "\nAfter creating heap the array is ->\n";
	for (k = 0; k < High; k++)
		cout << List[k] << "\t";

	int count = 0;
	while (end >= 0)
	{
		count++;
		//		cout << List[0] << "\t";
		Interchange(List[end], List[0]);
		end--;
		SiftDown(0, end);
		cout << "\nAfter <" << count << "> iteration array is ->\n";
		for (k = 0; k < High; k++)
			cout << List[k] << "\t";
		cout << endl;
		system("PAUSE");
	}
}

void Sorting::CombSort()
{
	int i, j, k, min, comparisons, interchanges;
	CopyList();
	int Swap;
	comparisons = 0;
	interchanges = 0;
	cout << "Comb Sort ->\n";
	cout << "\nActual array is ->\n";
	for (k = 0; k < High; k++)
		cout << List[k] << "\t";

	int Gap = High;
	bool Swapped = false;
	int iterations = 0;

	while (Gap > 1 || Swapped)
	{
		if (Gap > 1)
		{
			Gap = (size_t)((double)Gap / 1.247330950103979);
		}

		iterations++;
		Swapped = false;

		for (i = 0; Gap + i < High; ++i)
		{
			comparisons++;
			if (List[i] - List[i + Gap] > 0)
			{
				interchanges++;
				Swap = List[i];
				List[i] = List[i + Gap];
				List[i + Gap] = Swap;
				Swapped = true;
			}
		}
		cout << "\nList after <" << iterations << "> iteration ->\n";
		for (k = 0; k < High; k++)
			cout << List[k] << "\t";
		cout << endl
			 << "Gap is " << Gap << endl;
		system("PAUSE");
	}

	cout << "\nTotal comparisons <" << comparisons << "> Total Interchanges <" << interchanges << ">\n";
}

int main()
{
	system("cls");
	Sorting s(10);
	s.InitList();

	s.BubbleSort();
	system("PAUSE");

	system("cls");
	s.SelectionSort();
	system("PAUSE");

	system("cls");
	s.InsertionSort();
	system("PAUSE");

	system("cls");
	s.RadixSort();
	system("PAUSE");

	system("cls");
	s.QuickSort();
	system("PAUSE");

	system("cls");
	s.MergeSort();
	system("PAUSE");

	system("cls");
	s.ShellSort();
	system("PAUSE");

	system("cls");
	s.HeapSort();
	system("PAUSE");

	system("cls");
	s.CombSort();
	system("PAUSE");

	system("cls");
	s.RadixSortForWords();
	system("PAUSE");

	return 0;
}
