#include <iostream>

using namespace std;

long long int mod = 100000007;
long long int dp[2][4];

int main(){

    int n;

    cin >> n;

    //init
    dp[0][0] = 1;//end with 00
    dp[0][1] = 1;//end with 01
    dp[0][2] = 1;//end with 10
    dp[0][3] = 1;//end with 11

    for( int i = 3 ; i <= n ; i++ ){
        dp[i%2][0] = ( dp[(i-1)%2][0] + dp[(i-1)%2][2] ) % mod;
        dp[i%2][1] = dp[(i-1)%2][0] % mod;
        dp[i%2][2] = ( dp[(i-1)%2][1] + dp[(i-1)%2][3] ) % mod;
        dp[i%2][3] = ( dp[(i-1)%2][1] + dp[(i-1)%2][3] ) % mod;
    }

    cout << ( dp[n%2][0] + dp[n%2][1] + dp[n%2][2] + dp[n%2][3] ) % mod;
}
