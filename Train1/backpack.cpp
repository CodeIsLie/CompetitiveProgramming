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
    vector<int> weights(n);
    int w;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w);
        weights[i] = w;
    }

    vector<vector<int> > costs(s+1, vector<int>(n+1, 0));
    // TODO: find costs

    int max = 0;
    for (int i = 1; i <= s; ++i)
        if (costs[s][n] == 1 && s > max)
            max = s;
    printf("%d ", max);
}

int main(){
    knapsack();
    return 0;
}