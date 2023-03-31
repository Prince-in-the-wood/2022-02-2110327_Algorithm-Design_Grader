#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, pair<int, int>> pairOfIntPII;

vector<int> parent;
priority_queue<pairOfIntPII, vector<pairOfIntPII>, greater<pairOfIntPII>> q;

int findParent( int n ){
    if( parent[n] == n )return n;
    return findParent( parent[n] );
}

int main(){

    int n;
    int node1, node2, cost;
    int parent1, parent2;
    int ans = 0;

    cin >> n;

    parent.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        parent[i] = i;
    }


    for( int i = 0 ; i < n - 1 ; i++ ){
        for( int j = i + 1 ; j < n ; j++ ){
            cin >> cost;
            q.push({cost, { i, j} } );
        }
    }

    //Kruskal's Algorithm
    while( !q.empty() ){

        cost = q.top().first;
        node1 = q.top().second.first;
        node2 = q.top().second.second;
        q.pop();

        //if node1 and node2 already connect, do nothing
        parent1 = findParent(node1);
        parent2 = findParent(node2);
        if( parent1 == parent2 ) continue;

        //else we add this node and its connected component to MST
        ans += cost;
        parent[parent1] = parent2;

    }

    cout << ans;



}

