#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<double, pair<double, double>>> things; // { ration, { value, weight } }

int main(){

    int n;
    double w;

    cin >> w >> n;

    things.resize( n );

    for( int i = 0 ; i < n ; i++ ){
        cin >> things[i].second.first; //value
    }

    for( int i = 0 ; i < n ; i++ ){
        cin >> things[i].second.second; //weight
        things[i].first = things[i].second.first / things[i].second.second;
    }

    sort( things.begin(), things.end() );

    double ans = 0;

    for( int i = n - 1 ; i >= 0 && w > 0 ; i-- ){

        //may some precision lost due to ratio we calculate
        //then we should use this code to avoid that problem
        if( w >= things[i].second.second )
            ans += things[i].second.first;
        else
            ans += things[i].first * w;

        w -= min( w, things[i].second.second );
    }

    printf("%.4lf", ans );


}
