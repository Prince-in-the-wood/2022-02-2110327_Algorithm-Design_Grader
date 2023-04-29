#include <iostream>

using namespace std;

int iss( int mx, int w ){

    if( w == 0 ) return 1; //valid
    if( w < mx ) return 0; //the maximum number is more than the rest sum

    int ans = 0;

    for( int i = mx ; i <= w ; i++ ){
        ans += iss( i, w - i );
    }

    return ans;
}
int main(){

    int w;

    cin >> w;

    cout << iss( 1, w );
}
