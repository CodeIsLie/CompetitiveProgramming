//
// Created by Ilya on 06.09.2018.
//

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void balls(){
    int t;
    scanf("%d", &t);
    vector<int> tests(t);

    int m;
    for (int i = 0; i < t; ++i){
        scanf("%d", &m);
        tests[i] = m;
    }

    vector<int> ballsInLayer;
    vector<int> ballsInPyr;

    ballsInLayer.push_back(1);
    ballsInPyr.push_back(1);
    int i = 1;
    while (true){
        ++i;
        ballsInLayer.push_back(ballsInLayer[i-2] + i);
        int cntBalls = ballsInPyr[i-2] + ballsInLayer[i-1];
        if (cntBalls > 300000)
            break;
        ballsInPyr.push_back(cntBalls);
    }

    vector<int> cntPyramid(300000+1, INT32_MAX);
    for (int b: ballsInPyr){
        cntPyramid[b] = 1;
    }
    for (int i = 1; i <= 300000; ++i){
        for (int b: ballsInPyr){
            if (i - b <= 0)
                break;
            cntPyramid[i] = min(cntPyramid[i], cntPyramid[i-b]+1);
        }
    }

    for (int t: tests)
        printf("%d \n", cntPyramid[t]);
}

int main(){
    balls();
    return 0;
}