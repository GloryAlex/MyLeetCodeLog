#! /usr/bin/python3

import os
import re
import shutil

filePath = '.'
curFiles = os.listdir(filePath)
for i in curFiles:
    if not(i=='input' or re.match(r'(^\.|.*\.(?:cpp|h|py|md)$)',i)):
        if(os.path.isdir(i)):
            print('删除目录及所有文件',i)
            shutil.rmtree(i)
        else:
            print('正在删除文件',i)
            os.remove(i)

print('全部删除完毕！')