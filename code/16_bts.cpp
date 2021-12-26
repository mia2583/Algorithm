#include <bits/stdc++.h>

using namespace std;

int findLocation(map<int, string> &bts, string node) {
    int num =1;
    map<int, string>::iterator iter = bts.begin();
    while( bts.find(num) != bts.end() ) {
        if(bts[num] < node) num += num + 1;
        else if(bts[num] > node) num += num;
        else break;
    }
    return num;
}

void add(map<int, string> &bts, string node) {
    int num = findLocation(bts, node);
    bts.insert({num, node});
}

int findLast(map<int, string> &bts, int num) {
    int nextNum = num + num;
    if( bts.find(nextNum) != bts.end() ) {
        num = nextNum;
        nextNum += nextNum + 1;
        while( bts.find(nextNum) != bts.end() ) {
            num = nextNum;
            nextNum += nextNum + 1;
        }
        return num;
    }
    else if( bts.find(nextNum+1) != bts.end() ) {
        num = nextNum+ 1;
        nextNum += nextNum + 1;
        while( bts.find(nextNum) != bts.end() ) {
            num = nextNum;
            nextNum += nextNum;
        }
        return num;
    }
    return num;
}

void findLeaf(int root, map<int, string> &bts, vector<string> &leaf) {
    int more = 0;
    if( bts.find(root+root) != bts.end() ) {more++; findLeaf(root+root, bts, leaf); }
    if( bts.find(root+root+1) != bts.end() ) {more++;findLeaf(root+root+1, bts, leaf); }
    if ( more==0 ) { leaf.push_back(bts[root]); return;}
}

void printLeaf(map<int, string> &bts) {
    map<int, string>::iterator iter = bts.begin();
    vector<string> leaf;
    findLeaf(1, bts, leaf);
    sort(leaf.begin(), leaf.end());
    for(auto v : leaf)
        cout << v << " ";
    cout << endl;
}


void diff(map<int, string> &bts, string node) {
    int num = findLocation(bts, node);
    int deleteK = findLast(bts, num);
    if( bts.find(deleteK) == bts.end() ) return;
    vector<string> leaf;
    findLeaf(1, bts, leaf);
    while( find(leaf.begin(), leaf.end(), bts[num] ) == leaf.end() ) {
        if( bts.find(deleteK) == bts.find(num) ) break;
        bts[num] = bts[deleteK];
        num = deleteK;
        deleteK = findLast(bts, num);
    }
    bts.erase(deleteK);
}

void printDepth(map<int, string> &bts) {
    int k; vector<string> depthK;
    cin >> k;
    for(int i=pow(2,k-1); i< pow(2,k); i++) {
        if( bts.find(i) != bts.end() ) depthK.push_back(bts[i]);
    }
    sort(depthK.begin(), depthK.end());
    for(auto d : depthK)
        cout << d << " ";
    cout << endl;
}

void input(map<int, string> &bts, map<string, int> &op) {
    string operation, node;
    cin >> operation;
    while(operation != "quit") {
        switch(op[operation]) {
        case 0 : { cin >> node; add(bts, node); break; }
        case 1 : { cin >> node; diff(bts, node); break; }
        case 2 : { printDepth(bts); break;}
        case 3 : { printLeaf(bts); break; }
        default : cout << "no operation" <<endl; break;
        }
        cin >> operation;
    }
}

int main() {
    map<int, string> bts;
    map<string, int> op = {{"+", 0}, {"-", 1}, {"depth", 2}, {"leaf", 3}};
    input(bts, op);
    return 0;
}
