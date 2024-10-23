def Fibonacci(n):

    # Sprawdza czy n nie jest mniejszy od 0
    if n < 0:
        print("Zła cyfra")

    # Sprawdza czy n jest równe 0
    # Zwraca 0
    elif n == 0:
        return 0

    # Sprawdza czy n jest równe 1 lub 2
    # zwraca 1
    elif n == 1 or n == 2:
        return 1

    else:
        return Fibonacci(n-1) + Fibonacci(n-2)

n= int(input("Podaj, którą liczbę ciągu Fibonacciego wyświetlić: "))
print(Fibonacci(n))