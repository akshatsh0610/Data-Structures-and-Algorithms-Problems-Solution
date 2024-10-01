class Node
{
    public:
    Node* prv;
    string str;
    Node* next;
    
    Node(string temp)
    {
        prv = NULL;
        str = temp;
        next = NULL;
    }
};

class BrowserHistory 
{
public:
    Node* head = NULL;
    BrowserHistory(string home) 
    {
        head = new Node(home);
    }
    
    void visit(string url) 
    {
         if(head->next != NULL)
         {
             head->next->prv = NULL;
             head->next = NULL; 
         }
         head->next = new Node(url);
         head->next->prv = head;
         head = head -> next;
    }
    
    string back(int steps) 
    {
        int temp = steps;
        while(temp > 0 and head!=NULL and (head->prv)!=NULL)
        {
             head = head->prv;
             temp--;
        }
        return head->str;
    }
    
    string forward(int steps) 
    {
         int temp = steps;
         while(temp > 0 and head!=NULL and (head->next)!=NULL)
         {
             head = head->next;
             temp--;
         }
         return head->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
