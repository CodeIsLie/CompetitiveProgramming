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

    task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}


void task(){
    int n;
    cin >> n;

    vector<int> zeroIndices;
    set<pair<int, int>> negs;
    set<pair<int, int>> pos;

    int a;
    for (int i = 0; i < n; ++i){
        cin >> a;
        if (a==0)
            zeroIndices.push_back(i+1);
        else if (a < 0){
            negs.emplace(abs(a), i+1);
        } else{
            pos.emplace(a, i+1);
        }
    }

    int ps = pos.size();
    int ns = negs.size();
    if (zeroIndices.size() > 1) {
        for (int i = 0; i < zeroIndices.size() - 1; ++i) {
            printf("1 %d %d\n", zeroIndices[i], zeroIndices[i + 1]);
        }
    }

    if (zeroIndices.size() > 0){
        if (ns % 2){
            auto it = negs.begin();
            printf("1 %d %d\n", it->second, zeroIndices[zeroIndices.size()-1]);
            negs.erase(it);
        }
        if (negs.size() + pos.size() > 0) {
            printf("2 %d\n", zeroIndices[zeroIndices.size() - 1]);
        }
    }
    else{
        if (ns % 2){
            auto it = negs.begin();
            printf("2 %d\n", it->second);
            negs.erase(it);
        }
    }

    auto it = pos.begin();
    auto nextIt = it;

    if (pos.size() > 0) {
        for (int i = 0; i < pos.size() - 1; ++i) {
            nextIt = next(it);
            printf("1 %d %d\n", it->second, nextIt->second);
            it = nextIt;
        }
    }

    if (negs.size() > 0) {
        it = negs.begin();
        if (pos.size() > 0) {
            int lastIPos = nextIt->second;
            printf("1 %d %d\n", lastIPos, it->second);
        }
        for (int i = 0; i < negs.size() - 1; ++i) {
            nextIt = next(it);
            printf("1 %d %d\n", it->second, nextIt->second);
            it = nextIt;
        }
    }
}
