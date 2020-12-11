n = int(input('Введите количество сигалов\n'))
raw = list(map(int, input('Введите последовательность сигналов\n').split(' ')))
outer = []
size = int(0)
for i in range(n):
    outer.append(raw[i])
    size += 1
    outer.sort(reverse = True)
    if (size <= 5):
        for j in range(size):
            print(outer[j], end=" ")
        print()
    else:
        for j in range(size-5, size):
            print(outer[j], end=" ")
        print()