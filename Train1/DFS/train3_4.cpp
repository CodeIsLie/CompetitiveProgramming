#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> graph;
vector<bool> used;
vector<int> tin;
vector<int> fup;
set<int> cutpoints;

int timer;

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    for (size_t i=0; i<graph[v].size(); ++i) {
        int to = graph[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min(fup[v], tin[to]);
        else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1)
                cutpoints.insert(v);
            ++children;
        }
    }
    if (p == -1 && children > 1)
        cutpoints.insert(v);
}

int main() {
    freopen("points.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    graph = vector<vector<int>>(n+1);

    int v, to;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &v, &to);
        graph[v].push_back(to);
        graph[to].push_back(v);
    }

    used.resize(n+1);
    tin.resize(n+1);
    fup.resize(n+1);

    timer = 0;
    for (int i=1; i<=n; ++i)
        used[i] = false;
    for (int i = 1; i <= n; ++i){
        if (!used[i])
            dfs(i);
    }

    freopen("points.out", "w", stdout);
    printf("%d \n", cutpoints.size());
    for (int p: cutpoints)
    {
        printf("%d ", p);
    }

}