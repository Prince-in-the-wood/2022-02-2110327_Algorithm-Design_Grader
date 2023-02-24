#include <iostream>

using namespace std;

int arr[1010][1010];
int dp[1010][1010]; // define dp[i][j] = maximum diagonal sum that end at (i, j)

int main(){

    int n;
    int ans;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ )
            cin >> arr[i][j];
    }

    // ans always be the valid answer
    ans = arr[0][0];

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            if( i - 1 >= 0 && j - 1 >= 0 )
                dp[i][j] = max( 0, dp[i-1][j-1] ) + arr[i][j];
            else
                dp[i][j] = arr[i][j];

            ans = max( ans, dp[i][j] );
        }
    }

    cout << ans;

}
