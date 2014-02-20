class Solution:
    # @return a string
    def common_prefix(self, s1, s2):
        i = 0
        while i < min(len(s1), len(s2)):
            if s1[i] != s2[i]:
                break
            i += 1
        return s1[:i]

    def longestCommonPrefix(self, strs):
        if not strs:
            return ""
        if len(strs) == 1:
            return strs[0]
        prefix = strs[0]
        for s in strs[1:]:
            prefix = self.common_prefix(prefix, s)
        return prefix


