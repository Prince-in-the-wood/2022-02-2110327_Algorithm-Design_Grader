#include <iostream>

using namespace std;

int modExpo( int x, int n, int k ){

    if( n == 0 )return 1;
    if( n == 1 ) return x % k;

    int ans = modExpo( x, n / 2 , k );

    if( n % 2 == 0 ) return ( ans * ans )%k;

    return ( ( ( ans * ans ) % k )* modExpo( x, 1, k ) )%k;

}

int main(){
    int x, n, k;

    cin >> x >> n >> k;

    int ans = modExpo( x, n, k );

    cout << ans;
}
