class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>>minh;
    int size;
    KthLargest(int k, vector<int>& nums) {
     size = k;
     for(int i=0 ; i<nums.size() ; i++){    
      minh.push(nums[i]);
      if(minh.size() > k){
          minh.pop();
      }
     }
    }
    
    int add(int val) {
        minh.push(val);

        if(minh.size() > size){
            minh.pop();
        }

        return minh.top();
    }
};

