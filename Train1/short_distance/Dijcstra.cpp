#define FILE2 "dijkstra"

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

long long Dijcstra(int n, int s, int end){
    vector<long long> distances;
    distances.assign(n, INT64_MAX);
    distances[s] = 0;

    priority_queue<pair<long long, int>> q;
    q.emplace(0, s);
    while (!q.empty()){
        int v = q.top().second;
        long long cur_distance = -q.top().first;
        q.pop();
        if (cur_distance > distances[v])
            continue;
        for (auto edge: graph[v]){
            int to = edge.first;
            if (distances[v] + edge.second < distances[to]){
                distances[to] = distances[v] + edge.second;
                q.emplace(-distances[to], to);
            }
        }
    }

    return distances[end];
}

void task() {
    int n, s, f;
    cin >> n >> s >> f;

    graph.resize(n);
    int to;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin >> to;
            if (to != -1 && i != j){
                graph[i].emplace_back(j, to);
            }
        }
    }

    long long distance = Dijcstra(n, s-1, f-1);
    cout << ((distance == INT64_MAX)? -1: distance) << endl;
}