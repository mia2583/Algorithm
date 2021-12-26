#include <bits/stdc++.h>

using namespace std;
void input(map<char, vector<char>> &adjacent, array<char,3> &start) {
    char vertex, node;
    int nodeNum = 0;
    cin >> nodeNum;
    for(int i=0; i< 3; i++) {
        cin >> vertex;
        start[i] = vertex;
    }

    while(nodeNum--) {
        vector<char> linked;
        cin >> vertex;
        cin >> node;
        while(node != '$') {
            linked.push_back(node);
            cin >> node;
        }
        adjacent.insert({vertex, linked});
    }
}

void findWay(char f, int i, map<char, vector<char>> &adjacent, array<array<int,26>,3> &times, list<char> &left, vector<char> visited){
    for(auto r: adjacent[f]) {
        if(count(visited.begin(), visited.end(), r))
           continue;
        left.push_back(r);
        int newWay = times[i][(int)f-(int)'a'] + 1;
        if(times[i][(int)r-(int)'a']== -1 || newWay < times[i][(int)r-(int)'a'] )
            times[i][(int)r-(int)'a'] = times[i][(int)f-(int)'a'] + 1;
    }
    for(auto r: adjacent[f]) {
        if(count(visited.begin(), visited.end(), r))
           continue;
        visited.push_back(r);
    }
    if(!left.empty()) {
        char next = left.front();
        left.pop_front();
        findWay(next, i, adjacent, times, left, visited);
    }
}

void data(map<char, vector<char>> &adjacent, array<char,3> &start, array<array<int,26>,3>  &times) {
    for(int i=0; i <3; i++) {
         vector<char> visited;
         list<char> left;
        char f = start[i];
        times[i][(int)f-(int)'a'] = 0;
        visited.push_back(f);
        findWay(f, i, adjacent, times, left, visited);
    }

    array<int, 26> total = {0};
    for(int i=0; i <3; i++) {
        for(int j=0; j <26; j++) {
            if ( times[i][j] == -1) total[j] = -1;
            else if (total[j] != -1 && times[i][j] > total[j]) total[j] = times[i][j];
        }
    }

    int fastest = 26;
    int locate = 0;
    for(int j=0; j <26; j++) {
        if(total[j] != -1 && fastest > total[j]) { fastest = total[j]; locate = j;}
    }

    if (fastest == 26) {
        cout << '@' <<endl;
        cout << -1<<endl;
    }
    else {
        char restaurant = 'a' + locate;
        cout << restaurant <<endl;
        cout << fastest + 2*(fastest-1)<<endl;
    }
}

int main() {
    map<char, vector<char>> adjacent;
    array<char,3> start;
    array<int,26> alphabet;
    alphabet.fill(-1);
    array<array<int,26>,3> times;
    times.fill(alphabet);
    input(adjacent, start);
    data(adjacent, start, times);
    return 0;
}
