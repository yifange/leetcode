class Solution:
    # @return a float
    def findKth(self, A, B, k):
        i = int((k - 1) * float(len(A)) / (len(A) + len(B)))
        j = k - 1 - i
        # print "i", i
        # print "j", j
        if len(A) == 0:
            ai1 = -32767
            ai = 32768
        elif i == 0:
            ai1 = -32767
            ai = A[i]
        elif i == len(A):
            ai1 = A[i - 1]
            ai = 32768
        else:
            ai1 = A[i - 1]
            ai = A[i]
        if len(B) == 0:
            bj1 = -32767
            bj = 32768
        elif j == 0:
            bj1 = -32767
            bj = B[j]
        elif j == len(B):
            bj1 = B[j - 1]
            bj = 32768
        else:
            bj1 = B[j - 1]
            bj = B[j]
        # print "ai-1", ai1
        # print "ai", ai
        # print "bj-1", bj1
        # print "bj", bj
        if bj1 < ai and ai <= bj:
            return ai
        if ai1 <= bj and bj < ai:
            return bj
        if ai < bj1:
            # print A[i + 1:], B, k - i - 1
            if i == len(A):
                return self.findKth(A[i + 1:], B, k - i)
            else:
                return self.findKth(A[i + 1:], B, k - i - 1)
        else:
            # print A, B[j + 1:], k - j - 1
            if j == len(B):
                return self.findKth(A, B[j + 1:], k - j)
            else:
                return self.findKth(A, B[j + 1:], k - j - 1)

    def findMedianSortedArrays(self, A, B):
        m = len(A)
        n = len(B)
        if ((m + n) % 2 == 1):
            return float(self.findKth(A, B, (m + n) / 2 + 1))
        else:
            return (float(self.findKth(A, B, (m + n) / 2)) + self.findKth(A, B, (m + n) / 2 + 1)) / 2

sol = Solution()
A = [1, 2]
B = [1, 2]
print sol.findMedianSortedArrays(A, B)
