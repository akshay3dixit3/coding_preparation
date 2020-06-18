class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
//     int zero = 0;
//     int two =  arr.size() - 1;
    
//     while(zero < two)
//     {
//         if(arr[zero] > arr[two])
//         {
//             swap(arr[zero], arr[two]);
//             // printarry(arr);
//         }
        
//         while(arr[zero] == 0 && zero < two)
//         {
//             zero++;
//         }
        
//         while(arr[two] == 2 && zero < two)
//         {
//             two--;
//         }
//     }
        
    }
};