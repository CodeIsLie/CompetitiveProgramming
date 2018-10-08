#define FILE2 "cover"

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <ctime>
#include <algorithm>
#include <climits>
#include <list>

using namespace std;

void task();

int main(){
#ifdef TEAM
    freopen("./inp.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
#endif
#ifdef FILE2
    freopen(FILE2".in", "r", stdin);
    freopen(FILE2".out", "w", stdout);
#endif
    task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}

void task() {
    int m;
    scanf("%d", &m);

    set<pair<int, pair<int, int>>> scan_line;
    vector<pair<int, int>> segments;
    int l, r;
    int i = 0;
    while(true){
        scanf("%d %d", &l, &r);
        if (!l && !r)
            break;
        scan_line.emplace(l, make_pair(r, i));
        segments.emplace_back(l, r);
        ++i;
    }
    scan_line.emplace(m+1, make_pair(INT_MAX, -1));

    vector<pair<int, int>> required_segments;
    int bound = 0;
    int maxX = -1;
    int maxInd = -1;
    for (auto s: scan_line){
        if (s.first <= bound){
            if (s.second.first > maxX){
                maxX = s.second.first;
                maxInd = s.second.second;
            }
        }else{
            required_segments.push_back(segments[maxInd]);
            if (maxX <= bound) {
                printf("No solution\n");
                return;
            }
            bound = maxX;
            if (bound >= m)
                break;
            if (s.first <= bound) {
                if (s.second.first > maxX) {
                    maxX = s.second.first;
                    maxInd = s.second.second;
                }
            }
            else{
                printf("No solution\n");
                return;
            }
        }
    }
    if (bound < m) {
        printf("No solution\n");
        return;
    }

    printf("%d\n", (int)required_segments.size());
    for (auto p: required_segments){
        printf("%d %d\n", p.first, p.second);
    }

}