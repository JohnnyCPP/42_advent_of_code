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

static	int	absolute_of(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

static	void	compute_result(t_list **list_a, t_list **list_b)
{
	t_list	*current_node_a;
	t_list	*current_node_b;
	int		result;
	int		node_a_number;
	int		node_b_number;

	if (!list_a || !list_b)
		return ;
	current_node_a = *list_a;
	current_node_b = *list_b;
	result = 0;
	while (current_node_a != NULL && current_node_b != NULL)
	{
		node_a_number = current_node_a->number;
		node_b_number = current_node_b->number;
		result += absolute_of(node_a_number - node_b_number);
		current_node_a = current_node_a->next;
		current_node_b = current_node_b->next;
	}
	printf("Computed result is: \"%i\"\n", result);
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

static	void	list_sort(t_list **list)
{
	t_list	**head;
	t_list	*current_node;
	int		swapped;
	int		current_number;
	int		next_number;

	if (!list)
		return ;
	head = list;
	current_node = *list;
	swapped = 0;
	while (current_node != NULL && current_node->next != NULL)
	{
		current_number = current_node->number;
		next_number = current_node->next->number;
		if (current_number > next_number)
		{
			current_node->number = next_number;
			current_node->next->number = current_number;
			swapped = 1;
		}
		current_node = current_node->next;
	}
	if (swapped)
		list_sort(head);
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
	while (i < length)
	{
		result[i] = '\0';
		i ++;
	}
	result[i] = '\0';
	return (result);
}

static	void	process_buffer(char *buffer, t_list **list_a, t_list **list_b)
{
	char	*left_str;
	char	*right_str;
	int		left_number;
	int		right_number;

	left_str = ft_strncpy(buffer, 5);	// numbers have 5 digits
	if (!left_str)
		return ;
	//	right number begins after the first number (5) and three spaces (+3)
	right_str = ft_strncpy(buffer + 8, 5);
	if (!right_str)
	{
		free(left_str);
		return ;
	}
	left_number = atoi(left_str);
	right_number = atoi(right_str);
	if (!list_push(list_a, left_number))
		printf("Error: could not push a number to list A.\n");
	if (!list_push(list_b, right_number))
		printf("Error: could not push a number to list B.\n");
	free(left_str);
	free(right_str);
}

static	int	read_from_fd(int fd, t_list **list_a, t_list **list_b)
{
	int		chars_to_read;
	char	*buffer;
	int		bytes_read;
	int		line_count;

	if (fd < 0)
		return (0);
	//	each number has 5 digits, there are two numbers for each line
	//	the two numbers are divided by three spaces, with a newline at the end
	chars_to_read = (5 * 2) + 3 + 1;
	buffer = (char *) malloc(sizeof(char) * (chars_to_read + 1));
	if (!buffer)
		return (0);
	bytes_read = read(fd, buffer, chars_to_read);
	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	line_count = 0;
	while (bytes_read != 0)
	{
		buffer[chars_to_read] = '\0';
		process_buffer(buffer, list_a, list_b);
		//printf("%i: %s", line_count + 1, buffer);
		//if (bytes_read < chars_to_read || buffer[bytes_read - 1] != '\n')
		//	printf("\n");
		line_count ++;
		bytes_read = read(fd, buffer, chars_to_read);
		if (bytes_read == -1)
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
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
	t_list	*list_a;
	t_list	*list_b;

	message = "Error: file could not be opened.\n";
	fd = get_fd();
	if (fd == -1)
	{
		printf("%s", message);
		return (1);
	}
	list_a = NULL;
	list_b = NULL;
	read_correctly = read_from_fd(fd, &list_a, &list_b);
	if (!read_correctly)
	{
		message = "Error: file could not be read.\n";
		printf("%s", message);
		return (1);
	}
	list_sort(&list_a);
	list_sort(&list_b);
	compute_result(&list_a, &list_b);
	close(fd);
	return (0);
}
