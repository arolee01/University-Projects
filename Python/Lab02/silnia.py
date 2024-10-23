def silnia_rekurencyjna( n ):
    if n== 0:
        return 1
    return silnia_rekurencyjna( n- 1 )* n

def silnia_iteracyjna( n ):
    wynik= 1
    for i in range( n ):
        wynik*= i+ 1
    return wynik
n= int(input("Podaj liczbę na której wykona się silnia: "))
print("Silnia iteracyjna: ", silnia_iteracyjna(n))
print("Silnia rekurencyjna: ", silnia_rekurencyjna(n))
