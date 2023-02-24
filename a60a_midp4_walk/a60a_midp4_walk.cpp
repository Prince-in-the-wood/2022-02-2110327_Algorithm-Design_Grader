#include <iostream>

using namespace std;

int forest[510][510];
int dp[510][510];

int main(){

    int n, m;

    cin >> n >> m;

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < m ; j++ ){
            cin >> forest[i][j];
        }
    }

    for( int i = 0 ; i < n ; i++ ){

        for( int j = 0 ; j < m ; j++ ){

            //at start point
            if( i == 0 && j == 0 )
                dp[i][j] = forest[i][j];
            else if( i - 1 >= 0 && j - 1 >= 0 )
                dp[i][j] = max( max( dp[i-1][j], dp[i][j-1] ) + forest[i][j] , dp[i-1][j-1] + 2 * forest[i][j] );
            else if( i == 0 )
                dp[i][j] = dp[i][j-1] + forest[i][j];
            else
                dp[i][j] = dp[i-1][j] + forest[i][j];
        }
    }

    cout << dp[ n - 1 ][ m - 1 ];
}
