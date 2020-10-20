cnt = int(0)
x = int(1)
while True:
    n = int(input('Введите число n\n'))
    if n >= 0:
        while x <= n:
            x = x * 2
            cnt = cnt + 1
        print(cnt)
        break
    else:
        print('Вы ввели некорректные данные. Попробуйте ещё раз\n')