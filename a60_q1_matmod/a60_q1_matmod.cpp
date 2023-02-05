#include <iostream>
#include <vector>

using namespace std;

const int matrixSize = 4;
vector<int> A(matrixSize);
vector<int> identity = { 1, 0, 0, 1 };

vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N,int k){

    vector<int> ans(matrixSize);

    ans[0] = ( M[0] * N[0] + M[1] * N[2] ) % k;
    ans[1] = ( M[0] * N[1] + M[1] * N[3] ) % k;
    ans[2] = ( M[2] * N[0] + M[3] * N[2] ) % k;
    ans[3] = ( M[2] * N[1] + M[3] * N[3] ) % k;

    return ans;

}

vector<int> matMod( int n, int k ){

    if( n == 0 ){
        return identity;
    }

    if( n == 1 ){
        return A;
    }

    vector<int> matrix = matMod( n/2, k );

    return matrix_multiply( matrix_multiply( matrix, matrix, k ), matMod( n % 2, k ), k );


}



int main(){

    int n, k;
    int a;

    cin >> n >> k;

    for( int i = 0; i < matrixSize ; i++ )
        cin >> A[i];


    for( int i = 0 ; i < matrixSize ; i++ )
        A[i] %= k;

    vector<int> ans = matMod( n, k );

    for( int i = 0 ; i < matrixSize ; i++ )
        cout << ans[i] << " ";
}
