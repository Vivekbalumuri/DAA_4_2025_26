class Solution:
    def minDifference(self, arr):
        totalSum = sum(arr)
        target = totalSum // 2
      
        dp = [False] * (target + 1)
        dp[0] = True
        
        for num in arr:
            for s in range(target, num - 1, -1):
                dp[s] = dp[s] or dp[s - num]

        for s in range(target, -1, -1):
            if dp[s]:
                return totalSum - 2 * s
