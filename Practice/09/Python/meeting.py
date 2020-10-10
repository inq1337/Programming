while True:
    try:
        h1, m1 = map(int,input('Введите время прихода первого человека\n').split(':'))
        if h1<=23 and h1>=0  and m1<=59 and m1>=0:
            break
        else:
            print('Вы ввели некорректные данные. Попробуйте ещё раз')
            continue
    except ValueError:
        print("Введите время в формате ЧЧ:ММ")
while True:
    try:
        h2, m2 = map(int,input('Введите время прихода второго человека\n').split(':'))
        if h2<=23 and h2>=0  and m2<=59 and m2>=0:
            break
        else:
            print('Вы ввели некорректные данные. Попробуйте ещё раз')
            continue
    except ValueError:
        print("Введите время в формате ЧЧ:ММ")

t1=h1*60+m1
t2=h2*60+m2
if abs(h2-h1)<=15:
    print('Встреча состоится')
else:
    print('Встреча не состоится')