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

void taskD(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n, q;
        scanf("%d %d\n", &n, &q);

        string s;
        char stmp[n+1];
        scanf("%s", stmp);
        s = stmp;

        counts.assign(n, vector<int>(27, 0));
        counts[0][s[0] - 'a']++;
        for (int i = 1; i < n; ++i){
            for (int j = 0; j < 27; ++j){
                counts[i][j] = counts[i-1][j];
            }
            counts[i][s[i] - 'a']++;
        }

        int l, r;
        char c;
        for (int i = 0; i < q; ++i){
            scanf("%d %d %c", &l, &r, &c);
            printf("%d\n", cnt(c, r, n) - cnt(c, l-1, n));
        }
    }
}
