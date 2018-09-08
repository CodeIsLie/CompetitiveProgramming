//
// Created by Ilya on 07.09.2018.
//

// #define FILE2 "joseph"

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void knapsack(){
#ifdef FILE2
    freopen(FILE2".in", "r", stdin);
    freopen(FILE2".out", "w", stdout);
#endif

    int s, n;
    scanf("%d%d", &s, &n);
    vector<int> weights(n+1);
    int w;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &w);
        weights[i] = w;
    }

    vector<vector<int> > costs(s+1, vector<int>(n+1, 0));
    for (int i = 0; i <=n; ++i){
        costs[0][i] = 1;
    }
    for (int i = 1; i <= s; ++i){
        for (int j = 1; j <= n; ++j) {
            costs[i][j] = costs[i][j-1];
            if (i-weights[j] >= 0){
                costs[i][j] = max(costs[i-weights[j]][j-1], costs[i][j]);
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= s; ++i)
        if (costs[i][n] == 1 && i > max)
            max = i;
    printf("%d ", max);
}

int main(){
    knapsack();
    return 0;
}