pattern = str('a???55661')

def IsTicketValid(code) -> bool:
	if (len(code) == len(pattern)):
		if ord(code[0]) == 97 and ord(code[1]) in range(97, 122+1):
			for i in range(2, len(pattern)):
				if (pattern[i] == '?'):
					if ord(code[i]) in range(48, 57+1):
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
		code = input('Введите билеты\n').split()
		for i in range(len(code)):
			if IsTicketValid(code[i]) == True:
				print(code[i], end = ' ')
				k = k + 1
		if k == 0:
			print(-1)
		break
	else:
		print('Количество билетов должно быть больше нуля\n')