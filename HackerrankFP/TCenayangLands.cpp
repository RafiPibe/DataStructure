#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
int n;
int x[305], y[305];
int mn = INF;
int counter;

int ar(int xa, int ya,int xb, int yb, int xc, int yc) {
    return abs (xa * yb - xb * ya + xb * yc - xc * yb + xc * ya - xa * yc) ;
}

int main () {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    
    for (int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                int are= ar(x [i], y[i], x[j], y[j], x[k], y[k]) ;

                if(are != 0) {
                    if (mn == are){
                        counter++;
                    } else if (mn > are) {
                        mn = min(mn, are);
                        counter = 1;
                    }
                }
            }
        }
    }

    if (mn == INF || counter > 1) {
        cout << "-1.00\n";
    } else {
        cout << mn / 2 << "." << 5 * (mn % 2) << "0\n";
    }
}