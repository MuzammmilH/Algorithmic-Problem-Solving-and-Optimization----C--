//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <unordered_map>
//
//using namespace std;
//
//const int MAX_NODES = 4; // Maximum number of nodes
//
//// Function to calculate the average travel time for a given path
//double calculateAverageTime(const char* path, const int pathLength, const int distances[MAX_NODES][MAX_NODES]) {
//    double totalTravelTime = 0;
//    for (int i = 0; i < pathLength - 1; ++i) {
//        char source = path[i] - 'A';
//        char destination = path[i + 1] - 'A';
//
//        totalTravelTime += distances[source][destination];
//    }
//
//    return totalTravelTime;
//}
//
//int main() {
//    // Open the file
//    ifstream inputFile("testcase1.txt");
//
//    if (!inputFile.is_open()) {
//        cout << "Error: Unable to open the file." << endl;
//        return 1;
//    }
//
//    // Define nodes and distances
//    int distances[MAX_NODES][MAX_NODES] = { 0 };
//    unordered_map<string, int> distanceMap;
//
//    // Read Paths and Distances
//    string line;
//    while (getline(inputFile, line) && !line.empty()) {
//        stringstream ss(line);
//        string path;
//        int distance;
//
//        ss >> path >> distance;
//
//        char source = path[0];
//        char destination = path[2];
//
//        distances[source - 'A'][destination - 'A'] = distance;
//        distanceMap[path] = distance;
//    }
//   
//    inputFile.close();
//    for (int i = 0; i < MAX_NODES; i++)
//    {
//        for (int j = 0; j < MAX_NODES; j++)
//        {
//            cout << distances[i][j] << "  ";
//        }
//        cout << endl;
//    }
//
//    // Define possible paths
//    const char* paths[] = {
//
//        "AB",
//        "AC",
//        "BC",
//    };
//
//    // Calculate and print path costs
//    cout << "Path Costs:" << std::endl;
//    for (const char* path : paths) {
//        int pathLength = 0;
//        double pathCost = 0;
//        while (path[pathLength] != '\0') {
//            ++pathLength;
//        }
//
//        cout << path << " = ";
//        for (int i = 0; i < pathLength - 1; ++i) {
//            char source = path[i] - 'A';
//            char destination = path[i + 1] - 'A';
//
//            pathCost += distances[source][destination];
//            cout << distances[source][destination];
//            if (i < pathLength - 2) {
//                cout << " + ";
//            }
//        }
//        cout << " = " << pathCost << " minutes" << std::endl;
//    }
//
//    // Calculate and print total sum of times, total number of paths, and average time
//    double totalSumOfTimes = 0;
//    int totalPaths = 0;
//
//    std::cout << "\nResults:" << endl;
//    for (const char* path : paths) {
//        int pathLength = 0;
//        while (path[pathLength] != '\0') {
//            ++pathLength;
//        }
//
//        double pathCost = calculateAverageTime(path, pathLength, distances);
//        totalSumOfTimes += pathCost;
//        totalPaths++;
//    }
//
//    cout << "Total sum of times = " << totalSumOfTimes << " minutes" << endl;
//    cout << "Total number of paths = " << totalPaths << endl;
//    cout << "Average time to move between locations = " << totalSumOfTimes / totalPaths << " minutes" << endl;
//
//    return 0;
//}
