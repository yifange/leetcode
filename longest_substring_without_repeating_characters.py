class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        a = {}
        left = 0
        right = 0
        l = 0
        while right < len(s):
            if not a.has_key(s[right]) or a[s[right]] == 0:
                # print "go ", s[right]
                a[s[right]] = 1
            else:
                # print s[right], "!", right
                while left < right:
                    if s[left] == s[right]:
                        left += 1
                        break
                    a[s[left]] = 0
                    left += 1

                # print s[left], "..", left
            if right - left + 1 > l:
                l = right - left + 1
                # print s[left:right + 1], " ", right - left + 1

            right += 1
        return l

sol = Solution()
s = "bbbbb"
print sol.lengthOfLongestSubstring(s)
