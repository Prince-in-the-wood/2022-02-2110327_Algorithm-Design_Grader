#include <iostream>

using namespace std;

int sum[1010][1010];
char grid[1010];

int main(){

    int r, c;
    int ans = 0;

    cin >> r >> c;

    //initial
    for( int i = 0 ; i <= r ; i++ )
        sum[i][0] = 0;

    for( int j = 0 ; j <= c ; j++ )
        sum[0][j] = 0;

    //input & compute prefix sum
    for( int i = 1 ; i <= r ; i++ ){
        cin >> grid;

        for( int j = 1 ; j <= c ; j++ ){

            if( grid[ j - 1 ] == '0' )
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + 1;
            else
                sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

        }
    }


    for( int i = 1 ; i <= r ; i++ ){

        for( int j = 1 ; j <= c ; j++ ){

            for( int k = max( 1, ans ) ; k <= min( r, c ) ; k++ ){

                if( i + k - 1 > r || j + k - 1 > c ) break;

                if( sum[ i + k - 1 ][ j + k - 1 ] - sum[ i + k - 1 ][ j - 1 ] - sum[ i - 1 ][ j + k - 1 ] + sum[ i - 1 ][ j - 1 ] == 0 )
                    ans = k;

            }
        }
    }

    cout << ans;


}
