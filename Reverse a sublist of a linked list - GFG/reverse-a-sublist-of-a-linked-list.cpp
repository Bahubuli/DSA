// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    
    pair<Node *,Node *> reverse(Node *head)
    {
        Node *nhead ,*tail;
        tail = head;
        
        Node *nxt,*prev = NULL,*curr = head;
        
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        nhead =  prev;
        return {nhead,tail};
    }
    
    Node* reverseBetween(Node* head, int m, int n)
    { 
        Node *prehead = new Node(0);
        prehead->next = head;
        Node *temp = prehead;
        
        for(int i=1;i<m;i++)
        {
            temp = temp->next;
        }
        Node *rest = prehead;
        for(int i=1;i<=n;i++) rest = rest->next;
        
        Node *temp2 = rest->next;
        rest->next = NULL;
        
        auto res = reverse(temp->next);
        
        temp->next = res.first;
        res.second->next = temp2;
        
        return prehead->next;
        
        
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends