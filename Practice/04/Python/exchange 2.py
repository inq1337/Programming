a = float(input("Введите число a\n"))
b = float(input("Введите число b\n"))
print("Производится обмен значениями между a и b...")
a = a+b
b = a-b
a = a-b
print("Число a =", a, "Число b =", b)