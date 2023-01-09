// 1120�� ���ڿ� �ǹ�4
// https://www.acmicpc.net/problem/1120
// 29��
#include<bits/stdc++.h>
using namespace std;

string A, B;
int answer;

void input() {
    cin >> A >> B; //A, B�� ���� ���ڿ�
}

// B�� j��° ���ڿ����� A�� ���Ͽ�
// ������ ����ϱ�
int findDifference(int j) {
    int diff = 0;
    for(int i=0; i<A.length(); i++) {
        if(A[i]!=B[j+i]) diff+=1;
    }
    return diff;
}

void solve() {
    // �� ���ڿ��� ���̰� ������ �ѹ��� ��
    if(A.length() == B.length()) answer = findDifference(0);
    else {
        int leastDiff = A.length();
        // �� ���ڿ��� ���̰� �ٸ���
        // ��� A���̸�ŭ�� B���ڿ��� A�� ��
        for(int j=0; j<B.length()-A.length()+1; j++) {
            int diff = findDifference(j);
            if(diff < leastDiff) leastDiff = diff;
        }
        // �� �߿��� �ּ��� �� ã��
        answer = leastDiff;
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
