/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoy <rchoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 17:06:33 by rchoy             #+#    #+#             */
/*   Updated: 2016/08/23 19:23:29 by rchoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_list.h"

void	print_list(t_list *list)
{
	ft_putstr("\n\t[ " CYN);
	while (list)
	{
		ft_putstr(list->data);
		ft_putstr(" -> ");
		list = list->next;
	}
	ft_putstr("NULL");
	ft_putstr(RESET " ]\n");
}

void	describe_action_with_data(char *str, void *data)
{
	ft_putstr(GRN "");
	ft_putstr(str);
	ft_putstr(RESET " with data \""GRN);
	ft_putstr(data);
	ft_putstr(RESET"\" : ");
}

void	describe_action_no_data(char *str)
{
	ft_putstr(GRN "");
	ft_putstr(str);
	ft_putstr(RESET"");
}

void	try_function(char *str, void *data, t_list **element, void (*f)(t_list**, void*))
{
	ft_putstr(GRN "");
	ft_putstr(str);
	ft_putstr(RESET " with data \""GRN);
	ft_putstr(data);
	ft_putstr(RESET"\"");
	f(element, data);
	print_list(*element);
}

void	print_yellow(void *str)
{
	ft_putstr(YEL "");
	ft_putstr(str);
	ft_putstr(RESET " ");
}

int		main(int argc, char **argv)
{
	t_list	*element;
	t_list	*inputed_args;
	char *test_values[] = {"toto", "tata", "tati", "tutu", "OK"};

	describe_action_with_data("Create first element of chained list", test_values[0]);
	element = ft_create_elem("NULL");
	inputed_args = ft_list_push_params(argc, argv);
	print_list(element);
	try_function("Push back", test_values[1], &element, &ft_list_push_back);
	try_function("Push back", test_values[2], &element, &ft_list_push_back);
	try_function("Push back", test_values[3], &element, &ft_list_push_back);
	try_function("Push front", test_values[0], &element, &ft_list_push_front);
	try_function("Push front", test_values[2], &element, &ft_list_push_front);
	describe_action_no_data("Result from ft_list_size : ");
	ft_putnbr(ft_list_size(element));
	print_list(element);
	try_function("Push front", test_values[0], &element, &ft_list_push_front);
	try_function("Push front", test_values[2], &element, &ft_list_push_front);
	describe_action_no_data("Result from ft_list_size : ");
	ft_putnbr(ft_list_size(element));
	print_list(element);
	describe_action_no_data("Result from ft_list_last : ");
	ft_putstr(ft_list_last(element)->data);
	print_list(element);
	describe_action_no_data("Result from ft_list_clear on first list : ");
	ft_list_clear(&element);
	print_list(element);
	describe_action_no_data("Result from ft_list_reverse on inputed list : ");
	ft_list_reverse(&element);
	print_list(element);
	describe_action_no_data("Result from command lines parameters : ");
	print_list(inputed_args);
	describe_action_no_data("\nResult from ft_list_at with 3 : ");
	if (ft_list_at(inputed_args, 3) != NULL)
		ft_putstr(ft_list_at(inputed_args, 3)->data);
	else
		ft_putstr(RED "function returns NULL pointer" RESET);
	print_list(inputed_args);
	describe_action_no_data("\nResult from ft_list_at with 0 : ");
	if (ft_list_at(inputed_args, 0) != NULL)
		ft_putstr(ft_list_at(inputed_args, 0)->data);
	else
		ft_putstr(RED "function returns NULL pointer" RESET);
	print_list(inputed_args);
	describe_action_no_data("\nResult from ft_list_at with 6 : ");
	if (ft_list_at(inputed_args, 6) != NULL)
		ft_putstr(ft_list_at(inputed_args, 6)->data);
	else
		ft_putstr(RED "function returns NULL pointer" RESET);
	print_list(inputed_args);
	describe_action_no_data("Result from ft_list_reverse on inputed list : ");
	ft_list_reverse(&inputed_args);
	print_list(inputed_args);
	describe_action_no_data("Result from print_yellow on previous list : ");
	ft_list_foreach(inputed_args, &print_yellow);
	print_list(inputed_args);
	describe_action_with_data("print yellow on strings matching", test_values[4]);
	ft_list_foreach_if(inputed_args, &print_yellow, test_values[4], &ft_strcmp);
	print_list(inputed_args);
	describe_action_with_data("ft_list_find on strings matching", test_values[4]);
	print_list(ft_list_find(inputed_args, test_values[4], &ft_strcmp));
	print_list(inputed_args);
	describe_action_with_data("ft_list_remove_if on strings matching", test_values[0]);
	ft_list_remove_if(inputed_args, test_values[0], &ft_strcmp);
	print_list(inputed_args);
	describe_action_no_data("Merge list 1 & 2 : ");
	ft_list_merge(&element, inputed_args);
	print_list(element);
	describe_action_no_data("Result from ft_list_reverse_fun on thus sorted list : ");
	ft_list_reverse_fun(element);
	print_list(element);
	describe_action_no_data("Sort thus created list: ");
	ft_list_sort(&element, &ft_strcmp);
	print_list(element);
	describe_action_with_data("Result from ft_sorted_list_insert", test_values[2]);
	ft_sorted_list_insert(&element, test_values[2], &ft_strcmp);
	print_list(element);
	describe_action_with_data("Result from ft_sorted_list_insert", "../a");
	ft_sorted_list_insert(&element, "../a", &ft_strcmp);
	print_list(element);

}
