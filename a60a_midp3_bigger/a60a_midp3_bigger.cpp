#include <iostream>

using namespace std;

int c[10010];
int dp[10010][2]; //define dp[i][x] = maximum sum of customer seeing billboard
                  // x = 0; to not choose this billboard
                  // x = 1; to choose this billboard

int main(){

    int n;

    cin >> n;

    for( int i = 1 ; i <= n ; i++ )
        cin >> c[i];

    //initial
    dp[0][0] = 0;
    dp[0][1] = 0;

    for( int i = 1 ; i <= n ; i++ ){

        //choice 1: we don't choose this billboard
        int mx = max( dp[i-1][0], dp[i-1][1] );
        dp[i][0] = ( i - 2 >= 0 ) ? max( mx, max( dp[i-2][0], dp[i-2][1] ) ) : mx;

        //choice 2: we choose this billboard
        dp[i][1] = ( i - 2 >= 0 ) ? dp[i-2][0] + c[i] : c[i];
    }

    cout << max( dp[n][0], dp[n][1] );
}
