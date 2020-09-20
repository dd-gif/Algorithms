#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("search2.in", "r", stdin);
    freopen("search2.out", "w", stdout);
    string p, t, s;
    cin >> p >> t;
    s = p + "#" + t;
    int pl = p.length(), tl = t.length();
    vector<int> answer; int ans = 0;
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
    for (int i = 0; i < tl; i++){
        if (prefix[pl + i + 1] == pl){
            answer.push_back(i - pl + 2);
            ans++;
        }
    }
    cout << ans << "\n";
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
}
