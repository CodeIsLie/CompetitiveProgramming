// #define FILE2 "cover"

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


void task(){
    int m;
    cin >> m;

    set<pair<int, pair<int, int>>> scan_line;
    vector<pair<int, int>> segments;
    int l, r;
    int i = 0;
    while(true){
        cin >> l >> r;
        if (!l && !r)
            break;
        scan_line.emplace(l, make_pair(1, i));
        scan_line.emplace(r, make_pair(2, i));
        segments.emplace_back(l, r);
        ++i;
    }

    vector<pair<int, int>> result_segments;
    l = 0;
    r = -1;
    int cnt_open = 0;
    int remain_open = 0;
    for (auto p:scan_line){
        if (p.second.first == 1){
            if (p.first > r+1 && remain_open == 0) {
                remain_open = cnt_open;
            }
            if (cnt_open == 0 && p.first > r+1)
            {
                cout << "No solution\n";
                return;
            }
            cnt_open++;
        } else{
            if (p.first > r && remain_open == 0) {
                remain_open = cnt_open;
            }
            if (segments[p.second.second].first <= r+1)
                remain_open--;
            if (remain_open == 0){
                result_segments.push_back(segments[p.second.second]);
                r = p.first;
                if (r >= m)
                    break;
            }
            cnt_open--;
        }
    }

    if (r < m)
    {
        cout << "No solution\n";
        return;
    }

    cout << result_segments.size() << endl;
    for (auto p: result_segments){
        cout << p.first << ' ' << p.second << endl;
    }
}