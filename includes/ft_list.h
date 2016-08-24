/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoy <rchoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 16:25:15 by rchoy             #+#    #+#             */
/*   Updated: 2016/08/23 19:20:11 by rchoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_LIST_H
# define __FT_LIST_H

# include <unistd.h>
# include <stdlib.h>
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

typedef struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list	*ft_create_elem(void *data);
t_list	*ft_list_last(t_list *begin_list);
t_list	*ft_list_push_params(int ac, char **av);
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
int		ft_strcmp(char *s1, char *s2);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
int		ft_list_size(t_list *begin_list);
void	ft_putnbr(int n);
void	ft_list_clear(t_list **begin_list);
void	ft_list_reverse(t_list **begin_list);
void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)());
t_list	*ft_list_remove_if(t_list *begin_list, void *data_ref, int (*cmp)());
void 	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void 	ft_list_sort(t_list **begin_list, int (*cmp)());
void	ft_list_reverse_fun(t_list *begin_list);
void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)());
void 	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)());
void	try_function(char *str, void *data, t_list **element, void (*f)(t_list**, void*));
void	describe_action_with_data(char *str, void *data);
void	describe_action_no_data(char *str);
void	print_list(t_list *list);

#endif
