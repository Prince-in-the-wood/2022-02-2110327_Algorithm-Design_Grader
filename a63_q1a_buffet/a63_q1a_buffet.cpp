#include <iostream>
#include <algorithm>

using namespace std;

int food[200010];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    int l, w;

    cin >> n >> k >> m;

    food[0] = 0;

    for( int i = 1 ; i <= n ; i++ ){
        cin >> food[i];

        food[i] += food[i-1] - m;
    }

    for( int i = 0 ; i < k ; i++ ){
        cin >> l >> w;

        int idx = lower_bound( food + l, food + n + 1, food[l-1] + w ) - food;

        cout << idx << "\n";
    }


}
