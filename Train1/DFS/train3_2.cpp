#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int cycle_start, cycle_end;

bool dfs(int v, vector<vector<int>>& graph, vector<char>& used, vector<int>& parents){
    used[v] = 1;
    for (int to: graph[v]){
        if (used[to] == 0){
            parents[to] = v;
            if (dfs(to, graph, used, parents))
                return true;
        } else if (used[to] == 1){
            cycle_end = v;
            cycle_start = to;
            return true;
        }

    }
    used[v] = 2;
    return false;
}

void findCycle() {
    freopen("cycle2.in", "r", stdin);
    int n, m;
    string s;
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>());
    int v, to;
    for (int i = 0; i < m; ++i) {
        cin >> v >> to;
        graph[v].push_back(to);
    }

    bool cycleV = false;
    vector<char> used(n+1, 0);
    vector<int> parents(n+1, 0);
    string answer = "NO";
    for (int v = 1; v < graph.size(); ++v){
        if (!used[v]) {
            cycleV = dfs(v, graph, used, parents);
            if (cycleV) {
                answer = "YES";
                break;
            }
        }
    }

    freopen("cycle2.out", "w", stdout);
    cout << answer << endl;
    if (answer == "YES"){
        vector<int> cycle;
        //cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parents[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);

        for (int i = cycle.size()-1; i>= 0; --i){
            cout << cycle[i] << ' ';
        }
    }
}


int main3_2(){
    findCycle();
    return 0;
}


