a1 = float(input("Введите число a\n"))
b1 = float(input("Введите число b\n"))
print("Производится обмен значениями между a и b...")
c = a1
a1 = b1
b1 = c
print("Число a = ", a1, sep="")
print("Число b = ", b1, sep="")
a2 = float(input("Введите число a\n"))
b2 = float(input("Введите число b\n"))
print("Производится обмен значениями между a и b...")
a2 = a2+b2
b2 = a2-b2
a2 = a2-b2
print("Число a =", a2, "Число b =", b2)