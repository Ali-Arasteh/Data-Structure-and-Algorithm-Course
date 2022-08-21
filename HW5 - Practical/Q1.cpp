#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <vector>  
using namespace std;

int main() 
{
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][n];
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix[i][j] = 0;
        }
    }
    int n1, n2, w;
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &n1, &n2, &w);
        matrix[n1-1][n2-1] = w;
        matrix[n2-1][n1-1] = w;
    }
    int sum = 0;
    int temp;
    int current_node;
    int bfs[n]; 
    struct Node {
        int node;
        int parent;
    };
    Node temp_node_1, temp_node_2;
    int minimum;
    bool flag;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (matrix[i][j] > 0) {
                temp = matrix[i][j];
                matrix[i][j] = 0;
                for (int k=0; k<n; k++) {
                    bfs[k] = 0;
                }
                vector<int> v;
                v.push_back(i);
                while (!v.empty()) {
                    current_node = v[0];
                    bfs[current_node] = 1;
                    if (current_node == j) {
                        break;
                    }
                    for (int k=0; k<n; k++) {
                        if (matrix[current_node][k] > 0 && bfs[k] == 0) {
                            v.push_back(k);
                        }
                    }
                    v.erase(v.begin());
                }
                matrix[i][j] = temp;
                if (bfs[j] == 1) {
                    int max_flow[n][n];
                    for (int k=0; k<n; k++) {
                        for (int l=0; l<n; l++) {
                            if (matrix[k][l] > 0 && matrix[k][l] < matrix[i][j]) {
                                max_flow[k][l] = 1;
                            }
                            else {
                                max_flow[k][l] = 0;
                            }
                        }
                    }
                    do {
                        for (int k=0; k<n; k++) {
                            bfs[k] = -1;
                        }
                        vector<Node> nodes;
                        temp_node_1.node = i;
                        temp_node_1.parent = i;
                        nodes.push_back(temp_node_1);
                        while (!nodes.empty()) {
                            temp_node_1 = nodes[0];
                            bfs[temp_node_1.node] = temp_node_1.parent;
                            if (temp_node_1.node == j) {
                                break;
                            }
                            for (int k=0; k<n; k++) {
                                if (max_flow[temp_node_1.node][k] > 0 && bfs[k] == -1) {
                                    temp_node_2.node = k;
                                    temp_node_2.parent = temp_node_1.node;
                                    nodes.push_back(temp_node_2);
                                }
                            }
                            nodes.erase(nodes.begin());
                        }
                        if (bfs[j] != -1) {
                            temp = bfs[j];
                            minimum = max_flow[temp][j];
                            while (temp != bfs[temp]) {
                                if (max_flow[bfs[temp]][temp] < minimum) {
                                    minimum = max_flow[bfs[temp]][temp];
                                }
                                temp = bfs[temp];
                            }
                            sum += minimum;
                            temp = j;
                            while (temp != bfs[temp]) {
                                max_flow[bfs[temp]][temp] -= minimum;
                                max_flow[temp][bfs[temp]] += minimum;
                                temp = bfs[temp];
                            }
                            flag = true;
                        }
                        else {
                            flag = false;
                        }
                    }
                    while (flag);
                }
            }
        }
    }
    printf("%d", sum);
    return 0;
}