"""[Problem] https://www.facebook.com/photo.php?fbid=1404921536220872&set=pcb.172845249917898&type=3&theater
[Hint] a * b mod m = (a mod m) * (b mod m) mod m
"""

import math
from functools import reduce

M = 10**9+7

n = input()
n = int(n)
sqrt_n = math.sqrt(n)
sqrt_n = math.floor(sqrt_n)

factors = filter(lambda x: n % x == 0, range(1, sqrt_n+1))
factors = map(lambda x: (x % M, n / x % M), factors)

prod = lambda a, b: (a % M) * (b % M) % M
ans = map(lambda x: prod(x[0], x[1]) if x[0] != x[1] else x[0], factors)
ans = reduce(prod, ans)
ans = int(ans)

print(ans)
