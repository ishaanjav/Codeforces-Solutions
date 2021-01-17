'''
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
'''

def lcm(a, b):
    return int(a * b / gcd(a, b))

def gcd(a, b):
    return b if a == 0 else gcd(b % a, a)

test = int(input())
while test > 0:
    a = input()
    b = input()
    poss = False
    for i in range(1, 21):
        for j in range(1, 21):
            if(a * i == j * b):
                poss = True
    if poss:
        print(a * int(((lcm(len(a), len(b)))/len(a))))
    else:
        print(-1)
    test -= 1
