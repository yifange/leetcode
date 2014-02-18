class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def kmp_search(self, s, w, t):
        m = 0
        i = 0
        if not w:
            return s
        if not s:
            return None
        while m + i < len(s):
            if w[i] == s[m + i]:
                if i == len(w) - 1:
                    return s[m:]
                i += 1
            else:
                m = m + i - t[i]
                if t[i] > -1:
                    i = t[i]
                else:
                    i = 0
        return None

    def kmp_table(self, w):
        if len(w) > 1:
            pos = 2
            cnd = 0
            t = [0] * len(w)
            t[0] = -1
            t[1] = 0
            while pos < len(w):
                if w[pos - 1] == w[cnd]:
                    cnd += 1
                    t[pos] = cnd
                    pos += 1
                elif cnd > 0:
                    cnd = t[cnd]
                else:
                    t[pos] = 0
                    pos += 1
            return t
        elif len(w) == 1:
            return [-1]
        else:
            return []

    def strStr(self, haystack, needle):
        t = self.kmp_table(needle)
        return self.kmp_search(haystack, needle, t)

sol = Solution()
print sol.strStr("abcabc", "cab")
