while True:
    a, sign, b =input('Введите выражение\n').split()
    a = float(a)
    b = float(b)
    if sign == '/' and b == 0:
        print('Делить на 0 нельзя. Попробуйте ещё раз')
        continue
    elif sign == '+' or sign == '-' or sign == '*' or sign == '/':
        if sign == '+':
            print(a+b)
        elif sign == '-':
            print(a-b)
        elif sign == '*':
            print(a*b)
        elif sign == '/':
            print(a/b)
    else:
        print('Неверный знак. Попробуйте ещё раз')
        continue
    break