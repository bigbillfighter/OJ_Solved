import sys
import math

line_data = []

for line in sys.stdin:
    a = line.strip()[1:-1]
    line_data.append(a)

# line_data = [
#     "'An Apple orange Apple','Chinese is an banana','Chinese KongFu','Apple is not pen'",
#     "0, 'Apple'"
# ]


content_data = line_data[0].split(',')
content_data = [cd.strip()[1:-1].split(' ') for cd in content_data]

query_data = line_data[1].split(',')
idx = int(query_data[0])
query_word = query_data[1].strip()[1:-1]

cnt = 0
for wd in content_data[idx]:
    if wd == query_word:
        cnt += 1

tf = cnt / len(content_data[idx])

total_wd = 0
for cd in content_data:
    for wd in cd:
        if wd == query_word:
            total_wd += 1
            break

idf = math.log(len(content_data) / (1 + total_wd) + 1)

# print(cnt, total_wd)
# print(tf, idf)

print("{:.3f}".format(tf*idf))




