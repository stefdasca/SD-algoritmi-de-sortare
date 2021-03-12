#include<bits/stdc++.h>
using namespace std;

vector<int> quicksort(vector<int> v)
{
	if(v.size() == 0)
		return v;
	long long pivot = 1LL * rand() * rand();
	pivot %= (v.size());
	vector<int> greater, smaller, a, b;
	int same_value = 0;
	for(int i = 0; i < v.size(); ++i)
		if(v[i] < v[pivot])
			smaller.push_back(v[i]);
		else
			if(v[i] == v[pivot])
				++same_value;
			else
				greater.push_back(v[i]);
	if(same_value == v.size())
		return v;
	a = quicksort(greater);
	b = quicksort(smaller);
	vector<int> answer;
	for(int i = 0; i < b.size(); ++i)
		answer.push_back(b[i]);
	for(int i = 1; i <= same_value; ++i)
		answer.push_back(v[pivot]);
	for(int i = 0; i < a.size(); ++i)
		answer.push_back(a[i]);
	return answer;
}

void mergesort(int L, int R, vector<int> &v)
{
	if(L == R)
		return;
	int mid = (L + R) / 2;
	mergesort(L, mid, v);
	mergesort(mid+1, R, v);
	
	vector<int> v2;
	int x = L, y = mid+1;
	while(x <= mid && y <= R)
		if(v[x] <= v[y])
			v2.push_back(v[x]), ++x;
		else
			v2.push_back(v[y]), ++y;
	while(x <= mid)
		v2.push_back(v[x]), ++x;
	while(y <= R)
		v2.push_back(v[y]), ++y;

	for(int i = 0; i < v2.size(); ++i)
		v[L+i] = v2[i];
}

vector<int> v3;
int poz = 0;
void radix_sort(vector<int> v, int pwr)
{
	if(pwr == 0)
	{
		for(int i = 0; i < v.size(); ++i)
			v3[poz++] = v[i];
		return;
	}
	vector<int> a[10];
	for(int i = 0; i < v.size(); ++i)
	{
		int val = v[i] % pwr;
		if(pwr != 1)
			val /= (pwr/10);
		a[val].push_back(v[i]);
	}
	for(int i = 0; i <= 9; ++i)	
		if(!a[i].empty())
			radix_sort(a[i], pwr/10);
}
int main()
{
	ifstream cin("sortare.in");
	ofstream cout("sortare.out");
	int n;
	cin >> n;
	vector<int> v(n), v2(n);
	
	int max_number = 0;
	for(int i = 0; i < n; ++i)
		cin >> v[i], v2[i] = v[i], max_number = max(max_number, v[i]);
	
	clock_t t, t2;
		
	for(int i = 1; i <= 6; ++i)
	{
		for(int j = 0; j < n; ++j)
			v[j] = v2[j];
		if(i == 1)
		{
			t = clock();
			sort(v.begin(), v.end());
			t2 = clock();
			cout << "Sort " << fixed << setprecision(9) << ((double) t2 - t)/CLOCKS_PER_SEC << '\n';
		}
		if(i == 2)
		{
			t = clock();
			vector<int> sorted = quicksort(v);
			t2 = clock();
			cout << "QuickSort " << fixed << setprecision(9) << ((double) t2 - t)/CLOCKS_PER_SEC << '\n';
		}
		if(i == 3)
		{
			t = clock();
			mergesort(0, n-1, v);
			t2 = clock();
			cout << "MergeSort " << fixed << setprecision(9) << ((double) t2 - t)/CLOCKS_PER_SEC << '\n';
		}
		if(i == 4)
		{
			t = clock();
			if(max_number > 100000000)
				cout << "CountSort nu poate sorta vectorul pentru ca are valori prea mari si are nevoie de prea multa memorie " << '\n'; 
			else
			{
				vector<int> fr(max_number + 1, 0);
				int poz = 0;
				for(int i = 0; i < max_number; ++i)
					for(int j = 1; j <= fr[i]; ++j)
						v[poz++] = i;
				t2 = clock();
				cout << "CountSort " << fixed << setprecision(9) << ((double) t2 - t)/CLOCKS_PER_SEC << '\n';
			}
		}
		if(i == 5)
		{
			t = clock();
			poz = 0;
			v3.resize(n);
			radix_sort(v, 1000000000);
			t2 = clock();
			cout << "RadixSort " << fixed << setprecision(9) << ((double) t2 - t)/CLOCKS_PER_SEC << '\n';
		}
		if(i == 6)
		{
			t = clock();
			bool ok = 1;
			if(n <= 100000)
				while(ok)
				{
					t2 = clock();
					if(((double) t2 - t)/CLOCKS_PER_SEC >= 120.00000000)
						break;
					ok = 0;
					for(int i = 0; i + 1 < n; ++i)
						if(v[i] > v[i+1])
						{
							swap(v[i], v[i+1]);
							ok = 1;
						}
				}
			t2 = clock();
			if(n > 100000 || ((double) t2 - t)/CLOCKS_PER_SEC >= 120.00000000)
				cout << "BubbleSort e prea incet si nu poate sorta vectorul in 120 de secunde" << '\n';
			else
				cout << "BubbleSort " << fixed << setprecision(9) << ((double) t2 - t)/CLOCKS_PER_SEC << '\n';
		}
	}
	return 0;
}

