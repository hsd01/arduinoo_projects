from datetime import datetime
c = datetime.now()
current_time = c.strftime('%H:%M:%S')
print('Current Time is:', current_time)

def greet():
    hello = ["hello", "hey", "what's up"]
    tim = datetime.now()
    current_time = tim.strftime('%H:%M:%S')
    print('Current Time is:', current_time)
    cu_time = current_time.split(":")
    time_now = cu_time[0]
    print(time_now)
