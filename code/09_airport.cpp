#include <bits/stdc++.h>

using namespace std;

class AirLine {
private:
    queue<int> ids;
public:
    void addId(int id) {ids.push(id);}

    void popId() {
        ids.pop();
    }
    int frontId() {
        return ids.front();
    }

    bool isEmpty() {
        return ids.empty();
    }
};

vector<AirLine> getAirport() {
    int numLine, airplaneId, i=0;
    cin >> numLine;
    vector<AirLine> airport(numLine);

    while(i<numLine) {
        cin>> airplaneId;
        if(airplaneId == 0) {i++; continue;}
        airport.at(i).addId(airplaneId);
    }
    return airport;
}

void printAirport(vector<AirLine>& airport, int minLine) {
    for(int j=0; j< airport.size(); j++) {
        if(airport[j].isEmpty()) continue;
        else if( airport[minLine].frontId() > airport[j].frontId() ) minLine = j;
    }
    cout << airport[minLine].frontId() << endl;
    airport[minLine].popId();
}

int main() {
    vector<AirLine> airport;
    airport = getAirport();
    int start =0;
    while(start < airport.size()) {
        while(airport[start].isEmpty()) {start++;}
        if (start >= airport.size() ) break;
        printAirport(airport, start);
    }
    return 0;
}
