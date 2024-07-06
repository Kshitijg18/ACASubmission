#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

bool isAccessible(int r, int c, int h, int R, int C, int H, const vector<vector<vector<int>>>& maze) {
    return 0 <= r && r < R && 0 <= c && c < C && 0 <= h && h < H && maze[r][c][h] == 0;
}

int findShortestRoute(int R, int C, int H, int sr, int sc, int sh, int er, int ec, int eh, const vector<vector<vector<int>>>& maze) {
    vector<tuple<int, int, int>> moves = {
        {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, 
        {0, 1, 0}, {0, 0, -1}, {0, 0, 1}
    };
    
    queue<tuple<int, int, int, int>> bfsQueue;
    bfsQueue.push({sr, sc, sh, 0});
    
    set<tuple<int, int, int>> explored;
    explored.insert({sr, sc, sh});
    
    while (!bfsQueue.empty()) {
        auto [r, c, h, steps] = bfsQueue.front();
        bfsQueue.pop();
        
        if (r == er && c == ec && h == eh) {
            return steps;
        }
        
        for (const auto& [dr, dc, dh] : moves) {
            int nr = r + dr, nc = c + dc, nh = h + dh;
            
            if (isAccessible(nr, nc, nh, R, C, H, maze) && explored.find({nr, nc, nh}) == explored.end()) {
                explored.insert({nr, nc, nh});
                bfsQueue.push({nr, nc, nh, steps + 1});
            }
        }
    }
    
    return -1;
}

int main() {
    int R, C, H;
    cin >> R >> C >> H;
    
    int sr, sc, sh, er, ec, eh;
    cin >> sr >> sc >> sh >> er >> ec >> eh;
    
    vector<vector<vector<int>>> maze(R, vector<vector<int>>(C, vector<int>(H)));
    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            for (int k = 0; k < H; ++k) {
                cin >> maze[i][j][k];
            }
        }
    }
    
    int shortestPath = findShortestRoute(R, C, H, sr, sc, sh, er, ec, eh, maze);
    cout << shortestPath << endl;
    
    return 0;
}