#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int,int>>> graph; // node, weight
vector<int> k(8);
vector<bool> seq;

bool bound( int k, int node ){

    if( k == 0 ) return true;

    int summx = 0;
    int mn = 1999999999;

    //calculate minimum and maximum length
    for( int i = 0 ; i < seq.size() ; i++ ){
        if( node == i || seq[i] ) continue;

        int mx = 0;

        for( int j = 0 ; j < graph[i].size() ; j++ ){
            if( !seq[ graph[i][j].first ] ){
                mx = max( mx, graph[i][j].second );
                mn = min( mn, graph[i][j].second );
            }

        }

        summx += mx;
    }

    return mn <= k && k <= summx;
}

bool findPath( int k, int node ){

    if( k == 0 ) return true;

    bool ans = false;

    seq[node] = true;

    for( int i = 0 ; i < graph[node].size() ; i++ ){
        int v = graph[node][i].first;
        int w = graph[node][i].second;

        //never visit that node and weight is not more than we need
        if( !seq[v] && w <= k && bound( k - w, v )){
            if( findPath( k - w, v ) ){
                ans = true;
                break;
            }
        }
    }

    seq[node] = false;
    return ans;
}

bool pathSum( int k, int n ){

    for( int i = 0 ; i < n ; i++ ){
        if( findPath( k, i ) ) return true;
    }

    return false;

}

int main(){

    int n, m;
    int a, b, w;

    cin >> n >> m;

    graph.resize(n);
    seq.resize(n);

    for( int i = 0 ; i < 8 ; i++ )
        cin >> k[i];

    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b >> w;

        graph[a].push_back( { b, w } );
        graph[b].push_back( { a, w } );
    }

    for( int i = 0 ; i < 8 ; i++ ){
        if( pathSum( k[i], n ) )
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}
