#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int main(){
    ull num;
    set<ull> s;

    while(scanf("%llu",&num)!=EOF) {
        if(s.count(num)) {
                int x = num % 10001;
                int ans = 7312;
                if(x < ans) printf("<\n");
                if(x == ans) printf("==\n");
                if(x > ans) printf(">\n");
        }

        else s.insert(num);
    }

    return 0;
}