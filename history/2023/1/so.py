class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mymap = {}
        for i in range(len(nums)):
            if target - nums[i] in mymap:
                return [mymap[target - nums[i]], i]
            mymap[nums[i]] = i
        return []