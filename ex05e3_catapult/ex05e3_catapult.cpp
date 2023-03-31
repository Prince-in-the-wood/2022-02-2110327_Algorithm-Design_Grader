#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> graphT;
vector<pair<int,int>> fin;
vector<int> check;
vector<int> ans;

int time1 = 1;

void dfs_gt( int n ){

    for( int i = 0 ; i < graphT[n].size() ; i++ ){
        if( fin[graphT[n][i]].first == -1 ){
            fin[graphT[n][i]].first = -2;
            dfs_gt(graphT[n][i]);
        }
    }

    fin[n].first = ++time1;
}

int dfs( int n ){

    int ans = 1;

    check[n] = 1;

    for( int i = 0 ; i < graph[n].size() ; i++ ){
        if( check[ graph[n][i] ] == 0 ){
            ans += dfs( graph[n][i] );
        }
    }

    return ans;
}

int main(){

    int n, m;
    int a;

    cin >> n;

    graph.resize(n);
    graphT.resize(n);
    check.resize(n);
    fin.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> m;

        for( int j = 0 ; j < m ; j++ ){
            cin >> a;

            graph[i].push_back(a);
            graphT[a].push_back(i);
        }
    }

    //init
    for( int i = 0 ; i < n ; i++ ){
        fin[i].first = -1;
        fin[i].second = i;
    }


    //Kosaraju's Algorithm
    for( int i = 0 ; i < n ; i++ ){
        if( fin[i].first != -1 ) continue;

        fin[i].first = 0;
        dfs_gt( i );
    }

    sort( fin.begin(), fin.end() );

    for( int i = n - 1 ; i >= 0 ; i-- ){
        if( check[ fin[i].second ] ) continue;

        ans.push_back( dfs( fin[i].second ) );

    }


    //Print answer
    sort( ans.begin(), ans.end() );

    for( int i = 0 ; i < ans.size() ; i++ )
        cout << ans[i] << " ";


}
