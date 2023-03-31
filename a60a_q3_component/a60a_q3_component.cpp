#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> check;

void bfs( int node ){

    queue<int> q;

    q.push(node);

    while( !q.empty() ){
        node = q.front();
        q.pop();

        if( check[node] )continue;
        check[node] = true;

        for( int i = 0 ; i < graph[node].size() ; i++ ){
            if( !check[ graph[node][i] ] ){
                q.push( graph[node][i] );
            }
        }

    }

}

int main(){

    int v, e;
    int a, b;
    int ans = 0;

    cin >> v >> e;

    graph.resize(v+1);
    check.resize(v+1);

    for( int i = 0 ; i < e ; i++ ){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for( int i = 1 ; i <= v ; i++ ){

        if( check[i] )continue;
        bfs(i);
        ans++;
    }

    cout << ans;
}
