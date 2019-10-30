import re
n = int(input())
w = list(input().split())
pattern=r'takahashikun[.]*'
print(len([x for x in w if re.fullmatch(pattern,x,re.IGNORECASE)]))