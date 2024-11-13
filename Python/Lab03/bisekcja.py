def bis(a, b, eps, f):
    sr = (a + b) / 2
    while b - a > eps:
        fa = f(a)
        fsr = f(sr)
        if fsr == 0:
            return sr
        if fa * fsr < 0:
            b = sr
        else:
            a = sr
        sr=(a + b) / 2
    return sr

import math

print(bis(0,4, .0001, math.sin))