//#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <vector>
#include <climits>
#define MAX 5010
#define INF 0x3F3F3F3F3F3F3F3FLL
//#define INF (LLONG_MAX/2)
using namespace std;

int used[MAX];
long long w, d[MAX];

struct node {
	int to;
	long long dist;
	node(int to, long long dist) : to(to), dist(dist) {};
};

vector<vector<node> > graph;

void Bellman_Ford(int &n,int &s) {
	int i, j, k;

	memset(d, 0x3F, sizeof(d));

	d[s] = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (k = 0; k < graph[j].size(); k++) {
				int to = graph[j][k].to;
				long long dist = graph[j][k].dist;
				if ((d[j] < INF) && (d[to] > d[j] + dist))
					d[to] = d[j] + dist;
			}
		}
	}
}

void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < graph[v].size(); i++) {
		int to = graph[v][i].to;
		if (!used[to]) 
			dfs(to);
	}
}

int main() {
	ifstream fin("path.in");
	ofstream fout("path.out");

	int n, m, s;
	fin >> n >> m >> s;
	graph.resize(n + 1);

	for (int i = 1; i <= m; i++) {
		int u, v;
		fin >> u >> v >> w;
		graph[u].push_back(node(v, w));
	}

	Bellman_Ford(n,s);

	memset(used, 0, sizeof(used));

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int to = graph[i][j].to;
			long long dist = graph[i][j].dist;
			if ((d[i] < INF) && (d[to] > d[i] + dist) && !used[to])
				dfs(to);
		}
	}

	for (int i = 1; i <= n; i++)
		if (d[i] == INF)
			fout << "*" << endl;
		else if (used[i] || d[i] < -5e18)
			fout << "-" << endl;
		else
			fout << d[i] << endl;
	return 0;
}
