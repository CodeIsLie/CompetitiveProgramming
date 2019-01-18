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
vector<map<int, long long>> paths;

void DFS(int v){
    used[v] = 1;

    for (auto edge: graph[v]){
        int to = edge.first;
        long long weight = edge.second;
        if (!used[to]){
            DFS(to);

            long long path_len = (paths[to].empty()) ?
                                 fuels[to] :
                                 max_element(paths[to].begin(), paths[to].end(),
                                             [](const pair<int, long long> p1, const pair<int, long long> p2){
                                                 return p1.second < p2.second;
                                             })->second;
            if (path_len + weight > 0){
                paths[v][to] = fuels[v] + weight + path_len;
            }
        }
    }
}

long long find_max_path(int n){
    long long max_path = fuels[0];
    // find 2 maximal paths

    for (int i = 0; i < n; ++i){
        vector<long long> path_lens;
        for (auto &e: paths[i]){
            path_lens.push_back(e.second);
        }
        sort(path_lens.rbegin(), path_lens.rend());
        long long current_path = 0;
        if (path_lens.empty()){
            current_path = fuels[i];
        }
        else if (path_lens.size() < 2){
            current_path = path_lens[0];
        }else{
            current_path = -fuels[i] + path_lens[0] + path_lens[1];
        }
        max_path = max(max_path, current_path);

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

    graph.resize(n);
    int u, v, c;
    for (int i = 0; i < n-1; ++i){
        cin >> u >> v >> c;
        graph[u-1].emplace_back(v-1, -c);
        graph[v-1].emplace_back(u-1, -c);
    }

    paths.resize(n);
    used.assign(n, 0);
    DFS(0);

    cout << find_max_path(n) << endl;
}