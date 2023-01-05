// 7568번 덩치 실버5
// https://www.acmicpc.net/problem/7568
// 23분

#include<bits/stdc++.h>
using namespace std;

int N, x, y;
vector<tuple<int, int, int>> people;

void input() {
    cin >> N; //N은 전체 사람 수
    for(int i=0; i<N; i++) {
        cin >> x >> y; // x는 몸무게, y는 키
        people.push_back({x, y, 1});
    }
}

void solve() {
    for(int j=0; j<N; j++) {
        for(int k=j+1; k<N; k++) {
            if(get<0>(people[j])<get<0>(people[k])) { // 몸무게 : k > j
                if(get<1>(people[j])<get<1>(people[k])) { // 키 : k > j
                    get<2>(people[j]) += 1; // k가 j보다 덩치가 크다 = j의 순위를 낮춘다.
                }
            }
            else if(get<0>(people[j])>get<0>(people[k])) { // 몸무게 : j > k
                if(get<1>(people[j])>get<1>(people[k])) { // 키 : j > k
                    get<2>(people[k]) += 1; // j가 k보다 덩치가 크다 = k의 순위를 낮춘다.
                }
            }
        }
    }
}

void output() {
    for(int n=0; n<N; n++) {
        cout << get<2>(people[n]) << " "; // 순위 결과 출력하기
    }
    cout << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
