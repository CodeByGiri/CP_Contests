## B - Split Ticketing

### Idea
We are given costs between pairs.  
We need to check if there exist `a < b < c` such that:

$$
C[a][b] + C[b][c] = C[a][c]
$$

### Approach
- Store the triangular matrix
- Try all triples `(a, b, c)`
- Check condition directly

Constraints are small → brute force works

### Complexity
Time: O(n³)  
Space: O(n²)

### Code
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;

    vector<vector<long long>> C(N + 1, vector<long long>(N + 1, 0));
    
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            cin >> C[i][j];
        }
    }

    for (int a = 1; a <= N - 2; a++) {
        for (int b = a + 1; b <= N - 1; b++) {
            for (int c = b + 1; c <= N; c++) {
                if (C[a][b] + C[b][c] < C[a][c]) {
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}
```