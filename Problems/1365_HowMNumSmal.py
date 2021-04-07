from typing import List

# todo: 1365. How Many Numbers Are Smaller Than the Current Number
# ? Easy
#* O(n log n)

def smallerNumbersThanCurrent(nums: List[int]) -> List[int]:
    """
        Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
    """
    sNums = sorted(nums)
    dMap = dict()

    for i in range(len(sNums)):
        if i > 0 and sNums[i] == sNums[i-1]:
            continue
        else:
            dMap[sNums[i]] = i

    res = []
    for n in nums:
        res.append(dMap[n])
    return res


nums = [8, 1, 2, 2, 3]
print(smallerNumbersThanCurrent(nums)) #todo: [4, 0, 1, 1, 3]
