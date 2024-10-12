class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans;
        for(int i=0;i<nums2.size();i++)
        {
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        
        if((nums1.size()%2)==0)
        {
            int mid=nums1.size()/2;
            ans= double(nums1[mid]+nums1[mid-1])/2;
        }
        else if(nums1.size()%2!=0)
        {
            int mid=nums1.size()/2;
            ans= nums1[mid];
        }
        return ans;
    }
};
