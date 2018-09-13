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
vector<vector<long long>> noise;
vector<vector<int>> used;

//for different marks in used
int True;

void BFS(int i, int j, int noiseSize){
    queue<pair<pair<int, int>, int>> q;
    q.emplace(make_pair(i, j), noiseSize);
    used[i][j] = True;

    while (!q.empty()){
        auto p = q.front();
        q.pop();
        auto coords = p.first;
        i = coords.first;
        j = coords.second;
        noiseSize = p.second;
        noise[coords.first][coords.second] += noiseSize;

        for (pair<int, int> pr: {make_pair(i-1, j), make_pair(i+1, j), make_pair(i, j-1), make_pair(i, j+1)}){
            if (blocks[pr.first][pr.second]!= '*' && used[pr.first][pr.second] != True && noiseSize/2 > 0) {
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
    noise.assign(n+2, vector<long long>(m+2, 0));
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
//    freopen("../input.txt", "w", stdout);
//    for (int i = 0; i < 250; ++i){
//        for (int j = 0; j < 250; ++j){
//            cout << "Z";
//        }
//        cout << endl;
//    }
    return 0;
}
