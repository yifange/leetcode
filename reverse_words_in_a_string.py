class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        w = s.split()
        w.reverse()
        return "".join(w)

