#include <bits/stdc++.h>

using namespace std;
vector <int> balls;

int main() {
    int i, 
    check, 
    flag, 
    num,
    count = -1;
    
    cin >> i;

    while(i--) {
        count++;
        cin >> num;
        balls.push_back(num);

        flag = 1;
        
        for(check = 1 ; check < num ; check++) {
            if(check > count || balls.at(count - check) != num) {
                flag = 0;
                break;
            }
        }

        if(flag) {
            balls.erase(balls.end() - check, balls.end());
            count = count - num;
        }
        cout << balls.size() << endl;
    }
    
    return 0;
}