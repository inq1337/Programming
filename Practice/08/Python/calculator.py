while True:
    a, sign, b =input('Введите выражение\n').split()
    a = float(a)
    b = float(b)
    if sign == '+' or sign == '-' or sign == '*' or sign == '/':
        if sign == '+':
            print(a+b)
        elif sign == '-':
            print(a-b)
        elif sign == '*':
            print(a*b)
        elif sign == '/':
            if b == 0:
                print('Делить на 0 нельзя. Попробуйте ещё раз\n')
                continue
            else:
                print(a/b)
        break
    else:
        print('Неверный знак. Попробуйте ещё раз\n')