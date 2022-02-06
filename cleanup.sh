#!/bin/bash
# 检查是否存在版本控制
if [[ -e .git ]];then
	echo '正在开始清理...'
else
	echo '没有检测到git仓库，不能执行危险操作'
	exit 1
fi
# 自定义分隔符
IFS=$'\n'
for i in $(ls .)
do
	if [[ -z "$(git ls-files "$i")" ]]; then
		trash -v "$i"
	fi
done

echo '清理结束'