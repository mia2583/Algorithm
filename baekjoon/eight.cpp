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

// R과 L의 공통 숫자 시작 위치 구하기
int findDiffLen() {
    int diff = R-L;
    int diffLen = 1;
    while(diff) {
        diffLen*=10;
        diff/=10;
    }
    return diffLen;
}

void solve() {
    // R과 L이 동일하면 바로 8의 개수 구하기
    if(R-L==0) answer = countEight(R);
    // 두 숫자의 차이가 있으면
    // 공통 숫자 외에는 반드시 8이 0개 들어가는 자연수가 있음.
    // 따라서 공통 숫자에서만 8의 개수를 셀 것.
    else {
        int len = findDiffLen();
        answer = countEight(R/len);
        if(countEight(L/len)<answer) answer = countEight(L/len);
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
