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

void task() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    map<char, int> char_cnts;
    for (char c: s){
        char_cnts[c] ++;
    }

    int cnt_odd = 0;
    vector<char> odd_symbols;
    for (auto ch: char_cnts){
        if (ch.second % 2 == 1){
            cnt_odd++;
            odd_symbols.push_back(ch.first);
        }
    }

    int cnt_even = n - cnt_odd;

    if (cnt_odd == 0){
        for (auto& ch: char_cnts){
            ch.second /= 2;
        }
        string pal = "";
        for (auto& ch: char_cnts){
            while (ch.second > 0){
                pal += ch.first;
                ch.second--;
            }
        }
        string pal_rev = pal;
        reverse(pal_rev.begin(), pal_rev.end());
        pal = pal + pal_rev;
        cout << 1 << endl;
        cout << pal << endl;
        return;
    }

    while (cnt_even*2 >= cnt_odd && (cnt_even / 2) % cnt_odd != 0){
        cnt_odd += 2;
        cnt_even -= 2;
    }

    if ( (cnt_even / 2) % cnt_odd != 0){
        cout << n << endl;
        for (char c: s){
            cout << c << endl;
        }
        return;
    }

    vector<string> palindroms;
    for (int i = 0; i < cnt_odd; ++i){
        for (char odd_c: odd_symbols){
            int pal_length = 1;
            string pal = string(1, odd_c);
            string suffix = "";
            while (pal_length < n / cnt_odd){
                pal_length+=2;
                //suffix += string(1, symb);
            }
            palindroms.push_back(pal);
        }
    }

    cout << palindroms.size();
    for (auto& pal: palindroms){
        cout << pal << endl;
    }
}