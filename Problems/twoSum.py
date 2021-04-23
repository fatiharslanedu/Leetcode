from typing import List 

def twoSum(nums: List[int], target: int) -> List[int]:
    pair = dict()
    i = 0
    for n in nums:
        #*find pairs
        if n in pair:
            return [pair[n], i]
        else:
        #*Add to dictionary
            pair[target - n] = i
            i += 1


nums = [2,7,11,15]
target = 9
print(twoSum(nums,target))
