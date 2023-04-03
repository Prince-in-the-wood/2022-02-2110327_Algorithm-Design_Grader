#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph;
vector<bool> check;
stack<int> ans;

void dfs(int node){

    //since this graph doesn't have cycle
    //then no need to check if we found unfinish visited node
    for( int i = 0 ; i < graph[node].size() ; i++ ){
        if( !check[ graph[node][i] ] ){
            dfs( graph[node][i] );
        }
    }

    check[node] = true;
    ans.push(node);
}

int main(){

    int n, m;
    int node;

    cin >> n;

    graph.resize(n);
    check.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> m;

        for( int j = 0 ; j < m ; j++ ){
            cin >> node;

            graph[node].push_back( i );
        }

    }

    //Topological sort
    for( int i = 0 ; i < n ; i++ ){
        if( check[i] )continue;
        dfs(i);
    }

    while( !ans.empty() ){
        cout << ans.top() << " ";
        ans.pop();
    }
}
