#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int time_counter;
vector<int> time_in;
vector<int> time_out;
vector<char> used;

void dfs(int v, vector<vector<int>>& graph)
{
    used[v] = 1;
    time_in[v] = time_counter++;

    for(int to: graph[v])
    {
        if (!used[to])
            dfs(to, graph);
    }

    time_out[v] = time_counter++;
}

bool isAncestor(int a, int b){
    return (time_in[a] < time_in[b]) && (time_out[b] < time_out[a]);
}

void ancestor(){
    freopen("ancestor.in", "r", stdin);
    int n, m;
    scanf("%d", &n);

    vector<vector<int>> graph(n+1);
    used.assign(n+1, 0);
    time_in.assign(n+1, 0);
    time_out.assign(n+1, 0);

    int parent;
    int root = 1;
    for (int i = 1; i < n+1; ++i){
        scanf("%d", &parent);
        if (parent == 0)
            root = i;
        else
            graph[parent].push_back(i);
    }
    dfs(root, graph);

    scanf("%d", &m);
    vector<int> answers(m, 0);
    int a, b;
    for (int i = 0; i < m; ++i){
        scanf("%d%d", &a, &b);
        answers[i] = int(isAncestor(a, b));
    }

    freopen("ancestor.out", "w", stdout);
    for (int a: answers){
        printf("%d ", a);
    }
}

int main(){
    time_counter = 0;
    ancestor();
    return 0;
}