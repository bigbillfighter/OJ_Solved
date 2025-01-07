import sys

for line in sys.stdin:
    a = line.strip()

# a = "124358|1801|200|807936|3"

input_data = a.split('|')
speak_time = int(input_data[1])
speak_fee = int(input_data[2])
data_time = int(input_data[3])
data_fee = int(input_data[4])

ans = 0

# speak
speak_minute = (speak_time + 59) // 60
if speak_minute > 1:
    if speak_minute <= 5:
        ans += (9 + (speak_fee - 1) * 1.5 * speak_fee) // 10
    else:
        ans += 4 * 1.5 * speak_fee // 10
        if speak_minute <= 10:
            ans += ( 9 + (speak_minute - 5) * speak_fee) // 10
        else:
            ans += 5 * speak_fee // 10
            if(speak_minute <= 20):
                ans += (9 + (speak_minute - 10) * speak_fee * 0.5) // 10
            else:
                ans += 10 * speak_fee * 0.5 // 10

                ans += (9 + (speak_minute - 20) * speak_fee * 0.2) // 10



# data
data_mb = data_time // 1024

if data_mb < 100:
    ans += (99 + data_time * data_fee) // 100
else:
    ans += 100*1024 * data_fee // 100


if data_mb > 125:
    if data_mb < 225:
        ans += (99 + (data_time - 1024*125) * data_fee) // 100
    else:
        ans += 100*1024 * data_fee // 100


if data_mb > 325:
    if data_mb < 725:
        ans += (99 + (data_time - 1024*325) * data_fee) // 100
    else:
        ans += 400*1024 * data_fee // 100
    
        times = (data_mb - 725) // 200
        ans += 100 * data_fee * times // 100

        res = (ans - 725) % 200
        if res > 100:
            ans += (99 + (res - 100) * data_fee)  // 100

print(int(ans))


