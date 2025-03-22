/*

- 백준 1504번 : 특정한 최단 경로 (실버 1)

- 문제 유형 : 다익스트라 

- 풀이 방법 도출 과정
1. 방향 그래프와 각 거리(비용)가 입력된다.
2. 최단 거리를 구해야한다.
3. v1과 v2 중에 무엇을 먼저 지나는 것이 최단의 경로가 될지 모르니 1 -> v1 -> v2 -> N, 1-> v2 -> v1 -> N 경우 모두 구해서 비교한다.

- 시간 복잡도
다익스트라의 시간 복잡도가 ElogV인데, 총 6번 다익스트라를 실행하므로 O(6ElogV)

- 문제 풀이 핵심 설명
현재 cost가 최단으로 저장된 것보다 클 때, 무시하면 시간을 더욱 단축할 수 있다. 

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, E, a, b, c;
int v1, v2;
vector<vector<pair<int, int>>> map(801); // a번째 행: {b, c}
vector<int> shortest_map(801, 1e9); // 최단 경로 저장용

int dijkstra(int start, int destination) {
    fill(shortest_map.begin(), shortest_map.end(), 1e9); // 최단 경로 초기화

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    shortest_map[start] = 0;

    while (!pq.empty()) {
        c = pq.top().first;
        b = pq.top().second;
        pq.pop();

        if (c > shortest_map[b]) continue; // 이미 더 좋은 경로가 있는 경우

        for (int i = 0; i < map[b].size(); i++) {
            if (c + map[b][i].second < shortest_map[map[b][i].first]) {
                shortest_map[map[b][i].first] = c + map[b][i].second;
                pq.push({shortest_map[map[b][i].first], map[b][i].first});
            }
        }
    }

    return (shortest_map[destination] == 1e9) ? -1 : shortest_map[destination]; // 경로가 없으면 -1 리턴
}

int main() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c; // a->b with dist c
        map[a].push_back({b, c});
        map[b].push_back({a, c}); // 양방향 그래프
    }

    cin >> v1 >> v2;
    
    int answer1_tov1 = dijkstra(1, v1); // 1 -> v1
    int answer1_tov2 = dijkstra(v1, v2); // v1 -> v2
    int answer1_toN = dijkstra(v2, N); // v2 -> N
    int answer1 = -1;

    if (answer1_tov1 != -1 && answer1_tov2 != -1 && answer1_toN != -1) {
        answer1 = answer1_tov1 + answer1_tov2 + answer1_toN;
    }

    int answer2_tov2 = dijkstra(1, v2); // 1 -> v2
    int answer2_tov1 = dijkstra(v2, v1); // v2 -> v1
    int answer2_toN = dijkstra(v1, N); // v1 -> N
    int answer2 = -1;

    if (answer2_tov2 != -1 && answer2_tov1 != -1 && answer2_toN != -1) {
        answer2 = answer2_tov2 + answer2_tov1 + answer2_toN;
    }

    if (answer1 == -1 && answer2 == -1) {
        cout << -1 << endl; // 두 경로 모두 불가능한 경우
    } else if (answer1 == -1) {
        cout << answer2 << endl; // 첫 번째 경로가 불가능한 경우
    } else if (answer2 == -1) {
        cout << answer1 << endl; // 두 번째 경로가 불가능한 경우
    } else {
        cout << min(answer1, answer2) << endl; // 둘 중 더 짧은 경로
    }

    return 0;
}
