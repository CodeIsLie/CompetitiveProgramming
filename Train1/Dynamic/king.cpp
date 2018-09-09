//
// Created by Ilya on 06.09.2018.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


bool inDesk(int x, int y, int sizeGrid){
    return x >= 0 && x <= sizeGrid && y >= 0 && y < sizeGrid;
}

void king(){
    freopen("king2.in", "r", stdin);
    int sizeGrid = 8;
    vector<vector<int>> weights(sizeGrid, vector<int>(sizeGrid, 0));
    vector<vector<int>> minCosts(sizeGrid, vector<int>(sizeGrid, INT32_MAX));

    int w;
    for (int i = 0; i < sizeGrid; ++i){
        for (int j = 0; j < sizeGrid; ++j){
            scanf("%d", &w);
            weights[i][j] = w;
        }
    }

    minCosts[sizeGrid-1][0] = 0;
    for (int i = sizeGrid-1; i >= 0; --i){
        for (int j = 0; j < sizeGrid; ++j){
            int x1 = j-1, y1 = i+1;
            int x2 = j-1, y2 = i;
            int x3 = j, y3 = i+1;
            if (inDesk(x1, y1, sizeGrid))
                minCosts[i][j] = min(minCosts[y1][x1], minCosts[i][j]);
            if (inDesk(x2, y2, sizeGrid))
                minCosts[i][j] = min(minCosts[y2][x2], minCosts[i][j]);
            if (inDesk(x3, y3, sizeGrid))
                minCosts[i][j] = min(minCosts[y3][x3], minCosts[i][j]);
            minCosts[i][j] += weights[i][j];
        }
    }

    freopen("king2.out", "w", stdout);
    printf("%d ", minCosts[0][sizeGrid-1]);
}

int main(){
    king();
    return 0;
}