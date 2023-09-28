class Solution:
    def myPow(self, x: float, n: int) -> float:
        if x == 0:
            return 0
        elif x == 1:
            return 1
        elif x == -1:
            return 1 if n % 2 == 0 else -1;
        
        if n == 0:
            return 1
        else:
            return x ** n
        
