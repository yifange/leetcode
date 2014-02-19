class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return False
        rev = 0
        number = x
        while number > 0:
            d = number % 10
            rev = rev * 10 + d
            number = number / 10
        return rev == x
