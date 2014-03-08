class Solution:
    # @return a boolean
    def nextToken(self, p):
        if p:
            ch = p[0]
            if len(p) > 1:
                if p[1] in ["*", "+"]:
                    return (ch, p[1], p[2:])
                else:
                    return (ch, "", p[1:])
            else:
                return (ch, "", "")
        else:
            return (None, "", "")

    def isMatch(self, s, p):
        if not s:
            return True
        else:
            token, dec, np = self.nextToken(p)
            if dec == "*":
                if token == "." or s[0] == token:
                    nextToken, nextDec, _ = self.nextToken(np)
                    if nextToken == "." or nextToken == s[0]:
                        return self.isMatch(s[1:], p) or self.isMatch(s, np)
                    else:
                        return self.isMatch(s[1:], p)
                else:
                    return self.isMatch(s, np)
            elif dec == "+":
                if token == "." or s[0] == token:
                    return self.isMatch(s[1:], token + "*" + np)
                else:
                    return False
            else:
                if token == "." or s[0] == token:
                    return self.isMatch(s[1:], np)
                else:
                    return False
sol = Solution()
s = "aab"
p = "a+aab"
print sol.isMatch(s, p)
