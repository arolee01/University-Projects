# ALGORYTM JEDNOCZESNEGO ZNAJDOWANIA MINIMUM I MAXIMUM

def min_max( lista ):
    for liczba in lista:
        print(liczba, end=" ")

    print("\nMin: ", min(lista))
    print("Max: ", max(lista))

lista = [11, 5 , 16, 2, -1, 7, 0]
print( min_max( lista ))

print( sorted(lista))