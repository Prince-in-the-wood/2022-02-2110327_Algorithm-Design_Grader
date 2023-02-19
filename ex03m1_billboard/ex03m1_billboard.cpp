#include <iostream>

using namespace std;

int c[10010];
int sum[10010][2]; // define sum[i][x] is maximum number of customer
                   // seeing all billboard we rent from 1 to i without breaking rules
                   // when x = 0; is to not select i th
                   // when x = 1; is to select i th
int main(){

    int n;

    cin >> n;

    for( int i = 1 ; i <= n ; i++ )
        cin >> c[i];

    //initial
    sum[0][0] = 0;
    sum[0][1] = 0;

    for( int i = 1 ; i <= n ; i++ ){
        sum[i][0] = max( sum[ i - 1 ][0], sum[ i - 1 ][1] );
        sum[i][1] = sum[ i - 1 ][0] + c[i];
    }

    cout << max( sum[n][0], sum[n][1] );
}
