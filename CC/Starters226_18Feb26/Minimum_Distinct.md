## D. Minimum Distinct

### Idea:
We are given an array of `N` integers.

We can perform at most `K` operations.

In one operation:

- Choose indices `i < j`
- Set `A[j] = A[i]`

We must minimize the number of distinct elements in the array.

---

### Key Observation:

Since we can only copy values **forward** (`i < j`),  
we cannot completely eliminate the value of the **first element**.

Because there is no earlier index to convert `A[0]`.

So:

- The value `A[0]` will always remain in the array.
- We can only eliminate other distinct values.

---

### Strategy:

1. Count frequency of each distinct value.
2. Store the value of the first element.
3. Exclude its frequency(we cannot remove it).
4. Sort the remaining frequencies in ascending order.
5. Greedily remove the smallest groups first.
6. Each group with frequency `f` costs `f` operations.

---

### Why Greedy?

To completely remove a distinct value with frequency `f`, 
we must convert all its occurences.

So removing one distinct value costs:

$$
f \text{ operations}
$$

To minimize distinct values, we remove the smallest groups first.

---

### Final Answer:

Then:

$$
\text{Answer} = D - r
$$

We do not need `max(1, ...)` because
the first element's value is always preserved.

---

### Example:

For:

```
N = 4, K = 2
Array = [1,2,3,4]
```

Frequencies:

```
1:1
2:1
3:1
4:1
```

We must keep `1` (first element).

Remaining frequencies:

```
1,1,1
```

We can remove 2 groups using 2 operations.

Remaining distinct:

$$
4 - 2 = 2
$$

### Complexity:

- Frequency Counting: **O(N)**
- Sorting Frequencies: **O(N log N)**

Overall:

- Time: **O(N)**
- Memory: **O(N)**

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N);
        map<int, int> freq;

        for(int i = 0 ; i < N; i++) {
            cin >> A[i];
            freq[A[i]]++;
        }

        //First value stored separately
        int first_element = A[0]; 

        vector<int> counts;
        for(auto const& [val, count] : freq) {

            //First value cannot be removed hence not considered in array with removable counts
            if(val != first_element) {
                counts.push_back(count);
            }
        }

        // Sort the remaining frequencies
        sort(counts.begin(), counts.end());

        int removed = 0;
        for(int c : counts) {
            if(K >= c) {
                K -= c;
                removed++;
            } else {
                break;
            }
        }
        
        //No of distinc elements initially is size of the freq map, and new count is given
        cout << freq.size() - removed << "\n";
    }
    
    return 0;
}
```