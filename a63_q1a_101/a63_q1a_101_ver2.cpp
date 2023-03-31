#include <iostream>
#include <vector>

using namespace std;

long long int mod = 100000007;


vector<vector<long long int>> dp({ { 1, 0, 0, 0 },
                                   { 0, 1, 0, 0 },
                                   { 0, 0, 1, 0 },
                                   { 0, 0, 0, 1 } });
vector<vector<long long int>> dp2({ { 1, 1, 0, 0 },
                                    { 0, 0, 1, 1 },
                                    { 1, 0, 0, 0 },
                                    { 0, 0, 1, 1 }});


long long int cal( long long int a, long long int b ){
    return ( a * b ) % mod;
}


vector<vector<long long int>> divide( long long int n ){

    if( n == 2 )
        return dp;

    if( n == 3 ){
        return dp2;
    }

    vector<vector<long long int>> arr = divide(n/2);
    vector<vector<long long int>> inr({ {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0},
                                        {0, 0, 0, 0}
                                      });

    if( n % 2 == 0 ){

        for( int i = 0 ; i < 4 ; i++ ){
            for( int j = 0 ; j < 4 ; j++ ){
                inr[i][j] = ( cal( arr[i][0], arr[0][j] ) + cal( arr[i][0], arr[1][j] ) + cal( arr[i][0], arr[2][j] ) + cal( arr[i][0], arr[3][j] ) ) %mod +
                            ( cal( arr[i][1], arr[0][j] ) +                               cal( arr[i][1], arr[2][j] ) + cal( arr[i][1], arr[3][j] ) ) %mod +
                            ( cal( arr[i][2], arr[0][j] ) + cal( arr[i][2], arr[1][j] )                                                             ) %mod +
                            ( cal( arr[i][3], arr[0][j] ) +                               cal( arr[i][3], arr[2][j] ) + cal( arr[i][3], arr[3][j] ) ) %mod;
                inr[i][j] %= mod;
            }
        }

    }else{
         for( int i = 0 ; i < 4 ; i++ ){
            for( int j = 0 ; j < 4 ; j++ ){
                inr[i][j] = ( cal( arr[i][0], arr[0][j] ) + cal( arr[i][0], arr[1][j] ) + cal( arr[i][0], arr[2][j] ) + cal( arr[i][0], arr[3][j] ) ) %mod +
                            ( cal( arr[i][1], arr[0][j] ) + cal( arr[i][1], arr[1][j] )                                                             ) %mod +
                            ( cal( arr[i][2], arr[0][j] ) + cal( arr[i][2], arr[1][j] ) + cal( arr[i][2], arr[2][j] ) + cal( arr[i][2], arr[3][j] ) ) %mod +
                            ( cal( arr[i][3], arr[0][j] ) + cal( arr[i][3], arr[1][j] )                                                             ) %mod;
                inr[i][j] += ( cal( arr[i][0], arr[0][j] ) + cal( arr[i][0], arr[2][j] ) + cal( arr[i][0], arr[3][j] ) ) %mod +
                             ( cal( arr[i][1], arr[0][j] ) + cal( arr[i][1], arr[2][j] ) + cal( arr[i][1], arr[3][j] ) ) %mod +
                             ( cal( arr[i][3], arr[0][j] ) + cal( arr[i][3], arr[2][j] ) + cal( arr[i][3], arr[3][j] )  ) %mod;

                inr[i][j] %= mod;
            }
        }
    }

    return inr;
}

int main(){

    long long int n;

    cin >> n;

    long long int ans = 0;
    vector<vector<long long int>> arr = divide(n);


    for( int i = 0 ; i < 4 ; i++ ){
        for( int j = 0 ; j < 4 ; j++ )
            ans = ( ans + arr[i][j] )%mod;
    }
    cout << ans;

}

