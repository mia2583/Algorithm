#include <bits/stdc++.h>
using namespace std;

int data(map<set<int>, set<int, greater<int>> > &gbic) {
    char cmd; int id, syndrome;
    cin >> cmd;
    set<int> genetic;
    map < char, int> mode = {{'R',1}, {'Q', 2}, {'$',3} };

    while (true) {
        switch(mode[cmd]) {
        case 1:
            genetic.clear();
            cin >> id;
            while(id > 0) {
                genetic.insert(id);
                cin >> id;
            }
            if (gbic.find(genetic) != gbic.end() ) {
                 gbic[genetic].insert(id);
            }
            else {
                set<int, greater<int>> syndrome {id};
                gbic.insert( {genetic, syndrome} );
            }
            break;

        case 2:
            genetic.clear();
            cin >> id;
            while(id > 0) {
                genetic.insert(id);
                cin >> id;
            }
            if (gbic.find(genetic) != gbic.end() ) {
                for(auto s : gbic[genetic]) {
                    cout << s << " ";
                }
                cout <<endl;
            }
            else cout << "None" <<endl;
            break;


        case 3:
            return 0;
        defalut : break;
        }
        cin >> cmd;
    }
}

int main() {
    map< set<int>, set<int, greater<int>> > gbic;
    data(gbic);
    return 0;
}
