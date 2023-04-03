#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> beauty;
vector<int> fire;
vector<vector<int>> wind;

int main(){

    int n, m, k;
    int u, v;
    int sum = 0;

    cin >> n >> m >> k;

    beauty.resize(n);
    wind.resize(n);
    fire.resize(n);

    for( int i = 0 ; i < n ; i++ ){
        cin >> beauty[i];
        sum += beauty[i];
    }


    for( int i = 0 ; i < k ; i++ ){
        cin >> fire[i];
    }

    for( int i = 0 ; i < m ; i++ ){
        cin >> u >> v;

        wind[u].push_back(v);
    }

    queue<int> q;

    for( int i = 0 ; i < k ; i++ ){

        q.push( fire[i] );

        sum -= beauty[fire[i]];
        beauty[fire[i]] = 0;

        while( !q.empty() ){
            u = q.front();
            q.pop();

            for( int i = 0 ; i < wind[u].size() ; i++ ){
                v = wind[u][i];
                if( beauty[v] > 0 ){
                    sum -= beauty[v];
                    beauty[v] = 0;
                    q.push(v);
                }
            }

        }

        cout << sum << " ";

    }

}
