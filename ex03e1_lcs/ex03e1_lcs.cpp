#include <iostream>
#include <cstring>

using namespace std;

int main(){

    char A[510], B[510];
    int dp[510][510];

    cin >> A >> B;

    for( int i = 0 ; i <= strlen(A) ; i++ )
        dp[i][0] = 0;

    for( int j = 0 ; j <= strlen(B) ; j++ )
        dp[0][j] = 0;

    for( int j = 1 ; j <= strlen(B) ; j++ ){
        for( int i = 1 ; i <= strlen(A) ; i++ ){

            if( A[i-1] == B[j-1] )
                dp[i][j] = max( dp[i-1][j-1] + 1, max( dp[i-1][j], dp[i][j-1] ) );
            else
                dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
        }
    }

    cout << dp[strlen(A)][strlen(B)];
}
