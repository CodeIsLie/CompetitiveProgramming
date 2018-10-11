#define FILE2 "distance"

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
vector<int> p;

long long Dijcstra(int n, int s, int end){
    vector<long long> distances;
    distances.assign(n, INT64_MAX);
    p.assign(n, -1);
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
                p[to] = v;
                q.emplace(-distances[to], to);
            }
        }
    }

    return distances[end];
}

void task() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;

    graph.resize(n);
    int v, to, weight;
    for (int i = 0; i < m; ++i){
        cin >> v >> to >> weight;
        graph[v-1].emplace_back(to-1, weight);
        graph[to-1].emplace_back(v-1, weight);
    }

    long long distance = Dijcstra(n, s-1, f-1);
    cout << ((distance == INT64_MAX)? -1: distance) << endl;
    v = f-1;
    vector<int> path;
    if (distance == INT64_MAX)
        return;
    while (v != s-1){
        path.push_back(v+1);
        v = p[v];
    }

    path.push_back(s);
    for (auto it = path.rbegin(); it != path.rend(); ++it){
        cout << (*it) << ' ';
    }
    cout << endl;
}