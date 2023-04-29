#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> subtask;
vector<int> work; //exact time

int main(){

    int n, m;
    double sum = 0;

    cin >> n >> m;

    subtask.resize(m);
    work.resize(n);

    for( int i = 0 ; i < m ; i++ )
        cin >> subtask[i];

    sort( subtask.begin(), subtask.end() );

    for( int i = 0 ; i < m ; i++ ){
        work[ i % n ] += subtask[i];
        sum += work[ i % n ];
    }

    printf("%.3f", sum / m );

}
