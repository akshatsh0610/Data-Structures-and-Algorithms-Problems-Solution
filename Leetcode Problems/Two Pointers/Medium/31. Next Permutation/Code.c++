class Solution {
public:
    void nextPermutation(vector<int>& arr) 
    {
          //code
   bool flag=false;    //no next permutation exist initally
   int x;
   
   for(int i=arr.size()-1;i>=0;i--)
   {
   	     int val_i=arr[i];
   	     
   	     int value=INT_MAX;
   	     
   	     for(int j=i+1;j<arr.size();j++)
   	     {
   	         int val_j=arr[j];
   	         
   	         if(val_j>val_i and val_j<value)
   	         {
   	            flag=true;
				x=j;
				value=val_j;   	
	         }
         }
         if(flag==true)
         {
         	int temp=arr[i];
         	arr[i]=arr[x];
         	arr[x]=temp;
         	
         	sort(arr.begin()+i+1,arr.end());
         	break;
		 }
   }
   if(flag==false)
   {
   	  sort(arr.begin(),arr.end());
   	  return;
   }
   return ;     
    }
};
