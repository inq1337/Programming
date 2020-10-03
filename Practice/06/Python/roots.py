import math
while True:
    a = float(input('Введите коэффициент a\n'))
    b = float(input('Введите коэффициент b\n'))
    c = float(input('Введите коэффициент c\n'))
    if (a == 0 and b == 0 and c == 0):
        print ('Корнем уравнения является любое число\n')
        break
    elif (a == 0 and b != 0 and c == 0):
        print ('Корень уравнения равен нулю\n')
        break
    elif (a != 0 and b == 0 and c == 0):
        print ('Корень уравнения равен нулю\n')
        break
    elif (a < 0 and b == 0 and c < 0):
        print ('Нет корней\n')
        break
    elif (a == 0 and b != 0 and c != 0):
        x1 = b / -c
        print ('Уравнение имеет один корень')
        print( 'x1 =', x1)
        break
    elif (a != 0 and b != 0 and c == 0):
        x1 = 0
        x2 = -b / a
        print ('Уравнение имеет следующие корни:\n', "x1 = ", x1, sep="")
        print ('x2 =', x2)
        break
    elif (a != 0 and b == 0 and c < 0):
        x1 = math.sqrt(-c / a)
        x2 = -math.sqrt(-c / a)
        print ('Уравнение имеет следующие корни:\n', "x1 = ", x1, sep="")
        print ('x2 =', x2)
        break
    elif (a != 0 and b != 0 and c != 0):
        D = b * b - 4 * a * c
        if (D >= 0):
            if (D == 0):
                x1 = -b / 2 * a
                print ('Уравнение имеет один корень')
                print( 'x1 =', x1)
            else:
                x1 = -b + math.sqrt(D) / 2 * a
                x2 = -b - math.sqrt(D) / 2 * a
                print ('Уравнение имеет следующие корни:\n', "x1 = ", x1, sep="")
                print ('x2 =', x2)
                break
        else:
            print ('Дискриминант отрицательный, уравнение не имеет действительных корней. Попробуйте ещё раз.\n')
    else:
        print ('Вы ввели некорректные значения. Решений нет. Попробуйте ещё раз\n\n')