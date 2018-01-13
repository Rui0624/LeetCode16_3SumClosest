//
//  main.cpp
//  LeetCode16_3SumClosest
//
//  Created by Rui on 1/12/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close = nums[0] + nums[1] + nums[2]; //set a value is the closeset number
        int diff = abs(close - target);//set a value to compare the distance
        sort(nums.begin(), nums.end());//sort the nums
        
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while(left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                int newDiff = abs(sum - target);
                if(diff > newDiff)//if the diff > newDiff, we have found a new closeset 3Sum, update the values
                {
                    diff = newDiff;
                    close = sum;
                }
                
                if(sum < target) // if the sum < target, we can larger the nums[left]
                    left++;
                else
                    right--;//else smaller the nums[right]
                    
            }
        }
        
        return close;
     }
};
