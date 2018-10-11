//#define FILE2 "negcycle"

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
vector<int> parents;
const long long ten15 = 1000000000000004;
const long long INF = INT64_MAX-ten15;

void bellmanFord(int n){
    distances.assign(n, 0);
    parents.assign(n, -1);
    int v_neg;
    for (int i = 0; i < n; ++i) {
        v_neg = -1;
        for (auto edge: graph) {
            //if (distances[edge.v] < INF)
                if (distances[edge.to] > distances[edge.v] + edge.weight) {
                    distances[edge.to] = distances[edge.v] + edge.weight;
                    parents[edge.to] = edge.v;
                    v_neg = edge.to;
                }
        }
    }

    if (v_neg == -1){
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    vector<int> path;
    int v = v_neg;
    for (int i=0; i<n; ++i)
        v = parents[v];

    int start_of_cycle = v;
    v = parents[start_of_cycle];
    while (v != start_of_cycle){
        path.push_back(v);
        v = parents[v];
    }
    path.push_back(start_of_cycle);
    reverse(path.begin(), path.end());

    cout << path.size()<< endl;
    for (int v: path){
        cout << v+1 << " ";
    }
    cout << endl;
}

void task() {
    int n;
    cin >> n;

    int  weight;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j) {
            cin >> weight;
            if (i != j && weight != 100000)
                graph.push_back({i, j, weight});
        }
    }
    bellmanFord(n);
}