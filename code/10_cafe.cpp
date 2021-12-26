#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> intPair;

queue<int> dataInput (int numSeat) {
    int numRecord, customerID;
    queue<int> records;
    cin >> numRecord;
    while(numRecord >0 ) {
        cin >> customerID;
        records.push(customerID);
        numRecord--;
    }
    return records;
}

bool compare (intPair a, intPair b) {
    return a.second < b.second;
}


int minSeatId (int startSeat, int maxDistance, int numSeat) {
    int minId1, minId2, addDistance;
    if(maxDistance%2 == 1) {
        minId1 = startSeat + maxDistance/ 2;
        minId2 = startSeat + maxDistance/ 2 + 1;
        if ( minId2 > numSeat ) minId1 = minId2;
    }
    else minId1 = startSeat + maxDistance/ 2;
    if (minId1 > numSeat) minId1 %= numSeat;
    return minId1;
}

int findMaxDistance (vector<intPair> &seated, int numSeat) {
    int maxDistance =0, distance=0, seatIndex = 0;
    for(int j = seated.size() - 1; j>=0; --j) {
        if( j == seated.size() - 1 ) distance = seated[0].second + numSeat -  seated[j].second;
        else distance = seated[ j + 1 ].second - seated[j].second;
        if( maxDistance <= distance) { maxDistance = distance; seatIndex = j; }
    }
    return minSeatId(seated[seatIndex].second, maxDistance, numSeat);
}

int checkOverlap (int id, vector<intPair> &seated) {
    int index=0;
    for(int i=0; i< seated.size(); i++) {
        if( id == seated[i].first ) index = i + 1; //bool 역할과 index역할을 모두 하기 위해서 1을 더해줌
    }
    return index;
}

void makeSeat (queue<int> &records, int numSeat) {
    vector<intPair> seated;
    int index=0, seatId;
    while(records.size() > 0) {
        if(seated.size() == 0) {
            seated.push_back( make_pair(records.front(), 1) );
            cout << records.front() << " 1" << endl;
            records.pop(); continue;
        }
        //나가는 손님인지 확인
        if( index = checkOverlap( records.front(), seated ) )  { seated.erase( seated.begin() + index-1 ); records.pop(); }
        else {
            seatId = findMaxDistance(seated, numSeat);
            cout << records.front() << " " << seatId << endl;
            seated.push_back( make_pair(records.front(), seatId) );
            sort(seated.begin(), seated.end(), compare);
            records.pop();
        }
    }
}

int main() {
    int numSeat;
    cin >> numSeat;
    queue<int> records = dataInput(numSeat);
    makeSeat(records, numSeat);
    return 0;
}