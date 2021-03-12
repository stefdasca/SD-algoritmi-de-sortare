#include<bits/stdc++.h>
using namespace std;

vector<int> v2;
int poz;

void radix_sort(vector<int> v, int pwr)
{
	if(pwr == 0)
	{
		for(int i = 0; i < v.size(); ++i)
			v2[poz++] = v[i];
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
	int n;
	cin >> n;
	vector<int> v(n);
	
	v2.resize(n);
	
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	radix_sort(v, 1000000000);
			
	for(int i = 0; i < n; ++i)
		cout << v2[i] << " ";
	return 0;
}

