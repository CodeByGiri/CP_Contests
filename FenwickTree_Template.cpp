#include<bits/stdc++.h>
using namespace std;

struct Fenwick{
    int N;
    vector<int> fen;

    Fenwick(int n) : N(n+1), fen(n+1,0) {}

    void update(int i, int add){ //Used to add values at index 'i'
        while(i < N){ // only updating till N-1
            fen[i] += add;
            i += (i & (-i)); //Move up tree
        }
    }

    int sum(int i){ //Prefix sum from 1 to i
        int s = 0;
        while(i > 0){
            s += fen[i];
            i = i - (i & (-i)); //Sets off rightmost bit, i.e, moves down the tree
        }
        return s;
    }

    int rangeSum(int l, int r){
        return sum(r) - sum(l-1);
    }
};

