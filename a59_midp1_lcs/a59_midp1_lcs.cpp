#include <iostream>

using namespace std;

char x[1010], y[1010];
char ans[1010];
int dp[1010][1010];

int main(){

    int n, m;   // size of x, y respectively
    int sz = 0; // answer size
    int i, j;   // counter for x, y respectively

    cin >> n >> m;

    cin >> x >> y;

    for( i = 0 ; i <= n ; i++ ){
        for( j = 0 ; j <= m ; j++ )
            cin >> dp[i][j];
    }

    i = n;
    j = m;

    while( i > 0 && j > 0 ){
        if( x[i-1] == y[j-1] ){
            ans[sz++] = x[i-1];
            i--;
            j--;
        }else if( dp[i][j] == dp[i-1][j] )
            i--;
        else
            j--;
    }

    for( i = sz - 1 ; i >= 0 ; i-- )
        cout << ans[i];


}
