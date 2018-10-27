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

vector<vector<int>> fst_labirint;
vector<vector<int>> snd_labirint;
int n;

struct Vertex{
    int r1, c1;
    int r2, c2;
};

vector<Vertex> get_possible_moves(Vertex v){
    vector<Vertex> possible_moves;
    int r1, c1, r2, c2;
    int shift;
    // left move
    r1 = v.r1;
    if (v.c1 > 0){
        // если клетка свободна, то там 0 и мы двигаемся, если 1 , то не двигаемся
        shift = 1 - fst_labirint[v.r1][v.c1-1];
        c1 = v.c1 - shift;
    }else{
        c1 = 0;
    }
    r2 = v.r2;
    if (v.c2 > 0){
        shift = 1 - snd_labirint[v.r2][v.c2-1];
        c2 = v.c2 - shift;
    }
    else{
        c2 = 0;
    }
    possible_moves.push_back({r1, c1, r2, c2});

    // right move
    r1 = v.r1;
    if (v.c1 < n-1){
        // если клетка свободна, то там 0 и мы двигаемся, если 1 , то не двигаемся
        shift = 1-fst_labirint[v.r1][v.c1+1];
        c1 = v.c1 + shift;
    }else{
        c1 = n-1;
    }
    r2 = v.r2;
    if (v.c2 < n-1){
        shift = 1-snd_labirint[v.r2][v.c2+1];
        c2 = v.c2 + shift;
    }
    else{
        c2 = n-1;
    }
    possible_moves.push_back({r1, c1, r2, c2});

    // down move
    c1 = v.c1;
    if (v.r1 > 0){
        shift = 1 - fst_labirint[v.r1-1][v.c1];
        r1 = v.r1 - shift;
    }else{
        r1 = 0;
    }
    c2 = v.c2;
    if (v.r2 > 0){
        shift = 1 - snd_labirint[v.r2-1][v.c2];
        r2 = v.r2 - shift;
    }else{
        r2 = 0;
    }
    possible_moves.push_back({r1, c1, r2, c2});

    //top move
    c1 = v.c1;
    if (v.r1 < n-1){
        shift = 1 - fst_labirint[v.r1+1][v.c1];
        r1 = v.r1 + shift;
    }else{
        r1 = n-1;
    }
    c2 = v.c2;
    if (v.r2 < n-1){
        shift = 1 - snd_labirint[v.r2+1][v.c2];
        r2 = v.r2 + shift;
    }else{
        r2 = n-1;
    }
    possible_moves.push_back({r1, c1, r2, c2});

    return move(possible_moves);
}

inline
int to_code(Vertex v){
    int code = (v.r1*n + v.c1)*n*n + v.r2*n + v.c2;
    return code;
}

int BFS( Vertex start){
    int n2 = n*n;
    vector<char> used;
    vector<int> distances;
    used.assign(n2*n2, 0);
    distances.assign(n2*n2, 0);

    queue<Vertex> q;
    q.push(start);
    used[to_code(start)] = 1;
    distances[to_code(start)] = 0;
    Vertex v;
    while (!q.empty()){
        v = q.front();
        q.pop();
        int v_code = to_code(v);
        if (v_code == 0){
            break;
        }

        vector<Vertex> possible_moves = get_possible_moves(v);
        for (auto& move: possible_moves){
            int code = to_code(move);
            if (!used[code]){
                used[code] = 1;
                distances[code] = distances[v_code] + 1;
                q.push(move);
            }
        }
    }

    return distances[0];
}

void task() {
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    fst_labirint.resize(n);
    for (int i = 0; i < n; ++i){
        fst_labirint[i].resize(n);
        for (int j = 0; j < n; ++j){
            cin >> fst_labirint[i][j];
        }
    }

    snd_labirint.resize(n);
    for (int i = 0; i < n; ++i){
        snd_labirint[i].resize(n);
        for (int j = 0; j < n; ++j){
            cin >> snd_labirint[i][j];
        }
    }
    Vertex start = {r1, c1, r2, c2};

    cout <<  BFS(start);
}