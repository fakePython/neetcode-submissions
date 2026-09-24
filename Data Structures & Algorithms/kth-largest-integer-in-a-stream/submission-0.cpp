class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> stream; //min heap (min element at top.)/ max at bottom
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        for(int num : nums){
            stream.push(num);
        }
    }
    
    int add(int val) {
        stream.push(val);

        while(stream.size() > kth){
            stream.pop();
        }

        return stream.top();
    }
};
/**
k = 3

1 2 3 3 -> null heap = 3 3 2
1 2 3 3 3 -> 3 heap 3 3 3
1 2 3 3 3 5 -> 3 heap 5 3 3
1 2 3 3 3 5 6 -> 3 heap 6 5 3
1 2 3 3 3 5 6 7-> 5 heap 7 6 5
1 2 3 3 3 5 6 7 8-> 6

*/