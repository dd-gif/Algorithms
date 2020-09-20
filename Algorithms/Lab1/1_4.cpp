#include <iostream>

using namespace std;

int main ()
{
	freopen ("smallsort.in", "r", stdin);
	freopen ("smallsort.out", "w", stdout);
	int n, a[10000], key;
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> a[i];
	for ( int i = 0; i < n-1; i++ )
	{
		for ( int j = 0; j < n-1; j++ )
		{
			if ( a[j] > a[j+1] )
			{
				key = a[j];
				a[j] = a[j+1];
				a[j+1] = key;
			}
		}
	} 
	for ( int i = 0; i < n; i++ )
		cout << a[i] << " ";
}
