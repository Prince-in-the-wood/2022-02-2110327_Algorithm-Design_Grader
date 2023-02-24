#include <iostream>

using namespace std;

int jump[1000010];//define jump[i] = the maximum score we can make when we end at i tile

int main(){

    int n, score;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> score;

        if( i == 0 ){
            //alway get this score
            jump[i] = score;
        }else{

            jump[i] = -2000000000; //set min

            for( int j = 1 ; j <= 3 && i - j >= 0 ; j++ )
                jump[i] = max( jump[i], jump[ i - j ] );

            jump[i] += score;
        }

    }

    cout << jump[n-1];
}
