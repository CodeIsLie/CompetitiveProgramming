//
// Created by Ilya on 13.09.2018.
//

#define FILE1

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

void tickets(){
#ifdef FILE1
    freopen("../input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif

    long long n, a, b, k, f;
    cin >> n >> a >> b >> k >> f;

    map<string, int> paths;
    string s;
    string st1, st2;
    vector<pair<string, string>> stations;

    int d = 0;
    for (int i = 0; i < n; ++i){
        cin >> st1;
        cin >> st2;
        stations.push_back(make_pair(st1, st2));
        //cout << st1 << " " << st2 << endl;

        string path1 = st1 + " " + st2;
        string path2 = st2 + " " + st1;
        if (paths.find(path1) == paths.end()){
            paths.emplace(path1, d);
            paths.emplace(path2, d);
            d++;
        }
    }

    vector<int> costs;
    costs.assign(n, 0);

    string path = stations[0].first + " " + stations[0].second;
    costs[paths[path]] = a;
    for (int i = 1; i < stations.size(); ++i){
        string path = stations[i].first + " " + stations[i].second;
        int ind = paths[path];
        if (stations[i].first == stations[i-1].second){
            costs[ind] += b;
        }
        else{
            costs[ind] += a;
        }
    }

    sort(costs.rbegin(), costs.rend());
    for (int i = 0; i < costs.size(); ++i){
        if (i == k)
            break;
        if (costs[i] > f){
            costs[i] = f;
        }
    }

    int sum = 0;
    for (int i = 0; i < costs.size(); ++i)
        sum += costs[i];
    cout << sum;
}

int main(){
    tickets();
    return 0;
}
