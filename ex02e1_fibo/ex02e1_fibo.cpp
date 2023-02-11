#include <iostream>

using namespace std;

int main(){

    int n;
    int f0 = 0, f1 = 1, tmp;

    cin >> n;

    for( int i = 1 ; i < n ; i++ ){
        tmp = f1;
        f1 = f1 + f0;
        f0 = tmp;
    }

    cout << f1;
}
