//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        
        vector<int> v(26,0);
        
        for(int i=0;i<s.length();i++)
         v[s[i]-'a']++;
         
        vector<Node*> res;
        int k=s.length();
        Node* curr=head,*start=head;
        
        vector<int> a(26,0); vector<int> b(26,0);
        
        while(curr!=NULL){
            
            a[curr->data-'a']++; k--;
            if(k==0)   //check if we get a sublist of size same as string
            {
                if(v==a)   //check if characters in v is same as a
                 {
                    res.push_back(start);
                    Node* temp=curr->next;
                    curr->next=NULL; //to make end of a anagram
                    curr=temp;
                    start=temp;  // to avoid overlap
                    
                    a=b;
                    k=s.length();
                }
                else{
                    a[start->data-'a']--;
                    k++;
                    start=start->next;
                    curr=curr->next;
                }
            }
            else curr=curr->next;
            
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends