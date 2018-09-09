//
// Created by Ilya on 06.09.2018.
//
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void peacefulsets(){
    int n;
    scanf("%d", &n);
    vector<vector<int>> weights(n, vector<int>(n, 0));


    for (int i = n-2; i >= 0; --i){
        for (int j = 0; j < i+1; ++j){
            weights[i][j] += max(weights[i+1][j], weights[i+1][j+1]);
        }
    }

    printf("%d ", weights[0][0]);
}

int main(){
    peacefulsets();
    return 0;
}