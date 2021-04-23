from typing import List
#todo: 1512. Number of Good Pairs
#? Easy
def numIdenticalPairs(nums: List[int]) -> int:
    """There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed."""
    c = 0
    for i in range(len(nums)):
        for j in range(1, len(nums)):
            if nums[i] == nums[j] and i < j:
                c += 1
    return c

nums = [1,2,3,1,1,3]
# print(numIdenticalPairs(nums))

#todo: Solution1
from collections import Counter
def numIdenticalPairs1(nums: List[int]) -> int:
    return sum(num * (num - 1) for num in Counter(nums).values()) // 2
# print(numIdenticalPairs1(nums))

#todo: Solution2
def numIdenticalPairs2(nums: List[int]) -> int:
    pairs = 0
    counts = {}
    for num in nums:
        prior_num_count = counts.get(num, 0)
        pairs += prior_num_count
        counts[num] = prior_num_count + 1
    return pairs

print(numIdenticalPairs1(nums))
