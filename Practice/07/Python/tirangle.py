method = int(input('Выберите способ рассчёта площади треугольника\n1 - через длину сторон\n2 - через координаты вершин\n'))
while True:
    if method == 1:
        print('Введите длины сторон a, b и c')
        a = float(input())
        b = float(input())
        c = float(input())
        while True:    
            if a>0 and b>0 and c>0 and b+c>a and c+a>b and a+b>c:
                p = (a + b + c) / 2
                S = (p * (p - a) * (p - b) * (p - c))**0.5
                print('Площадь треугольника S = ', S, sep="")
                break
            else:
                print('Такого треугольника не существует. Попробуйте ещё  раз')
                a = float(input())
                b = float(input())
                c = float(input())
                continue
        break
    elif method == 2:
        break
    else:
        print('Введите 1 или 2')
        method = int(input())