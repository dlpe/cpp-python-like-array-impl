from datetime import datetime

start = datetime.now()

soma = 0

array = []
for i in range(100 ** 3):
    soma += 1
    array.append(soma)

new_array = map(lambda i: i * 3, array)

print (datetime.now() - start).total_seconds()


