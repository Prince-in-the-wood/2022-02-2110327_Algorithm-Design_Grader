#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct item{
    double value;
    double weight;

    bool operator<( const item& r )const{
        return value/weight > r.value/r.weight;
    }
};

vector<item> things;

struct knapsack{

    double weightLimit;// weight limit of back
    double value; // total value
    int nextItem; // next item to be pick

    double bound()const{
        double ans = value;
        double nwl = weightLimit;
        for( int i = nextItem ; i < things.size() && nwl != 0 ; i++ ){
            ans += things[i].value/things[i].weight * min( things[i].weight, nwl );
            nwl -= min( things[i].weight, nwl );
        }

        return ans;
    }

    bool operator<( const knapsack& r )const{
        return bound() < r.bound();
    }

};

priority_queue<knapsack> pq;


int main(){
    int n;
    double w;
    double ans = 0;
    knapsack knaps;

    cin >> w >> n;

    things.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> things[i].value;
    }

    for( int i = 0 ; i < n ; i++ ){
        cin >> things[i].weight;
    }

    sort( things.begin(), things.end() );

    knaps.value = 0;
    knaps.weightLimit = w;
    knaps.nextItem = 0;
    pq.push( knaps );

    while( !pq.empty() ){
        knaps = pq.top();
        pq.pop();

        //select/ not select all of the item
        if( knaps.nextItem == n ){
            ans = max( ans, knaps.value );
            continue;
        }

        //maximum bound is less than answer
        //means no other possible answer that is more than this ans
        if( knaps.bound() < ans ){
            break;
        }

        //not choose this item
        knaps.nextItem++;
        pq.push( knaps );

        //choose this item
        if( knaps.weightLimit >= things[knaps.nextItem-1].weight ){
            knaps.value += things[knaps.nextItem-1].value;
            knaps.weightLimit -= things[knaps.nextItem-1].weight;
            pq.push( knaps );
        }


    }

    std::cout << std::setprecision(10) << ans;
}
