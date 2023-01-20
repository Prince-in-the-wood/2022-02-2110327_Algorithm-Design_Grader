#include <iostream>
#include <vector>

using namespace std;

void permutation(int n,
                 vector<int> &sol,
                 vector<bool> &used,
                 vector<vector<int>> &rule,
                 int len ){

    if( n == len ){
        for( int i = 0 ; i < n ; i++ ){
            cout << sol[i] << " ";
        }
        cout << "\n";
        return;
    }

    bool okay;

    for( int i = 0 ; i < n ; i++ ){

        if( used[i] ) continue;

        okay = true;

        for( int j = 0 ; j < rule[i].size() ; j++ ){
            if( !used[ rule[i][j] ] ){
                okay = false;
                break;
            }
        }

        if( okay ){

            used[i] = true;
            sol[len] = i;
            permutation( n, sol, used, rule, len + 1);
            used[i] = false;
        }


    }

}

int main(){

    int n, m;
    int a, b;

    cin >> n >> m;

    vector<int> sol(n);
    vector<bool> used(n, false);
    vector<vector<int>> rule(n);// rule[i][j] must come before i

    for( int i = 0 ; i < m ; i++ ){
        cin >> a >> b;
        rule[b].push_back(a);
    }


    permutation( n, sol, used, rule, 0 );

}
