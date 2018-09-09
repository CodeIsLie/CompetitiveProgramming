//
// Created by Ilya on 07.09.2018.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void badSubstring(){
    int n;
    cin >> n;

    int aStrings = 1;
    int bStrings = 1;
    int cStrings = 1;

    for (int i = 1; i < n; ++i){
        int newA = aStrings + bStrings + cStrings;
        int newB = bStrings + cStrings;
        int newC = newA;

        aStrings = newA;
        bStrings = newB;
        cStrings = newC;
    }


    int cntStrings = 1;
    if (n > 0){
        cntStrings = aStrings + bStrings + cStrings;
    }
    printf("%d ", cntStrings);
}

int main(){
    badSubstring();
    return 0;
}