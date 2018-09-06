 #include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<bool> used;
vector<int> tin;
vector<int> fup;
vector<int> bridges;

int timer;

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (size_t i=0; i<graph[v].size(); ++i) {
        int to = graph[v][i].first;
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            //find bridge
            if (fup[to] > tin[v]){
                int number_edge = graph[v][i].second;
                bridges.push_back(number_edge);
            }
        }
    }
}

void find_bridges(int n) {
    timer = 0;
    for (int i=0; i<=n; ++i)
        used[i] = false;
    for (int i=1; i<n+1; ++i)
        if (!used[i])
            dfs (i);
}

void get_bridges(){
    freopen("bridges.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    graph = vector<vector<pair<int, int>>>(n+1);

    int v, to;
    for (int i = 1; i < m+1; ++i){
        scanf("%d%d", &v, &to);
        graph[v].emplace_back(to, i);
        graph[to].emplace_back(v, i);
    }

    used.resize(n+1);
    tin.resize(n+1);
    fup.resize(n+1);
    find_bridges(n);

    freopen("bridges.out", "w", stdout);
    printf("%d ", bridges.size());
    sort(bridges.begin(), bridges.end());
    for (int b: bridges)
        printf("%d ", b);
}

int main(){
    get_bridges();
    return 0;
}