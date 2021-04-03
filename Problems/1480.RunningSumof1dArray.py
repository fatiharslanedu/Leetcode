from typing import List

#todo: 1480. Running Sum of 1d Array
#? Easy
def runningSum(nums: List[int]) -> List[int]:
    """
        Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
    """
    for i in range(1, len(nums)):
        nums[i] = nums[i] + nums[i - 1]
    return nums


nums = [1, 2, 3, 4]
print(runningSum(nums))
