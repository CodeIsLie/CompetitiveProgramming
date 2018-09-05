//
// Created by Ilya on 05.09.2018.
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fire_stations;
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

void dfs_fire(int v, vector<vector<int>> & graph){
    used[v] = 1;
    for (int to: graph[v]){
        if (!used[to]){
            dfs_fire(to, graph);
        }
    }
}

void find_firestations(vector<vector<int>> & graph){
    for (int i: order){
        if (!used[i]) {
            fire_stations.push_back(i);
            dfs_fire(i, graph);
        }
    }
}


void firesafe(){
    freopen("firesafe.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    used.assign(n+1, 0);
    vector<vector<int>> rev_graph(n+1);

    int v, to;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &v, &to);
        rev_graph[to].push_back(v);
    }

    topological_sort(n, rev_graph);

    used.assign(n+1, 0);
    find_firestations(rev_graph);

    freopen("firesafe.out", "w", stdout);
    printf("%d \n", fire_stations.size());
    for (int s: fire_stations){
        printf("%d ", s);
    }
}

int main(){
    firesafe();
    return 0;
}