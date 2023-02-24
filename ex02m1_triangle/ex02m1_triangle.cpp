#include <iostream>

using namespace std;

int main(){

    int n;
    int dp[110][110];
    int triangle[110][110];
    int ans = 0; //since the inputs are non negative number

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j <= i ; j++ )
            cin >> triangle[i][j];
    }

    dp[0][0] = triangle[0][0];

    for( int i = 1 ; i < n ; i++ ){

        for( int j = 0 ; j <= i ; j++ ){

            if( j == 0 ){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }else{
                dp[i][j] = max( dp[i-1][j], dp[i-1][j-1] ) + triangle[i][j];
            }

            if( i == n - 1 )
                ans = max( ans, dp[i][j] );

        }

    }

    cout << ans;
}
