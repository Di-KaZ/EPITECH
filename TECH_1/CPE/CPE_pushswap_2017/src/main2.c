/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include "pushswap.h"

elem_t *swap (elem_t *list)
{
	int temp;

	if (list == NULL)
		return (NULL);
	if (list->next == NULL)
		return (list);
	temp = list->nb;
	list->nb = list->next->nb;
	list->next->nb = temp;
	return (list);
}

elem_t *rotate_left (elem_t *list)
{
	elem_t *temp = list->next;
	elem_t *to_move = list;

	to_move->next = NULL;
	list = list->next;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = to_move;
	return(list);
}

elem_t *rotate_right (elem_t *list)
{
	elem_t *temp = list;
	elem_t *ptemp = list;

	while (temp->next != NULL) {
		ptemp = temp;
		temp = temp->next;
	}
	ptemp->next = NULL;
	temp->next = list;
	return (temp);
}

void free_list (elem_t *list)
{
	elem_t *temp = list;
	elem_t *ptemp = list;

	while (temp->next != NULL) {
		ptemp = temp;
		temp = temp->next;
		free(ptemp);
	}
	free(temp);
}

elem_t *push (elem_t **list1, elem_t *list2)
{
	elem_t *temp = *list1;

	(*list1) = (*list1)->next;
	if (!list2) {
		temp->next = NULL;
		return (temp);
	}
	temp->next = list2;
	return (temp);
}
