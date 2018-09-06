//
// Created by Ilya on 05.09.2018.
//
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> order;
vector<int> used;
int component_counter;
set<pair<int, int>> edges;

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

void dfs2 (int v, vector<vector<int>> & graph) {
    used[v] = component_counter;
    for (int to: graph[v])
        if (!used[to])
            dfs2(to, graph);
}

void mark_vertices(vector<vector<int>> & graph){
    for (int v: order){
        component_counter++;
        if (!used[v]){
            dfs2(v, graph);
        }
    }
}

void find_condensation_edges(vector<vector<int>> & graph){
    for (int i = 1; i < graph.size(); ++i){
        for (int to: graph[i]){
            if (used[to] != used[i])
                edges.emplace(used[i], used[to]);
        }
    }
}

void condensation(){
    freopen("condense2.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);

    used.assign(n+1, 0);
    vector<vector<int>> graph(n+1);
    vector<vector<int>> rev_graph(n+1);
    int v, to;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &v, &to);
        graph[v].push_back(to);
        rev_graph[to].push_back(v);
    }

    topological_sort(n, rev_graph);

    used.assign(n+1, 0);
    component_counter = 0;
    mark_vertices(graph);

    find_condensation_edges(graph);
    int cntEdges = edges.size();

    freopen("condense2.out", "w", stdout);
    printf("%d ", cntEdges);
}

int main(){
    condensation();
    return 0;
}