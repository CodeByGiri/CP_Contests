## Bank Glitch

### Idea:

Chef has two types of currency:

- `A` units of currency 1
- `B` units of currency 2

Normally:
1 unit of currency1 = 1 unit of currency2

However, due to a banking glitch, Chef can perform a trade:

X units of currency1 → Y units of currency2

Where
$$
X < Y
$$

This means every trade **increases Chef's total money**.

Chef can perform this trade **multiple times**, but each trade must be exactly `X` units.

---

### Key Observation

Each trade changes Chef's total money by:
$$
Profit = Y - X
$$

So every time we perform a trade, Chef gains `Y - X` additional money.

The maximum number of trades Chef can perform is limited by how many currency1 units he has:

Max_trades = A/X

(integer division).

---

### Final Calculation

Initial money:

A + B

After performing all possible trades:

final_money = A + B + (A / X) × (Y - X)

---

### Example

For:

A = 5 B = 2 X = 4 Y = 10

Maximum trades:

5 / 4 = 1

Profit from trade:

10 - 4 = 6

Final money:

5 + 2 + 6 = 13

---

### Complexity

Each test case involves constant calculations.

- Time Complexity: **O(1)**
- Space Complexity: **O(1)**

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
    
    while(t--){
        long long A,B,X,Y;
        cin >> A >> B >> X >> Y;
        
        long long trades = A/X;
        long long profit = trades * (Y-X);
        
        cout << A + B + profit << "\n";
    }
    return 0;
}
```