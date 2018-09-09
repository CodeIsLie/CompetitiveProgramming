//
// Created by Ilya on 06.09.2018.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;


void ladder(){
    freopen("lepus.in", "r", stdin);
    int n;
    scanf("%d\n", &n);
    vector<int> weights(n);
    vector<int> sums(n);

    char c;
    for (int i = 0; i < n; ++i){
        scanf("%c", &c);
        if (c == '"'){
            weights[i] = 1;
        } else if (c == '.'){
            weights[i] = 0;
        }else if (c == 'w'){
            weights[i] = -1000;
        }
    }

    sums[0] = weights[0];
    for (int i = 1; i < n; ++i){
        sums[i] = sums[i-1] + weights[i];
        if (i >= 3){
            sums[i] = max(sums[i], sums[i-3] + weights[i]);
        }
        if (i >= 5){
            sums[i] = max(sums[i], sums[i-5] + weights[i]);
        }
    }

    int maxScore = sums[n-1];
    if (maxScore < 0)
        maxScore = -1;


    freopen("lepus.out", "w", stdout);
    printf("%d ", maxScore);
}

int main(){
    ladder();
    return 0;
}