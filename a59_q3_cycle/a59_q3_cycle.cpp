#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> check;

int dfs( int node, int parent ){
    int ans = 0;

    for( int i = 0 ; i < graph[node].size() ; i++ ){
        if( check[ graph[node][i] ] == -1 ){
            check[ graph[node][i] ] = check[node] + 1;
            ans = max( ans, dfs( graph[node][i], node ));
        }else if( graph[node][i] != parent ){
            ans = abs( check[node] - check[graph[node][i]] ) + 1;
        }
    }

    return ans;
}

int main(){

    int n;
    int a, b;

    cin >> n;

    graph.resize(n);
    check.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //init
    for( int i = 0 ; i < n ; i++ )
        check[i] = -1;

    check[0] = 0;

    cout << dfs(0, 0);
}
