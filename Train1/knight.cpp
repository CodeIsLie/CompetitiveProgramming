#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


bool inDesk(int x, int y, int n, int m){
    return x < m && x >= 0 && y < n && y >= 0;
}

void knight(){
    freopen("knight.in", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> paths(n, vector<int>(m, 0));

    paths[0][0] = 1;
    for (int i = 1; i < n; ++i){
        for (int j = 1; j < m; ++j){
            int y1 = i-2;
            int x1 = j-1;
            if (inDesk(x1, y1, n, m)){
                paths[i][j] += paths[y1][x1];
            }

            int y2 = i-1;
            int x2 = j-2;
            if (inDesk(x2, y2, n, m)){
                paths[i][j] += paths[y2][x2];
            }
        }
    }

    int cntPaths = paths[n-1][m-1];

    freopen("knight.out", "w", stdout);
    printf("%d ", cntPaths);
}

int main(){
    knight();
    return 0;
}