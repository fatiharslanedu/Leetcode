from typing import List

#todo: 771. Jewels and Stones
#? Easy
def numJewelsInStones(jewels: str, stones: str) -> int:
    """Output will be 3"""
    jew = {}
    count = 0
    for i in jewels: # element get in the dict.
        jew[i] = i
    for i in stones: # check the element, if in the dict.
        if i in jew:
            count += 1
    return count


jewels = "aA"
stones = "aAAbbbb"
# print(numJewelsInStones(jewels,stones))


def numJewelsInStones(jewels: str, stones: str) -> int:
    return sum(map(stones.count, list(jewels)))

#* MAP in PYTHON

def calcSquare(n):
    return n * n

numbers = (1,2,3,4)
result = map(calcSquare, numbers)
# print(result) #todo: <map object at 0x7f5c49536040>
numbersSquare = set(result)
# print(numbersSquare) #todo: {16, 1, 4, 9}

#* Example 2
numbers = (1,2,3,4)
result = map(lambda x: x * x, numbers)
numbersSquare = set(result)
# print(numbersSquare)

#* Example 3: Passing Multiple Iterators to map() Using Lambda

num1 = [4, 5, 6]
num2 = [5, 6, 7]

result = map(lambda n1, n2: n1+n2, num1, num2)
# print(list(result)) #todo: [9, 11, 13]