class Solution(object):
    def minMoves2(self, nums):
        nums.sort()

        n = len(nums)
        median = nums[n // 2]

        moves = 0

        for i in range(n):
            moves += abs(nums[i] - median)

        return moves