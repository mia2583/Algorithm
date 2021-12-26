#include<bits/stdc++.h>

using namespace std;
/*ifstream in("/NESPA/sapiens.txt");

vector ops = {"front", "back", "cut", "double", "flip","report"};
cin << op ;
idx = find(ops.begin(), ops.end(), op) - ops.begin();*/

/*void readFile(list<char>& dna) {
    ifstream in("sampledata13/sapiens.txt");
    string s;
    in.seekg(0, ios::end);
    int length = in.tellg();
    s.resize(length);
    in.seekg(0, ios::beg);
    in.read(&s[0], length);
    dna.resize(length);
    for(char c : s)
        //if(c!='\n') dna.push_back(c);
        cout << c;
    cout << dna.size();
}*/

void readFile(list<char>& dna) {
    ifstream in("sampledata13/sapiens_small/sapiens.txt");
    char c;
    char buf[100];
    in.getline(buf, 100);
    while(in.get(c))
        if(c!='\n')
            dna.push_back(c);
    cout << dna.size()<<endl;
    /*for (const auto &i : dna) {
        cout << i;
    }*/
}

void funcFront(list<char>& dna, int from, int to) {
    list<char>::iterator iterA = dna.begin(), iterB = dna.begin();
    advance(iterA, from - 1);
    advance(iterB, to);
    dna.splice(dna.begin(), dna, iterA, iterB);
}

void funcBack(list<char>& dna, int from, int to) {
    list<char>::iterator iterA = dna.begin(), iterB = dna.begin();
    advance(iterA, from - 1);
    advance(iterB, to);
    dna.splice(dna.end(), dna, iterA, iterB);
}

void funcCut(list<char>& dna, int from, int to) {
    list<char>::iterator iterA = dna.begin(), iterB = dna.begin();
    advance(iterA, from - 1);
    advance(iterB, to);
    dna.erase(iterA, iterB);
}

void funcDouble(list<char>& dna, int from, int to) {
    list<char>::iterator iterA = dna.begin(), iterB = dna.begin();
    advance(iterA, from - 1);
    advance(iterB, to+1);
    dna.insert(iterB, iterA, --iterB);
}

void funcFlip(list<char>& dna, int from, int to) {
    list<char>::iterator iterA = dna.begin(), iterB = dna.begin();
    list<char> forReverse;
    advance(iterA, from - 1);
    advance(iterB, to);
    reverse(iterA, iterB);
}

void funcReport(list<char>& dna, int from, int to) {
    cout << dna.size() << endl;
    list<char>::iterator iterA = dna.begin(), iterB = dna.begin();
    if(from > dna.size()) iterA = dna.end();
    else advance(iterA, from - 1);
    if(to >dna.size()) iterB = dna.end();
    else advance(iterB, to);

    if(iterA==dna.end() && iterB==dna.end()) cout << "NONE"<<endl;
    else
        while(iterA!=iterB) {
            cout <<*iterA;
            iterA++;
        }
}

void action(list<char>& dna) {
    int actionNum, i, j, idx;
    string op;
    vector<string> ops = {"front", "back", "cut", "double", "flip","report"};
    cin >> actionNum;
    while(actionNum--) {
        cin >> op;
        cin >> i >> j;
        idx = find(ops.begin(), ops.end(), op) - ops.begin();
        switch(idx) {
            case 0: funcFront(dna,i,j);     break;
            case 1: funcBack(dna,i,j);     break;
            case 2: funcCut(dna,i,j);       break;
            case 3: funcDouble(dna,i,j); break;
            case 4: funcFlip(dna,i,j);        break;
            case 5: funcReport(dna,i,j);  break;
            default : break;
        }
        /*for (const auto &i : dna) {
            cout << i;
        }*/
    }
}

int main() {
    list<char> dna;
    readFile(dna);
    cout << dna.size()<<endl;
    action(dna);
    return 0;
}
