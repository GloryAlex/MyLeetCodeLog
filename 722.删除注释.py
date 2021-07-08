import os
from typing import List
#
# @lc app=leetcode.cn id=722 lang=python3
#
# [722] 删除注释
#

# @lc code=start


class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        inBlock=False
        result=[]
        for line in source:
            i = 0
            if not inBlock:
                newLine = []
            while i < len(line):
                if line[i:i+2]=='/*' and not inBlock:
                    inBlock=True
                    i+=1
                elif line[i:i+2]=='*/' and inBlock:
                    inBlock=False
                    i+=1
                elif line[i:i+2]=='//' and not inBlock:
                    break
                elif not inBlock:
                    newLine.append(line[i])
                i+=1
            if newLine and not inBlock:
                result.append("".join(newLine))
        return result

# @lc code=end


f = open("input")
for line in f.readlines():
    arr = [item.replace('"','') for item in line[1:-1].split(", ")]
    print(Solution().removeComments(arr))
