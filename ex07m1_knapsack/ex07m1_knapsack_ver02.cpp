#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<double, double>> goods; // { value, weight}
double ans = 0;

// To calculate maximum possible value that we can select ( upperbound )
double fknapsack( int idx, double weight ){

    double ans = 0;

    for( int i = idx ; i < goods.size() && weight > 0 ; i++ ){

        if( weight >= goods[i].second )
            ans += goods[i].first;
        else
            ans += goods[i].first / goods[i].second * weight;

        weight -= min( weight, goods[i].second );
    }

    return ans;
}

void knapsack( int idx, double value, double weight, int n ){

    // we finish selecting all of things
    if( idx == n ){
        ans = max( ans, value );
        return;
    }

    //condition we must concern
    // 1. we can select idx
    //    --> if its weight <= remaining weight of the bag
    // 2. we should do
    //    --> upperbound of value is more than answer we have before
    if( goods[idx].second <= weight && value + goods[idx].first + fknapsack( idx + 1, weight - goods[idx].second ) > ans )
        knapsack( idx + 1, value + goods[idx].first, weight - goods[idx].second, n );

    // 1. we should do
    //    --> upperbound of value is more than answer we have before
    if( value + fknapsack( idx + 1, weight ) > ans )
        knapsack( idx + 1, value, weight, n );

}

// for sorting
bool sortByRatio( pair<double, double> p1, pair<double, double> p2 ){

    return p1.first/p1.second > p2.first/p2.second;

}

int main(){

    int n;
    double w;

    cin >> w >> n;

    goods.resize( n );

    for( int i = 0 ; i < n ; i++ )
        cin >> goods[i].first;

    for( int i = 0 ; i < n ; i++ )
        cin >> goods[i].second;

    sort( goods.begin(), goods.end(), sortByRatio );

    knapsack( 0, 0, w, n );

    printf("%.4f", ans );


}
