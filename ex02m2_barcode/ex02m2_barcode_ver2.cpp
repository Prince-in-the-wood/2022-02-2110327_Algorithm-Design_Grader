#include <iostream>

using namespace std;

int dp[35][35]; //define dp[i][j] = number of barcode length i that be swapped j time

int main(){

    int n, m, k;

    cin >> n >> m >> k;

    //initial
    for( int i = 0 ; i <= n ; i++ ) // any length swap 0 time = 1 if i <= m else it is 0
        dp[i][0] = ( i <= m ) ? 1: 0;

    for( int j = 0 ; j <= k ; j++ ) //any swap time in length 0 = 0
        dp[0][j] = 0;

    for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= k ; j++ ){
            dp[i][j] = 0;

            for( int k2 = 1 ; k2 <= m && i - k2 >= 0 ; k2++ )
                dp[i][j] += dp[ i - k2 ][ j - 1 ];
        }
    }

    cout << dp[n][k];
}
