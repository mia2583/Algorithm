#include<bits/stdc++.h>

using namespace std;

typedef map<string, list<string>> m_mafia;

int input(m_mafia &m, map<string, int> &sub) {
   int node =0;
   string boss="", person="";
   cin >> node;
    int n = node -1;
    while (n!=0) {
        cin >> person >> boss;
        if( m.find(boss) != m.end() ) m[boss].push_back(person);
        else m[boss] = list<string> {person};

        if( sub.find(boss) == sub.end() ) sub.insert({boss, 0});
        sub.insert({person, 0});
        n--;
   }
   return node;
}

string findBoss(m_mafia &m, string person) {
    string boss = "";
    for(auto mafia: m ) {
        for(auto p: mafia.second) {
            if( person == p ) { boss = mafia.first; return boss;}
        }
    }
    return person;
}

string findFirst(m_mafia &m) {
    m_mafia::iterator iter = m.begin();
    string boss = iter->first;
    string person = "";
    while(true) {
        person =findBoss(m, boss);
        if(person == boss) break;
        else boss = person;
    }
    return boss;
}

void findLeaf(m_mafia &m, list<string> &leaf) {
    for(auto mafia: m ) {
        for(auto p: mafia.second) {
                if( !m.count(p) ) leaf.push_back(p);
        }
    }
}

int countSub(m_mafia &m, list<string> &leaf, string person) {
    m_mafia::iterator iter = m.find(person);
    int sub = 0;
    if(count(leaf.begin(), leaf.end(), person)) {
        sub = 0;
        return sub;
    }
    for(auto p: iter->second) {
        sub += 1 + countSub(m, leaf, p);
    }
    return sub;
}

int countDepth(m_mafia &m, list<string> &leaf, string person) {
    int d = 1;
    string boss = findFirst(m);
    while(true) {
        person = findBoss(m, person);
        if( boss == person ) break;
        d++;
    }
    return d;
}

void data(m_mafia &m, map<string, int> &sub, map<string, int> &depth, int nodeNum) {
    list<string> leaf;
    findLeaf(m, leaf);
    for(auto p : sub) {
        sub[p.first] = countSub(m, leaf, p.first);
    }
    for(auto p : depth) {
        depth[p.first] = countDepth(m,leaf, p.first);
    }
}

bool cmp(tuple<string, int,int> &a, tuple<string, int,int> &b) {
    if(get<1>(a) == get<1>(b)) {
        if(get<2>(a) == get<2>(b)) {
            return get<0>(a) < get<0>(b);
        }
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) > get<1>(b);
}

void output(map<string, int> &sub, map<string, int> &depth) {
    vector<tuple<string, int, int>> vec;
    for(auto s : sub) {
        vec.push_back(make_tuple(s.first, s.second, depth[s.first]));
    }
    sort(vec.begin(), vec.end(), cmp);
    for(auto v : vec) {
        cout << get<0>(v) << endl;
    }
}

int main() {
    m_mafia m;
    map<string, int> sub;

    int numNode = input(m, sub);
    map<string, int> depth(sub);
    data(m, sub, depth, numNode);

    output(sub, depth);
    return 0;
}
