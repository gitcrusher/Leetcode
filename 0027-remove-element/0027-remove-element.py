class Solution(object):
    def removeElement(self, nums, val):
        s = []
        l = 0
        r = len(nums) - 1

        while l <= r:
            if nums[l] != val:
                s.append(nums[l])

            if l != r and nums[r] != val:
                s.append(nums[r])

            l += 1
            r -= 1

        for i in range(len(s)):
            nums[i] = s[i]

        return len(s)