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
    int n, m;
    cin >> n;
    string word;
    cin >> word;
    cin >> m;

    vector<string> words;
    words.resize(m);
    for (int i = 0; i < m; ++i){
        cin >> words[i];
    }

    map<char, int> matches;
    for (auto w: words){
        bool b = true;
        set<char> chars;
        for (int i = 0; i < w.size(); ++i){
            char c = w[i];
            if (word[i] == '*'){
                if (word.find(c) != string::npos) {
                    m--;
                    b = false;
                    break;
                }
            }
            else{
                if (word[i] != c){
                    m--;
                    b = false;
                    break;
                }
            }
            if (word[i] == '*' && word.find(c) == string::npos){
                chars.insert(c);
            }
        }
        if (b)
            for (char c: chars){
                matches[c]++;
            }
    }

    int cnt_letters = 0;
    for (auto match: matches){
        if (match.second == m){
            cnt_letters ++;
        }
    }
    cout << cnt_letters << endl;
}