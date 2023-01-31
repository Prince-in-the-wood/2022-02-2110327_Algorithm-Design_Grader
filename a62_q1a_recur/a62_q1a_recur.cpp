#include <iostream>
#include <math.h>

using namespace std;

int arr[500][500];

void recur( int x, int y, int a, int b ){

    if( a == 0 ){
        arr[x][y] = b;
        return;
    }

    int x2 = x + pow( 2, a - 1 );
    int y2 = y + pow( 2, a - 1 );

    recur(  x,  y, a - 1 , b );
    recur(  x, y2, a - 1, b - 1 );
    recur( x2,  y, a - 1, b + 1 );
    recur( x2, y2, a - 1 , b );

}

int main(){

    int a, b;

    cin >> a >> b;

    recur( 0, 0, a, b );

    for( int i = 0 ; i < pow( 2, a ) ; i++ ){
        for( int j = 0 ; j < pow( 2, a ) ; j++ )
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}
