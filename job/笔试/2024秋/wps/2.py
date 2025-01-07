import sys

data_list = list()

# data_list = [
#     "6",
#     "1 3 1 2 6 4",
# ]

for line in sys.stdin:
    data_list.append(line.strip())

n = int(data_list[0])
arr = [int(i) for i in data_list[1].split(' ')]

pre_sum = arr[0]
end_with_nbr = [i+1 for i in range(n)]
cur_sum_arr = [arr[0]]
pre_max = arr[0]

for i in range(1, n):
    cur_sum = end_with_nbr[i] * arr[i]
    if pre_max > arr[i]:
        for j in range(i-1, -1, -1):
            if arr[j] > arr[i]:
                cur_sum = cur_sum_arr[j] + (end_with_nbr[i] - end_with_nbr[j]) * arr[i]
                break
    else:
        pre_max = arr[i]
    
    pre_sum += cur_sum
    cur_sum_arr.append(cur_sum)

total_nbr = (n + 1) * n // 2
print("{:.6f}".format(pre_sum / total_nbr))

