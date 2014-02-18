class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def copy(self, origin):
        result = []
        for i in origin:
            result.append(i)
        return result

    def get_next(self, prev):
        suffix_head = len(prev) - 1
        cur = self.copy(prev)
        while (suffix_head >= 0 and cur[suffix_head - 1] >= cur[suffix_head]):
            suffix_head -= 1
        if (suffix_head <= 0):
            return None
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


    def permute(self, num):
        result = []
        num.sort()
        result.append(num)
        nt = self.get_next(num)
        while (nt):
            result.append(nt)
            nt = self.get_next(nt)
        return result


