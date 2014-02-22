class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def addBinary(self, a, b):
        # a = a[::-1]
        # b = b[::-1]

        # carry = False
        # c = ""
        # for i in range(min(len(a), len(b))):
        #     d = str(int(a[i]) ^ int(b[i]) ^ carry)
        #     carry = (carry and (bool(int(a[i])) or bool(int(b[i])))) or (bool(int(a[i])) and bool(int(b[i])))
        #     print bool(int(a[i])), bool(int(b[i])), carry
        #     c += d
        # # print c
        # for i in range(min(len(a), len(b)), max(len(a), len(b))):
        #     if len(a) < len(b):
        #         d = str(int(b[i]) ^ carry)
        #         carry = int(b[i]) and carry
        #         c += d
        #     else:
        #         d = str(int(a[i]) ^ carry)
        #         carry = int(a[i]) and carry
        #         c += d
        # if carry:
        #     c += "1"
        # c = c[::-1]
        # return c
        return bin(int(a, 2) + int(b, 2))[2:]
sol = Solution()
a = "0"
b = "1"
print sol.addBinary(a, b)

