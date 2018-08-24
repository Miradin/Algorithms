#Теперь возьмём задачу, где люди идентичны, а группы уникальны. 
#То есть надо просто какую-то группу людей разделить на команды. Пустые команды допускаются.
#Проще всего реализовать на Питоне из-за легкого процесса конвертаций типов.
#После приведения типов задача сводится к нахождению суммы цифр и проверке.

people = 5;
groups = 4;
a = str(people)*groups
b = int(a)
for j in range(b+1):
    n = j
    result = 0
    for i in range(len(str(n))):
        result = result + int(str(n)[i:i+1])

    if (result==people):
        t = '{:0>{groups}d}'.format(j, groups = groups)
        print("Could be obtained as summ of: ")
        for k in range (groups):
            print(t[k] + "  ", end='')
        print()
