#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> h;
    int h_input;
    while(cin>>h_input) {
        h.push_back(h_input);
    }
    for(int i=0; i<h.front()+1; i++) {
        while(h.back()-i==0) h.pop_back();
        cout<< h.size() << " ";
    }
    return 0;
}
