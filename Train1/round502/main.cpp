#define FILE2 "qsort"

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

void qsort(vector<int>& arr, int l, int r){
    if (l >= r)
        return;
    int m = (l+r)/2;
    qsort(arr, l, m);
    qsort(arr, m+1, r);
    vector<int> temp;
    temp.assign(r-l+1, 0);
    int li = l;
    int ri = m+1;
    int i;
    for (i = 0; i < r-l+1; ++i){
        if (arr[li] < arr[ri]){
            temp[i] = arr[li];
            li++;
            if (li > m){
                ++i;
                break;
            }

        }else{
            temp[i] = arr[ri];
            ri++;
            if (ri > r){
                ++i;
                break;
            }
        }
    }

    if (ri > r){
        while (li <= m){
            temp[i] = arr[li];
            li++;
            i++;
        }
    }
    else{
        while (ri <= r){
            temp[i] = arr[ri];
            ri++;
            i++;
        }
    }

    for (i = 0; i < temp.size(); ++i){
        arr[l+i] = temp[i];
    }

}


void task() {
    int n;
    scanf("%d", &n);

    vector<int> arr;
    arr.assign(n, 0);
    int k;
    for (int i = 0; i < n; ++i){
        scanf("%d", &k);
        arr[i] = k;
    }

    qsort(arr, 0, n-1);
    for (int i: arr){
        printf("%d ", i);
    }
}