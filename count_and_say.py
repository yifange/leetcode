class Solution:
    # @return a string
    def countAndSay(self, n):
        s = "1"
        for i in range(n - 1):
            j = 0
            next_s = ""
            while j < len(s):
                k = j
                while k < len(s) and s[k] == s[j]:
                    k += 1
                next_s += str(k - j) + s[j]
                j = k
            s = next_s
        return s
sol = Solution()
print [sol.countAndSay(i) for i in range(10)[1:]]
print sol.countAndSay(20)




