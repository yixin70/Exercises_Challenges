#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    double static findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() > nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int nums1pos = nums1.size()/2;
        int nums2pos = (nums1.size() + nums2.size() + 1) / 2;
        nums2pos -= nums1pos;

        if(nums2.size() <= 0){
            if(nums1.size() % 2 == 0){
                double sol = nums1[nums1pos - 1] + nums1[nums1pos];
                sol /= 2;
                return sol;
            }
            else if(nums1.size() == 1){
                return nums1[0];
            }
            else{
                return nums1[nums1pos - 1];
            }
        }


        int nums1Left, nums1Right, nums2Left, nums2Right;
        bool found = false;
      
        while(!found){
            nums1Left = (nums1pos <= 0)? INT_MIN: nums1[nums1pos - 1];
            nums1Right = (nums1pos >= nums1.size())? INT_MAX: nums1[nums1pos];
            nums2Left = (nums2pos <= 0)? INT_MIN: nums2[nums2pos - 1];
            nums2Right = (nums2pos >= nums2.size())? INT_MAX: nums2[nums2pos];

            if(nums1Left <= nums2Right && nums2Left <= nums1Right)
                found = true;
            
            else if(nums1Left > nums2Right){
                nums1pos--;
                nums2pos++;
            }
            else{
                nums1pos++;
                nums2pos--;
            }
        }

        if((nums1.size() + nums2.size()) % 2 == 0 ){
            double sol = (std::max(nums1Left, nums2Left) + std::min(nums1Right, nums2Right));
            sol = sol / 2;
            return sol;
        }else{
            return std::max(nums1Left, nums2Left);
        }
    }
};

int main(){
    int myints[] = {};
    std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

    int s[] = {};
    std::vector<int> ss (s, s + sizeof(s) / sizeof(int) );

    std::cout << Solution::findMedianSortedArrays(fifth, ss);
}