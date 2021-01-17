'''
 * Created by ishaanjav
 * github.com/ishaanjav
 * Codeforces Solutions: https://github.com/ishaanjav/Codeforces-Solutions
'''

test = int(input())
while test > 0:
    n = int(input())
    arr = list(map(int, input().split()))
    dp = [0] * n
    for i in range(n - 1, -1, -1):
        dp[i] += arr[i]
        if i + arr[i] < n:
            dp[i] += dp[i + arr[i]]
    print(max(dp))
    test -= 1
