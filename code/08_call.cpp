#include <bits/stdc++.h>

using namespace std;

class CallFunction {
private :
    char name;
    vector<string> words;
    int wordsSize = 0;
public:
    void setWords(string wordIn) {
        words.push_back(wordIn);
        wordsSize++;
    }
    string showVec(int index) {return words[index];}
    void setName(char nameIn) {name = nameIn;}
    char showName() {return name;}
    int showSize() {return wordsSize;}
};

void setData(CallFunction func[], map<char, int>& functionsIndex, int numData) {
    char functionName;
    string stringIn;
    for(int i =0; i < numData; i++) {
        cin >> functionName;
        func[i].setName(functionName);
        functionsIndex.insert( make_pair(functionName, i) );
        while(cin >> stringIn) {
            if(stringIn == "$") break;
            else func[i].setWords(stringIn);
        }
    }
}

bool checkInfinite(vector<pair<char, int>>functionRunning) {
    for(auto j=functionRunning.begin(); j<functionRunning.end() - 1; j++ )
        if(j->first == functionRunning.back().first) return true;
    return false;
}

void findExcution(CallFunction func[], map<char, int>& functionsIndex, int limit1, int limit2) {
    vector<pair<char, int>> functionRunning;
    char now = func[0].showName();
    string nowWord = "";
    int index = 0, funcIndex = functionsIndex[now], time=0;
    string limit1Func = ""; string limit2Func = "";

    while( !functionRunning.empty() || index < func[ funcIndex ].showSize() ) {
        while(index >= func[ funcIndex ].showSize()) {
            now =  functionRunning.back().first;
            funcIndex  = functionsIndex[ now ];
            index = functionRunning.back().second + 1;
            functionRunning.pop_back();
            if(functionRunning.empty() && index >= func[ funcIndex ].showSize()) break;
        }
        if(functionRunning.empty() && index >= func[ funcIndex ].showSize()) continue;
        if(func[ funcIndex ].showVec(index)[0] >= 'A' && func[ funcIndex ].showVec(index)[0] <= 'Z') {
            functionRunning.push_back( make_pair(func[funcIndex].showName(), index) );
            nowWord = func[ funcIndex ].showVec(index)[0];
            now = nowWord[0];
            funcIndex  = functionsIndex[ now ];
            index = 0;
            if( checkInfinite(functionRunning) ) {
                    cout<< "DEADLOCK" <<endl; return;
            }
            continue;
        }

        nowWord = func[ funcIndex ].showVec(index);
        index++;
        time++;

        if( time == limit1 ) {
            limit1Func = now; limit1Func  += "-"; limit1Func += nowWord;}
        if( time == limit2 ) {
             limit2Func = now; limit2Func  += "-"; limit2Func += nowWord;}
    }
    if(limit1Func =="") limit1Func = "NONE";
    if(limit2Func =="") limit2Func = "NONE";
    cout << limit1Func << "\n" << limit2Func <<endl;
}

int main() {
    map<char, int> functionsIndex;
    int numData = 0;
    int time1, time2;
    cin >> numData;
    CallFunction functions[numData];
    cin >> time1 >> time2;
    setData(functions, functionsIndex, numData);
    findExcution(functions, functionsIndex, time1, time2);
    return 0;
}
