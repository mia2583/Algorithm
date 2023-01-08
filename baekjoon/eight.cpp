// 1105�� �� �ǹ�1
// https://www.acmicpc.net/problem/1105
// 14��

#include<bits/stdc++.h>
using namespace std;

int L, R, eightN;
int answer=10;

void input() {
    // L���� ũ�ų� ����, R���� �۰ų� ���� �ڿ���
    cin >> L >> R;
}

// Ư�� ������ 8�� ����
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
        // ���� ���� 8�� ����
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
