

def create(size, a0 = 0, d = 0) -> list:
    arr = []
    arr.append(a0)
    for i in range(1, size):
        arr.append(arr[i-1] + d)

    return arr


def sort(arr) -> list:
    for i in range(1, len(arr)):
        key = arr[i]
        j = i-1
        while j >=0 and key < arr[j]:
                arr[j+1] = arr[j]
                j -= 1
        arr[j+1] = key

    return arr


realPrint = print

def print(arr) -> list:
    realPrint('[', end='')
    for i in range(len(arr) - 1):
        realPrint(arr[i], end=', ')
    realPrint(arr[len(arr) - 1], ']', sep='')

    return arr


while True:
    try:
        size, firstElem, step = map(int,input('Enter space-separated length, first number, and step of the arithmetic progression\n').split(' '))
        arr = create(size, firstElem, step)
        sort(arr)
        print(arr)
        break
    except ValueError:
        print('Incorrect input')