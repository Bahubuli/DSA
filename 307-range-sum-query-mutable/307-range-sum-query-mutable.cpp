class SegmentTree{
    
    SegmentTree *left, *right;
    int L,R,val;
    
    public:
    
    SegmentTree(vector<int>&nums,int l,int r)
    {
        L = l;
        R = r;
        right = NULL;
        left = NULL;
        
        build(nums);
    }
    
    void build(vector<int>&nums)
    {
        if(L==R) val = nums[L];
        else
        {
            int mid = (L+R)/2;
            left = new SegmentTree(nums,L,mid);
            right = new SegmentTree(nums,mid+1,R);
            val = left->val + right->val;
        }
    }
    
    void update(int i,int x)
    {
        if(L==R) val = x;
        else
        {
            int mid = (L+R)/2;
            
            if(i<=mid) left->update(i,x);
            else right->update(i,x);
            
            val = left->val+right->val;
        }
    }
    
    int sum(int l,int r)
    {
        if(l>r) return 0;
        
        if(l==L && r==R) return val;
        int mid = (L+R)/2;
        
        return left->sum(l,min(mid,r)) + right->sum(max(l,mid+1),r);
    }
};


class NumArray {
public:
    
    SegmentTree *tree;
    NumArray(vector<int>& nums) 
    {
        tree = new SegmentTree(nums,0,size(nums)-1);
    }
    
    void update(int idx, int val) 
    {
        tree->update(idx,val);
    }
    
    int sumRange(int left, int right) 
    {
        return tree->sum(left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */