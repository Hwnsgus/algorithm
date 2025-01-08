#include <iostream>
#include <vector>
#include <iomanip> // for std::setw

using namespace std;

const int INF = 1e9; // 무한대를 나타내는 큰 값

void printGraph(const vector<vector<int>>& graph) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] == INF)
                cout << setw(4) << "INF";
            else
                cout << setw(4) << graph[i][j];
        }
        cout << endl;
    }
}

int main() {
    // 그래프 초기화 (4개의 노드 예시)
    vector<vector<int>> graph = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    int n = graph.size();

    // Floyd-Warshall 알고리즘
    vector<vector<int>> dist = graph;
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 결과 출력
    cout << "Initial Graph:" << endl;
    printGraph(graph);

    cout << "\nShortest Paths (Floyd-Warshall Result):" << endl;
    printGraph(dist);

    return 0;
}
