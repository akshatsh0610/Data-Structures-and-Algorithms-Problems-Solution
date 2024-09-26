class node
{
    public:
    int end;
    int count;
    node* next[26];
    node()
    {
        for(int i = 0 ; i < 26 ; i++){
             next[i] = NULL;
        }
        end = 0;
        count = 0;
    }
};
class Solution {
public:
    node* root = new node();
    vector<int>ans;
    vector<int> sumPrefixScores(vector<string>& arr) 
    {
         for(int i = 0 ; i < arr.size() ; i++)
         {
              insert(arr[i]);
         }    
         for(int i = 0 ; i < arr.size() ; i++)
         {
              int count = search(arr[i]);
              ans.push_back(count);
         }
         return ans;
    }
    int search(string &str)
    {
         int count = 0;
         node* temp = root;
         for(int i = 0 ; i < str.length() ; i++)
         {
              if(temp->next[str[i] - 'a'] == NULL) return count;

              temp = temp->next[str[i] - 'a'];
              count = count + temp->count;
         }
         return count;
    }
    void insert(string &str)
    {
         node* temp = root;
         for(int i = 0 ; i < str.length() ; i++)
         {
              if(temp->next[str[i] - 'a'] == NULL) 
              temp->next[str[i] - 'a'] = new node();
              
              temp = temp->next[str[i] - 'a'];
              temp->count++;
              
         }
         temp->end++;
    }
};
