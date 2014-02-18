class Solution:
    # @param num, a list of integer
    # @return a list of integer
    def nextPermutation(self, num):
        suffix_head = len(num) - 1
        cur = num[:]
        while (suffix_head >= 0 and cur[suffix_head - 1] >= cur[suffix_head]):
            suffix_head -= 1
        if (suffix_head > 0):
            i = len(cur) - 1
            while (cur[i] <= cur[suffix_head - 1]):
                i -= 1
            temp = cur[suffix_head - 1]
            cur[suffix_head - 1] = cur[i]
            cur[i] = temp
        for i in range(suffix_head, len(cur) - 1):
            for j in range(i + 1, len(cur)):
                if cur[i] > cur[j]:
                    temp = cur[i]
                    cur[i] = cur[j]
                    cur[j] = temp
        return cur

