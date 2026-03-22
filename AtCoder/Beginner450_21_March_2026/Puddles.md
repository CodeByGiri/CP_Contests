## Problem C. Puddles

### Idea
​We need to count connected components of white cells (.) that are completely enclosed by black cells (#). If a white region touches the boundary of the grid, it is a "lake" or "ocean" and not a "puddle."

---

​### Approach
​Eliminate Edge Regions: Start a BFS or DFS from every white cell located on the four edges of the grid. Mark all reachable white cells as "visited" or "external."
​Count Interior Puddles: Iterate through the interior of the grid. If you find a white cell that hasn't been visited yet:
​It must belong to a surrounded puddle.
​Increment the puddle_count.
​Start a BFS/DFS from that cell to mark the entire puddle as "visited" so it isn't counted again.

---

​### Complexity
​Time: O(H \times W) — Each cell is visited at most once.
Space: O(H \times W) — To store the grid and the visited status.

---
### Code
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int H, W;
vector<string> grid;
vector<vector<bool>> visited;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

void bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = curr.first + dr[i];
            int nc = curr.second + dc[i];

            if (nr >= 0 && nr < H && nc >= 0 && nc < W && grid[nr][nc] == '.' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> H >> W)) return 0;
    grid.resize(H);
    visited.assign(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) cin >> grid[i];

    for (int i = 0; i < H; i++) {  //flood fill white cells on border
        if (grid[i][0] == '.' && !visited[i][0]) bfs(i, 0);
        if (grid[i][W - 1] == '.' && !visited[i][W - 1]) bfs(i, W - 1);
    }

    for (int j = 0; j < W; j++) { 
        if (grid[0][j] == '.' && !visited[0][j]) bfs(0, j);
        if (grid[H - 1][j] == '.' && !visited[H - 1][j]) bfs(H - 1, j);
    }

    int surr_count = 0;
    for (int i = 1; i < H - 1; i++) {
        for (int j = 1; j < W - 1; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                surr_count++;
                bfs(i, j);
            }
        }
    }
    cout << surr_count << endl;

    return 0;
}
```
