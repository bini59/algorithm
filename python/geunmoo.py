
def removeT(tt, t):

    n = min(tt, key = lambda li : li[1])
    idx = 0
    temp = True
    for i in range(len(tt)):
        if n[1] == tt[i][1] and n[0] != tt[i][0]:
            temp = False
        if n[0] == tt[i][0]:
            idx = i    


    if temp and t:
        tt.append(tt.pop(idx))
    elif temp and not t:
        tt.insert(0, tt.pop(idx))

    if temp:
        for i in range(len(tt)):
            if i != idx:
                tt[i][1] -= n[1]
    
    return tt

    


f1 = [["이준호", 0], ["이영근", 0], ["엄선홍", 0], ["황준호", 0], ["임유빈", 0], ["정원영", 0], ["김태윤", 0], ["김민걸", 0]]
s1 = [["이준호", 0], ["정원영", 0], ["김태윤", 0], ["엄선홍", 0], ["이영근", 0], ["황준호", 0], ["김민걸", 0], ["임유빈", 0]]
t1 = [["이영근", 0], ["황준호", 0], ["김민걸", 0], ["엄선홍", 0], ["이준호", 0], ["정원영", 0], ["김태윤", 0], ["임유빈", 0]]

f2 = [["이준호", 0], ["이영근", 0], ["엄선홍", 0], ["황준호", 0], ["임유빈", 0], ["정원영", 0], ["김태윤", 0], ["김민걸", 0]]
s2 = [["이준호", 0], ["정원영", 0], ["김태윤", 0], ["엄선홍", 0], ["이영근", 0], ["황준호", 0], ["김민걸", 0], ["임유빈", 0]]
t2 = [["이영근", 0], ["황준호", 0], ["김민걸", 0], ["엄선홍", 0], ["이준호", 0], ["정원영", 0], ["김태윤", 0], ["임유빈", 0]]

result = [[0, 0, 0, 0, 0, 0]]

i = 0
while i < 365000:

    temp = []

    if i % 7 == 5 or i % 7 == 6:

        f2 = removeT(f2, False)
        s2 = removeT(s2, False)

        if result[i][4] == f2[-1][0] or result[i][5] == f2[-1][0]:
            f2.insert(0, f2.pop())
            f2[-2][1] += 1
        
        temp.append(f2[-1][0])
        f2.insert(0, f2.pop())
        temp.append(f2[-1][0])
        f2.insert(0, f2.pop())

        temp.append(s2[-1][0])
        s2.insert(0, s2.pop())
        temp.append(s2[-1][0])
        s2.insert(0, s2.pop())
        

    else:

        f1 = removeT(f1, True)
        s1 = removeT(s1, True)

        if result[i][4] == f1[0][0] or result[i][5] == f1[0][0]:
            f1.append(f1.pop(0))
            f1[1][1] += 1

            
        
        temp.append(f1[0][0])
        f1.append(f1.pop(0))
        temp.append(f1[0][0])
        f1.append(f1.pop(0))

        temp.append(s1[0][0])
        s1.append(s1.pop(0))
        temp.append(s1[0][0])
        s1.append(s1.pop(0))

    for j in range(2):
        n = 0
        if i % 7 == 5 or i % 7 == 4:
            t2 = removeT(t2, False)
            for k in range(len(temp)):
                if temp[k] == t2[-1][0]:
                    n += 1
            
            if n == 2:
                t2.insert(0, t2.pop())
                t2[-2][1] += 1
            temp.append(t2[-1][0])
            t2.insert(0, t2.pop())
        else:
            t1 = removeT(t1, True)
            for k in range(len(temp)):
                if temp[k] == t1[-1][0]:
                    n += 1
            
            if n == 2:
                t1.append(t1.pop(0))
                t1[1][1] += 1
            temp.append(t1[0][0])
            t1.append(t1.pop(0))

    result.append(temp)
    i += 1



for i in result:
    print(i)

print(f1, f2)
print(s1, s2)
print(t1, t2)

f = open("test.txt", "w")
for i in range(50):
    
    if i != 0:
        data = ''
        for j in result[i]:
            data += j
            data += ' '
        data += '\n'
        if i % 7 == 0:
            data += '\n\n'
        f.write(data)

three = [0, 0, 0, 0, 0, 0, 0, 0]
four = [0, 0, 0, 0, 0, 0, 0, 0]
for i in result:
    for j in range(len(f1)):
        if f1[j][0] == i[2]:
            three[j] += 1
for i in result:
    for j in range(len(f1)):
        if f1[j][0] == i[3]:
            four[j] += 1

wone = [0, 0, 0, 0, 0, 0, 0, 0]
wtwo = [0, 0, 0, 0, 0, 0, 0, 0]
plus = [0, 0, 0, 0, 0, 0, 0, 0]

for i in range(len(result)):
    if i % 7== 5 or i % 7 == 6:
        for j in range(len(f1)):
            if f1[j][0] == result[i][0]:
                wone[j] += 1
            if f1[j][0] == result[i][1]:
                wtwo[j] += 1

print(wone)
print(wtwo)

print(three)
print(four)

for i in range(8):
    plus[i] = wone[i]+wtwo[i]

print(plus)

for i in wone:
    f.write(f'{i} ')
f.write('\n')
for i in wtwo:
    f.write(f'{i} ')
f.write('\n')
for i in plus:
    f.write(f'{i} ')
f.write('\n')
for i in three:
    f.write(f'{i} ')
f.write('\n')
for i in four:
    f.write(f'{i} ')
f.write('\n')
f.close()

