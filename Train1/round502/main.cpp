#define FILE2 "stars"

#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <ctime>
#include <algorithm>
#include <initializer_list>
#include <climits>

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

vector<vector<vector<long long>>> t;
int n;

void init (int nn)
{
    t.assign (nn, vector<vector<long long>>(nn, vector<long long>(nn, 0)));
}

long long sum (int x, int y, int z)
{
    //printf("%d %d %d - ", x, y, z);
    long long result = 0;
    for (; x >= 0; x = (x & (x+1)) - 1)
        for (; y >= 0; y = (y & (y+1)) - 1)
            for (; z >= 0; z = (z & (z+1)) - 1)
                result += t[x][y][z];
    //printf("%lld \n", result);
    return result;
}

void inc (int x, int y, int z, long long val)
{
    for (int i = x; i < n; i = (i | (i+1)))
        for (int j = y; j < n; j = (j | (j+1)))
            for (int k = z; k < n; k = (k | (k+1)))
                t[i][j][k] += val;
}

long long sum (int x, int y, int z, int x1, int y1, int z1)
{
    return sum(x, y, z) - sum(x1-1, y, z) - sum(x, y1-1, z) - sum(x, y, z1-1)
            + sum(x, y1-1, z1-1) + sum(x1-1, y, z1-1) + sum(x1-1, y1-1, z) - sum(x1-1, y1-1, z1-1);
}

void init (vector<vector<vector<long long>>>& a)
{
    init ((int) a.size());
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a.size(); j++)
            for (int k = 0; k < a.size(); k++)
                inc (i, j, k, a[i][j][k]);
}

vector<vector<vector<long long>>> stars;

void task(){
    int m;
    scanf("%d", &n);
    stars.assign(n, vector<vector<long long>>(n, vector<long long>(n, 0)));
    init(stars);

    int x, y, z, k;
    int x1, y1, z1, x2, y2, z2;
    while (true){
        scanf("%d", &m);
        if (m == 3)
            break;
        if (m == 1){
            scanf("%d %d %d %d", &x, &y, &z, &k);
            inc(x, y, z, k);
            stars[x][y][z] += k;
        }else if (m == 2){
            scanf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
            long long cntStars = sum(x2, y2, z2, x1, y1, z1);
            printf("%lld \n", cntStars);
        }
    }
}