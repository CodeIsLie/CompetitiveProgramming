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

vector<vector<pair<int, int>>> graph;
vector<char> used;
vector<int> fuels;
vector<long long> paths;

void DFS(int v){
    used[v] = 1;

    for (auto edge: graph[v]){
        int to = edge.first;
        if (!used[to]){
            DFS(to);
        }
    }

    long long max_path = 0;
    for (auto edge: graph[v]){
        int to = edge.first;
        long long weight = edge.second;
        if (fuels[to] + weight > max_path){
            max_path = fuels[to] + weight;
        }
    }
    paths[v] = fuels[v] + max_path;
}

long long find_max_path(int n){
    long long max_path = fuels[0];
    // find 2 maximal paths
    for (int i = 0; i < n; ++i){

    }
    return max_path;
}

void task(){
    int n;
    cin >> n;
    fuels.resize(n);
    for (auto& f: fuels){
        cin >> f;
    }

    int u, v, c;
    for (int i = 0; i < n; ++i){
        cin >> u >> v >> c;
        graph[u-1].emplace_back(v-1, -c);
        graph[v-1].emplace_back(u-1, -c);
    }

    paths.assign(n, 0);
    used.assign(n, 0);
    DFS(0);
}