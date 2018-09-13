//
// Created by Ilya on 13.09.2018.
//
#define FILE1


#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

vector<string> blocks;
vector<vector<int>> noise;
vector<vector<int>> used;

//for different marks in used
int True;

inline
bool isCorrect(int i, int j){
    return blocks[i][j] != '*';
}

inline
vector<pair<int, int>> getNeighbors(int i, int j){
    vector<pair<int, int>> neighbors;
    if (isCorrect(i-1, j)){
        neighbors.emplace_back(i-1, j);
    }
    if (isCorrect(i+1, j)){
        neighbors.emplace_back(i+1, j);
    }
    if (isCorrect(i, j-1)){
        neighbors.emplace_back(i, j-1);
    }
    if (isCorrect(i, j+1)){
        neighbors.emplace_back(i, j+1);
    }
    return move(neighbors);
}

void BFS(int i, int j, int noiseSize){
    queue<pair<pair<int, int>, int>> q;
    q.emplace(make_pair(i, j), noiseSize);
    used[i][j] = True;

    while (!q.empty()){
        auto p = q.front();
        q.pop();
        auto coords = p.first;
        noiseSize = p.second;
        noise[coords.first][coords.second] += noiseSize;

        for (auto pr: getNeighbors(coords.first, coords.second)){
            if (used[pr.first][pr.second] != True && noiseSize/2 > 0) {
                used[pr.first][pr.second] = True;
                q.emplace(pr, noiseSize / 2);
            }
        }
    }
}

void noiseLevel() {
#ifdef FILE1
    freopen("../input.txt", "r", stdin);
#endif

    int n, m, q, p;
    cin >> n >> m >> q >> p;

    string line;
    noise.assign(n+2, vector<int>(m+2, 0));
    used.assign(n+2, vector<int>(m+2, 0));

    blocks.push_back(string(m+2, '*'));
    for (int i = 0; i < n; ++i) {
        cin >> line;
        blocks.push_back("*" + line + "*");
    }
    blocks.push_back(string(m+2, '*'));

    True = 0;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < m+1; ++j) {
            if (blocks[i][j] != '*' && blocks[i][j] != '.'){
                int noiseSize = (blocks[i][j] - 'A' + 1) * q;
                True++;
                BFS(i, j, noiseSize);
            }
        }
    }

    int cntBlocks = 0;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < m+1; ++j) {
            if (noise[i][j] > p)
                cntBlocks ++;
        }
    }

    cout << cntBlocks;
}

int main(){
    noiseLevel();
    return 0;
}
