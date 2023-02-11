#include <iostream>

using namespace std;

int main(){

    int n, input;
    int sum = 0, mn, mx;
    int mnformx = 0, mxformn = 0;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> input;

        sum += input;

        mn = ( i == 0 ) ? input: min( mn, sum - mxformn );
        mx = ( i == 0 ) ? input: max( mx, sum - mnformx );

        mxformn = max( mxformn, sum );
        mnformx = min( mnformx, sum );
    }

    if( sum == mn )
        cout << mx;
    else
        cout << max( sum - mn, mx );
}
