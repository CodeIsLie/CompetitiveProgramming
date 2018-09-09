//
// Created by Ilya on 07.09.2018.
//
#define FILE2 "joseph"

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void Joseph(){
    #ifdef FILE2
    freopen(FILE2".in", "r", stdin);
    freopen(FILE2".out", "w", stdout);
    #endif

    int n, p;
    cin >> n >> p;

    vector<int> position(n);
    position[0] = 1;
    for (int i = 1; i < n; ++i){
        position[i] = 1 + (position[i-1] + p - 1) % (i+1);
    }

    printf("%d ", position[n-1]);
}

int main(){
    Joseph();
    return 0;
}