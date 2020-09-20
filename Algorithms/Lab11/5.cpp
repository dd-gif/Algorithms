#include <bits/stdc++.h>
using namespace std;
struct graph{
    int first, second, weight;
};
int main(){
    ios_base::sync_with_stdio(false);
    freopen("negcycle.in", "r", stdin);
    freopen("negcycle.out", "w", stdout);
    int n, m = 0, x;
    cin >> n;
    vector<graph> g;
	vector<int> p (n, -1), ans, d (n, 1);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> x;
            if (x != 1000000000)
                g.push_back({i, j, x});
        }
    }
    d[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < g.size(); j++){
            if (d[g[j].second] > d[g[j].first] + g[j].weight){
                d[g[j].second] = d[g[j].first] + g[j].weight;
                p[g[j].second] = g[j].first;
            }
        }
    }
    for (int i = 0; i < g.size(); i++){
    	if (d[g[i].second] > d[g[i].first] + g[i].weight){
    	    int y = g[i].first;
    		for (int i = 0; i < n; i++)
    		    y = p[y];
    		for (int i = y; ; i = p[i]){
    		    ans.push_back (i);
    		    if (i == y && ans.size() > 1) break;
    		}
    		break;    
    	}
    }
    if (ans.size() == 0){
        cout << "NO";
        return 0;
    }
    cout << "YES\n" << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    	cout << ans[i] + 1 << " ";
}
