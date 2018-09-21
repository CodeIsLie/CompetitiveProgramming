#define TEAM

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <algorithm>
#include <initializer_list>

using namespace std;

void task();

int main(){
#ifdef TEAM
    freopen("./inp.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--)
        task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}

vector<vector<int>> counts;

int cnt(char c, int r, int n){
    int fullBlocks = r/n;
    int modulo = r % n;
    int result = counts[n-1][c-'a'] * fullBlocks;
    if (modulo > 0){
        result += counts[modulo-1][c-'a'];
    }
    return result;
}

void task(){
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
