##  Problem 1: Construct Uniform Parity Array I

###  Idea
We need to construct an array where all elements are either:
- all even OR
- all odd

Allowed operations:
- Keep nums[i] as is
- OR nums[i] = nums[i] - nums[j]

Key observation:
- Even - Even = Even  
- Odd - Odd = Even  
- Even - Odd = Odd  
- Odd - Even = Odd  

So:
If we can make all numbers same parity → answer is true

###  Approach
Count:
- number of even elements
- number of odd elements

Case 1:
- If all are already same parity → return true

Case 2:
- If both even and odd exist:
  - We can always convert everything to one parity using operations
  - BUT constraint (updated one): nums[i] - nums[j] ≥ 1
    → means nums[i] > nums[j]

So:
 Need at least one strictly smaller element to subtract from

Final logic:
- Sort array
- If smallest element is even:
  → can convert all to even
- Else:
  → can convert all to odd

Hence:
 Always possible

###  Complexity
Time: O(n log n)  
Space: O(1)

###  Code
```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        return true;
    }
};