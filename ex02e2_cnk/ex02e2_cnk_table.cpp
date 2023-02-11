#include <iostream>

using namespace std;

//       n   k
int cnk[35][35];

int main()
{
    int n, k;

    cin >> n >> k;

    for( int i = 0; i <= n ; i++ ){
        for( int j = 0 ; j <= min( i, k ) ; j++ ){
            if( i == j || j == 0 )
                cnk[i][j] = 1;
            else
                cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];
        }
    }

    cout << cnk[n][k];
}
