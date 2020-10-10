while True:
    num = int(input('Ведите число\n'))
    if num >= 2:
        for cnt in range(2, int(num**0.5)+1):
            if num % cnt == 0:
                print('Составное')
                break
        else:
            print('Простое')
        break
    else:
        print ('Вы ввели некорректные данные. Попробуйте ещё раз\n')