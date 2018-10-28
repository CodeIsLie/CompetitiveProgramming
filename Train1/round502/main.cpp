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
#include <queue>

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
    int t;
    cin >> t;
    while (t--) {
        task();
    }

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}


void minimumBribes(vector<int> q) {
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        if (q[i] > i + 3) {
            cout << "Too chaotic\n";
            return;
        }
    }

    int swaps = 0;
    int cur = 1;
    int next = cur+1;
    vector<char> used(n+1);
    for (int i = 0; i < q.size()-1; ++i){
        used[q[i]] = 1;
        if (q[i] != cur) {
            swaps++;
            if (q[i] != next) {
                swaps++;
            }else{
                for (int j = next + 1; j <= n; ++j) {
                    if (used[j] == 0) {
                        next = j;
                        break;
                    }
                }
            }
        }
        else {
            cur = next;
            for (int j = next + 1; j <= n; ++j) {
                if (used[j] == 0) {
                    next = j;
                    break;
                }
            }
        }
    }

    cout << swaps << endl;
}

void task(){
    int n;
    cin >> n;
    vector<int> q(n);
    for (int i = 0; i < n; ++i)
        cin >> q[i];
    minimumBribes(q);
}