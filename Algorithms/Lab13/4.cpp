#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("prefix.in", "r", stdin);
    //freopen("prefix.out", "w", stdout);
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    int l = s.length();
    vector<int> pi(l);
    pi[0] = 0;
    for (int i = 1; i < l; i++){
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])  
		    j++;
		pi[i] = j;
    }
    vector<vector<int>> aut(l + 1, vector<int>(n));
    for (int i = 0; i < aut.size(); i++){
        int k = 0;
        char c = 'a';
        while (k < n){
            if (i > 0 && c != s[i])
                aut[i][k] = aut[pi[i - 1]][k];
            else if (c == s[i])
                aut[i][k] = i + 1;
            else if (c != s[i])
                aut[i][k] = i;
            k++;
            c++;
        }
    }
    for (int i = 0; i < aut.size(); i++){
        for (int j = 0; j < aut[i].size(); j++)
            cout << aut[i][j] << " ";
        cout << endl;
    }
}
