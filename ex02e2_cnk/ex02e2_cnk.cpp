#include <iostream>

using namespace std;

int cnk( int n, int k ){

    if( n == k || k == 0 ) return 1;
    return cnk( n - 1, k - 1 ) + cnk( n - 1, k );
}

int main()
{
    int n, k;

    cin >> n >> k;
    cout << cnk( n, k );
}
