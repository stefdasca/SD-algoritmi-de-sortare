// sortare folosind metoda quicksort, pivotul este ales random

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

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	vector<int> sorted = quicksort(v);
	
	
	for(int i = 0; i < n; ++i)
		cout << sorted[i] << " ";
	return 0;
}
