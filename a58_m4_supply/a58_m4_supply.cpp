#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,pair<int,int>>> seq; // day, ( event, store/plant number )
queue<int> waiting; // sequence of store that waiting for product
queue<int> stock;  // sequence of plant that produce product

int main(){

    int n, m, k;
    int event, label;
    int ans;

    cin >> n >> m >> k;

    seq.resize(k);

    for( int i = 0 ; i < k ; i++ )
        cin >> seq[i].first >> seq[i].second.first >> seq[i].second.second;

    sort( seq.begin(), seq.end() );

    for( int i = 0 ; i < k ; i++ ){

        event = seq[i].second.first;
        label = seq[i].second.second;
        ans = 0;

        //event A: Plant produce products
        if( event == 0 ){
            if( !waiting.empty() ){
                ans = waiting.front();
                waiting.pop();
            }else{
                stock.push(label);
            }
        }

        //event B: Store request for products
        if( event == 1 ){
            if( !stock.empty() ){
                ans = stock.front();
                stock.pop();
            }else{
                waiting.push( label );
            }
        }

        cout << ans << "\n";

    }
}
