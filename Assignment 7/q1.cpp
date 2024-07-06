#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void findPaths(map<int, vector<int>>& graph, int source, int destination, vector<int>& currentPath, vector<vector<int>>& allPaths) {
    currentPath.push_back(source);

    if (source == destination) {
        allPaths.push_back(currentPath);
    } else {
        for (int neighbor : graph[source]) {
            if (find(currentPath.begin(), currentPath.end(), neighbor) == currentPath.end()) {
                findPaths(graph, neighbor, destination, currentPath, allPaths);
            }
        }
    }
    currentPath.pop_back();
}
