#include <bits/stdc++.h>

using namespace std;

void inQTS(string &qts) {
    cin >> qts;
}

void inIMG(vector<vector<int>> &img, int k) {
    int vecSize = pow(2, k);
    string val="";
    for(int i=0; i<vecSize; i++) {
        cin >> val;
        for(int j=0; j <vecSize; j++) {
            img[i][j] = int(val[j]) - int('0');
        }
    }
}

void change(vector<vector<int>> &img, int x, int y, int length) {
    for(int i=y; i<y+length; i++) {
        for(int j = x-length; j <x; j++) {
            img[i][j] = 1;
        }
    }
}

void makeIMG(string &qts, vector<vector<int>> &img, int x, int y, int length) {
    if(qts[0] == '1') {
        change(img, x, y, length);
        qts = qts.substr(1);
    }
    else if(qts[0] == '(') {
        qts = qts.substr(1);
        makeIMG(qts, img, x, y, length/2);
        makeIMG(qts, img, x-length/2, y, length/2);
        makeIMG(qts, img, x-length/2, y+length/2, length/2);
        makeIMG(qts, img, x,  y+length/2, length/2);
    }
    else if(qts[0] == ')') {
        qts = qts.substr(1);
        makeIMG(qts, img, x, y, length);
    }
    else {
        qts = qts.substr(1);
    }
}

int allSame(string &qts, vector<vector<int>> &img, int x, int y, int length) {
    int same = img[y][x-length];
    for(int i=y; i<y+length; i++) {
        for(int j = x-length; j <x; j++) {
            if(same != img[i][j]) return -1;
        }
    }
    return same;
}

void makeQTS(string &qts, vector<vector<int>> &img, int x, int y, int length) {
    int same = allSame(qts, img, x, y, length);
    if(same != -1) {
        qts += to_string(same);
    }
    else {
        qts += "(";
        makeQTS(qts, img, x, y, length/2);
        makeQTS(qts, img, x-length/2, y, length/2);
        makeQTS(qts, img, x-length/2, y+length/2, length/2);
        makeQTS(qts, img, x,  y+length/2, length/2);
        qts += ")";
    }
}

void outQTS(string &qts) {
    cout << qts<<endl;
}

void outIMG(vector<vector<int>> &img) {
   for(auto c: img) {
        for(auto l : c) cout << l ;
        cout << endl;
   }
}

void data(vector<vector<int>> &img, int k) {
    string type; map <string, int> m = {{"QTS", 0}, {"IMG", 1}};
    string qts; int vecSize = pow(2, k);
    cin >> type;
    switch(m[type]) {
        case 0 : {
            inQTS(qts);
            makeIMG(qts, img, vecSize, 0, vecSize);
            outIMG(img);
            break;
        }
        case 1 : {
            inIMG(img, k);
            makeQTS(qts, img, vecSize, 0, vecSize);
            outQTS(qts);
            break;
        }
        default : break;
    }
}

int main() {
    int k;
    cin >> k;
    int vecSize = pow(2, k);
    vector<vector<int>> img(vecSize, vector<int>(vecSize, 0));
    data(img, k);
    return 0;
}
