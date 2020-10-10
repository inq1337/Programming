print('Введите число и степень, в которую его надо возвести')
defnum = float(input())
deg = int(input())
num = defnum
if deg == 0:
    print(1)
elif deg < 0:
	deg = -deg
	for cnt in range(1, deg):
		num = num * defnum
	print(1 / num)
else:
	for cnt in range(1, deg):
		num = num * defnum
	print(num)