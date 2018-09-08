//
// Created by admin on 08.09.2018.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

void lowerBound(){
    int n, start, x;
    cin >> n >> start >> x;

    vector<pair<int, int>> values;
    int maxQueries = 1999;
    int rndQueries = 1000;
    int listQueries = maxQueries - rndQueries;

    int xi, next;
    int answer = -1;
    if (n <= maxQueries){
        // do 1999 queries, memorize in massive, find required
        for (int i = 0; i < n; ++i){
            printf("? %d ", i+1);
            fflush(stdout);
            scanf("%d%d", &xi, &next);
            values.emplace_back(xi, next);
        }

        sort(values.begin(), values.end());
        for (int i = 0; i < n; ++i){
            if (values[i].first >= x){
                answer = values[i].first;
                break;
            }
        }
    } else{
        // do rndQueries, find (x1, x2)| x1 < x, x < x2
        // next, from x1, find first >= x
        set<int> indexes;
        indexes.insert(start);
        for (int i = 0; i < rndQueries-1; ++i) {
            int index = 1 + (rand() % n);
            indexes.insert(index);
        }

        for (int i: indexes){
            printf("? %d ", i);
            fflush(stdout);
            scanf("%d%d", &xi, &next);
            values.emplace_back(xi, next);
        }

        sort(values.begin(), values.end());
        int firstMoreX = -1;
        for (int i = 0; i < values.size(); ++i){
            if (values[i].first >= x){
                firstMoreX = i;
                break;
            }
        }
        if (firstMoreX == 0)
            answer = values[0].first;
        else {
            if (firstMoreX == -1){
                firstMoreX = values.size();
            }
            pair<int, int> curPair = values[firstMoreX-1];
            int k = 0;
            while (curPair.second != -1 && k < listQueries){
                printf("? %d ", curPair.second);
                fflush(stdout);
                scanf("%d%d", &xi, &next);
                curPair.first = xi;
                curPair.second = next;
                if (xi >= x){
                    break;
                }
                k++;
            }
            if (curPair.first >= x)
                answer = curPair.first;
            else
                answer = -1;
        }
    }

    printf("! %d", answer);
    fflush(stdout);
}

int main(){
    srand(time(0));

    lowerBound();
    return 0;
}
