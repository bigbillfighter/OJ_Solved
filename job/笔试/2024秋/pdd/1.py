import sys

lines = []

for line in sys.stdin:
    lines.append(line)

n, m = lines[0].strip().split(' ')
n, m = int(n), int(m)

wpdd, wo_pdd = [], []
for i in range(1, n+1):
    if "PDD" in lines[i]:
        wpdd.append(lines[i].strip())
    else:
        wo_pdd.append(lines[i].strip())

wpdd = sorted(wpdd)
wo_pdd = sorted(wo_pdd)

rst = wpdd + wo_pdd
for i in range(m):
    print(rst[i])

