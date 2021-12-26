//50Á¡
#include <bits/stdc++.h>
#define SIGN(x) (x<0)?-1:1
using namespace std;

class Cop {
private :
    int x=0; int y=0;
public :
    void setPoint(int x_, int y_) {x=x_, y=y_;}
    int pointX() {return x;}
    int pointY() {return y;}
    void moveX(int walk) {x += walk;}
    void moveY(int walk) {y += walk;}
    bool operator ==(Cop cop) {
        return (this->x == cop.pointX()) && (this->y == cop.pointY());
    }
    int operator -(Cop cop) {
        return abs(x - cop.pointX() + y - cop.pointY());
    }
    void showPoint() {cout << x << " " << y <<endl;}
};

int setData(vector<pair<int, int>> &data, Cop &c1, Cop &c2) {
    int numData;
    int beforeX=0, beforeY=0, x=0, y=0;
    cin >> numData;
    cin >> beforeX >> beforeY;
    c1.setPoint(beforeX, beforeY);
    data.push_back(make_pair(beforeX, beforeY));
    for(int i=1; i< numData; i++) {
        cin >> x >> y;
        if(i == numData/2-1) c2.setPoint(x, y);
        data.push_back(make_pair(x, y));
    }
    return numData;
}

int calPosition(vector<pair<int, int>> &data, int times, int numData, Cop &c1, Cop &c2) {
    int c1Way = 1,  c1Index =1;
    int c2Way = -1, c2Index =numData/2-2;
    int change = 1;

    while(times > 0) {

        if(c1.pointX() ==  data[c1Index].first && c1.pointY() ==  data[c1Index].second )  {
            c1Index = (c1Index + c1Way)%numData;
            if(c1Index < 0) c1Index += numData;
        }

        if(c1.pointX() != data[c1Index].first ) c1.moveX(SIGN( data[c1Index].first-c1.pointX() ));
        else                                                       c1.moveY((SIGN( data[c1Index].second-c1.pointY() )));

        if(c2.pointX() ==  data[c2Index].first && c2.pointY() ==  data[c2Index].second ) {
            c2Index = (c2Index + c2Way)%numData;
            if(c2Index < 0) c2Index += numData;
        }

        if(c2.pointX() != data[c2Index].first ) c2.moveX(SIGN( data[c2Index].first-c2.pointX() ));
        else                                                       c2.moveY((SIGN( data[c2Index].second-c2.pointY() )));

        if(c1 - c2 ==1) change *=-1;
        if(c1==c2&&abs(c1Index - c2Index)<=1) change *=-1;
        times--;
    }
    return change;
}

int  main() {
    vector<pair<int, int>> data;
    int time, numData, change;
    Cop c1,c2;
    numData = setData(data, c1, c2);
    cin >> time;
    change =  calPosition(data, time, numData, c1, c2);
    if(change = 1) {c1.showPoint(); c2.showPoint();}
    else                  {c2.showPoint(); c1.showPoint();}
    return 0;
}
