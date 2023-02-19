#include <iostream>

using namespace std;

int barcode( int n, int black, int white, int nswap, int m, int k ){

    if( nswap > k ) return 0;
    if( nswap < k && n <= k - nswap ) return 0;

    if( n == 1 ) return 1;

    if( black == m )
        return barcode( n - 1, 0, 1, nswap + 1, m, k );

    if( white == m )
        return barcode( n - 1, 1, 0, nswap + 1, m, k );

    if( black == 0 )//now this is white
        return barcode( n - 1, black, white + 1, nswap, m, k ) + barcode( n - 1, 1, 0, nswap + 1, m, k );

    //now this is black
    return barcode( n - 1, black + 1, white, nswap, m, k ) + barcode( n - 1, 0, 1, nswap + 1, m, k );
}

int main(){

    int n, m, k;

    cin >> n >> m >> k;

    cout << barcode( n, 1, 0, 0, m, k );

}
