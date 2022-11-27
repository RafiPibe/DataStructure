#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <string.h>
using namespace std;

int main() {
    int input;
    cin >> input;
    vector<string> stackarr{"home", "anton"};

    while (input--) {
        string command;
        string a;

        cin >> command;

        if (command == "goto") {
            cin >> a;
            stackarr.push_back(a);
        }
        else if (command == "goback") {
            if(!stackarr.empty()) {
                stackarr.pop_back();
            }
            else cout << "cannot go back\n";
        }
        else if (command == "whereami") {
            if(!stackarr.empty()) {
                for (int j = 0; j < stackarr.size() - 1; j++) {
		            cout << stackarr[j] << "/";
            }
            cout << stackarr.back() << endl;
            }
            else cout << "i am nowhere\n";
        }
        else cout << "Query not found\n";
    }
}
