// 1105번 팔 실버1
// https://www.acmicpc.net/problem/1105
// 14분

#include<bits/stdc++.h>
using namespace std;

int L, R, eightN;
int answer=10;

void input() {
    // L보다 크거나 같고, R보다 작거나 같은 자연수
    cin >> L >> R;
}

// 특정 숫자의 8의 개수
int countEight(int number) {
    eightN = 0;
    while(number) {
        if(number%10==8) eightN++;
        number/=10;
    }
    return eightN;
}

void solve() {
    for(int i=L; i<=R; i++) {
        eightN = countEight(i);
        // 가장 적은 8의 개수
        if(eightN < answer) answer=eightN;
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
