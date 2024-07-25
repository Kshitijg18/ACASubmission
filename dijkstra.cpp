#include <bits/stdc++.h>
using namespace std;

struct Edge {
    string destination;
    int distance;
};

class Graph {
public:
    void addNode(const string& node) {
        adjacencyList[node] = vector<Edge>();
    }

    void addEdge(const string& source, const string& destination, int distance) {
        adjacencyList[source].push_back({destination, distance});
        adjacencyList[destination].push_back({source, distance});
    }

    void printGraph() const {
        for (const auto& pair : adjacencyList) {
            cout << pair.first << ": ";
            for (const auto& edge : pair.second) {
                cout << "(" << edge.destination << ", " << edge.distance << ") ";
            }
            cout << endl;
        }
    }

    vector<string> dijkstra(const string& start, const string& end) const {
        unordered_map<string, int> distances;
        unordered_map<string, string> previous;
        auto compare = [&distances](const string& lhs, const string& rhs) {
            return distances.at(lhs) > distances.at(rhs);
        };
        priority_queue<string, vector<string>, decltype(compare)> nodesQueue(compare);

        for (const auto& pair : adjacencyList) {
            distances[pair.first] = INT_MAX;
            previous[pair.first] = "";
        }
        distances[start] = 0;
        nodesQueue.push(start);

        while (!nodesQueue.empty()) {
            string current = nodesQueue.top();
            nodesQueue.pop();

            if (current == end) break;

            for (const auto& edge : adjacencyList.at(current)) {
                int alt = distances[current] + edge.distance;
                if (alt < distances[edge.destination]) {
                    distances[edge.destination] = alt;
                    previous[edge.destination] = current;
                    nodesQueue.push(edge.destination);
                }
            }
        }

        vector<string> path;
        for (string at = end; !at.empty(); at = previous[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        return path;
    }

private:
    unordered_map<string, vector<Edge>> adjacencyList;
};

int main() {
    Graph g;

    // Add nodes
    g.addNode("Hall 1");
    g.addNode("Hall 2");
    g.addNode("Hall 3");
    g.addNode("Hall 4");
    g.addNode("Hall 5");
    g.addNode("Hall 6");
    g.addNode("Hall 7");
    g.addNode("Hall 8");
    g.addNode("Hall 9");
    g.addNode("Hall 10");
    g.addNode("Hall 11");
    g.addNode("Hall 12");
    g.addNode("Hall 13");
    g.addNode("Girls Hostel 1");
    g.addNode("Counselling Service");
    g.addNode("Kargil Chowk");
    g.addNode("Open Air Theatre");
    g.addNode("New Shopping Complex");
    g.addNode("Pronit Ground");
    g.addNode("Health Centre");

    // Add edges
    g.addEdge("Hall 1", "Hall 2", 180);
    g.addEdge("Hall 1", "Hall 5", 75);
    g.addEdge("Hall 2", "Hall 12", 180);
    g.addEdge("Hall 2", "Hall 3", 100);
    g.addEdge("Hall 3", "Hall 4", 100);
    g.addEdge("Hall 4", "New Shopping Complex", 140);
    g.addEdge("Hall 5", "Hall 6", 88);
    g.addEdge("Hall 5", "Hall 3", 75);
    g.addEdge("Hall 5", "Hall 9", 170);
    g.addEdge("Hall 6", "Health Centre", 20);
    g.addEdge("Hall 7", "Hall 8", 30);
    g.addEdge("Hall 7", "Hall 10", 100);
    g.addEdge("Hall 8", "Hall 11", 160);
    g.addEdge("Hall 8", "Open Air Theatre", 50);
    g.addEdge("Hall 9", "Hall 10", 180);
    g.addEdge("Hall 9", "Hall 12", 150);
    g.addEdge("Hall 9", "Hall 13", 100);
    g.addEdge("Hall 10", "Hall 11", 200);
    g.addEdge("Hall 10", "Hall 7", 100);
    g.addEdge("Hall 11", "Pronit Ground", 160);
    g.addEdge("Hall 12", "Hall 13", 280);
    g.addEdge("Hall 12", "Hall 13", 180);
    g.addEdge("Hall 13", "Hall 9", 100);
    g.addEdge("Girls Hostel 1", "Kargil Chowk", 250);
    g.addEdge("Girls Hostel 1", "Counselling Service", 250);
    g.addEdge("Health Centre", "Counselling Service", 245);

    // Print the graph
    g.printGraph();

    // Find the shortest path
    string start = "Hall 5";
    string end = "Health Centre";
    vector<string> path = g.dijkstra(start, end);

    cout << "Shortest path from " << start << " to " << end << ": ";
    for (const string& node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
