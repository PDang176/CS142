#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> v(n);
    for(unsigned i = 0; i < n; i++){
        cin >> v[i];
    }

    // Find longest increasing sequence starting at each index
    vector<int> lis(n, 1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Checking if sequence is just increasing
    if(lis[n - 1] == n){
        cout << "0";
        return 0;
    }

    // Find longest decreasing sequence ending at each index
    vector<int> lds(n, 1);
    for(int i = n - 2; i >= 0; i--){
        for(int j = n - 1; j > i; j--){
            if(v[i] > v[j] && lds[i] < lds[j] + 1){
                lds[i] = lds[j] + 1;
            }
        }
    }

    // Checking if sequence is just decreasing
    if(lds[0] == n){
        cout << "0";
        return 0;
    }

    int lus = lis[0] + lds[0] - 1;
    for(int i = 1; i < n; i++){
        if(lis[i] + lds[i] - 1 > lus){
            lus = lis[i] + lds[i] - 1;
        }
    }

    cout << lus;

    return 0;
}