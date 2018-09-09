//
// Created by Ilya on 06.09.2018.
//
#define FILE2 "peacefulsets"

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void peacefulsets(){
#ifdef FILE2
    freopen(FILE2".in", "r", stdin);
    freopen(FILE2".out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);

    vector<vector<long long> > sizes(n+1, vector<long long>(n+1, 0));
    vector<vector<long long> > cumulativeSums(n+1, vector<long long>(n+1, 0));

    // count sets with size = 1 and sum(weights) = n is 1
    for (int i = 1; i <= n; ++i){
        sizes[i][i] = 1;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i/2; j <= i; ++j){
            sizes[i][j] += cumulativeSums[i-j][j/2];

        }
        for (int j = 1; j <= n; ++j){
            cumulativeSums[i][j] = cumulativeSums[i][j-1] + sizes[i][j];
        }
    }

//    for (int i = 1; i <= n; ++i)
//    {
//        for (int j = 1; j <= i; ++j){
//            cout << sizes[i][j] << ' ';
//        }
//        cout << endl;
//    }

    long long nSets = cumulativeSums[n][n];
    cout << nSets;
}

int main(){
    peacefulsets();
    return 0;
}