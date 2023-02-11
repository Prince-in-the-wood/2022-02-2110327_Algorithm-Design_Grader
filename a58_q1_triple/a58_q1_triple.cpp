#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n, m;
    int l, r;
    int t;
    bool found;

    cin >> n >> m;

    vector<long long int> input(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> input[i];
    }

    for( int q = 0 ; q < m ; q++ ){

        cin >> t;

        found = false;

        for( int i = 0 ; i < n && !found ; i++ ){

            l = i + 1;
            r = n - 1;

            while( l < r ){

                if( input[i] + input[l] + input[r] == t ){
                    found = true;
                    break;
                }

                if( input[i] + input[l] + input[r] < t ) l++;
                else r--;

            }
        }

        if( found )
            cout << "YES\n";
        else
            cout << "NO\n";
    }


}
