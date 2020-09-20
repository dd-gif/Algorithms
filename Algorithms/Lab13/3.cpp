#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    string s;
    cin >> s;
    int prefix[s.length()];
    prefix[0] = 0;
    for (int i = 1; i < s.length(); i++){
        int k = prefix[i - 1];
        while (k > 0 && s[i] != s[k])
            k = prefix[k - 1];
        if (s[i] == s[k])
            k++;
        prefix[i] = k;
    }
    for (int i = 0; i < s.length(); i++)
        cout << prefix[i] << " ";
}
