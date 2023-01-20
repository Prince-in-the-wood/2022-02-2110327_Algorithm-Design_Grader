#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int DIVOC_20( const vector<int>& dna, int beginPoint, int endPoint ){

    if( endPoint - beginPoint == 1 ){
        return dna[beginPoint] + dna[endPoint];
    }

    int len = ( endPoint - beginPoint + 1 ) / 2;

    int oneLeft = DIVOC_20(dna, beginPoint, beginPoint + len - 1 );
    int oneRight = DIVOC_20(dna, beginPoint + len, endPoint );

    if( oneLeft == -1 || oneRight == -1 ) return -1;
    if( abs( oneLeft - oneRight ) > 1 ) return -1;
    return oneLeft + oneRight;
}

int main(){

    int n, k;
    int ans;

    cin >> n >> k;

    vector<int> dna( (int)pow(2, k) );

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < dna.size() ; j++ )
            cin >> dna[j];

        ans = DIVOC_20( dna , 0, dna.size() - 1 );

        if( ans == -1 ) cout << "no\n";
        else cout << "yes\n";
    }



}

