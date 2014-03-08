# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    # @param intervals, a list of Interval
    # @return a list of Interval
    def merge(self, intervals):
        if len(intervals) <= 1:
            return intervals

        intervals.sort(lambda x, y: x.start - y.start)
        # print [(i.start, i.end) for i in intervals]
        result = [intervals[0]]
        for interval in intervals[1:]:
            prev = result[-1]
            if interval.start > prev.end:
                result.append(interval)
            else:
                result[-1].end = max(interval.end, prev.end)
        return result

i1 = Interval(1, 4)
i2 = Interval(0, 4)
# i3 = Interval(8, 10)
# i4 = Interval(15, 18)
sol = Solution()
ii = sol.merge([i1, i2])
print [(i.start, i.end) for i in ii]
