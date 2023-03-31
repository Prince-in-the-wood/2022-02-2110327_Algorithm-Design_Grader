#include <iostream>

using namespace std;

int bb[200010][2];

int dpl[200010][2][51];
int dpr[200010][2][51];

int main(){

    int n, w, k;
    int ans = 0;

    cin >> n >> w >> k;

    for( int i = 1 ; i <= n ; i++ )
        cin >> bb[i][0];

    for( int i = 1 ; i <= n ; i++ )
        cin >> bb[i][1];

    if( n == k ){
        dpl[0][0][0] = 0;
        dpl[0][1][0] = 0;
        dpr[0][0][0] = 0;
        dpr[0][1][0] = 0;

        for( int i = 1 ; i <= n ; i++ ){
            if( i <= w ){
                dpl[i][1][0] = bb[i][0];
                dpr[i][1][0] = bb[i][1];
            }else{
                dpl[i][1][0] = max( dpr[i-w-1][0][0], dpr[i-w-1][1][0] ) + bb[i][0];
                dpr[i][1][0] = max( dpl[i-w-1][0][0], dpl[i-w-1][1][0] ) + bb[i][1];
            }

            dpl[i][0][0] = max( dpl[i-1][0][0], dpl[i-1][1][0] );
            dpr[i][0][0] = max( dpr[i-1][0][0], dpr[i-1][1][0] );


            ans = max( ans, max( max( dpl[i][0][0], dpl[i][1][0] ), max( dpr[i][0][0], dpr[i][1][0] ) ) );
        }

        cout << ans;
    }else{

        for( int i = 0 ; i <= k ; i++ ){
            dpl[0][0][i] = 0;
            dpl[0][1][i] = 0;
            dpr[0][0][i] = 0;
            dpr[0][1][i] = 0;
        }


        for( int i = 1 ; i <= n ; i++ ){

            for( int j = 0 ; j <= k ; j++ ){

                if( j == 0 ){
                    dpl[i][1][j] = 0;
                    dpr[i][1][j] = 0;
                }
                else if( i <= w ){
                    dpl[i][1][j] = bb[i][0];
                    dpr[i][1][j] = bb[i][1];
                }else{
                    dpl[i][1][j] = max( dpr[i-w-1][0][j-1], dpr[i-w-1][1][j-1] ) + bb[i][0];
                    dpr[i][1][j] = max( dpl[i-w-1][0][j-1], dpl[i-w-1][1][j-1] ) + bb[i][1];
                }

                dpl[i][0][j] = max( dpl[i-1][0][j], dpl[i-1][1][j] );
                dpr[i][0][j] = max( dpr[i-1][0][j], dpr[i-1][1][j] );


                ans = max( ans, max( max( dpl[i][0][j], dpl[i][1][j] ), max( dpr[i][0][j], dpr[i][1][j] ) ) );
            }

        }

        cout << ans;

    }

}
