#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int size;
    cin >> size;

    vector<int> candies(size);
    for(int i = 0; i < size; i++){
        cin >> candies[i];
    }

    int swaps = 0;

    int ones = 0;
    int twos = 0;
    int threes = 0;
    vector<vector<int>> positions(3, vector<int>(3));

    for(int i = 0; i < size; i++){ // Counting the number of 1's, 2's, and 3's
        if(candies[i] == 1){
            ones++;
        }
        else if(candies[i] == 2){
            twos++;
        }
        else{
            threes++;
        }
    }

    for(int i = 0; i < size; i++){ // Storing the number in each position
        if(candies[i] == 1){
            if(i < ones){
                continue;
            }
            else if(i < twos + ones){
                positions[0][1]++;
            }
            else{
                positions[0][2]++;
            }
        }
        else if(candies[i] == 2){
            if(i < ones){
                positions[1][0]++;
            }
            else if(i < twos + ones){
                continue;
            }
            else{
                positions[1][2]++;
            }
        }
        else{
            if(i < ones){
                positions[2][0]++;
            }
            else if(i < twos + ones){
                positions[2][1]++;
            }
            else{
                continue;
            }
        }
    }

    int temp = min(positions[0][1], positions[1][0]); // Swapping 1's and 2's
    swaps += temp;
    positions[0][1] -= temp;
    positions[1][0] -= temp;

    temp = min(positions[0][2], positions[2][0]); // Swapping 1's and 3's
    swaps += temp;
    positions[0][2] -= temp;
    positions[2][0] -= temp;

    temp = min(positions[1][2], positions[2][1]); // Swapping 2's and 3's
    swaps += temp;
    positions[1][2] -= temp;
    positions[2][1] -= temp;

    if(positions[0][1] != 0){
        swaps += (2 * positions[0][1]);
    }
    else if(positions[0][2] != 0){
        swaps += (2 * positions[0][2]);
    }

    cout << swaps;

    return 0;
}