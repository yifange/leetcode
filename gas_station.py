class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        start = 0
        count = 0
        length = 0
        i = start
        s = 0
        if len(gas) == 1:
            if gas[0] < cost[0]:
                return -1
            else:
                return 0
        while count < 2 * len(gas):
            # print "i = ", i
            s += gas[i] - cost[i]
            # print "s = ", s
            if s < 0:
                start = (i + 1) % len(gas)
                length = 0
                # print "moving start to ", (i + 1) % len(gas)
                s = 0
            else:
                length += 1
            i = (i + 1) % len(gas)
            count += 1
            # print "length: ", length
            if length == len(gas):
                return start
        return -1

sol = Solution()
gas = [1, 2, 3, 3]
cost = [2, 1, 5, 1]
print sol.canCompleteCircuit(gas, cost)

