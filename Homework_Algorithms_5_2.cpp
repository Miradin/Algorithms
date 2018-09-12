//Alexander Zhigunov
//Programming language: C++

/*
2. Добавить в программу “реализация стека на основе односвязного списка” проверку на выделение памяти.
 Если память не выделяется, то выводится соответствующее сообщение.
 Постарайтесь создать ситуацию, когда память не будет выделяться (добавлением большого количества данных).
*/

#include <stdio.h>
#include <malloc.h>
#define T int
// Опишем структуру узла списка
struct TNode
{
    T value;
    struct TNode *next;
};
typedef struct TNode Node;

struct Stack
{
    Node *head;
    int size;
    int maxSize;
};
struct Stack Stack;

void push(T value)
{
    Node *tmp;
    tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL)
    {
        printf ("Memory was not allocated"); //Here we check for memory alocation
        exit(1);
    }
    tmp->value = value;
    tmp->next = Stack.head;
    Stack.head = tmp;
    Stack.size++;
}

T pop() {
    if (Stack.size == 0)
    {
        printf("Stack is empty");
        return 0;
    }
    // Временный указатель
    Node* next = NULL;
    // Значение "наверху" списка
    T value;
    value = Stack.head->value;
    next = Stack.head;
    Stack.head = Stack.head->next;
    // Запись, на которую указывала голова удаляем, освобождая память
    free(next);
    // Возвращаем значение, которое было в голове
    Stack.size--;
    return value;
}

void PrintStack()
{
    Node *current = Stack.head;
    while(current != NULL)
    {
        printf("%i ", current->value);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    Stack.maxSize = 100;
    Stack.head = NULL;
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    for (int i=0; i < 100000000000; i++) //here we simulate memory-not-allocated. Value can vary depending on OS used/settings and memory available
        push(i);
    //PrintStack();
    return 0;
}
