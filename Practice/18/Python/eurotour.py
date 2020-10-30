dictionary = str('hallo, klempner, das, ist, fantastisch, fluggegecheimen')

def remover(d: str) -> str:
    d1 = d.replace(',', '')
    dmerged = d1.replace(' ', '')
    return dmerged

def counter(d:str, letter) -> float:
    q = int(0)
    for i in range(len(d)):
        if (d[i] == letter):
            q = q + 1
    return q

dmerged = remover(dictionary)
prob = float(1)
stop = input('Введите стоп-слово\n')
for i in range(len(stop)):
    prob = prob * (counter(dmerged, stop[i]) / len(dmerged))
print('Вероятность для стоп-слова:', prob)