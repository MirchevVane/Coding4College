class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        prevmap = {}

        for i, n in enumerate(nums):
            diff = target - n
            if diff in prevmap:
                return[prevm[diff], i]
            prevmap[n] = i
        return