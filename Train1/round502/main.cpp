#define FILE2 "path"

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

vector<vector<pair<int, long long>>> graph;
vector<long long> distances;
vector<char> used;
const long long ten15 = 1000000000000004;
const long long ten18 = -2000000000000000004;
const long long INF = INT64_MAX-ten15;
const long long NEG_INF = ten18;

void DFS(int v){
    distances[v] = INT64_MIN;
    used[v] = 1;
    for (auto edge: graph[v]){
        if (!used[edge.first]){
            DFS(edge.first);
        }
    }
}

void bellmanFord(int n, int s){
    used.assign(n+1, 0);
    distances.assign(n+1, INF);
    distances[s] = 0;
    //used[s] = 1;
    for (int i = 0; i < n-1; ++i) {
        for (int v = 1; v < graph.size(); ++v) {
            for (auto edge: graph[v]){
                if (distances[v] < INF)
                    if (distances[edge.first] - edge.second > distances[v]) {
                        distances[edge.first] = max(NEG_INF+100, distances[v] + edge.second);
                    }
            }
        }
    }

    vector<long long> newDistances = distances;
    for (int i = 0; i < n; ++i) {
        for (int v = 1; v < graph.size(); ++v) {
            for (auto edge: graph[v]){
                if (newDistances[v] < INF)
                    if (newDistances[edge.first] - edge.second > newDistances[v]) {
                        newDistances[edge.first] = max(NEG_INF, newDistances[v] + edge.second);
                    }
            }
        }
    }

    used.assign(n+1, 0);
    for (int i = 0; i < n+1; ++i){
        if (newDistances[i] < distances[i]){
            DFS(i);
        }
    }
}

void task() {
    int n, m, s;
    cin >> n >> m >> s;

    int v, to;
    long long weight;
    graph.resize(n+1);
    for (int i = 0; i < m; ++i){
        cin >> v >> to >> weight;
        graph[v].emplace_back(to, weight);
    }

    bellmanFord(n, s);

    for (int i = 1; i < distances.size(); ++i){
        long long w = distances[i];
        if (w == INF){
            cout << "*\n";
        }
        else if (w == INT64_MIN){
            cout << "-\n";
        }else{
            cout << w << endl;
        }
    }
}