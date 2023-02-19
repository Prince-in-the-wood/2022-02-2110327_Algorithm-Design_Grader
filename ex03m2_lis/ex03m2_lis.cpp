#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n;
    int seq;

    vector<int> lis;

    cin >> n;

    for( int i = 0 ; i < n ; i++ ){
        cin >> seq;

        auto it = upper_bound( lis.begin(), lis.end(), seq );

        if( it == lis.end() ) // seq > all elements in subsequence
            lis.push_back( seq );
        else
            *it = seq;
    }

    cout << lis.size();

}
