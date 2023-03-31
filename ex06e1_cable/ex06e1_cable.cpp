#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int graph[1000][1000];
vector<bool> check;
vector<int> dis;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

int main(){

    int n;
    int node, cost;
    int ans = 0;

    cin >> n;

    check.resize(n);
    dis.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        dis[i] = 2000000000;
        check[i] = false;
    }


    for( int i = 0 ; i < n - 1 ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
            cin >> cost;
            graph[i][j] = cost;
            graph[j][i] = cost;
        }
    }

    //first node to add
    q.push({0, 0});

    while( !q.empty() ){

        cost = q.top().first;
        node = q.top().second;
        q.pop();

        //if node already connect, do nothing
        if( check[node] ) continue;

        //else we add this node to MST
        ans += cost;
        check[node] = true;

        for( int i = 0 ; i < n ; i++ ){

            //if node i isn't in MST and distance to node i is fewer than before
            if( !check[i] && dis[i] > graph[node][i] ){
                dis[i] = graph[node][i];
                q.push( { dis[i], i });
            }

        }

    }

    cout << ans;



}
