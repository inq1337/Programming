import random

def ArrayOuter(arr: list, n: int):
	for i in range(n):
		print(arr[i], ' ', end='')
	print()

def BozoSortArray(arr: list, order = True) -> list:
	sorted = False
	n = int(len(arr))
	while (not sorted):
		if (order):
			index1 = random.randint(0, (n - 1))
			index2 = random.randint(0, (n - 1))

			temp = arr[index1]
			arr[index1] = arr[index2]
			arr[index2] = temp

			sorted = True

			for i in range(1, n):
				if (arr[i - 1] > arr[i]):
					sorted = False
					break
		else:
			index1 = random.randint(0, (n - 1))
			index2 = random.randint(0, (n - 1))

			temp = arr[index1]
			arr[index1] = arr[index2]
			arr[index2] = temp

			sorted = True

			for i in range(1, n):
				if (arr[i - 1] < arr[i]):
					sorted = False
					break
	return arr

def BozoSortMatrix(matrix: list, order = True) -> list:
	s = int(len(matrix))
	arr = []
	for i in range(s):
		for j in range(s):
			arr.append(matrix[i][j])
	del i, j
	return BozoSortArray(arr, order)

def BozoSortNums(a: int, b: int, c: int, order = True) -> list:
	return BozoSortArray([a, b, c], order)

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

a = int(arr[0])
b = int(arr[1])
c = int(arr[2])

ArrayOuter(BozoSortArray(arr), n)
ArrayOuter(BozoSortArray(arr, False), n)
ArrayOuter(BozoSortMatrix(matrix), n)
ArrayOuter(BozoSortMatrix(matrix, False), n)
ArrayOuter(BozoSortNums(arr[0], arr[1], arr[2]), 3)
ArrayOuter(BozoSortNums(arr[0], arr[1], arr[2], False), 3)