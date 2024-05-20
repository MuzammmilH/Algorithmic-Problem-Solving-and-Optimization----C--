//#include <iostream>
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//const int MAX_VERTICES = 1000;
//const int MAX_EDGES = 1000;
//
//void findShortestCycle(int vertex, int parent, int start, int depth, int& shortestCycle, int currentCycle[], int shortestCycleVertices[], bool visited[], const vector<vector<int>>& edges) {
//    visited[vertex] = true;
//    currentCycle[depth] = vertex;
//
//    for (int neighbor : edges[vertex]) {
//        if (neighbor != parent) {
//            if (!visited[neighbor]) {
//                findShortestCycle(neighbor, vertex, start, depth + 1, shortestCycle, currentCycle, shortestCycleVertices, visited, edges);
//            }
//            else if (neighbor == start && depth > 1 && depth < shortestCycle) {
//                shortestCycle = depth;
//                for (int j = 0; j <= depth; ++j) {
//                    shortestCycleVertices[j] = currentCycle[j];
//                }
//            }
//        }
//    }
//
//    visited[vertex] = false;
//}
//
//int main() {
//    int numVertices;
//    cout << "Enter the number of vertices (2 to 1000): ";
//    cin >> numVertices;
//
//    if (numVertices < 2 || numVertices > MAX_VERTICES) {
//        cout << "Invalid number of vertices. Exiting program.\n";
//        return 1;
//    }
//
//    vector<vector<int>> edges(numVertices);
//
//    int u, v;
//    while (true) {
//        cout << "Enter edge (ui vi, enter -1 to stop): ";
//        cin >> u;
//
//        if (u == -1) {
//            break;
//        }
//
//        cin >> v;
//        if (v == -1) {
//            break;
//        }
//
//        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
//            cout << "Invalid vertex label. Vertex label should be between 0 and " << numVertices - 1 << ". Exiting program.\n";
//            return 1;
//        }
//
//        edges[u].push_back(v);
//        edges[v].push_back(u);
//    }
//
//    int shortestCycle = MAX_VERTICES + 1;
//    int shortestCycleVertices[MAX_VERTICES];
//
//    for (int i = 0; i < numVertices; ++i) {
//        bool visited[MAX_VERTICES] = { false };
//        int currentCycle[MAX_VERTICES];
//        findShortestCycle(i, -1, i, 0, shortestCycle, currentCycle, shortestCycleVertices, visited, edges);
//    }
//
//    cout << "Assigned numbers to vertices:" << endl;
//    for (int i = 0; i < numVertices; ++i) {
//        cout << "Vertex " << i << ": " << i << endl;
//    }
//
//    cout << "Connections between vertices:" << endl;
//    for (int i = 0; i < numVertices; ++i) {
//        cout << "Vertex " << i << " is connected to: ";
//        for (int neighbor : edges[i]) {
//            cout << neighbor << " ";
//        }
//        cout << endl;
//    }
//
//    if (shortestCycle == MAX_VERTICES + 1) {
//        cout << "No cycle found in the graph." << endl;
//    }
//    else {
//        cout << "Length of the shortest cycle: " << shortestCycle << endl;
//        cout << "Vertices of the shortest cycle: ";
//        for (int i = 0; i <= shortestCycle; ++i) {
//            cout << shortestCycleVertices[i] << " ";
//        }
//        cout << shortestCycleVertices[0] << endl; // Include the starting vertex at the end
//    }
//
//    return 0;
//}







#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream> 


using namespace std;

const int MAX_VERTICES = 1000;
const int MAX_EDGES = 1000;

void findShortestCycle(int vertex, int parent, int start, int depth, int& shortestCycle, int currentCycle[], int shortestCycleVertices[], bool visited[], const vector<vector<int>>& edges) {
    visited[vertex] = true;
    currentCycle[depth] = vertex;

    for (int neighbor : edges[vertex]) {
        if (neighbor != parent) {
            if (!visited[neighbor]) {
                findShortestCycle(neighbor, vertex, start, depth + 1, shortestCycle, currentCycle, shortestCycleVertices, visited, edges);
            }
            else if (neighbor == start && depth > 1 && depth < shortestCycle) {
                shortestCycle = depth;
                for (int j = 0; j <= depth; ++j) {
                    shortestCycleVertices[j] = currentCycle[j];
                }
            }
        }
    }

    visited[vertex] = false;
}

int main() {
    /*  int numVertices;
      cout << "Enter the number of vertices (2 to 1000): ";
      cin >> numVertices;

      if (numVertices < 2 || numVertices > MAX_VERTICES) {
          cout << "Invalid number of vertices. Exiting program.\n";
          return 1;
      }

      vector<vector<int>> edges(numVertices);

      int u, v;
      while (true) {
          cout << "Enter edge (ui vi, enter -1 to stop): ";
          cin >> u;

          if (u == -1) {
              break;
          }

          cin >> v;
          if (v == -1) {
              break;
          }

          if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
              cout << "Invalid vertex label. Vertex label should be between 0 and " << numVertices - 1 << ". Exiting program.\n";
              return 1;
          }

          edges[u].push_back(v);
          edges[v].push_back(u);
      }*/

    ifstream inputFile("testcase1B.txt");
    if (!inputFile) {
        cout << "Error opening file. Exiting program.\n";
        return 1;
    }

    int numVertices;
    inputFile >> numVertices;

    if (numVertices < 2 || numVertices > MAX_VERTICES) {
        cout << "Invalid number of vertices. Exiting program.\n";
        return 1;
    }

    vector<vector<int>> edges(numVertices);
    int u, v;
    string line;
    getline(inputFile, line); // To move to the next line after reading numVertices

    while (getline(inputFile, line)) {
        if (line.empty()) {
            break; // Assuming empty line indicates end of edge input
        }

        istringstream edgeStream(line);
        edgeStream >> u >> v;

        if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
            cout << "Invalid vertex label. Vertex label should be between 0 and " << numVertices - 1 << ". Exiting program.\n";
            return 1;
        }

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    inputFile.close();



    int shortestCycle = MAX_VERTICES + 1;
    int shortestCycleVertices[MAX_VERTICES];

    for (int i = 0; i < numVertices; ++i) {
        bool visited[MAX_VERTICES] = { false };
        int currentCycle[MAX_VERTICES];
        findShortestCycle(i, -1, i, 0, shortestCycle, currentCycle, shortestCycleVertices, visited, edges);
    }

    cout << "Assigned numbers to vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": " << i << endl;
    }

    cout << "Connections between vertices:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << " is connected to: ";
        for (int neighbor : edges[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    if (shortestCycle == MAX_VERTICES + 1) {
        cout << "No cycle found in the graph." << endl;
    }
    else {
        cout << "Length of the shortest cycle: " << shortestCycle << endl;
        cout << "Vertices of the shortest cycle: ";
        for (int i = 0; i <= shortestCycle; ++i) {
            cout << shortestCycleVertices[i] << " ";
        }
        cout << shortestCycleVertices[0] << endl; // Include the starting vertex at the end
    }

    return 0;
}
