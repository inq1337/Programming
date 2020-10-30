pattern = str('a???55661')

def IsTicketValid(code: str, n: int) -> bool:
	if (len(code) == 9):
		if code[0] == 'a' and 97 <= code[1] and code[1] <= 122:
			for i in range(2,9):
				if (pattern[i] == '?'):
					if 48 <= code[i] and code[i] <= 57:
						continue
					else:
						return False
				else:
					if code[i] == pattern[i]:
						continue
					else:
						return False
		else:
			return False
		return True
	else:
		return False

while True:
	k = int(0)
	n = int(input('Введите количество билетов\n'))
	if (n > 0):
		print('Введите билеты')
		for i in range(0, n):
			code = input().split(' ')
			if (IsTicketValid(code, 9) == True):
				answer = answer + code + ' '
				k = k + 1
		if (k > 0):
			print(answer)
		else:
			print(-1)
		break
	else:
		print('Количество билетов должно быть больше нуля\n')