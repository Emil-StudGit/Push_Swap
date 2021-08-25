/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebellon <ebellon@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:26:07 by ebellon           #+#    #+#             */
/*   Updated: 2021/08/25 19:08:04 by ebellon          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack)
	{
		stack->content = content;
		stack->next = NULL;
		stack->prev = NULL;
	}
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	last = ft_stacklast(*stack);
	if (!*stack)
		*stack = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_stacksize(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

// int	ft_in_stack(t_stack *stack, int content)
// {
// 	while (stack)
// 	{
// 		if (stack->content == content)
// 			return (1);
// 		stack = stack->next;
// 	}
// 	return (0);
// }

// void	ft_free_stack(t_stack *stack)
// {
// 	t_stack	*tmp;

// 	while (stack)
// 	{
// 		tmp = stack->next;
// 		free(stack);
// 		stack = tmp;
// 	}
// }
