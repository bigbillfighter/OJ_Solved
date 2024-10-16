import sys


for line in sys.stdin:
    data_list = line.strip()

a = float(data_list.split(' ')[0])
b = float(data_list.split(' ')[1])

rst = 0.25 * (a * 4 + b + a*2+b*2 + b*2+a*2 + a + b*4)
print("{:.2f}".format(rst))

