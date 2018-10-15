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
#include <queue>

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

struct Edge{
    int to;
    int ind;
    int type;
};

void task() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<vector<Edge>> graph;
    graph.resize(n);
    map<int, char> orientation;
    int t, u ,v;
    for (int i = 0; i < m; ++i){
        cin >> t >> u >> v;
        if ( t == 1 ){
            graph[u].push_back({v, i, 1});
        }else{
            orientation[i] = 0;
            graph[u].push_back({v, i, 2});
            graph[v].push_back({u, i, 2});
        }
    }
}