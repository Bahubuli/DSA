#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BtNode
{
    public:
    T data;
    BtNode* left;
    BtNode* right;

    BtNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BtNode()
    {
        delete left;
        delete right;
    }
};

void printbtree(BtNode<int>* root)
{
    if(root==NULL)
    return;
    cout<<root->data<<" ";
    if(root->left)
    cout<<"L : "<<root->left->data<<" ";

    if(root->right)
    cout<<"R : "<<root->right->data<<" ";
    cout<<endl;
    printbtree(root->left);
    printbtree(root->right);
}

void printtreelw(BtNode<int>* root)
{
    queue<BtNode<int>*> rest;
    rest.push(root);

    while(rest.size()!=0)
    {
        BtNode<int>* front = rest.front();
        cout<<front->data<<" ";
        rest.pop();
        if(front->left!=NULL)
        {
        rest.push(front->left);
        cout<<"L : " <<front->left->data<<" ";
        }

        if(front->right!=NULL)
        {
        rest.push(front->right);
        cout<<"R : "<<front->right->data<<" ";
        }
        cout<<endl;
    }
}

BtNode<int> *takeinput()
{
    int rootData;
    cout<<"enter data "<<endl;
    cin>>rootData;
    if(rootData == -1)
    return NULL;

    BtNode<int> * newn = new BtNode<int>(rootData);
    BtNode<int>* leftc = takeinput();
    BtNode<int>* rightc = takeinput();

    newn->left = leftc;
    newn->right = rightc;

    return newn;

}
BtNode<int> *takeinputlw()
{
    int Data;
    cout<<" enter data ";
    cin>>Data;
    BtNode<int>* root = new BtNode<int>(Data);

    queue<BtNode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(!pendingnodes.empty())
    {
        BtNode<int> *front = pendingnodes.front();
        pendingnodes.pop();

        cout<<"enter left child of "<<front->data<<endl;
        int leftc;
        cin>>leftc;

        if(leftc!= -1)
        {
            BtNode<int>* lnode = new BtNode<int>(leftc);
            front->left = lnode;
            pendingnodes.push(lnode);
        }
        cout<<"enter right child of "<<front->data<<endl;
        int rightc;
        cin>>rightc;

        if(rightc!= -1)
        {
            BtNode<int>* rnode = new BtNode<int>(rightc);
            front->right = rnode;
            pendingnodes.push(rnode);
        }

    }
    return root;
}

int countnodes(BtNode<int>* root)
{
    if(root==NULL)
        return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}

int height(BtNode<int>* root)
{
    if(root==NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

void mirrorbt(BtNode<int>* root)
{
    if(root==NULL)
        return;
    BtNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorbt(root->left);
    mirrorbt(root->right);
}

void preorder(BtNode<int>* root)
{
    if(root==NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
//  1 2 3 4 5 6 7 -1 -1  -1 -1 8 9 -1 -1 -1 -1 -1 -1


int main()
{
    BtNode<int>*root = takeinputlw();

    preorder(root);
}


  vector<long long >ans;

        stack<long long >st;

        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[i]>=st.top() )
            st.pop();

            if(st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(arr[i]);

        }

        reverse(ans.begin(),ans.end());
        return ans;
    }

      vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        int j = nums2.size()-1;
        vector<int>ans;
        stack<int>st;
        unordered_map<int,int> mp;
        while( j>=0)
        {
            while(!st.empty() && st.top()<=nums2[j])
                st.pop();



                if(st.empty())
                {
                    mp[nums2[j]]=-1;
                    st.push(nums2[j]);
                    j--;

                }
                else
                {
                    mp[nums2[j]]=st.top();
                    st.push(nums2[j]);
                    j--;

                }


        }

        for(int i=0;i<nums1.size();i++)
        {
           ans.push_back(mp[nums1[i]]);
        }

        //reverse(ans.begin(),ans.end());
        return ans;
    }

  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n,0), ans;

        for(auto &e :edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==1) q.push(i),indegree[i]--;
        }

        while(!q.empty())
        {
            int s = q.size();
            ans.clear();

            for(int i=0;i<s;i++)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);

                for(auto child :graph[curr])
                {
                    indegree[child]--;
                    if(indegree[child]==1) q.push(child);

                }
            }
        }
        if(n==1)  ans.push_back(0);
        return ans;
    }
vector <int> calculateSpan(int price[], int n)
    {
       vector<int>ans;
       stack<int> st;

       for(int i=0;i<n;i++)
       {
           while(!st.empty() && price[i]>=price[st.top()])
           st.pop();

           if(st.empty())
           ans.push_back(i+1);
           else
           {
               ans.push_back(i-st.top());
           }
           st.push(i);
       }
       return ans;
    }
    int largestRectangleArea(vector<int>& nums)
    {
        int n = nums.size();
      stack<int>st;
      vector<int>nsr;
      vector<int>nsl;

      for(int i=0;i<n;i++)
      {
         while(!st.empty() && nums[st.top()]>=nums[i])
             st.pop();
          if(st.empty())
          {
              nsl.push_back(-1);
          }
          else
              nsl.push_back(st.top());

          st.push(i);

      }
      while(!st.empty())
          st.pop();

      for(int i=n-1;i>=0;i--)
      {
          while(!st.empty() && nums[st.top()]>=nums[i])
              st.pop();
          if(st.empty())
              nsr.push_back(n);
          else
              nsr.push_back(st.top());
          st.push(i);
      }
        reverse(nsr.begin(),nsr.end());

        int mx =0;
        for(int i=0;i<n;i++)
        {

            mx =max(mx,((nsr[i]-nsl[i])-1)*nums[i]);

        }
        return mx;

    }
int largestRectangleArea(vector<int>& nums)
    {
        int n=nums.size();
        int mx=0;
        stack<int>st;

        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || nums[st.top()]>=nums[i]))
            {
                int h = nums[st.top()];
                st.pop();
                int w;
                if(st.empty())
                    w=i;
                else
                    w=i-st.top()-1;
                mx=max(mx,w*h);
            }
            st.push(i);
        }
        return mx;
    }
    int mah(vector<int>&nums)
    {
        int n =nums.size();
        stack<int>st;
        int mx=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (i==n || nums[st.top()]>=nums[i]))
            {
                int h = nums[st.top()];
                st.pop();
                int w;
                if(st.empty())
                    w=i;
                else
                    w=i-st.top()-1;
                mx = max(mx,w*h);
            }
            st.push(i);
        }

        return mx;

    }

    int maximalRectangle(vector<vector<char>>&arr)
    {
        int ans =0;
        int res=0;
        vector<int>dum(arr[0].size(),0);

        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[0].size();j++)
            {
                if(arr[i][j]=='0')
                {
                    dum[j]=0;
                }
                else
                {
                    dum[j]=dum[j]+(arr[i][j]-'0');
                }
            }

            res=mah(dum);
            ans = max(ans,res);
        }
        return ans;

    }


    int trap(vector<int>& height) {
        int n=height.size();
        int arr[n];
        for(int i=0;i<n;i++)
            arr[i]=height[i];

                 if (n <= 1) return 0;
    int lmarr[n];
    lmarr[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        lmarr[i] = max(lmarr[i - 1], arr[i]);
    }

    int rmarr[n];
    rmarr[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rmarr[i] = max(rmarr[i + 1], arr[i]);
    }

    int totalw = 0;
    for (int i = 0; i < n; i++)
    {
        totalw = totalw + max(0, (min(lmarr[i], rmarr[i]) - arr[i]));
    }
    return totalw;

    }
 int findUnsortedSubarray(vector<int>& nums)
    {
        int i=0;
        int j= nums.size()-1;
        int count  = 0;
        while(i<j)
        {
            if(nums[i]<nums[i+1] && nums[j-1]<nums[j])
            {
                i++;
                j--;
            }
            else if(nums[i]<nums[i+1])
            {
                i++;
            }
            else if(nums[j-1]<nums[j])
            {
                j--;
            }
            else
            {
                count = j-i+1;
                break;
            }

        }
        return count;

    }
int findUnsortedSubarray(vector<int>& nums)
    {

        int nd = -1;
        int mx = nums[0];

        for(int i=1;i<nums.size();i++)
        {
            if(mx>nums[i])
            {
                nd = i;
            }
            else
            {
                mx = nums[i];
            }

        }

        int st = 0;
        int mn = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]>mn)
            {
                st = i;
            }
            else
            {
                mn = nums[i];
            }
        }
        return nd-st+1;
    }
int findMin(vector<int>& arr)
    {
        int n = arr.size();


    int l = 0, h = n - 1;
    int idx = 0;

    while(l<h)
    {

        int mid = (l + h) / 2;


        if(arr[mid]>arr[mid+1])
        {
            idx = mid+1;
            break;
        }

        else if(arr[mid]>arr[h])
            l = mid+1;

        else
            h = mid;

    }

    return arr[idx];

    }
// simple approach is to find breakpoint and search in the either left or right based upon the element

int findminidx(vector<int>& arr)
    {
        int n = arr.size();


    int l = 0, h = n - 1;
    int idx = 0;

    while(l<h)
    {

        int mid = (l + h) / 2;


        if(arr[mid]>arr[mid+1])
        {
            idx = mid+1;
            break;
        }

        else if(arr[mid]>arr[h])
            l = mid+1;

        else
            h = mid;

    }

    return idx;


    }

    int search(vector<int>& nums, int target)
    {
        int midx = findminidx(nums);
        cout<<midx<<endl;
        int n = nums.size();
        int l=0, h=n-1;
        int ans = -1;

        if(target<=nums[h])
        {
            l = midx;
        }
        else
        {
            h = midx-1;
        }


        while(l<=h)
        {
            int mid = (l+h)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                return mid;
            }
            else if(nums[mid]>target)
            {
                h=mid-1;
            }
            else
                l=mid+1;

        }

        return ans;

    }/
        // striver bhau ki approach
        int l=0;
        int h = nums.size()-1;

        while(l<=h)
        {
            int mid = (l+h)/2;

            if(nums[mid]==target)
                return mid;
            else if(nums[l]<=nums[mid])
            {
                if(target<=nums[mid] && target>=nums[l])
                {
                    h = mid-1;
                }
                else
                {
                    l=mid+1;
                }

            }
            else
            {
                if(target>=nums[mid] && target<=nums[h])
                {
                    l=mid+1;
                }
                else
                {
                    h=mid-1;
                }
            }
        }
        return -1;


[In reply to Deepanshu]
ye code sare question solve kr dega ye 0 1 2  type wale...ex array containing  0 1 2 3 4 5   sort this

time complexity ~ O(k*n)   where k is max value in array;

void sortColors(vector<int>& nums,int s,int e,int lv,int rv)
    {
        if(lv>=rv || s>=e)
        return;

        int l=s,c=s,h =e ;
        int count =0;
        while(c<=h)
        {
                count++;
            if(nums[c]==lv)
            {
                int temp = nums[c];
                nums[c] = nums[l];
                nums[l]=temp;
                l++;
                c++;


            }

            else if(nums[c]>lv && nums[c]<rv)
            {
                c++;
            }
            else if(nums[c]==rv)
            {
                int temp = nums[c];
                nums[c]=nums[h];
                nums[h]=temp;
                h--;
            }

        }
        sortColors(nums,l,h,lv+1,rv-1);

    }
