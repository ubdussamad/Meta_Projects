#legend = list(map(int,input("enter range sepreate by comma:").split(',')))
years = [*range(1901,2001)] #from 1901 to 2000 (1 added for making up wuth range)
days = 0
for i in years:
	if i%4:
		days+=365
	days+=366
d = days
days = ["Mon","Tue","Wed","Thu","Fri","Sat","Sun"]
mapped_days = []
count = 0
for i in range(1,d+1):
	if i%7:
		mapped_days.append(days[count])
		count +=1
		continue
	mapped_days.append(days[count])
	count = 0

calender = []

for i in years:
	if i%4:
		#Not Leap year
		days = [31,28,31,30,31,30,31,31,30,31,30,31]
		for i in days:
			calender.append(mapped_days[:i])
			del mapped_days[:i]
		continue
	days = [31,29,31,30,31,30,31,31,30,31,30,31]
	for i in days:
		calender.append(mapped_days[:i])
		del mapped_days[:i]
suns = 0
for month in calender:
	if month[0] == 'Sun':
		suns+=1
print(suns)
