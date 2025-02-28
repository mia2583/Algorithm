/*

- 백준 1916번 : 최소 비용 구하기 (골드5)

- 문제 유형 : 다익스트라

- 풀이 방법 도출 과정
1. 위치 A에서 위치 B로 가는 비용들이 표시되고 최소 비용을 찾는다 -> 다익스트라 or 플로이드 와샬
2. 어느 한 지점에서 다른 한 지점으로의 최소 비용이므로 다익스트라

- 시간 복잡도
버스 개수 M만큼 for문을 돌면서 입력을 받고, 다익스트라의 시간 복잡도는 MlogN(N은 도시 수)이므로 O(M + MlogN) = O(MlogN)

- 문제 풀이 핵심 설명
1. 시작점에서 간선을 따라 이동할 수 있는 모든 정점을 방문한다.
2. "현재 위치 비용 + 현재->다음 이동 비용" < "다음 위치 비용" 이면 "다음 위치 비용"을 "현재 위치 비용 + 현재->다음 이동 비용"로 업데이트하면 매 위치별로 최소 비용을 구할 수 있다.
3. 처음 풀이때 시간 초과 났는데, 9번줄에서 처럼 최소 비용이 아닌 것을 미리 제거하면 시간을 단축할 수 있다

*/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

int N, M;
int bus_s, bus_e, price;
int city_s, city_e, min_price, city_start;
int INF = int(1e9);
map<int, vector<pair<int, int>>> bus; // {출발, {도착, 가격}}
int prices[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


int main() {
    cin >> N >> M;

    for (int i=0; i<M; i++) {
        cin >> bus_s >> bus_e >> price;
        bus[bus_s].push_back({bus_e, price});
    }

    
    cin >> city_s >> city_e;

    fill_n(prices, 1001, INF);

    prices[city_s] = 0;
    pq.push({0, city_s});

    while (!pq.empty()) {
        min_price = pq.top().first;
        city_start = pq.top().second;
        pq.pop();
        
        if (prices[city_start] < min_price) continue;

        // 최소 일때만 q에 넣어서 업데이트
        for (int i=0; i<bus[city_start].size(); i++) {
            if (min_price + bus[city_start][i].second < prices[bus[city_start][i].first]) {
                prices[bus[city_start][i].first] = min_price + bus[city_start][i].second;
                pq.push({prices[bus[city_start][i].first], bus[city_start][i].first});
            }
        }
    }

    cout << prices[city_e];
    
    return 0;
}