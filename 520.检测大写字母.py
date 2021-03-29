import re


class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        AllCapitalPattern = '[A-Z]*'
        AllNoCapitalPattern = '[a-z]*'
        FirstCapitalPattern = '[A-Z][a-z]*'
        return re.match(AllCapitalPattern, word) != None or re.match(AllNoCapitalPattern, word) != None or re.match(FirstCapitalPattern, word) != None


f = open("input")
lines = f.readline()
for line in lines:
    print(Solution().detectCapitalUse(line))
