class Node
{
    public:
    Node* next;
    Node* prev;
    
    int key;
    int value;
    
    Node(int k,int v)
    {
        key=k;
        value=v;
        next=NULL;
        prev=NULL;
    }
};
class LRUCache {
public:
    unordered_map<int,Node*>mp;
    int capacity;
    Node* head;
    Node* tail;
    LRUCache(int cap) 
    {
       //we initialize the head and tail of the linked list
       head=new Node(-1,-1);
       tail=new Node(-1,-1);
       head->next=tail;
       tail->prev=head;
       capacity=cap;
    }
    
    int get(int key) 
    {
       if(mp.find(key)==mp.end())
       {
           //does not exist in the map
           return -1;
       }
       else
       {
           int result=mp[key]->value;
           remove(key);
           mp.erase(key);
           
           mp[key]=movetofront(key,result);
           return result;
       }
    }
    void put(int key, int value) 
    {
       if(mp.find(key)!=mp.end())
       {
           //update  -->remove -->movetofront with key val
           remove(key);
           mp[key]=movetofront(key,value);
        
       }
       else if(mp.find(key)==mp.end())
       {
           if(mp.size()==capacity)
           {
               //lru eviction
               int k=tail->prev->key;
               remove(k);
               mp.erase(k);
               //adding as the priority node or vip node
               mp[key]=movetofront(key,value);
           }
           else
           {
               mp[key]=movetofront(key,value);
           }
       }
    }
    Node* movetofront(int key,int value)
    {
        Node* temp=head->next;
        Node* newnode=new Node(key,value);
        
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
        temp=NULL;
        
        return newnode;
    }
    void remove(int key)
    {
        Node* node=mp[key];
        node->prev->next=node->next;
        node->next->prev=node->prev;
        
        node->next=NULL;
        node->prev=NULL;
        
        delete(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
