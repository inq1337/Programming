import random
from multipledispatch import dispatch
#в питоне не предусмотрена перегрузка
#будем использовать декоратор dispatch

def ArrayOuter(arr: list, n: int):
	for i in range(n):
		print(arr[i], ' ', end='')
	print()

#при использовании декоратора dispacth
#не работают аргументы по-умолчанию
@dispatch(list, bool)
def BozoSort(arr, order) -> list:
	#в питоне нельзя проверить, является ли список
	#2D на этапе получения функцией аргумента
	if type(arr[0]) == list:
		matrix = arr
		s = int(len(matrix))
		arr = []
		for i in range(s):
			for j in range(s):
				arr.append(matrix[i][j])
		del i, j
	n = int(len(arr))
	sorted = False
	while (not sorted):
		if (order):
			index1 = random.randint(0, (n - 1))
			index2 = random.randint(0, (n - 1))
			arr[index1], arr[index2] = arr[index2], arr[index1]

			sorted = True

			for i in range(1, n):
				if (arr[i - 1] > arr[i]):
					sorted = False
					break
		else:
			index1 = random.randint(0, (n - 1))
			index2 = random.randint(0, (n - 1))
			arr[index1], arr[index2] = arr[index2], arr[index1]

			sorted = True

			for i in range(1, n):
				if (arr[i - 1] < arr[i]):
					sorted = False
					break
	return arr

@dispatch(int, int, int, bool)
def BozoSort(a, b, c, order) -> list:
	return BozoSort([a, b, c], order)

n = int(input('Введите количество элементов\n'))
s = int(n**0.5)
arr = list(map(int, input('Заполните массив через пробел\n').split(' ')))
print()
matrix = []
row = []
k = 0
for i in range(n):
	row.append(arr[i])
	k += 1
	if (k % s == 0):
		matrix.append(row)
		row = []
del row, k, i

ArrayOuter(BozoSort(arr, True), n)
ArrayOuter(BozoSort(arr, False), n)
ArrayOuter(BozoSort(matrix, True), n)
ArrayOuter(BozoSort(matrix, False), n)
ArrayOuter(BozoSort(arr[0], arr[1], arr[2], True), 3)
ArrayOuter(BozoSort(arr[0], arr[1], arr[2], False), 3)