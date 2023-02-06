#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

vector<int> idx;
vector<int> idx2;
vector<int> number;

long long int destroy( int l, int r, int A, int B ){

    int start = lower_bound( idx2.begin(), idx2.end(), l ) - idx2.begin() - 1;
    int fin   = upper_bound( idx2.begin(), idx2.end(), r ) - idx2.begin() - 1;

    int numHero = number[fin] - number[start];

    if( l == r ){

        if( numHero == 0 ){
            return A;
        }
        return B * numHero;
    }

    int mid = ( l + r )/2;

    if( numHero == 0 ) return A;

    long long int ans1 = destroy( l, mid, A, B ) + destroy( mid + 1, r, A, B );
    long long int ans2 = (long long int)B * (long long int)( r - l + 1 ) * (long long int)numHero;


    //We can cast into int because problem guarantee that answer is in range of int
    if( ans1 < ans2 ) return (int)ans1;

    return (int)ans2;


}



int main(){

    int n, m, A, B;
    int a;

    cin >> n >> m >> A >> B;

    idx.resize(m+1);
    idx[0] = 0;
    number.push_back(0);
    idx2.push_back(0);

    for( int i = 0 ; i < m ; i++ ){
        cin >> idx[i+1];
    }

    sort( idx.begin(), idx.end() );

    for( int i = 1 ; i <= m ; i++ ){
        if( idx[i-1] == idx[i] )
            number[ number.size() - 1 ]++;
        else{
            number.push_back( number[ number.size() - 1 ] + 1 );
            idx2.push_back(idx[i]);
        }
    }

    cout << destroy( 1, pow(2,n), A, B );

}
