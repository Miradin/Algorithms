/*Теперь возьмём задачу, где люди идентичны, и группы тоже. То есть надо просто какую-то группу людей разделить на команды.
Тогда алгоритм немного другой:
Пусть будет у нас 4 человека и 3 команды.
1. Для начала представим людей как единички и всех положим в команду 1. [1111] [0000] [0000]  - делаем вывод
2. берем [0001] и делаем XOR с командой 1 и командой 2 - делаем вывод
3. берем [0001] и делаем XOR с командой 2 и командой 3 - не надо, если команды не уникальны

4. берем [0001] и делаем XOR с командой 3 и командой 1 -- вернулись в исходное состояние

5. берем [0011] и делаем XOR с командой 1 и командой 2 - делаем вывод
6. берем [0011] и делаем XOR с командой 2 и командой 3  - не надо, если команды не уникальны

7. берем [0011] и делаем XOR с командой 3 и командой 1 -- вернулись в исходное состояние

8. берем [0111] и делаем XOR с командой 1 и командой 2 - делаем вывод
9. берем [0111] и делаем XOR с командой 2 и командой 3  - не надо, если команды не уникальны

XOR с [1111] делать надо только в случае если команды уникальны*/

