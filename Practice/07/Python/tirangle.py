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
        break
    elif method == 2:
        print('Введите попарно координаты вершин x и y')
        xA, yA = map(float,input('Введите координаты вершины A\n').split())
        xB, yB = map(float,input('Введите координаты вершины B\n').split())
        xC, yC = map(float,input('Введите координаты вершины C\n').split())
        a = ((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB))**0.5
        b = ((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC))**0.5
        c = ((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA))**0.5
        while True:    
            if a>0 and b>0 and c>0 and b+c>a and c+a>b and a+b>c:
                p = (a + b + c) / 2
                S = (p * (p - a) * (p - b) * (p - c))**0.5
                print('Площадь треугольника S = ', S, sep="")
                break
            else:
                print('Такого треугольника не существует. Попробуйте ещё  раз')
                xA, yA = map(float,input('Введите координаты вершины A\n').split())
                xB, yB = map(float,input('Введите координаты вершины B\n').split())
                xC, yC = map(float,input('Введите координаты вершины C\n').split())
                a = ((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB))**0.5
                b = ((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC))**0.5
                c = ((xB - xA) * (xB - xA) + (yB - yA) * (yB - yA))**0.5
        break
    else:
        print('Введите 1 или 2')
        method = int(input())