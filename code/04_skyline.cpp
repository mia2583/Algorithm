#include <bits/stdc++.h>
using namespace std;

int makeData(vector<tuple<int, int, int>> &data, int dataSize) {
    int x, v, h;
    int maxP=0;
    for(int i=0; i<dataSize; i++) {
        cin >> x >>v >>h;
        if( x+h >maxP ) maxP = x+h;
        data.push_back(make_tuple(x, v, h));
    }
    return maxP;
}

void draw(vector<tuple<int, int, int>> &data, int dataSize, int maxP) {
    int building[maxP] = { };
    for(int i=0; i < dataSize; i++) {
        for(int j=get<0>(data[i]); j < get<0>(data[i]) + get<2>(data[i]); j++) {
            if(get<1>(data[i]) > building[j]) building[j] = get<1>(data[i]);
        }
    }
    cout << endl;
    int startP = get<0>(data[0]), endP = 0;
    int height = 0;
    cout << startP << " ";
    for(int k=startP; k< maxP;) {
        cout << building[k] - height << " ";
        height = building[k];
        while(building[k] == height) k++;
        endP = k;
        cout << endP - startP << " ";
        startP = endP;
    }
    cout << -1*building[maxP-1];
}


int main() {
    int n;
    cin >> n;
    vector <tuple<int, int, int>> apart;
    int maxP = makeData(apart, n);
    sort(apart.begin() , apart.end());
    draw(apart, n, maxP);
}
