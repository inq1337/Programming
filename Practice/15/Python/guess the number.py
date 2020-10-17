import random
print('Вас приветствует игра \"Угадай число\"')
print('Загадано целое число от 0 до 100')
while True:
    x = random.randint(0, 100)
    print('Попробуйте угадать. У вас есть 5 попыток. Введите число')
    for cnt in range(0, 5):
        ig = int(input())
        if ig > x and cnt < 4:
            print('Загаданное число меньше')
        elif ig < x and cnt < 4:
            print('Загаданное число больше')
        elif ig == x:
            print('Поздравляю! Вы угадали')
            break
        elif ig != x and cnt == 4:
            print('Вы проиграли. Было загадано: ', x, sep="")
    restart = int(input('Хотите начать сначала? (1 - ДА)\n'))
    if restart != 1:
        break