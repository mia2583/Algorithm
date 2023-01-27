// 1100¹ø ÇÏ¾áÄ­ ºê·ÐÁî2
// https://www.acmicpc.net/problem/1100
// 14ºÐ

#include<bits/stdc++.h>
using namespace std;

int chess[8][8] ={0, };
vector<string> states;
int answer=0;
string state="";

void input() {
    for(int i=0; i<8; i++) {
        cin >> state;
        states.push_back(state);
    }
}

void solve() {
    for(int m=0; m<8; m++) {
        for(int n=0; n<8; n+=2) {
            if(states[m][n+m%2]=='F') answer++;
        }
    }
}

void output() {
    cout << answer << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
