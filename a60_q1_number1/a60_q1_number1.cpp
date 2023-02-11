#include <iostream>
#include <math.h>

using namespace std;

int cnt = 0;
int seq = 0;

void numberOne( int n, int l, int r ){
    if( n <= 1 ){
        seq++;

        if( l <= seq && seq <= r && n == 1 ) cnt++;
        return;
    }

    int pass_num = pow( 2, ceil( log( n/2 + 1 )/log(2) ) ) - 1;

    if( seq + pass_num >= l )
        numberOne( n/2, l, r );
    else
        seq += pass_num;

    if( seq > r )return;

    numberOne( n%2, l, r );
    if( seq > r )return;

    if( seq + pass_num >= l )
        numberOne( n/2, l, r );
    else
        seq += pass_num;

}


int main(){

    int n, l, r;

    cin >> n >> l >> r;

    numberOne( n, l, r );

    cout << cnt;
}

