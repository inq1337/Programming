print('Введите коэффициенты уравнения a, b и c')
a = float(input())
b = float(input())
c = float(input())
if a != 0:
    if c != 0 or b != 0:
        D = b*b-4*a*c
        if D > 0:
            print('x1 = ', (-b + D**0.5)/(2*a), sep="")
            print('x2 = ', (-b - D**0.5)/(2*a), sep="")
        elif D == 0:
            print ('x = ', -b/2*a, sep="")
        else :
            print('Нет корней')
    else:
        print ('x = 0', sep="")
else:
    if b == 0:
        print('Это не уравнение')
    elif c == 0:
        print('x = ', 0, sep="")
    else:
        print('x = ', -c/b, sep="")