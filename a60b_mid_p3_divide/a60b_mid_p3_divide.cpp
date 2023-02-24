#include <iostream>

using namespace std;

int mod = 1997;
int dp[510][510]; //define dp[i][j] is number of pattern that it can be
                  //when we arrange i things to j boxes

int main(){

    int n, k;

    cin >> n >> k;

    //initial
    for( int i = 0 ; i <= n ; i++ ){
        dp[i][1] = 1;
        dp[i][i] = 1;
    }

    for( int i = 1 ; i <= n ; i++ ){
        for( int j = 2 ; j < i ; j++ ){
            // case 1: new thing into one empty box
            //         then we know it have dp[i-1][j-1]
            // case 2: new thing into one of the j box which is always unique
            //         then we know it have dp[i-1][j] * j
            dp[i][j] = ( dp[ i - 1 ][ j - 1 ] + ( dp[ i - 1 ][j] * j % mod )) % mod;
        }
    }

    cout << dp[n][k];

}
