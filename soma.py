from datetime import datetime

start = datetime.now()

soma = 0
for i in range(100 ** 4):
    soma += 1

print soma
print (datetime.now() - start).total_seconds()


