//
// Created by Ilya on 06.09.2018.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void balls(){
    freopen("balls.in", "r", stdin);
    int t;
    scanf("%d", &t);
    vector<int> tests(t);
    vector<int> answers(t);

    int m;
    for (int i = 0; i < t; ++i){
        scanf("%d", &m);
        tests[i] = m;
    }

    freopen("balls.out", "w", stdout);
    for (int a: answers)
        printf("%d \n", a);
}

int main(){
    balls();
    return 0;
}