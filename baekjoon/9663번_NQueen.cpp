/*

- 백준 9663번 : N Queen (골드4)

- 문제 유형 : 백트레킹

- 풀이 방법 도출 과정
1. 체스판 위에 N개의 퀸을 놓습니다. 서로 공격하지 못하게 하려면 대각선이나 직선으로 겹치면 안됩니다.
2. 이전의 퀸의 위치가 어디냐에 따라 다음 퀸 위치에 영향을 줍니다. 하지만이 규칙이 하나의 식으로 명확하게 정의되지 않습니다.
3. 퀸을 놓을 때, 종료 조건이 명확합니다. (N번째 놓거나 더 이상 퀸을 놓을 수 있는 위치가 없을 때)
4. 만약 종료 조건에 해당되면 이전 상태에서 다시 시도할 수 있습니다.

- 시간 복잡도
퀸의 위치는 모든 이전 퀸들의 위치의 열을 제외하고 놓으므로, O(N!)

*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int answer = 0;
vector<int> board;

bool possible(int position, int row) {
    for (int i=0; i<board.size(); i++) {
        if (position == board[i]) { // 같은 열
            return false;
        } else if (position == board[i]-(row-i)) { // 대각선
            return false;
        } else if (position == board[i]+(row-i)) { // 대각선
            return false;
        }
    }
    return true;
}

void put_queen(int row) {
    if (row == N) {
        answer++;
        return;
    }

    for (int i=0; i<N; i++) {
        if (possible(i, row)) {
            board.push_back(i);
            put_queen(row+1);
            board.pop_back();
        }
    }
}

int main() {
    cin >> N;
    put_queen(0);

    cout << answer << endl;
    return 0;
}
