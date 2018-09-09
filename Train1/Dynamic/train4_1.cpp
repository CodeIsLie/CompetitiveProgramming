//
// Created by Ilya on 06.09.2018.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


void ladder(){
    freopen("ladder.in", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> weights(n);
    vector<int> sums(n);

    int w;
    for (int i = 0; i < n; ++i){
        scanf("%d", &w);
        weights[i] = w;
    }

    sums[0] = weights[0];
    sums[1] = max(0, weights[0]) + weights[1];
    for (int i = 2; i < n; ++i){
        sums[i] = max(sums[i-2], sums[i-1]) + weights[i];
    }

    int maxSum = sums[n-1];

    freopen("ladder.out", "w", stdout);
    printf("%d ", maxSum);
}

int main(){
    ladder();
    return 0;
}