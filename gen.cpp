// generatorul de teste, creat prin platforma Polygon (http://polygon.codeforces.com/)

#include "testlib.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int max_value = atoi(argv[2]);
    int testtype = atoi(argv[3]); 
    cout << n << endl;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
		  v[i] = rnd.next(0, max_value);
	
	if(testtype == 1) // sorted array
		sort(v.begin(), v.end());
	
	if(testtype == 2) // reversed array
		sort(v.begin(), v.end(), greater<int>());
	
	for(int i = 0; i < n; ++i)
	{
		cout << v[i];
		if(i + 1 != n)
		    cout << " ";
	}
	cout << endl;
}
