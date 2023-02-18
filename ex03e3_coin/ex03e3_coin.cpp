#include<iostream>

using namespace std;

int coin[20];
int use[10010]; //define use[i] = c;
                //i is value, c is the minimum number of coin and note

int main(){

    int n, m;

    cin >> n >> m;

    for( int i = 0 ; i < n ; i++ )
        cin >> coin[i];

    use[0] = 0;

    for( int i = 1 ; i <= m ; i++ ){

        use[i] = 2000000000; //set max_int

        for( int j = n - 1 ; j >= 0 ; j-- ){\

            //since coin is sort in decreasing order
            if( i - coin[j] < 0 ) break;

            //minimum number: think of every way we can denominate
            //and it is also guaranteed that the last denomination is always 1
            //which mean it always has an answer = no need to check if it does not have an answer
            use[i] = min( use[i], use[ i - coin[j] ] + 1 );

        }

    }

    cout << use[m];
}
