## B. Juice Wishlist

### Idea:

There are `N` customers and `M` canned juices.

Each customer `i` has a **wishlist** containing `Lᵢ` juices in a specific order of preference.

Customers choose their drinks **in order from 1 → N**.

The rule is:

- If the customer’s wishlist contains a juice that **has not been chosen yet**, they pick the **first such juice in their list**.
- If all juices in their wishlist are already taken, they choose **water**, represented by `0`.

Our task is to determine **which drink each customer ends up getting**.

---

### Key Observation

Once a juice is chosen by a customer, it **cannot be chosen again**.

So we simply need to keep track of which juices have already been taken.

We maintain a boolean array:

``used[j]``

where `used[j]` indicates whether juice `j` has already been selected.

---

### Strategy

For each customer:

1. Read the length `L` of their wishlist.
2. Traverse the wishlist in order.
3. If we find a juice that has **not been used**, we:
   - assign that juice to the customer
   - mark it as used
   - stop checking further items.
4. If no available juice is found, the customer gets **water (`0`)**.

---

### Example

For:

Process:

Customer 1 → picks `1`  
Customer 2 → `1` is already taken → picks `3`

Output:
1  3


---

### Complexity

Let `L` be the maximum wishlist size.

- Time Complexity: **O(N × L)**
- Space Complexity: **O(M)**

Since the constraints are small (`≤100`), this approach is efficient.

---

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<bool> used (M + 1, false);

    for(int i=0; i < N; i++){
        int L;
        cin >> L;

        vector<int> wishlist(L);

        for(int j = 0; j<L ; j++){
            cin >> wishlist[j];
        }

        int chosen = 0;

        for(int juice : wishlist){
            if(!used[juice]){
                chosen = juice;
                used[juice] = true;
                break;
            }
        }

        cout << chosen << "\n";
    }
    return 0;
}
```