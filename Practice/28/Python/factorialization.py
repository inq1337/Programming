def DGenerator(n: int) -> list:
    dividers = []
    i = int(1)
    while (True):
        if (i == n):
            dividers.append(i)
            break
        elif (n % i == 0 and i != 1):
            n = n / i
            dividers.append(i)
            i = 0
        i += 1
    return dividers

def print_factorization(n: int) -> None:
    dividers = DGenerator(n)
    size = len(dividers)
    temp = 0
    print(dividers[0], end="", sep="")
    for i in range (1, size):
        if (dividers[i] == temp):
            continue
        if (dividers[i - 1] == dividers[i]):
            k = int(1)
            temp = dividers[i]
            j = i - 1
            while (dividers[j] == temp):
                k += 1
                j += 1
            print('^', k, end="", sep="")
        else:
            print('*', dividers[i], end="", sep="")

n = int(input('Введите число\n'))
print_factorization(n)