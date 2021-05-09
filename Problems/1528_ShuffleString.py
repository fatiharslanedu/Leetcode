
# * 1528. Shuffle String
# ? Easy
from typing import List
def restoreString(s: str, indices: List[int]) -> str:
    """As shown, "codeleet" becomes "leetcode" after shuffling."""
    res = [None] * len(s)
    for char, idx in zip(s, indices):
        res[idx] = char
    return "".join(res)




s = "codeleet"
indices = [4,5,6,7,0,2,1,3]
print(restoreString(s, indices))