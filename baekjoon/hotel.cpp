// 1106 ȣ�� ���5
// https://www.acmicpc.net/problem/1106
// 31��

#include <bits/stdc++.h>
using namespace std;

int C, N, P, G;
vector<pair<int, int>> promotion;
int customers[1001] {0, };
int customer;


void input() {
    cin >> C >> N; // C�� �߰��ؾ� �� �� ��, N�� ���� ����
    for(int n=0; n<N; n++) {
        cin >> P >> G; // P�� ȫ�� ���, G�� ���� �� ��
        promotion.push_back({P, G});
    }
}

void solve(){
    for(int c=1; c<=C; c++) {
        customers[c] = 1000*C;
        for(pair<int, int> p : promotion) {
            if(c >= p.second) {
                customer = customers[c - p.second] + p.first;
                if(customer < customers[c]) customers[c] = customer;
            }
        }
    }
}

void output() {
    cout << customers[C] << endl;
}

int main() {
    input();
    solve();
    output();
    return 0;
}
