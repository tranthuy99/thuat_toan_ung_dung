#include<bits/stdc++.h>
using namespace std;
 
int a,b,c,d[2000][2000];
pair<int ,int> trace[1000][1000];
 
queue<pair<int, int> > q;
 
void ins(int x, int y, int dadx, int dady)
{
    if (x < 0 || y < 0 || x > a || y > b) return;
    if (d[x][y] == 1) return;
    trace[x][y] = {dadx, dady};
    q.push({x, y});
}
 
int main(){
    
    cin >> a >> b >> c;
    q.push({0, 0});
    d[0][0] = 1;
    int k = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        d[x][y] = 1;
        if(x == c || y == c ){
           
           while(x != 0 || y != 0)
           {
               k++;
               pair<int, int> tmp = trace[x][y];
               x = tmp.first;
               y = tmp.second;
           }
        cout << k << endl;
           return 0;
        }
        q.pop();
        ins(x, 0, x, y);
        ins(x, b, x, y);
        ins(0, y, x, y);
        ins(a, y, x, y);
        ins(x + y, 0, x, y);
        ins(0, x + y, x, y);
        ins(a, y - (a - x), x, y);
        ins(x - (b - y), b, x, y);
    }
    cout << "-1" << endl;
 
    return 0;
}
