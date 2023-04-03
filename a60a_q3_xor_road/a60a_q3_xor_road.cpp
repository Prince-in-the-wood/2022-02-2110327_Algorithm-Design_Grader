#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<bool> check;
vector<unsigned long long> graph;
vector<unsigned long long> dis;

int main(){

    int n;
    unsigned long long weight, node, ans = 0;

    cin >> n;

    check.resize(n);
    graph.resize(n);
    dis.resize(n);

    for( int i = 0 ; i < n ; i++ )
        cin >> graph[i];

    priority_queue<pair<unsigned long long, unsigned long long>> q;

    q.push({0, 0});

    while( !q.empty() ){
        weight = q.top().first;
        node = q.top().second;
        q.pop();

        if( check[node] )continue;

        check[node] = true;
        ans += weight;

        for( int i = 0 ; i < n ; i++ ){
            weight = graph[node] ^ graph[i];
            if( !check[i] && dis[i] < weight ){
                q.push( { weight, i } );
            }
        }
    }

    cout << ans;
}
