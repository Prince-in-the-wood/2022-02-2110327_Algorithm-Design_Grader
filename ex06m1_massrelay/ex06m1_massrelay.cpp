#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, pair<int,int>> pairofip;

vector<int> ans;
vector<int> disjset;
priority_queue<pairofip, vector<pairofip>, greater<pairofip>> pq;

int parent(int i){
    if( i == disjset[i] )return i;
    return parent(disjset[i]);
}

int main(){

    int n, m, q;
    int a, b, c;
    int d, group;

    cin >> n >> m >> q;

    //init
    ans.resize(n+1);
    disjset.resize(n+1);
    group = n;

    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> c;
        pq.push( {c, {a,b} } );
    }

    for( int i = 0 ; i < n ; i++ ){
        disjset[i] = i;
    }

    while( !pq.empty() ){

        c = pq.top().first;
        a = pq.top().second.first;
        b = pq.top().second.second;

        pq.pop();

        int p1 = parent(a), p2 = parent(b);

        if( p1 == p2 )continue;

        disjset[p1] = p2;
        group--;
        ans[group] = c;
    }

    for( int i = 0 ; i < q ; i++ ){
        cin >> d;

        cout << ans[ min(d, n) ] << "\n";

    }

}
