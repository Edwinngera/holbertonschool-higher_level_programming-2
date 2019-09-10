#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* insert_node - inserts a new node at a given position
* @head: first element of the list
* @number: index of the node we want to insert
* Return: the value of a n node.
*/
listint_t *insert_node(listint_t **head, int number)
{

	listint_t *current = NULL;
	listint_t *current2 = NULL;
	int idx = 0;
	int j, flag = 0;
	struct listint_s *new = NULL;

	current = *head;
	current2 = *head;

	if (head == NULL)
		return (NULL);
	if (current == NULL)
		new = add_nodeint(head, number);
	for (j = 0; current2 != NULL; j++)
		current2 = current2->next;
	while (current != NULL)
	{

		if (number > current->n)
		{
			current = current->next;
			idx++;
		}
		else
		{
			new = insert_nodeint_at_index(head, idx, number);
			flag = 1;
			return (new);
			break;
		}
	}
	if (flag == 0)
		new = add_nodeint_end(head, number);
	return (new);
}

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: first element of the list
 * @idx: index of the node we want to insert
 * @n: value of the node
 * Return: the value of a n node.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	struct listint_s *temp = NULL;
	struct listint_s *new = NULL;
	int count;

	count = 0;
	i = 0;
	temp = (struct listint_s *)malloc(sizeof(struct listint_s));
	new = (struct listint_s *)malloc(sizeof(struct listint_s));
	if (new == NULL || head == NULL || temp == NULL)
		return (NULL);
	if (idx == 0)
	{
		temp->n = n;
		temp->next = *head;
		*head = temp;
		return (temp);
	}
	if (*head == 0)
		return (NULL);
	temp = *head;
	new->n = n;
	while (temp != NULL)
	{
		if (temp == NULL)
			return (NULL);
		if (i == (idx - 1))
		{
			new->next = temp->next;
			temp->next = new;
			count = 1;
			break;
		}
		i++;
		temp = temp->next;
	}
	if (count == 0)
		return (NULL);
	return (new);
}

/**
 * add_nodeint - add the first node in a linked lis_t list.
 *@head: Address of first element of the list
 *@n: integer
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{

	struct listint_s *temp = NULL;

	temp = (struct listint_s *)malloc(sizeof(struct listint_s));
	if (temp == NULL)
		return (NULL);
	temp->n = n;
	temp->next = *head;
	*head = temp;
	return (temp);

}
