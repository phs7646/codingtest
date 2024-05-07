
#build mydict

mydict = {}

first_row = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p']
for index, key in enumerate(first_row):
    mydict[key] = (0, index)

second_row = ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l']
for index, key in enumerate(second_row):
    mydict[key] = (1, index)

third_row = ['z', 'x', 'c', 'v', 'b', 'n', 'm']
for index, key in enumerate(third_row):
    mydict[key] = (2, index)


a,b = input().strip().split()
leftx, lefty = mydict[a]
rightx, righty = mydict[b]

string = input().strip()

time = 0
for c in string :
    targetx, targety = mydict[c]
    if (targetx == 0 and targety <= 4) or (targetx == 1 and targety <= 4) or (targetx == 2 and targety <= 3) :
        #왼손
        time += abs(targetx - leftx)
        time += abs(targety - lefty)
        leftx = targetx
        lefty = targety
    else :
        #오른손
        time += abs(targetx - rightx)
        time += abs(targety - righty)
        rightx = targetx
        righty = targety
    time+=1
    
print(time)