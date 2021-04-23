from typing import List

#todo: 1108. Defanging an IP Address
#? Easy
def defangIPaddr(address: str) -> str:
    """'255[.]100[.]50[.]0'"""
    return address.replace(".", "[.]")


address = "255.100.50.0"
# * print(defangIPaddr(address))

#todo: 1470. Shuffle the Array
#? Easy
def shuffle(nums: List[int], n: int) -> List[int]:
    """Since x1=2, x2=5, x3=1, y1=3, y2=4, y3=7 then the answer is [2,3,5,4,1,7]."""
    li = []
    for i in range(0, n):
        li.append(nums[i])
        li.append(nums[n])
        n += 1
    return li


nums = [2, 5, 1, 3, 4, 7]
n = 3
# * print(shuffle(nums,n))
