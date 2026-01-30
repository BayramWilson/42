#include "push_swap.h"

void ft_rotate(t_list **head)
{
    t_list *first;
    t_list *last;

    first = *head;
    *head = first->next;
    first->next = NULL;
    
    last = ft_lstlast(*head);
    last->next = first;
}
