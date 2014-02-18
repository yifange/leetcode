class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        carry = 1
        for i in range(len(digits) - 1, -1, -1):
            x = carry + digits[i]
            if x > 9:
                digits[i] = x - 10
                carry = 1
            else:
                digits[i] = x
                carry = 0
        if carry == 1:
            digits.insert(0, 1)
        return digits

