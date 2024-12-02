//	NULL
#include <stddef.h>
//	open()
#include <fcntl.h>
//	close()
#include <unistd.h>
//	malloc(), atoi()
#include <stdlib.h>
//	printf()
#include <stdio.h>
#include "t_list.h"

char	*ft_gnl(int fd);

static	int	absolute_of(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

static	void	list_print(t_list **list)
{
	int		number;
	t_list	*current_node;

	if (!list)
		return ;
	current_node = *list;
	while (current_node != NULL)
	{
		number = current_node->number;
		printf("%i, ", number);
		current_node = current_node->next;
	}
	printf("\n");
}

static	int	list_put(t_list **list, int number)
{
	t_list	*aux;
	t_list	*new_node;

	if (!list)
		return (0);
	aux = *list;
	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	if (aux == NULL)
	{
		new_node->number = number;
		new_node->next = NULL;
		*list = new_node;
	}
	else
	{
		while (aux->next != NULL)
			aux = aux->next;
		new_node->number = number;
		new_node->next = NULL;
		aux->next = new_node;
	}
	return (1);
}

static	int	list_push(t_list **list, int number)
{
	t_list	*aux;
	t_list	*new_node;

	if (!list)
		return (0);
	aux = *list;
	new_node = (t_list *) malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->number = number;
	new_node->next = aux;
	*list = new_node;
	return (1);
}

static	void	list_empty(t_list **list)
{
	t_list	*current_node;
	t_list	*next_node;

	if (!list)
		return ;
	current_node = *list;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
	*list = NULL;
}

static	t_list	*list_copy(t_list **list)
{
	t_list	*current_node;
	t_list	*result;
	int		number;

	if (!list || !*list)
		return (NULL);
	current_node = *list;
	result = NULL;
	while (current_node != NULL)
	{
		number = current_node->number;
		list_put(&result, number);
		current_node = current_node->next;
	}
	return (result);
}

static	int	list_length(t_list **list)
{
	t_list	*current_node;
	int		length;

	if (!list)
		return (0);
	current_node = *list;
	length = 0;
	while (current_node != NULL)
	{
		length ++;
		current_node = current_node->next;
	}
	return (length);
}

static	void	list_pop(t_list **list, int index_of)
{
	t_list	*last_node;
	t_list	*current_node;
	int		index;

	if (!list || !*list || list_length(list) < index_of)
		return ;
	last_node = NULL;
	current_node = *list;
	index = 0;
	while (current_node->next != NULL && index < index_of)
	{
		last_node = current_node;
		current_node = current_node->next;
		index ++;
	}
	if (last_node != NULL)
	{
		last_node->next = current_node->next;
		free(current_node);
	}
	else
	{
		*list = current_node->next;
		free(current_node);
	}
}

static	char	*ft_strncpy(char *string, int length)
{
	char	*result;
	int		i;

	if (!string)
		return (NULL);
	result = (char *) malloc(sizeof(char) * (length + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (string[i] != '\0' && i < length)
	{
		result[i] = string[i];
		i ++;
	}
	result[i] = '\0';
	return (result);
}

static	int	is_digit(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

static	int	correct_delta_constraint(int delta)
{
	if (1 <= delta && delta <= 3)
		return (1);
	return (0);
}

static	int	is_report_safe(t_list **list)
{
	t_list	*head;
	t_list	*last_node;
	int		current_number;
	int		next_number;
	int		is_ascending;
	int		delta;

	if (!list || !*list)
		return (-1);
	head = *list;
	current_number = head->number;
	next_number = head->next->number;
	is_ascending = current_number < next_number;
	delta = absolute_of(current_number - next_number);
	if (!correct_delta_constraint(delta))
		return (0);
	head = head->next;
	if (is_ascending)
	{
		while (head->next != NULL)
		{
			last_node = head;
			head = head->next;
			current_number = last_node->number;
			next_number = head->number;
			is_ascending = current_number < next_number;
			delta = absolute_of(current_number - next_number);
			if (!is_ascending || !correct_delta_constraint(delta))
				return (0);
		}
	}
	else
	{
		while (head->next != NULL)
		{
			last_node = head;
			head = head->next;
			current_number = last_node->number;
			next_number = head->number;
			is_ascending = current_number < next_number;
			delta = absolute_of(current_number - next_number);
			if (is_ascending || !correct_delta_constraint(delta))
				return (0);
		}
	}
	return (1);
}

static	int	brute_force_report_safety(t_list **list)
{
	t_list	*copy;
	int		report_length;
	int		i;
	int		is_safe_report;

	if (is_report_safe(list))
		return (1);
	report_length = list_length(list);
	i = 0;
	while (i < report_length)
	{
		copy = list_copy(list);
		list_pop(&copy, i);
		is_safe_report = is_report_safe(&copy);
		list_empty(&copy);
		if (is_safe_report)
			return (1);
		i ++;
	}
	return (0);
}

static	int	check_report_safety(const char *report)
{
	t_list	*list;
	int		i;
	int		length;
	int		converted_value;
	int		is_safe;
	char	*aux;
	char	*start;
	char	*number;

	i = 0;
	length = 0;
	aux = (char *) report;
	start = (char *) report;
	is_safe = 0;
	list = NULL;
	while (report[i] != '\0')
	{
		while (report[i] != '\0' && is_digit(report[i]))
		{
			i ++;
			length ++;
		}
		if (!is_digit(report[i]) && length > 0)
		{
			number = ft_strncpy(start, length);
			converted_value = atoi(number);
			list_put(&list, converted_value);
			free(number);
			length = 0;
		}
		while (report[i] != '\0' && !is_digit(report[i]))
			i ++;
		start = aux + i;
	}
	is_safe = brute_force_report_safety(&list);
	list_empty(&list);
	return (is_safe);
}

static	int	read_from_fd(int fd)
{
	char	*string;
	int		report;
	int		result;
	int		i;

	if (fd < 0)
		return (0);
	result = 0;
	string = ft_gnl(fd);
	i = 0;
	while (string != NULL)
	{
		report = check_report_safety(string);
		string = ft_gnl(fd);
		if (report == -1)
			return (0);
		result += report;
		i ++;
	}
	printf("Tolerating a single bad level, this puzzle input has %i safe reports.\n", result);
	return (1);
}

static	int	get_fd()
{
	char	*file_path;
	int		fd;

	file_path = "./input.txt";
	fd = open(file_path, O_RDONLY);
	return (fd);
}

int	main(void)
{
	char	*message;
	int		fd;
	int		read_correctly;

	message = "Error: file could not be opened.\n";
	fd = get_fd();
	if (fd == -1)
	{
		printf("%s", message);
		return (1);
	}
	read_correctly = read_from_fd(fd);
	if (!read_correctly)
	{
		message = "Error: file could not be read.\n";
		printf("%s", message);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
