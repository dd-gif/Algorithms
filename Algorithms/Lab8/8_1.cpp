#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream fin( "input.txt" );
    ofstream fout( "output.txt" );
    int n, m;
    fin >> n >> m;
    int a, b, matrix[n][n];
    for ( int i = 0; i < n; i++ )
	for ( int j = 0; j < n; j++ )
	    matrix[i][j] = 0;
    for ( int i = 0; i < m; i++ ){
        fin >> a >> b;
        matrix[a - 1][b - 1] = 1;
    }
    for ( int i = 0; i < n; i++ ){
        for ( int j = 0; j < n; j++ ){
            fout << matrix[i][j] << " ";
	}
        fout << "\n";
    }
    return 0;
}