#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<class Iter1, class Iter2>
Iter2 copyElements(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while (f1 != e1)
	{
		*f2++ = *f1++;
	}
	return f2;
}

int main()
{
	int array1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list<int> l1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int array2[10] = {};
	memcpy(array2, array1, 10 * sizeof(int));
	vector<int> v2 = v1;
	list<int> l2 = l1;

	for (int i = 0; i < 10; i++)
	{
		array2[i] += 2;
	}

	for (int i = 0; i < 10; i++)
	{
		v2[i] += 3;
	}

	list<int>::iterator iteratorList = l2.begin();
	while (iteratorList != l2.end())
	{
		*iteratorList += 5;
		iteratorList++;
	}

	auto il1 = l2.begin();
	il1++;
	auto il2 = l2.end();
	il2--;
	auto iv1 = v2.begin();

	iv1 = copyElements(il1, il2, iv1);

	auto ia1 = begin(array2);

	ia1 = copyElements(begin(v2), iv1, ia1);

	auto ivf1 = find(begin(v1), end(v1), 27);

	if (ivf1 == end(v1))
	{
		cout << "Nie znaleziono\n";
	}

	/*
	auto ivtest1 = end(v1);
	ivtest1++;
	if (ivtest1 == end(v1))
	{
		cout << "Sa na tym samym miejscu";
	}
	*/
	
	return 0;
}