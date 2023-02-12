#include <iostream>
#include <algorithm>

using namespace std;

int pat[11] = { 0,     1,      11,      111,      1111,      11111,
                  111111, 1111111, 11111111, 111111111, 1111111111};

int check[11] = { 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0};

int findOnes( int n ){

    if( 0 <= n && n <= 11 ){
        if( n <= 6 )return n;
        else return 13 - n;
    }

    int idx = upper_bound( pat, pat + 11, n ) - pat;
    int way1 = n, way2;

    if( check[idx] == 0 ){
        check[idx] = 1;
        way1 = findOnes( pat[idx] - n ) + idx;
        check[idx] = 0;
    }

    way2 = findOnes( n - pat[idx-1] ) + idx - 1;

    return min( way1, way2 );


}

int main(){

    int n;

    cin >> n;

    cout << findOnes( n );
}

