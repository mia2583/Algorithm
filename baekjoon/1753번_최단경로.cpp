/*

- 백준 1753번 : 최단 경로 (골드4)

- 문제 유형 : 다익스트라

- 풀이 방법 도출 과정
1. 방향 그래프(u, v, w)가 주어진다.
2. 하나의 정점에서 다른 정점으로 가는 최단 경로의 값을 구한다 -> 다익스트라

- 시간 복잡도
다익스트라의 시간 복잡도는 O(ElogV)

- 문제 풀이 핵심 설명
방문 여부 확인과 weight에 따른 우선 순위 큐를 사용하여 계산 시간을 단축한다.

*/

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

int V, E, start;
int u, v, w;

vector<int> weights;
const int INF = numeric_limits<int>::max();
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<bool> visited;
vector<vector<pair<int, int>>> edges;

int main() {
    cin >> V >> E; // 정점 개수, 간선 개수
    cin >> start; // 시작 정점 번호
    edges.assign(V+1, vector<pair<int, int>>()); // 간선
    
    for(int i=0; i<E; i++) {
        cin >> u >> v >> w;
        edges[u].push_back({w, v});
        
    }
    weights.assign(V+1, INF);
    visited.assign(V+1, false);
    
    // 거리 배열을 INF로
    // (0, start) pq에 삽입하여 시작
    weights[start] = 0;
    pq.push({0, start});

    // pq에 아무것도 없을 때까지
    while(!pq.empty()) {
        w = pq.top().first;
        u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for(auto next_node : edges[u]) {
            if(visited[next_node.second]) continue;
            
            if(weights[next_node.second] > weights[u] + next_node.first) {
                weights[next_node.second] = weights[u] + next_node.first;
                pq.push({weights[next_node.second], next_node.second});
            }
        }
    }

    for(int i=1; i<V+1; i++) {
        if(weights[i] == INF) cout << "INF" << '\n';
        else cout << weights[i] << '\n';
    }

    return 0;
}
