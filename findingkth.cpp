#include <iostream>
#include <set>
#include <vector>

using namespace std;

//Finding k-th
int main(){
    int size;
    set<int> scores;

    cin >> size;

    int temp_score;
    for(int i = 0; i < size; i++){
        cin >> temp_score;
        scores.insert(temp_score);
    }

    int q_size;
    cin >> q_size;

    vector<int> queries(q_size);
    for(int i = 0; i < q_size; i++){
        cin >> queries[i];
    }

    set<int>::reverse_iterator it;
    for(int i = 0; i < q_size; i++){
        it = scores.rbegin();
        advance(it, queries[i] - 1);
        cout << *it << endl;
    }

    return 0;
}