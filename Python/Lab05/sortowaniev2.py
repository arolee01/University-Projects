def min_max(lista):
    n = len(lista)
    min = max = lista[0]
    for i in lista:
        if i < min:
            min = i
        if i > max:
            max = i
    return min, max

def sort_zliczanie(lista):
    min, max = min_max(lista)

    # Tworzenie tablicy liczników
    zakres = max - min + 1
    liczniki = [0] * zakres

    # Zliczanie wystąpień
    for liczba in lista:
        liczniki[liczba - min] += 1

    # Obliczenie sum częściowych
    for i in range(1, zakres):
        liczniki[i] += liczniki[i - 1]

    # Tworzenie posortowanej tablicy
    lista_koncowa = [0] * len(lista)
    for i in range(len(lista) - 1, -1, -1):  # Iteracja od końca
        liczba = lista[i]
        indeks = liczba - min
        pozycja = liczniki[indeks] - 1
        lista_koncowa[pozycja] = liczba
        liczniki[indeks] -= 1

    return lista_koncowa

tab = (7,5,8,7,2,0,5,0,3,8,5,2,0,7,3)
print(sort_zliczanie(tab))