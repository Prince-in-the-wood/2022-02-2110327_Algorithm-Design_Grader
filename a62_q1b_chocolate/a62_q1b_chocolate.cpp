#include <iostream>

using namespace std;

int mod = 1000003;
int sum[10010];
int choco[10];

int main(){

    int n, k;

    cin >> n >> k;

    for( int i = 0 ; i < k ; i++ )
        cin >> choco[i];

    //initial: we can eat 0 chocolate in 1 way
    sum[0] = 1;

    for( int i = 1 ; i <= n ; i++ ){

        sum[i] = 0;

        for( int j = 0 ; j < k ; j++ ){
            if( i - choco[j] >= 0 )
                sum[i] = ( sum[i] + sum[ i - choco[j] ] ) % mod ;
        }
    }

    cout << sum[n];
}
