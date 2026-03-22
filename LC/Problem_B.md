##  Problem 2: Construct Uniform Parity Array (with constraint)

###  Idea

We need to make all elements in the array have the **same parity** (all even or all odd).

Allowed operation:

$$
nums[i] = nums[i] - nums[j]   (only if nums[i] > nums[j])
$$

Important constraint:
 We can only subtract a **strictly smaller element**

---

###  Key Observation

The **smallest element cannot be changed**, because:
- There is no element smaller than it

So:
 Its parity is **fixed**
 Final array must match this parity

Let:

mn = minimum element

---

###  Case Analysis

#### Case 1: `mn` is EVEN

Check subtraction behavior:

even - even = even odd - even = odd

 Parity does NOT change

So:
- If any element is odd → cannot convert it to even ❌
- Therefore, all elements must already be even

---

#### Case 2: `mn` is ODD

even - odd = odd odd - odd = even

 Parity CAN change

So:
- Any element can be converted to odd
- Therefore, always possible 

---

###  Final Condition

If minimum element is odd → return true Else → check if all elements are even

---

###  Complexity

- Finding minimum: O(n)
- Checking parity: O(n)

Total: O(n)

---

###  Code

```cpp
class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());

        if (mn % 2 == 1) return true;

        for (int x : nums) {
            if (x % 2 != 0) return false;
        }

        return true;
    }
};
```