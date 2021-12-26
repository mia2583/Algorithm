#include <bits/stdc++.h>

using namespace std;

typedef priority_queue<pair<int,int>> pq_ii;
typedef priority_queue<tuple<int,int, int>> pq_iii;

void input(pq_ii &code) {
    int n=0, startP=0, endP=0;
    cin >> n;
    while(n--) {
        cin >> startP >> endP;
        code.push(make_pair(startP, -1));
        code.push(make_pair(endP, 1));
    }
}

void findMax(pq_ii &code, pq_iii &working) {
    int bi=0, ei=0;
    int maxE=0, maxB=0;
    int num=0, interval = 0;
    while(code.size() >1) {
        ei = code.top().first;
        while(code.top().first == ei) {
            num += code.top().second;
            code.pop();
            if(code.empty()) break;
        }
        bi = code.top().first;
        interval = ei - bi;
        working.push(make_tuple(num, interval, ei));
    }
}

void out(pq_iii &working) {
    cout << get<2>(working.top()) - get<1>(working.top()) << " " << get<2>(working.top());
}

int main() {
    pq_ii code; pq_iii working;
    input(code);
    findMax(code, working);
    out(working);
}
