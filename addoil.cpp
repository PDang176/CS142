#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    vector<vector<int>> paths(n, vector<int>(n, 0));

    for(int i = 0; i < m; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        paths[edges[i][0]][edges[i][1]] = edges[i][2];
        paths[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    // Implement Dijkstra's algorithm
    vector<int> distance(n, INT_MAX);
    distance[0] = 0;

    auto compare = [&distance](int lhs, int rhs){
        return distance[lhs] > distance[rhs];
    };

    priority_queue<int, vector<int>, decltype(compare)> pq(compare);

    pq.push(0);

    unordered_set<int> seen;

    while(!pq.empty()){
        int curr = pq.top();
        pq.pop();

        seen.insert(curr);

        for(int i = 0; i < n; i++){
            // Is a neighbor of current vertex and not already seen
            if(seen.count(i) == 0 && paths[curr][i] > 0){
                int weight = paths[curr][i] > distance[curr] ? paths[curr][i] : distance[curr];
                if(weight < distance[i]){
                    distance[i] = weight;
                    pq.push(i);
                }
            }
        }
    }

    int max_tank = distance[0];
    for(int i = 1; i < n; i++){
        if(distance[i] > max_tank){
            max_tank = distance[i];
        }
    }

    cout << max_tank;

    return 0;
}