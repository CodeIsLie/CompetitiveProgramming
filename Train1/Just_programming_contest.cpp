//
// Created by Ilya on 21.09.2018.
//

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <algorithm>
#include <initializer_list>

using namespace std;

void taskJ(){
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        long long sum = 0;
        int a;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            sum = (sum + a * (1 + sum)) % (1000000000 + 7);
        }

        printf("%lld\n", sum);
    }
}

