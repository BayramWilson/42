/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:35:03 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/22 18:32:04 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *new_node(int value)
{
    t_list *node;

    node = malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->value = value;
    node->next = NULL;
    return (node);
}

void    print_list(t_list *head)
{
    t_list *current;

    current = head;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
void    insert_ordered(t_list **head, int value)
{
    t_list *node;
    t_list *current;
    t_list *prev;

    node = new_node(value);
    if (!node)
        return;

    /* CASE 1: empty list OR insert before head */
    if (*head == NULL /* OR value should come before (*head)->value */)
    {
        /* YOU decide the condition */
        node->next = *head;
        *head = node;
        return;
    }

    prev = NULL;
    current = *head;

    while (current != NULL /* AND value should come after current->value */)
    {
        /* YOU decide the condition */
        prev = current;
        current = current->next;
    }

    /* CASE 2 & 3: middle or end */
    prev->next = node;
    node->next = current;
}

int main(void)
{
    t_list *list_a = NULL;
    t_list *list_b = NULL;
    //head = (t_list *) malloc(sizeof(t_list));
    // if (head == NULL) {
    //     return 1;
    // }
    
    insert_ordered(&list_a, 5);
    insert_ordered(&list_a, 2);
    insert_ordered(&list_a, 8);
    insert_ordered(&list_a, 3);
    print_list(list_a);
    printf("\n");
    // ft_swap(&list_a);
    // print_list(list_a);
    // printf("\n");
    // ft_push(&list_a, &list_b);
    // print_list(list_a);
    // printf("\n");
    // print_list(list_b);
    ft_push(&list_b, &list_a);
    // ft_push(&list_b, &list_a);
    print_list(list_a);
    ft_printf("\n");
    print_list(list_b);
    //print_list(list_b);
    // ft_lstclear(list_a);
    // ft_lstclear(list_b);
    

}
void *pb(t_list **lista, t_list **listb)
    {
        ft_push(&lista, &listb);
    }
