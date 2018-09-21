// #define TEAM

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
    task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}

int uniqes;

bool canCatch(string& s, int n){
    vector<int> charCnts(128, 0);
    int cntUniques = 0;
    for (int i = 0; i < n; ++i){
        if (!charCnts[s[i]])
            cntUniques++;
        charCnts[s[i]]++;
    }
    if (cntUniques == uniqes)
        return true;

    for (int i = n; i < s.size(); ++i){
        charCnts[s[i-n]]--;
        if (!charCnts[s[i-n]])
            cntUniques--;

        if (!charCnts[s[i]])
            cntUniques++;
        charCnts[s[i]]++;

        if (cntUniques == uniqes)
            return true;
    }

    return false;
}

void task(){
    int n;
    scanf("%d", &n);
    char c[n];
    scanf("%s", c);

    string s = c;
    set<int> uniqueChars;
    for (char c: s)
        uniqueChars.insert(c);
    uniqes = uniqueChars.size();

    int l = 1;
    int r = s.size();
    while (l<r){
        int m = (l+r)/2;
        if (canCatch(s, m)){
            r = m;
        }
        else{
            l = m+1;
        }
    }

    cout << r << endl;
}
