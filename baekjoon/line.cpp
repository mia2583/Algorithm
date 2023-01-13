// 1138번 한줄로서기 실버2
// https://www.acmicpc.net/problem/1138
// 19분
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
        answer.push_back(i); // 처음 시작은 1,2,3,4...
    }
}

void solve() {
    for(int i=0; i<N; i++) {
        if(tall[i]==0) continue;
        // 만약 왼쪽에 키가 큰 사람이 있으면
        for(int j=0; j<N; j++) {
            if(answer[j]==i) { // n번째 사람의 현재 위치에서
                for(int k=j; k<N; k++) { // 자신보다 현재 오른쪽에 있으면서
                    if(answer[k] > answer[j]) { // 자신보다 큰 사람과
                        swap(answer[k], answer[j]); // 위치 바꾸기
                        j=k;
                        tall[i]-=1; // n번째 사람의 왼쪽에 큰 사람이 taller[n] 만큼 있을 때까지 반복
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
