#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool canAddToPath(int vertex, vector<vector<int>>& graph, vector<int>& currentPath, int pos) {
    if (find(graph[currentPath[pos - 1]].begin(), graph[currentPath[pos - 1]].end(), vertex) == graph[currentPath[pos - 1]].end())
        return false;
    if (find(currentPath.begin(), currentPath.end(), vertex) != currentPath.end())
        return false;
    return true;
}

bool findHamPathHelper(vector<vector<int>>& graph, vector<int>& currentPath, int pos) {
    if (pos == graph.size())
        return true;
    for (int vertex = 0; vertex < graph.size(); vertex++) {
        if (canAddToPath(vertex, graph, currentPath, pos)) {
            currentPath[pos] = vertex;
            if (findHamPathHelper(graph, currentPath, pos + 1))
                return true;
            currentPath[pos] = -1;
        }
    }
    return false;
}

bool findHamPath(vector<vector<int>>& graph) {
    vector<int> currentPath(graph.size(), -1);
    currentPath[0] = 0;
    if (!findHamPathHelper(graph, currentPath, 1)) {
        cout << "No Hamiltonian Path exists" << endl;
        return false;
    }
    for (int i = 0; i < currentPath.size(); i++)
        cout << currentPath[i] << " ";
    cout << endl;
    return true;
}

bool canAddToCycle(int vertex, vector<vector<int>>& graph, vector<int>& currentPath, int pos) {
    if (find(graph[currentPath[pos - 1]].begin(), graph[currentPath[pos - 1]].end(), vertex) == graph[currentPath[pos - 1]].end())
        return false;
    if (find(currentPath.begin(), currentPath.end(), vertex) != currentPath.end())
        return false;
    return true;
}

bool findHamCycleHelper(vector<vector<int>>& graph, vector<int>& currentPath, int pos) {
    if (pos == graph.size()) {
        if (find(graph[currentPath[pos - 1]].begin(), graph[currentPath[pos - 1]].end(), currentPath[0]) != graph[currentPath[pos - 1]].end())
            return true;
        else
            return false;
    }
    for (int vertex = 1; vertex < graph.size(); vertex++) {
        if (canAddToCycle(vertex, graph, currentPath, pos)) {
            currentPath[pos] = vertex;
            if (findHamCycleHelper(graph, currentPath, pos + 1))
                return true;
            currentPath[pos] = -1;
        }
    }
    return false;
}

bool findHamCycle(vector<vector<int>>& graph) {
    vector<int> currentPath(graph.size(), -1);
    currentPath[0] = 0;
    if (!findHamCycleHelper(graph, currentPath, 1)) {
        cout << "No Hamiltonian Cycle exists" << endl;
        return false;
    }
    for (int i = 0; i < currentPath.size(); i++)
        cout << currentPath[i] << " ";
    cout << currentPath[0] << " ";
    cout << endl;
    return true;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2, 3},
        {0, 2, 3},
        {0, 1, 3},
        {0, 1, 2}
    };

    cout << "Hamiltonian Path:" << endl;
    findHamPath(graph);

    cout << "Hamiltonian Cycle:" << endl;
    findHamCycle(graph);

    return 0;
}
