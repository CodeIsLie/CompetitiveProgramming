//
// Created by admin on 12.09.2018.
//

#include <list>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int, int>> pairs;
    int l, r;
    pairs.emplace_back(0, 0);
    for (int i = 1; i <= n; ++i){
        cin >> l >> r;
        pairs.emplace_back(l, r);
    }

    vector<int> used;
    used.assign(n+1, 0);

    vector<list<int>> lists;
    int k = 0;
    for (int i = 1; i <= n; ++i){
        if (!used[i]){
            used[i] = 1;
            lists.push_back(list<int>(1, i));
            int left = pairs[i].first;
            while (left != 0){
                used[left] = 1;
                lists[k].push_front(left);
                left = pairs[left].first;
            }
            int right = pairs[i].second;
            while (right != 0){
                used[right] = 1;
                lists[k].push_back(right);
                right = pairs[right].second;
            }
            k++;
        }
    }

    int previous = 0;
    for (int i = 0; i < lists.size(); ++i){
        for (int j: lists[i]){
            int left = previous;
            int right;
            if (pairs[j].second == 0){
                if (i == lists.size()-1)
                    right = 0;
                else
                    right = lists[i+1].front();
            } else
            {
                right = pairs[j].second;
            }

            previous = j;
            pairs[j].first = left;
            pairs[j].second = right;
        }
    }

    for (int i = 1; i <= n; ++i){
        printf("%d %d \n", pairs[i].first, pairs[i].second);
    }

    return 0;
}