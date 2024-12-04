def min_max( lista ):
    n= len( lista )
    if lista[ 0 ]> lista[ 1 ]:
        max= 0
        min= 1
    else:
        max= 1
        min= 0
    for i in range( 1, n// 2 ):
        if lista[ 2* i ] > lista[ 2* i+ 1 ]:
            wiekszy = 2* i
            mniejszy = 2* i+ 1
        else:
            wiekszy = 2* i+ 1
            mniejszy = 2* i
        if lista[ wiekszy ]> lista[ max ]:
            max= wiekszy
        if lista[ mniejszy ]< lista[ min ]:
            min= mniejszy
    if n% 2== 1:
        if lista[ n- 1 ]> max:
            max= n- 1
        elif lista[ n- 1 ]< min:
            min= n- 1
    return min, max

def sort_zliczanie( lista ):
    min, max= min_max( lista )
    min= lista[ min ]
    max= lista[ max ]
    liczniki= []
    for i in range( max- min+ 1 ):
        liczniki.append( 0 )
    for x in lista:
        liczniki[ x- min ]+= 1
    liczniki[ 0 ]-= 1
    for i in range( 1, max- min+ 1 ):
        liczniki[ i ]+= liczniki[ i- 1 ]
    li_wyn= list( lista )
    for i in range( len( lista )- 1, -1, -1 ):
        x= lista[ i ]
        k= x- min
        j= liczniki[ k ]
        li_wyn[ j ]= x
        liczniki[ k ]-= 1
    for i in range( len( lista )- 1, -1, -1 ):
        li_wyn[ liczniki[ lista[ i ]- min ]]= lista[ i ]
        liczniki[ lista[ i ]- min ]-= 1
    return li_wyn

qq= ( 5,7,2,0,5,0,5,0,3,8,4,2,7,3)
print( sort_zliczanie( qq ))