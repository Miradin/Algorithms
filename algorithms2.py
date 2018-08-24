#Теперь возьмём задачу, где люди идентичны, а группы уникальны. 
#То есть надо просто какую-то группу людей разделить на команды. Пустые команды допускаются.
#Проще всего реализовать на Питоне из-за легкого процесса конвертаций типов.
#После приведения типов задача сводится к нахождению суммы цифр и проверке.

people = 5;
groups = 4;
a = str(people)*groups #make string 5555
b = int(a) #will be used as max number for cycle
for j in range(b):
    n = j
    summ = 0 #getting summ of digits
    for i in range(len(str(n))): 
        summ = summ + int(str(n)[i:i+1])

    if (summ==people):
        t = '{:0>{groups}d}'.format(j, groups = groups) #formating output
        print("Could be obtained as summ of: ")
        for k in range (groups):
            print(t[k] + "  ", end='') #print without endline
        print()
