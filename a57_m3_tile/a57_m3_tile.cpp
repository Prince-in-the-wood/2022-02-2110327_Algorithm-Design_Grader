#include <iostream>

using namespace std;

int dp[15][10010]; // define dp[i][j] is the minimum price we have to pay for area j with i tile
int tile[15];

int price( int a, int b ){

    int dif = a - b;
    return dif * dif;
}

int main(){

    int n, m;

    cin >> n >> m;

    for( int i = 1 ; i <= n ; i++ )
        cin >> tile[i];

    //set initial
    for( int i = 0 ; i <= n ; i++ )
        dp[i][0] = -1;

    for( int j = 0 ; j <= m ; j++ )
        dp[0][j] = -1;
    dp[0][0] = 0;

    for( int i = 1 ; i <= n ; i++ ){

        for( int j = 1 ; j <= m ; j++ ){
            dp[i][j] = -1;

            for( int k = 1 ; k <= 100 && j - k*k >= 0 ; k++ ){

                if( dp[i-1][ j - k*k ] != -1 ){
                    int value = dp[i-1][j-k*k] + price( tile[i], k );
                    dp[i][j] = ( dp[i][j] == -1 ) ? value : min( value, dp[i][j] );
                }
            }
        }
    }

    cout << dp[n][m];
}
