#include<bits/stdc++.h>

#define INF 9999999

using namespace std;

const int MAX = 1e6+10;

int n;
int a[MAX];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    int deepest = -INF;
    int highest = -INF;
    for(int i = 2; i <= n-1; i++) {
        // n?u i là thung lung
        if(a[i] < a[i-1] && a[i] < a[i+1]) {
            int deep = 0;
            int flagL = 0, flagR = 0;
            for(int j = i-1; j >= 1; j--) {
                if(a[j] <= a[j+1]) {
                    flagL = j+1; break;
                }
                if(j == 1) flagL = 1;
            }
            for(int j = i+1; j <= n; j++) {
                if(a[j] <= a[j-1]) {
                    flagR = j-1; break;
                }
                if(j == n) flagR = n;
            }
            deep = min(i - flagL, flagR - i);
            deepest = max(deepest, deep);
        }

        // n?u i là d?nh d?i
        if(a[i] > a[i-1] && a[i] > a[i+1]) {
            int high = 0;
            int flagL = 0, flagR = 0;
            for(int j = i-1; j >=1; j--) {
                if(a[j] >= a[j+1]) {
                    flagL = j+1; break;
                }
                if(j == 1) flagL = 1;
            }
            for(int j = i+1; j <= n; j++) {
                if(a[j] >= a[j-1]) {
                    flagR = j-1; break;
                }
                if(j == n) flagR = n;
            }
            high = min(i - flagL, flagR - i);
            highest = max(highest, high);
        }
    }
    if(highest == -INF) highest = 0;
    if(deepest == -INF) deepest = 0;
    cout << highest << " " << deepest << '\n';

    return 0;
}

