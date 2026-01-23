/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensche <fwuensche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 17:53:59 by angavrel          #+#    #+#             */
/*   Updated: 2019/03/05 08:39:05 by fwuensche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		curr = *begin_list;
		*begin_list = (*begin_list)->next;
		free(curr);
	}
	curr = *begin_list;
	while (curr && curr->next)
	{
		if (cmp(curr->next->data, data_ref) == 0)
		{
			tmp = curr->next;
			curr->next = tmp->next;
			free(tmp);
		}
		curr = curr->next;
	}
}

// hey you, would you mind submitting a main for this exercise?
// yes OFC! :)
# include <stdio.h>

int cmp_val(void *b1, void *b2)
{
    if(*(int *)b1 == *(int *)b2)
    {
        return 0;
    }
    return 1;
}
void push(t_list **node, int data_add)
{
    t_list *new;
    t_list *tmp;
    int *data;

    data = malloc(sizeof(int));
    *data = data_add;

    new = malloc(sizeof(t_list));
    new->data = data;
    new->next = NULL;

    if(!*node)
    {
        *node = new;
        return;
    }
    tmp = *node;
    while(tmp->next)
        tmp = tmp->next;

    tmp->next = new;
}
void print_list(t_list *node)
{
    while(node)
    {
        printf("%d ", *(int*) node->data);
        node = node->next;
    }
}
int main()
{
    t_list *head = NULL;
    int data_rem = 4;

    push(&head, 4);
    push(&head, 2);
    push(&head, 4);
    push(&head, 7);
    push(&head, 9);

    print_list(head);
    printf("\n");
    ft_list_remove_if(&head, &data_rem, cmp_val);

    print_list(head);
    printf("\n");
}
