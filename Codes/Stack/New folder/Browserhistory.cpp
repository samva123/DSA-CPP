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