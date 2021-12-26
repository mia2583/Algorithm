#include <bits/stdc++.h>
#define BIG(a,b) ((a)>(b))?(a):(b)
#define SMALL(a,b) ((a)>(b))?(b):(a)
using namespace std;

class Pack {
private:
    int width;
    int height;
public:
    void setSize(int w, int h) {
        if(w>=h) {width =w; height = h;}
        else     {width =h; height = w;}
    }
    int getW() {return width;}
    int getH() {return height;}
};

void sortSize(Pack box[]) {
    if(box[1].getW()>box[0].getW()) swap(box[1], box[0]);
    if(box[2].getW()>box[1].getW()) swap(box[2], box[1]);
    if(box[1].getW()>box[0].getW()) swap(box[1], box[0]);
}

void calPrice(Pack box[]) {
    int packW, packH;
    int price, price1, price2, price3, price4, price5;
    packW = BIG( box[0].getW(), box[1].getH() + box[2].getH() );
    packH = box[0].getH() + box[1].getW();
    price1 = packW*packW + packH*packH;

    packW = BIG( box[0].getW(), box[1].getW() + box[2].getH() );
    packH = box[0].getH() + (BIG( box[1].getH(), box[2].getW() ));
    price2 = packW*packW + packH*packH;

    packW = BIG( box[0].getW(), box[1].getW() + box[2].getW() );
    packH = box[0].getH() + (BIG( box[1].getH(), box[2].getH() ));
    price3 = packW*packW + packH*packH;

    packW = box[0].getW() + box[2].getH();
    packH = BIG( box[0].getH() + box[1].getH(), box[2].getW() );
    price4 = packW*packW + packH*packH;

    packW = box[0].getW();
    packH = box[0].getH() + box[1].getH() + box[2].getH();
    price5 = packW*packW + packH*packH;

    price = SMALL(price1, price2);
    price = SMALL(price  , price3);
    price = SMALL(price  , price4);
    price = SMALL(price  , price5);
    cout << price <<endl;
}

int main() {
    int w,h;
    Pack box[3];
    for(int i=0; i<3; i++) {
        cin >> w >>h;
        box[i].setSize(w,h);
    }
    sortSize(box);
    calPrice(box);
}
