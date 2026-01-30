#include "push_swap.h"

void    ft_swap(t_list **head)
{
    t_list *first;
    t_list *second;
    
    if (!head || !*head)
        return;
    first = *head;
    second = first->next;
    
    first->next = second->next;
    second->next = first;
    *head = second;
}