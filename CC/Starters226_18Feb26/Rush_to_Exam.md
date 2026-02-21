## A. Rush to Exam

### Idea:
Chef has:

- `N` hours before the exam
- `M` pages to be read.
- Reading spread of `A` pages per hour

We need to check whether Chef has finished all pages before the exam.

---

### Key Observation

In `N` hours, Chef can read:

$$
N \times A
$$

If this value is greater than or equal to `M`, then Chef can finish reading.

So the condition becomes:

$$
N \tims A \ge M
$$

---

### Example
Input:
[3,6,2]

Chef can read:

$$
3 \times 2 = 6
$$

Since `6 >= 6`, the answer is:
**YES**

---

### Complexity

- Time: **O(1)**
- Complexity: **O(1)**

---