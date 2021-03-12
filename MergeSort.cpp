// sortare folosind metoda mergesort

#include<bits/stdc++.h>
using namespace std;

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
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	mergesort(0, n-1, v);
	
	for(int i = 0; i < n; ++i)
		cout << v[i] << " ";
	
	return 0;
}

