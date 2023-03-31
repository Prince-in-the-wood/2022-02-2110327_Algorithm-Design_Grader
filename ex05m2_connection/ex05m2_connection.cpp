#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> graph;
vector<int> check;

int initCheck(){

    for( int i = 0 ; i < check.size() ; i++ )
        check[i] = 0;
}

int bfs( int node, int k ){

    int nw, ans = 0;
    queue<int> q;
    q.push(node);

    while( !q.empty() ){
        nw = q.front();
        q.pop();

        if( check[nw] <= k ){
            ans++;
        }

        for( int i = 0 ; i < graph[nw].size() && check[nw] + 1 <= k ; i++ ){
            if( check[graph[nw][i]] == 0 && graph[nw][i] != node ){
                check[graph[nw][i]] = check[nw] + 1;
                q.push(graph[nw][i]);
            }
        }
    }

    return ans;
}

int main(){
    int n, e, k;
    int a, b;
    int ans = 0, cnt, node = 0;

    cin >> n >> e >> k;

    graph.resize(n);
    check.resize(n);

    for( int i = 0 ; i < e ; i++ ){
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for( int i = 0 ; i < n ; i++ ){
        initCheck();

        ans = max( ans, bfs(i, k));

    }

    cout << ans;

}
