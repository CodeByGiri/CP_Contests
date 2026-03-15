## C. Omelette Restaurant

### Idea:

A restaurant operates for `N` days.

Each day has three actions:

1. **Morning** → `Aᵢ` eggs are purchased.
2. **Noon** → `Bᵢ` eggs are used.
3. **Evening** → Eggs that have been stored for `D` days are discarded.

Eggs are always used in the **order they were purchased (FIFO)**.

Our task is to determine **how many eggs remain after day `N`**.

---

### Key Observation

Since eggs must be used in the order they were bought, the process naturally behaves like a **queue**.

However, storing each egg individually would be inefficient.  
Instead, we store eggs in **batches**.

Each batch contains:

**amount of eggs** and **purchase day**


This allows us to efficiently simulate buying, using, and discarding eggs.

---

### Strategy

We maintain a queue of egg batches.

For each day `i`:

1. Add the purchased eggs `(A[i], i)` to the queue.
2. Use `B[i]` eggs:
   - Take eggs from the **front batch**.
   - Reduce its amount.
   - Remove the batch if it becomes empty.
3. Remove expired eggs:
   - If a batch was bought on day `j`, it expires when:

$$
j + D <= i
$$


4. Continue this process for all `N` days.

Finally, sum the eggs remaining in all batches.

---

### Example

Suppose:

N = 2
D = 2

Day 1:
Buy 3 eggs
Use 1 egg

Day 2:
Buy 2 eggs
Use 1 egg

Process:

Day 1 queue → (2 eggs left)
Day 2 queue → (1 egg from day1, 2 eggs from day2)


No eggs expire yet.

Remaining eggs = **3**.

---

### Complexity

Each batch is inserted and removed at most once.

- Time Complexity: **O(N)**
- Space Complexity: **O(N)**

---

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void solve() {
    int N, D;
    cin >> N >> D;
    
    vector<long long> A(N + 1), B(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];
    
    deque<pair<long long, int>> q;
    
    for (int i = 1; i <= N; i++) {

        //Carry over of eggs
        if (A[i] > 0)
            q.push_back({A[i], i});
        
        //Using while shop open
        long long needed = B[i];
        while (needed > 0 && !q.empty()) {
            if (q.front().first <= needed) {
                needed -= q.front().first;
                q.pop_front();
            } else {
                q.front().first -= needed;
                needed = 0; 
            }
        }
        
        // Removing
        int expiration_threshold = i - D;
        while (!q.empty() && q.front().second <= expiration_threshold) {
            q.pop_front();
        }
    }
    
    long long total_remaining = 0;
    for (auto batch : q) {
        total_remaining += batch.first;
    }
    
    cout << total_remaining << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
```