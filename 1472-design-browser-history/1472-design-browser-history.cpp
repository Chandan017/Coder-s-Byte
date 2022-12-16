class Node{
public:
    string data;
    Node* left = NULL, *right = NULL;
    
    Node(string url)
    {
        data = url;
    }
};

class BrowserHistory {
public:
    
    Node* head;
    BrowserHistory(string homepage) {
        
        head = new Node(homepage);
    }
    
    void visit(string url) {
        
        Node* curr = new Node(url);
        curr->left = head;
        head->right = curr;
        head = head->right;
        
    }
    
    string back(int steps) {
        
        while(head->left && steps--)
        {
            head = head->left;
            // steps--;
            // if(steps == 0)
            //     break;
        }
        
        return head->data;
    }
    
    string forward(int steps) {
        
        while(head->right && steps--)
        {
            head = head->right;
            // steps--;
            // if(steps == 0)
            //     break;
        }
        
        return head->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */