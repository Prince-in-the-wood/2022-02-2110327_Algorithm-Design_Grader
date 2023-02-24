#include <iostream>
#include <algorithm>

using namespace std;

long long int price[500010]; //define price[i] = the sum we have to pay if we cut grass from index 0 to i
long long int grass[500010]; //define grass[i] = the total number of grass from index 0 to i

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    int l;
    long long int budget;

    cin >> n >> m >> k;

    //initial
    price[0] = 0;
    grass[0] = 0;

    for( int i = 1 ; i <= n ; i++ ){
        cin >> grass[i];

        price[i] = price[i-1] + grass[i] + k;
        grass[i] += grass[i-1];
    }

    for( int i = 0 ; i < m ; i++ ){
        cin >> l >> budget;

        //since index of field start with 0
        //but we start in the array with 1
        l += 1;

        int idx = upper_bound( price, price + n + 1, price[ l - 1 ] + budget ) - price - 1;

        cout << grass[idx] - grass[l-1] << "\n";
    }

}
