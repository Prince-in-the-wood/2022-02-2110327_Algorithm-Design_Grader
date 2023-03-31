#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> graph;
vector<int> check; //0 - white, 1 - gray, 2 - black

int dfs( int node, int parent ){

    bool isValid = ( graph[node].size() <= 2 ) ? true : false;

    for( int i = 0 ; i < graph[node].size() ; i++ ){
        if( check[graph[node][i]] == 0 ){
            check[graph[node][i]] = 1;
            isValid = isValid && dfs( graph[node][i], node );
        }

        //check if it is loop
        if( check[graph[node][i]] == 1 && graph[node][i] != parent )
            isValid = false;
    }

    check[node] = 2;

    return isValid;
}

int main(){

    int v, e;
    int a, b;
    int ans = 0;

    cin >> v >> e;

    graph.resize(v);
    check.resize(v);

    for( int i = 0 ; i < e ; i++ ){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for( int i = 0 ; i < v ; i++ ){

        if( check[i] != 0 )
            continue;

        check[i] = 1;
        ans += dfs( i, i );

    }

    cout << ans;
}

