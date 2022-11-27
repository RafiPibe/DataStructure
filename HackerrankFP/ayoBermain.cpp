#include <bits/stdc++.h>

using namespace std;

vector <int> p1Move;
vector <int> p2Move;
vector <int> p3Move;
vector <int> p4Move;
vector <int> tempMove;

vector<string> lost;

int main() {
    string p1;
    string p2;
    string p3;
    string p4;
    string pSeek;
    
    int p1Stat = 1;
    int p2Stat = 1;
    int p3Stat = 1;
    int p4Stat = 1;
    
    int step;
    int playerMove;
    int nextArea;
    int pSeekFix;
    int rest;

    cin >> p1;
    cin >> p2; 
    cin >> p3;
    cin >> p4;
    cin >> step;
    cin >> pSeek;

    if(pSeek.compare(p1) == 0) {
        pSeekFix = 1;
    }
    else if(pSeek.compare(p2) == 0) {
        pSeekFix = 2;
    }
    else if(pSeek.compare(p3) == 0) {
        pSeekFix = 3;
    } else {
        pSeekFix = 4;
    }

    while(step--) {
        cin >> playerMove;
        cin >> nextArea;

        if(playerMove == pSeekFix) {
            tempMove.push_back(nextArea);
        } else {
            if(playerMove == 1){
                p1Move.push_back(nextArea);
            }
            else if(playerMove == 2){
                p2Move.push_back(nextArea);
            }
            else if(playerMove == 3){
                p3Move.push_back(nextArea);
            }
            else{
                p4Move.push_back(nextArea);
            }
        }
    }

    for(unsigned long i = 0 ; i < tempMove.size() ; i++) {
        if(p1Stat && pSeekFix != 1 && i < p1Move.size() && tempMove.at(i) == p1Move.at(i)){
            p1Stat = 0;
        }
        else if(p2Stat && pSeekFix != 2 && i < p2Move.size() && tempMove.at(i) == p2Move.at(i)){
            p2Stat = 0;
        }
        else if(p3Stat && pSeekFix != 3 && i < p3Move.size() && tempMove.at(i) == p3Move.at(i)){
            p3Stat = 0;
        }
        else if(p4Stat && pSeekFix != 4 && i < p4Move.size() && tempMove.at(i) == p4Move.at(i)){
            p4Stat = 0;
        }
    }

    if(pSeekFix != 4 && !p4Stat){
        lost.push_back(p4);
    }
    if(pSeekFix != 3 && !p3Stat){
        lost.push_back(p3);
    }
    if(pSeekFix != 2 && !p2Stat){
        lost.push_back(p2);
    }
    if(pSeekFix != 1 && !p1Stat){
        lost.push_back(p1);
    }
    
    
    if(lost.empty()) {
        cout << pSeek << " jaga lagi";
    }
    else if(!lost.empty()) {
       rest = lost.size(); 
       
       for(int i = 0 ; i < rest ; i++) {
            cout << lost.back();
            if(i == rest - 2){
                cout << ", dan ";
            }
            else if(i == rest - 1) {
                cout << " ditangkap oleh " << pSeek;
            } else {
                cout << ", ";
            }
            lost.pop_back();
       }
    }
}