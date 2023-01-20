#include<iostream>
#include<vector>

using namespace std;

void gen_barcode( int a, int b, vector<int> &sol, int one, int len ){

    if( len == b ){
        if( one != a ) return;
        for( int i = 0 ; i < b ; i++ )
            cout << sol[i];
        cout << "\n";
        return;
    }

    sol[len] = 0;
    gen_barcode( a, b, sol, one, len + 1 );

    sol[len] = 1;
    gen_barcode( a, b, sol, one + 1, len + 1 );
}

int main(){

    int a, b;

    cin >> a >> b;

    vector<int> sol(b);

    gen_barcode( a, b, sol, 0, 0 );
}
