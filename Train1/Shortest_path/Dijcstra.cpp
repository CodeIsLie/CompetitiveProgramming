//
// Created by admin on 09.10.2018.
//

// #define FILE2 "dijkstra"

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <ctime>
#include <algorithm>
#include <climits>
#include <list>

using namespace std;

void task();

int main(){
#ifdef TEAM
    freopen("./inp.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
#ifdef FILE2
    freopen(FILE2".in", "r", stdin);
    freopen(FILE2".out", "w", stdout);
#endif
    task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}

void task() {
    int n, s, f;
    cin >> n >> s >> f;

    vector<vector<pair<int, int>>> graph;
    graph.assign(n, vector<pair<int, int>>());

    int weight;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> weight;
            if (weight != -1){
                graph[i].emplace_back(j, weight);
            }
        }
    }


    vector<int> weights (n, INT_MAX);
    /*
     * vector<int> d (n, INF),  p (n);
	d[s] = 0;
	vector<char> u (n);
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		if (d[v] == INF)
			break;
		u[v] = true;

		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
				len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
     */

}
