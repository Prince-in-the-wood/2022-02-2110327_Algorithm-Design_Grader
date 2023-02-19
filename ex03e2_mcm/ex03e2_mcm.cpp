#include <iostream>

using namespace std;

int rc[110];
int dp[110][110]; // define dp[i][j] = c; i is start multiplication at ith, j is end multiplication at jth
                  // c is minimum number of scalar multiplication

int main(){

    int n;

    cin >> n;

    for( int i = 0 ; i <= n ; i++ ){
        cin >> rc[i];
    }

    //Initial state
    for( int i = 0 ; i < n ; i++ )
        dp[i][i] = 0;

    for( int j = 0 ; j < n ; j++ ){

        for( int i = j - 1 ; i >= 0 ; i-- ){
            dp[i][j] = 2000000000; // set to max

            for( int k = i ; k < j ; k++ )
                dp[i][j] = min( dp[i][j],
                                dp[i][k] + dp[k+1][j] + rc[i] * rc[k+1] * rc[j+1] );

        }
    }

    cout << dp[0][n-1];
}
