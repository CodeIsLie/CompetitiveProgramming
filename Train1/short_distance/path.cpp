//#define FILE2 "path_easy"

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

struct Edge{
    int v;
    int to;
    long long weight;
};

vector<Edge> graph;
vector<long long> distances;
const long long ten15 = 1000000000000004;
const long long INF = INT64_MAX-ten15;

void bellmanFord(int n, int s){
    vector<char> used;
    used.assign(n+1, 0);
    distances.assign(n+1, INF);
    distances[s] = 0;
    used[s] = 1;
    for (int i = 0; i < n-1; ++i) {
        //vector<long long> temp_distances = distances;
        for (auto edge: graph) {
            if (used[edge.v] && distances[edge.to] - edge.weight > distances[edge.v]) {
                distances[edge.to] = distances[edge.v] + edge.weight;
                used[edge.to] = 1;
            }
        }
        //copy(temp_distances.begin(), temp_distances.end(), distances.begin());
    }

    vector<long long> newDistances = distances;
    for (int i = 0; i < n; ++i) {
        //vector<long long> temp_distances = newDistances;
        for (auto edge: graph) {
            if (used[edge.v] && newDistances[edge.to] - edge.weight > newDistances[edge.v]) {
                newDistances[edge.to] = newDistances[edge.v] + edge.weight;
            }
        }
        //newDistances = temp_distances;
    }

    for (int i = 0; i < n+1; ++i){
        if (newDistances[i] < distances[i]){
            distances[i] = INT64_MIN;
        }
    }
}

void task() {
    int n, m, s;
    cin >> n >> m >> s;

    int v, to;
    long long weight;
    for (int i = 0; i < m; ++i){
        cin >> v >> to >> weight;
        graph.push_back({v, to, weight});
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