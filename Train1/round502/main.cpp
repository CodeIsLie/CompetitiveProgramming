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
    int to;
    int ind;
    int type;
    int start;
};


vector<vector<Edge>> graph;
vector<char> used;
map<int, char> orientation;

int minCntVertices = 0;
int maxCntVertices = 0;

void minDFS(int v){
    used[v] = 1;
    minCntVertices++;
    for (auto edge: graph[v]){
        if (edge.type == 1 ){
            if (!used[edge.to])
                minDFS(edge.to);
        }else{
            if (orientation[edge.ind] == 0){
                if (edge.start == edge.to){
                    orientation[edge.ind] = '+';
                }
                else{
                    orientation[edge.ind] = '-';
                }
            }
        }
    }
}

void maxDFS(int v){
    used[v] = 1;
    maxCntVertices++;
    for (auto edge: graph[v]){
        if (edge.type == 1 ){
            if (!used[edge.to])
                maxDFS(edge.to);
        }else{
            if (orientation[edge.ind] == 0){
                if (edge.start == edge.to){
                    orientation[edge.ind] = '-';
                }
                else{
                    orientation[edge.ind] = '+';
                }
                if (!used[edge.to])
                    maxDFS(edge.to);
            }
        }
    }
}

void task() {
    int n, m, s;
    cin >> n >> m >> s;

    graph.resize(n+1);
    used.assign(n+1, 0);
    int t, u ,v;
    for (int i = 0; i < m; ++i){
        cin >> t >> u >> v;
        if ( t == 1 ){
            graph[u].push_back({v, i, 1, u});
        }else{
            orientation[i] = 0;
            graph[u].push_back({v, i, 2, u});
            graph[v].push_back({u, i, 2, u});
        }
    }
    maxDFS(s);
    for (auto& edge: orientation){
        if (edge.second == 0){
            edge.second = '+';
        }
    }

    used.assign(n+1, 0);
    string orient = "";
    for (auto it = orientation.begin(); it != orientation.end(); ++it){
        orient += string(1, it->second);
        it -> second = 0;
    }

    cout << maxCntVertices << endl;
    cout << orient << endl;

    minDFS(s);
    orient = "";

    for (auto& edge: orientation){
        if (edge.second == 0){
            edge.second = '+';
        }
    }

    for (auto it = orientation.begin(); it != orientation.end(); ++it){
        orient += string(1, it->second);
        it -> second = 0;
    }

    cout << minCntVertices << endl;
    cout << orient << endl;
}