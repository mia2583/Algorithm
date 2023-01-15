// 1292번 쉽게 푸는 문제 브론즈1
// https://www.acmicpc.net/problem/1292
// 17분
#include<bits/stdc++.h>
using namespace std;

int startN, endN;
int answer=0;

void input() {
    cin >> startN >> endN;
}

void solve() {
    int location=0;
    for(int i=0; i<1000; i++) {
        for(int j=0; j<i; j++) {
            location+=1;
            if(location>=startN && location<=endN) answer += i;
            else if(location>endN) break;
        }
        if(location>endN) break;
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
