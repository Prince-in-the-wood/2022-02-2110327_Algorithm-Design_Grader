#include <iostream>

using namespace std;

int rope[4010]; // define rope[i] = the maximum number of part we divide from rope length i
bool can[4010]; // define  can[i] = Can we divide from rope length i

int main(){

    int n;
    int len[3]; // valid length of rope

    cin >> n;

    //set default
    rope[0] = 0;
    can[0]  = true;

    for( int i = 0 ; i < 3 ; i++ ){
        cin >> len[i];
    }


    for( int i = 1 ; i <= n ; i++ ){
        rope[i] = 0;
        can[i] = false;

        for( int j = 0 ; j < 3 ; j++ ){

            //check if we can divide the rope length ( i - len[j] )
            //if yes then we can divide i into i - len[j] and len[j]
            if( i - len[j] >= 0 && can[ i - len[j] ] ){
                can[i] = true;
                rope[i] = max( rope[i], rope[ i - len[j] ] + 1 );
            }
        }

    }

    //since it guarantee there is an answer
    cout << rope[n];


}
