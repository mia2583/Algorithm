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

// R�� L�� ���� ���� ���� ��ġ ���ϱ�
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
    // R�� L�� �����ϸ� �ٷ� 8�� ���� ���ϱ�
    if(R-L==0) answer = countEight(R);
    // �� ������ ���̰� ������
    // ���� ���� �ܿ��� �ݵ�� 8�� 0�� ���� �ڿ����� ����.
    // ���� ���� ���ڿ����� 8�� ������ �� ��.
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
