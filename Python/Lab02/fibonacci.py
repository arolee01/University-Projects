def ciag_fibonacciego(n):
    fi0=0
    fi1=1

    fi = fi1
    i=1

    while i <= n:
        print(fi, end=" ")
        i += 1
        fi0, fi1 = fi1, fi
        fi = fi0 + fi1
    print()

n=int(input("Podaj ile liczb ciągu fibonacciego wyświetlić: "))
print(ciag_fibonacciego(n))