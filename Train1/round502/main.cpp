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
    task();

#ifdef TEAM
    cout << "\n=================\n";
    cout<< ((double)clock() / CLOCKS_PER_SEC * 1e3)<< endl;
#endif
    return 0;
}

void task(){
    int n;
    long long s;
    cin >> n >> s;

    long long sum = 0;
    vector<int> volume(n);
    for (int &vol: volume){
        cin >> vol;
        sum += vol;
    }

    if (sum < s){
        cout << -1;
        return;
    }

    sort(volume.begin(), volume.end());
    sum = 0;
    int volume_min = volume.front();
    for (int i = 0; i < volume.size(); ++i){
        int remove = volume[i] - volume_min;
        volume[i] -= remove;
        sum += remove;
    }

    if (sum < s){
        volume_min -= (s - sum) / n + ((s - sum) % n != 0);
    }

    cout << volume_min;
}