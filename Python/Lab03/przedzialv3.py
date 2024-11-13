def trap( a, b, n, f ):
    dx = (b - a) / n
    suma = (f(a) + f(b)) / 2
    x = a + dx
    for i in range(n - 1):
        suma += f(x)
        x += dx
    suma *= dx
    return suma

import math

print(trap(0, math.pi, 2000, math.sin))