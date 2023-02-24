#include <iostream>

using namespace std;

int cost[10010][2];// define cost[i][x] = minimum cost from 0 to i th segment
                   // when x = 0; is to not build pressure station
                   // when x = 1; is to build pressure station

int main(){

    int n, k;
    int p;

    cin >> n >> k;

    for( int i = 0 ; i < n ; i++ ){
        cin >> p;

        //set initial
        if( i == 0 ){
            cost[i][0] = 0;
            cost[i][1] = p;
            continue;
        }

        //set max
        cost[i][0] = 2000000000;
        cost[i][1] = 2000000000;

        for( int j = 1 ; j <= k + 1 && i - j >= 0 ; j++ ){

            //not to build this pressure station
            //mean in range i - k to i - 1 must have 1 station
            if( j != k + 1 )
                cost[i][0] = min( cost[i][0], cost[ i - j ][1] );

            //to build this pressure station
            //mean in range i - k - 1 to i - 1 have or not have 1 station
            //but for the first k segment we have to ensure that there is at least 1 station
            //then when i == j == k + 1, we have to ensure that at least we pick the first one in the choice
            if( i - j == 0 && j == k + 1 )
                cost[i][1] = min( cost[i][1], cost[ i - j ][1] + p );
            else
                cost[i][1] = min( cost[i][1], min( cost[ i - j ][0], cost[ i - j ][1] ) + p );
        }
    }

    if( n == 1 )
        cout << cost[ n - 1 ][1];
    else
        cout << min( cost[ n - 1 ][0], cost[ n - 1 ][1] );

}
