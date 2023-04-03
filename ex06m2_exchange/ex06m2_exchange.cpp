#include <iostream>
#include <vector>

using namespace std;

double R[500][500];

int main(){

    int test, n;
    bool ans;

    cin >> test;

    for( int t = 0 ; t < test ; t++ ){
        cin >> n;

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < n ; j++ )
                cin >> R[i][j];
        }

        ans = false;

        //see all the possible length of loop
        // loop of length 1 - n
        // look similar to floyd warshall
        for( int k = 0 ; k < n && !ans ; k++ ){
          //round k:
          // every path between i to j that use node 0 to k
            for( int i = 0 ; i < n && !ans ; i++ ){
                for( int j = 0 ; j < n ; j++ ){

                  //path i to j --> compare with path i to k * path k to j
                    R[i][j] = max( R[i][j], R[i][k] * R[k][j] );

                  //check if loop make infinite profit
                    if( i == j && R[i][j] > 1 ){
                        ans = true;
                        break;
                    }
                }
            }
        }

        if( ans ) cout << "YES\n";
        else cout << "NO\n";

    }

}
