import sys

for line in sys.stdin:
    a = line.strip().split(',')
    str1 = a[0]
    str2 = a[1]

    if len(str1) > 0 and str1[-1] == '/':
        str1 = str1[:-1]
    
    if len(str2) > 0 and str2[0] == '/':
        str2 = str2[1:]
    
    print(str1+'/'+str2)
