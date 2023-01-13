// 1138�� ���ٷμ��� �ǹ�2
// https://www.acmicpc.net/problem/1138
// 19��
#include<bits/stdc++.h>
using namespace std;

int N;
int taller;
vector<int> tall;
vector<int> answer;

void input() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> taller;
        tall.push_back(taller);
        answer.push_back(i); // ó�� ������ 1,2,3,4...
    }
}

void solve() {
    for(int i=0; i<N; i++) {
        if(tall[i]==0) continue;
        // ���� ���ʿ� Ű�� ū ����� ������
        for(int j=0; j<N; j++) {
            if(answer[j]==i) { // n��° ����� ���� ��ġ����
                for(int k=j; k<N; k++) { // �ڽź��� ���� �����ʿ� �����鼭
                    if(answer[k] > answer[j]) { // �ڽź��� ū �����
                        swap(answer[k], answer[j]); // ��ġ �ٲٱ�
                        j=k;
                        tall[i]-=1; // n��° ����� ���ʿ� ū ����� taller[n] ��ŭ ���� ������ �ݺ�
                    }
                    if(tall[i]==0) break;
                }
                break;
            }
        }
    }
}

void output() {
    for(int a: answer) {
        cout << a+1 << " ";
    }
}

int main() {
    input();
    solve();
    output();
    return 0;
}
