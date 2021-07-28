#!/bin/bash
#自定义分隔符 
IFS=$'\n'
for i in `ls | grep -v '\(^input$\)\|^.*\.\(cpp\|h\|py\|md\|txt\|sh\)$'`;
do 
rm -rf $i
echo 正在删除 $i...
done