//
// Created by Ilya on 06.09.2018.
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> order;
vector<int> used;

void dfs(int v, vector<vector<int>> & graph){
    used[v] = 1;
    for (int to: graph[v]){
        if (!used[to]) {
            dfs(to, graph);
        }
    }
    order.push_back(v);
}

void topological_sort(int n, vector<vector<int>> & graph){
    for (int i = 1; i <= n; ++i){
        if (!used[i]) {
            dfs(i, graph);
        }
    }
    reverse(order.begin(), order.end());
}

void longPath(){
    freopen("longpath.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    used.assign(n+1, 0);
    vector<int> pathLengths(n+1, 0);
    vector<vector<int>> graph(n+1);

    int v, to;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &v, &to);
        graph[v].push_back(to);
    }

    topological_sort(n, graph);

    for (int v: order)
    {
        for (int to: graph[v]){
            pathLengths[to] = max(pathLengths[to], pathLengths[v] + 1);
        }
    }

    freopen("longpath.out", "w", stdout);
    printf("%d ", pathLengths[n]);
}

int main(){
    longPath();
    return 0;
}