#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

bool check_DIVOC_20( vector<int> &dna, int startPoint, int endPoint, bool isMutate ){

    if( endPoint - startPoint == 1 ){
        return ( dna[startPoint] == 0 && dna[endPoint] == 1 && !isMutate ) || // when not mutate - 0 1
               ( dna[startPoint] == 1 && dna[endPoint] == 0 && isMutate );    // when mutate     - 1 0
    }

    int len = ( endPoint - startPoint + 1 ) / 2;

    bool leftValid, rightValid;

    if( isMutate ){
        leftValid = check_DIVOC_20( dna, startPoint + len, endPoint, isMutate ) ||
                         check_DIVOC_20( dna, startPoint + len, endPoint, !isMutate );
        rightValid = check_DIVOC_20( dna, startPoint, startPoint + len - 1,  isMutate );
    }else{
        leftValid = check_DIVOC_20( dna, startPoint, startPoint + len - 1, isMutate ) ||
                         check_DIVOC_20( dna, startPoint, startPoint + len - 1, !isMutate );
        rightValid = check_DIVOC_20( dna, startPoint + len, endPoint, isMutate );
    }


    return leftValid && rightValid;
}

int main(){

    int n, k;

    cin >> n >> k;

    vector<int> dna( (int)pow( 2, k ) );

    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < dna.size() ; j++ )
            cin >> dna[j];

        if( check_DIVOC_20( dna, 0, dna.size() - 1 , false ) )
            cout << "yes\n";
        else
            cout << "no\n";
    }
}

