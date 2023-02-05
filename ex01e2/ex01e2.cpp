#include <iostream>

using namespace std;

int main(){

    int n, input;
    int mx, mn = 0, sum = 0;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> input;

        sum += input;

        mx = ( i == 0 ) ? input : max( mx, sum - mn );
        mn = min( mn, sum );

    }

    cout << mx;

}
