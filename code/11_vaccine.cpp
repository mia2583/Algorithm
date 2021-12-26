#include <bits/stdc++.h>

using namespace std;

void inputData(vector< tuple<int, int, char> > &vacList) {
    int numData, id, age;
    char sex;
    cin >> numData;
    while(numData) {
        cin >> id >> age >> sex;
        vacList.push_back( make_tuple(id, age, sex) );
        numData--;
    }
}

void Vaccine(vector< tuple<int, int, char> > &vacList) {
    queue<int> child, adultM, adultF, oldF, oldM;
    for(auto v: vacList) {
        if( get<1>(v) < 16 ) child.push( get<0>(v) );
        else if(get<1>(v) > 60) {
            if(get<2>(v) =='F') oldF.push( get<0>(v) );
            else oldM.push( get<0>(v) );
        }
        else {
            if(get<2>(v) =='F') adultF.push( get<0>(v) );
            else adultM.push( get<0>(v) );
        }
    }
   while(oldM.size() >0) {
        cout << oldM.front() << endl;
        oldM.pop();
    }
    while(oldF.size() >0) {
        cout << oldF.front() << endl;
        oldF.pop();
    }
    while(child.size() >0) {
        cout << child.front() << endl;
        child.pop();
    }
    while(adultF.size() >0) {
        cout << adultF.front() << endl;
        adultF.pop();
    }
    while(adultM.size() >0) {
        cout << adultM.front() << endl;
        adultM.pop();
    }
}

int main() {
    vector< tuple<int, int, char> > vacList;
    inputData(vacList);
    Vaccine(vacList);
}

