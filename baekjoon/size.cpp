// 7568�� ��ġ �ǹ�5
// https://www.acmicpc.net/problem/7568
// 23��

#include<bits/stdc++.h>
using namespace std;

int N, x, y;
vector<tuple<int, int, int>> people;

void input() {
    cin >> N; //N�� ��ü ��� ��
    for(int i=0; i<N; i++) {
        cin >> x >> y; // x�� ������, y�� Ű
        people.push_back({x, y, 1});
    }
}

void solve() {
    for(int j=0; j<N; j++) {
        for(int k=j+1; k<N; k++) {
            if(get<0>(people[j])<get<0>(people[k])) { // ������ : k > j
                if(get<1>(people[j])<get<1>(people[k])) { // Ű : k > j
                    get<2>(people[j]) += 1; // k�� j���� ��ġ�� ũ�� = j�� ������ �����.
                }
            }
            else if(get<0>(people[j])>get<0>(people[k])) { // ������ : j > k
                if(get<1>(people[j])>get<1>(people[k])) { // Ű : j > k
                    get<2>(people[k]) += 1; // j�� k���� ��ġ�� ũ�� = k�� ������ �����.
                }
            }
        }
    }
}

void output() {
    for(int n=0; n<N; n++) {
        cout << get<2>(people[n]) << " "; // ���� ��� ����ϱ�
    }
    cout << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
