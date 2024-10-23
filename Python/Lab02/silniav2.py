def silnia_rekurencyjna(n):
    if n== 0:
        return 1
    return silnia_rekurencyjna(n-1)* n

def silnia_iteracyjna(n):
    wynik= 1
    for i in range(n):
        wynik *= i+ 1
    return wynik

for i in range(15):
    print (i+1, end= '\t')
    print(silnia_rekurencyjna(i), end='\t')
    print(silnia_iteracyjna(i), end='\t')
    print( 4** i)

