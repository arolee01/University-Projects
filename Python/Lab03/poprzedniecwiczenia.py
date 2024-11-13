def sz_pot_i( x, n ):
    if m& 0b01 == 0b01:
        w *= y
    m>>= 1
    if m== 0:
        return w
    y=y*y

def ex( x, eps ):
    suma = 0
    i = 0
    a = 77
    while abs( a )>= eps:
        a = sz_pot_i( x, i )/sil_i(i)
        suma+=a
        i+=1
    return suma

def ex_ŹLE( x, eps ):
    suma= 0
    i= 0
    a= 77
    while abs( a )>= eps:
        a= sz_pot_i( x, i )/ sil_i( i )
        suma+= a
        i+= 1
    return suma

def ex( x, eps ):
    a= 1
    suma= a
    i= 1
    while abs( a )>= eps:
        a= a* x/ i
        suma+= a
        i+= 1
    return suma
