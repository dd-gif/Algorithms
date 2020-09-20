#include <iostream>

using namespace std;

int main ()
{
	freopen ("sortland.in", "r", stdin);
	freopen ("sortland.out", "w", stdout);
	int n, ib=0, ic=0, id=0;
	double a[10000], key, b, c, d, w[10000];
	cin >> n;
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
		w[i] = a[i];
		
	}
	for ( int i = 1; i < n; i++ )
	{
		for ( int j = 1; j < n; j++ )
		{
			if ( a[j] > a[j+1] )
			{
				key = a[j];
				a[j] = a[j+1];
				a[j+1] = key;
			}
		}
	}
	b = a[1];
	c = a[( n + 1 ) / 2];
	d = a[n]; 	
	for ( int i = 1; i <= n; i++ )
	{
		if ( w[i] == b )
			ib = i;
		if ( w[i] == c )
			ic = i;
		if ( w[i] == d )
			id = i;
	} 
	cout << ib << " " << ic << " " << id;
}
