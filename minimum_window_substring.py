class Solution:
    # @return a string
    def get_need_to_find(self, T):
        need_to_find = {}
        for c in T:
            if c in need_to_find:
                need_to_find[c] += 1
            else:
                need_to_find[c] = 1
        return need_to_find

    def minWindow(self, S, T):
        need_to_find = self.get_need_to_find(T)
        has_found = {}
        for c in need_to_find.iterkeys():
            has_found[c] = 0
        count = 0
        head = 0
        m = len(S)
        f = 0
        e = 0
        for i in range(len(S)):
            if S[i] in need_to_find.iterkeys():
                if has_found[S[i]] < need_to_find[S[i]]:
                    count += 1
                has_found[S[i]] += 1
                if count >= len(T):
                    while (head < i):
                        if S[head] in need_to_find.iterkeys():
                            if has_found[S[head]] > need_to_find[S[head]]:
                                has_found[S[head]] -= 1
                                head += 1
                            else:
                                break
                        else:
                            head += 1
                    if i - head + 1 < m:
                        f = head
                        e = i
                        m = i - head + 1
        return S[f : e + 1]

sol = Solution()
S = "ADOBECODEBANC"
T = "ABC"
print sol.minWindow(S, T)
