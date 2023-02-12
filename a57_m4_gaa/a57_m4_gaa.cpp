#include <iostream>
#include <vector>

using namespace std;

vector<int> gaa;

char findGaa( int n, int idx ){

    if( n == 0 )
        return ( idx == 1 )? 'g' : 'a';

    if( idx <= gaa[n-1] )
        return findGaa( n - 1, idx );

    if( idx <= gaa[n-1] + n + 3 ){
        if( idx == gaa[n-1] + 1 )
            return 'g';
        return 'a';
    }

    return findGaa( n - 1, idx - gaa[n-1] - n - 3 );
}

int main(){

    int n;

    cin >> n;

    gaa.push_back(3);

    for( int i = 1 ; i < n && gaa[i-1] < n ; i++ ){
        gaa.push_back( 2 * gaa[i-1] + i + 3 );
    }

    cout << findGaa( gaa.size() - 1 , n );


}
