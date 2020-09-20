#include <bits/stdc++.h>
using namespace std;
string split(string t, int i, int n){
    string s;
    for (int j = i; j < n + i; j++)
        s += t[j];
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("search1.in", "r", stdin);
    freopen("search1.out", "w", stdout);
    vector<int> pos;
    string p, t;
    cin >> p >> t;
    int n = p.length(), m = t.length();
    for (int i = 0; i <= m - n; i++){
        if (split(t, i, n) == p)
            pos.push_back(i + 1);
    }
    cout << pos.size() << "\n";
    for (int i = 0; i < pos.size(); i++)
        cout << pos[i] << " ";
}
