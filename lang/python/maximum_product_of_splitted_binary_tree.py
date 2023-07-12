# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maxvalue = 0

    def __rec__(self, root) -> int:
        if root == None:
            return 0
        sum = root.val
        sum = sum + self.__rec__(root.left)
        sum = sum + self.__rec__(root.right)
        return sum

    def __calc__(self, root, total) -> int:
        if root == None:
            return 0
        
        sum = root.val
        sum = sum + self.__calc__(root.left, total)
        sum = sum + self.__calc__(root.right, total)

        rem = total - sum

        self.maxvalue = max(self.maxvalue, sum * rem)

        return sum

    def maxProduct(self, root: Optional[TreeNode]) -> int:
        total = self.__rec__(root)
        self.__calc__(root, total)
        return (self.maxvalue % 1000000007)
