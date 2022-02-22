#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> p;

void addEdge(int n, p neighbors[][n], int end_index[], int x, int y, int z){
    neighbors[x][end_index[x]++] = make_pair(y, z);
    neighbors[y][end_index[y]++] = make_pair(x, z);
}

void dijkstra(vector<p> neighbors[], int end_index[], int n, int src){
    priority_queue<p, vector<p>, greater<p>> pq;

    int distance[n];
    fill(distance, distance + n, INT_MAX);

    pq.push(make_pair(0, src));
    distance[src] = 0;

    while(!pq.empty()){
        int curr = pq.top().second;
        pq.pop();

        for(int i = 0; i < end_index[curr]; i++){
            int v = neighbors[curr][i].first;
            int w = neighbors[curr][i].second;

            bool check = w > distance[curr];
            int weight = (w * check) + (distance[curr] * !check);
            if(weight < distance[v]){
                distance[v] = weight;
                pq.push(make_pair(weight, v));
            }
        }
    }

    int max = distance[0];
    for(int i = 1; i < n; i++){
        bool check = distance[i] > max;
        max = (distance[i] * check) + (max * !check);
    }
    cout << max;
}

int main(){
    int n, m;
    cin >> n >> m;

    p neighbors[n][n];
    int end_index[n];
    fill(end_index, end_index + n, 0);

    int x, y, z;

    for(int i = 0; i < m; i++){
        cin >> x >> y >> z;
        addEdge(n, neighbors, end_index, x, y, z);
    }

    dijkstra(neighbors, n, 0);

    return 0;
}