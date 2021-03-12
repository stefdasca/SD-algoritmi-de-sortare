#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	
	for(int i = 0; i < n; ++i)
		cin >> v[i];
	
	bool ok = 1;
	while(ok)
	{
		ok = 0;
		for(int i = 0; i + 1 < n; ++i)
			if(v[i] > v[i+1])
			{
				swap(v[i], v[i+1]);
				ok = 1;
			}
	}
	
	for(int i = 0; i < n; ++i)
		cout << v[i] << " ";
	return 0;
}
