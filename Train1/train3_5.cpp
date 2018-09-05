//
// Created by Ilya on 05.09.2018.
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void condensation(){
    freopen("firesafe.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    vector<vector<int>> graph(n+1);
    int v, to;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &v, &to);
        graph[v].push_back(to);
        graph[to].push_back(v);
    }

    int cntEdges = 0;
    // 1. inverse
    // 2. topological order
    // 3. dfs from start vertices if not used, create a counter
    // 4. memorise numbers of points

    freopen("firesafe.out", "w", stdin);
    printf("%d ", cntEdges);
}

int main(){
    condensation();
    return 0;
}