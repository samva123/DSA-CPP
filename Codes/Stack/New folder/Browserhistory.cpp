class BrowserHistory {
    stack<string>browserstack , fwdstack;
public:
    BrowserHistory(string homepage) {
        browserstack.push(homepage);
        
    }
    
    void visit(string url) {
        while(!fwdstack.empty()){
            fwdstack.pop();

        }
        browserstack.push(url);

        
    }
    
    string back(int steps) {
        while(steps--){
            if(browserstack.size()>1){
                fwdstack.push(browserstack.top());
                browserstack.pop();

            }
            else{
                break;
            }
        }
        return browserstack.top();
        
    }
    
    string forward(int steps) {
        while(steps--){
            if(!fwdstack.empty()){
                browserstack.push(fwdstack.top());
                fwdstack.pop();

            }
            else{
                break;
            }

        }
        return browserstack.top();
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */




class BrowserHistory {
    struct Node {
        string url;
        Node* prev;
        Node* next;
        Node(string u) : url(u), prev(nullptr), next(nullptr) {}
    };
    
    Node* current;
    
public:
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode = new Node(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    string back(int steps) {
        while (steps-- && current->prev) {
            current = current->prev;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while (steps-- && current->next) {
            current = current->next;
        }
        return current->url;
    }
};



// Time Complexity
// The BrowserHistory constructor has a time complexity of O(1).
// The visit function has a time complexity of O(n) in the worst case, where n is the number of elements in the fwdstack (since it clears the forward stack).
// The back function has a time complexity of O(steps), where steps is the number of steps to go back.
// The forward function has a time complexity of O(steps), where steps is the number of steps to go forward.
// Space Complexity
// The space complexity of the BrowserHistory class is O(n), where n is the total number of URLs visited. This is because the browserstack and fwdstack can store up to n URLs in the worst case.

// Optimization
// The current implementation is already efficient with O(n) space complexity and O(steps) time complexity for the back and forward functions. However, we can optimize the visit function to have O(1) time complexity by using a doubly linked list to store the history and a pointer to keep track of the current position.

// Explanation
// Use a doubly linked list to store the history of URLs.
// The visit function creates a new node for the URL and updates the pointers to maintain the doubly linked list structure.
// The back function moves the current pointer back by the specified number of steps.
// The forward function moves the current pointer forward by the specified number of steps.
// This approach maintains the space complexity of O(n) but optimizes the visit function to have O(1) time complexity, making the overall implementation more efficient.

