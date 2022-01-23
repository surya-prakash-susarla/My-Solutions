class Solution:
    def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
        minval = 0 
        maxval = 0
        
        temp = 0
        for i in differences:
            temp = temp + i
            minval = min(minval, temp)
            maxval = max(maxval, temp)
            
        answer = 0
        for i in range(lower, upper+1):
            if i+minval >= lower and i+maxval <= upper:
                answer = answer+1
                
        return answer