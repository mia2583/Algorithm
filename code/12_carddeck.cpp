
//time out
#include <bits/stdc++.h>

using namespace std;

int dataInput(list<int> &deck) {
    int numCard=0, trial=0, i=1;
    cin >> numCard >> trial;
    if(numCard%2) return 0;
    while(numCard--) {
        deck.push_back(i++);
    }
    return trial;
}

void shuffle(list<int> &deck) {
    list<int> newDeck;
    int deckSize=deck.size();
    list<int>::iterator iterA = deck.begin(), iterB = deck.begin();
    advance( iterB, deckSize/2 );
    while(newDeck.size() < deckSize) {
        newDeck.push_back( *iterA );
        newDeck.push_back( *iterB );
        iterA++; iterB++;
    }
    deck.swap(newDeck);
}

void cut(list<int> &deck, int from, int to) {
    list<int>::iterator iterA = deck.begin(), iterB = deck.begin();
    advance(iterA, from - 1);
    advance(iterB, to);
    deck.splice(deck.end(), deck, iterA, iterB);
}

void action(list<int> &deck, int trial) {
    string act;
    map<string, int> actionMap = { {"Shuffle", 1}, {"Cut", 2} };
    while(trial--) {
        cin >> act;
        if( actionMap.find(act) == actionMap.end() ) continue;
        switch(actionMap[act]) {
            case 1 : shuffle(deck); break;
            case 2 : {
                int from=0, to=0;
                cin >> from >> to;
                cut(deck, from, to); break;
            }
            default : break;
        }
    }
}


void printResult(list<int> &deck) {
    list<int>::iterator iter = deck.begin();
    advance(iter, deck.size()/2 - 1);
    cout << deck.front() << " " << *iter << " " << deck.back();
}

int main() {
    list <int> deck;
    int trial = dataInput(deck);
    action(deck, trial);
    printResult(deck);
}


//너무 느림
#include <bits/stdc++.h>

using namespace std;

int dataInput(list<int> &deck) {
    int numCard=0, trial=0, i=1;
    cin >> numCard >> trial;
    if(numCard%2) return 0;
    while(numCard--) {
        deck.push_back(i++);
    }
    return trial;
}

void shuffle(list<int> &deck) {
    int deckSize=deck.size(), j=deckSize/2;
    list<int>::iterator iterA = deck.begin(), iterB = deck.begin();
    iterA++;
    advance( iterB, deckSize/2 );
    while( iterB != deck.end() ) {
        deck.splice(iterA, deck, iterB);
        iterA++;
        advance(iterB, j);
        j--;
    }
}

void cut(list<int> &deck, int from, int to) {
    list<int>::iterator iterA = deck.begin(), iterB = deck.begin();
    advance(iterA, from - 1);
    advance(iterB, to);
    deck.splice(deck.end(), deck, iterA, iterB);
}

void action(list<int> &deck, int trial) {
    string act;
    map<string, int> actionMap = { {"Shuffle", 1}, {"Cut", 2} };
    while(trial--) {
        cin >> act;
        if( actionMap.find(act) == actionMap.end() ) continue;
        switch(actionMap[act]) {
            case 1 : shuffle(deck); break;
            case 2 : {
                int from=0, to=0;
                cin >> from >> to;
                cut(deck, from, to); break;
            }
            default : break;
        }
    }
}

void printResult(list<int> &deck) {
    list<int>::iterator iter = deck.begin();
    advance(iter, deck.size()/2 - 1);
    cout << deck.front() << " " << *iter << " " << deck.back();
}

int main() {
    list <int> deck;
    int trial = dataInput(deck);
    action(deck, trial);
    printResult(deck);
}


//slow2
#include <bits/stdc++.h>

using namespace std;

int dataInput(list<int> &deck) {
    int numCard=0, trial=0;
    cin >> numCard >> trial;
    if(numCard%2) return 0;
    for(int i=0; i <numCard; i++) {
        deck.push_back(i);
    }
    return trial;
}

void shuffle(list<int> &deck) {
    list<int> newDeck;
    int deckSize=deck.size();
    list<int>::iterator iterA = deck.begin(), iterB = deck.begin();
    advance( iterB, deckSize/2 );
    while(newDeck.size() < deckSize) {
        newDeck.push_back( *iterA );
        newDeck.push_back( *iterB );
        iterA++; iterB++;
    }
    deck.swap(newDeck);
}

void cut(list<int> &deck, int from, int to) {
    list<int>::iterator iterA = deck.begin(), iterB = deck.begin();
    advance(iterA, from - 1);
    advance(iterB, to);
    deck.splice(deck.end(), deck, iterA, iterB);
}

void action(list<int> &deck, int trial) {
    string act;
    map<string, int> actionMap = { {"Shuffle", 1}, {"Cut", 2} };
    while(trial--) {
        cin >> act;
        if( actionMap.find(act) == actionMap.end() ) continue;
        switch(actionMap[act]) {
            case 1 : shuffle(deck); break;
            case 2 : {
                int from=0, to=0;
                cin >> from >> to;
                cut(deck, from, to); break;
            }
            default : break;
        }
    }
}


void printResult(list<int> &deck) {
    list<int>::iterator iter = deck.begin();
    advance(iter, deck.size()/2 - 1);
    cout << deck.front() << " " << *iter << " " << deck.back();
}

int main() {
    list <int> deck;
    int trial = dataInput(deck);
    action(deck, trial);
    printResult(deck);
}


//slow3

#include <bits/stdc++.h>

using namespace std;

int dataInput(list<int> &deck) {
    int numCard=0, trial=0;
    cin >> numCard >> trial;
    if(numCard%2) return 0;
    for(int i=1; i <=numCard; i++) {
        deck.push_back(i);
    }
    return trial;
}

void shuffle(list<int> &deck) {
    list<int> newDeck;
    int deckSize=deck.size();
    list<int>::iterator iterA = deck.begin();
    advance( iterA, deckSize/2 );
    newDeck.splice(newDeck.end(), deck, deck.begin(), iterA);
    iterA = deck.begin();
    list<int>::iterator iterB = newDeck.begin();
    iterB++;
    while(newDeck.size() < deckSize) {
        newDeck.insert(iterB, *iterA);
        iterA++; iterB++;
    }
    deck.swap(newDeck);
}

void cut(list<int> &deck, int from, int to) {
    list<int>::iterator iterA = deck.begin(), iterB = deck.begin();
    advance(iterA, from - 1);
    advance(iterB, to);
    deck.splice(deck.end(), deck, iterA, iterB);
}

void action(list<int> &deck, int trial) {
    string act;
    map<string, int> actionMap = { {"Shuffle", 1}, {"Cut", 2} };
    while(trial--) {
        cin >> act;
        if( actionMap.find(act) == actionMap.end() ) continue;
        switch(actionMap[act]) {
            case 1 : shuffle(deck); break;
            case 2 : {
                int from=0, to=0;
                cin >> from >> to;
                cut(deck, from, to); break;
            }
            default : break;
        }
    }
}


void printResult(list<int> &deck) {
    list<int>::iterator iter = deck.begin();
    advance(iter, deck.size()/2 - 1);
    cout << deck.front() << " " << *iter << " " << deck.back();
}

int main() {
    list <int> deck;
    int trial = dataInput(deck);
    action(deck, trial);
    printResult(deck);
}
