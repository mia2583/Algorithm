#include <bits/stdc++.h>
#define SIGN(x) (x<0)?-1:1
using namespace std;

int setData(vector<pair<int, int>> &data) {
    int numData;
    int beforeX=0, beforeY=0, x=0, y=0;
    int firstX, firstY, total=0;
    cin >> numData;
    cin >> beforeX >> beforeY;
    data.push_back(make_pair(beforeX, beforeY));
    firstX = beforeX; firstY = beforeY;
    for(int i=1; i< numData; i++) {
        cin >> x >> y;
        total += abs(x - beforeX + y - beforeY);
        data.push_back(make_pair(x - beforeX, y - beforeY));
        beforeX = x; beforeY = y;
    }
    total += abs(firstX - beforeX + firstY - beforeY);
    data.push_back(make_pair(firstX - beforeX, firstY - beforeY));
    return total;
}

void setTime(vector <int> &times) {
     int time;
    while(cin >> time) {
        times.push_back(time);
    }
}

void calPosition(vector<pair<int, int>> &data, vector <int> &times, int circuit) {
    for(int j=0; j <times.size(); j++) {
        int totalWalk = times[j]%circuit;
        int walk=0, k =1;
        int moveX = data[0].first, moveY= data[0].second;
        walk += abs(data[1].first) + abs(data[1].second);
        while(walk < totalWalk) {
            moveX += data[k].first; moveY += data[k].second;
            walk += abs(data[k+1].first) + abs(data[k+1].second);
            k++;
        }
        walk -= (abs(data[k].first) + abs(data[k].second));
        if(data[k].first != 0) moveX += (SIGN(data[k].first))*(totalWalk - walk);
        else moveY += (SIGN(data[k].second))*(totalWalk -walk);
        cout << moveX << " " << moveY<<endl;
    }
}

int  main() {
    vector<pair<int, int>> data;
    vector <int> times;
    int circuit = setData(data);
    setTime(times);
    calPosition(data, times, circuit);
    return 0;
}
