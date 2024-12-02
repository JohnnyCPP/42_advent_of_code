/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonnavar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:19:12 by jonnavar          #+#    #+#             */
/*   Updated: 2023/10/01 15:25:14 by jonnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file libft.h
 * @brief Contains function declarations for the Libft.
 *
 * The Libft is the low-level development of Standard C 
 * Library functions to leverage in the future.
 *
 * @author jonnavar
 * @version giraffe-spider
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// @note Required for printf.
# include <stdarg.h>
# define NULL_POINTER "(nil)"

// @note Required for gnl.
# define LAST_FD 256
# define BUFFER_SIZE 1
# define BITS_IN_LONG 64
# define BITS_IN_INT 32

/**
 * @brief Structure representing a node in a linked list.
 *
 * The node contains a pointer to data of any type, 
 * and a pointer to the next node in the list.
 */
typedef struct s_list
{
	void			*data;
	struct s_list	*next_node;
}	t_list;

/**
 * @brief Checks if a character is upper case.
 *
 * @param character The character.
 *
 * @return 1 if it's upper case, 0 if it's not.
 */
int		ft_isupper(const char character);

/**
 * @brief Checks if a character is lower case.
 *
 * @param character The character.
 *
 * @return 1 if it's lower case, 0 if it's not.
 */
int		ft_islower(const char character);

/**
 * @brief Checks if a character is alphabetic.
 *
 * @param character The character.
 *
 * @return 1 if it's alphabetic, 0 if it's not.
 */
int		ft_isalpha(const char character);

/**
 * @brief Checks if a character is a digit.
 *
 * @param character The character.
 *
 * @return 1 if it's a digit, 0 if it's not.
 */
int		ft_isdigit(const char character);

/**
 * @brief Checks if a character is alphanumeric.
 *
 * @param character The character.
 *
 * @return 1 if it's alphanumeric, 0 if it's not.
 */
int		ft_isalnum(const char character);

/**
 * @brief Checks if a character is ASCII.
 *
 * @param character The character.
 *
 * @return 1 if it's ASCII, 0 if it's not.
 */
int		ft_isascii(const int character);

/**
 * @brief Checks if a character is printable.
 *
 * @param character The character.
 *
 * @return 1 if it's printable, 0 if it's not.
 */
int		ft_isprint(const char character);

/**
 * @brief Checks if a character is a plus or minus sign.
 *
 * @param character The character.
 *
 * @return 1 if it's a sign, 0 if it's not.
 */
int		ft_issign(const char character);

/**
 * @brief Checks if a character is a space.
 *
 * @param character The character.
 *
 * @return 1 if it's a space, 0 if it's not.
 */
int		ft_isspace(const char character);

/**
 * @brief Checks if a character is a 0 or a 1.
 *
 * @param character The character.
 *
 * @return 1 if it's binary, 0 if it's not.
 */
int		ft_isbinary(const char character);

/**
 * @brief Checks if a string is a binary representation.
 *
 * @param character A pointer to the first character of the string.
 *
 * @return 1 if it's a binary string, 0 if it's not.
 *
 * The string is expected to be null-terminated.
 *
 * This function iterates for each character of the null-terminated string, 
 * calling "ft_isbinary" for each of them.
 */
int		ft_isbinarystr(const char *character);

/**
 * @brief Calculates the integer square root of a given number.
 *
 * @param number The number for which the square root is to be calculated.
 *
 * @return The integer square root of the given number.
 *
 * This function computes the largest integer 'x' such that "x * x" 
 * is less than or equal to the given number.
 *
 * If the number is less than 4, it returns 1. Otherwise, it uses a simple 
 * iterative method to find the integer square root.
 */
int		ft_sqrt(const int number);

/**
 * @brief Calculates the length of a string.
 *
 * @param[character] A pointer to the first character of the string.
 *
 * @return The length of the string.
 */
size_t	ft_strlen(const char *character);

/**
 * @brief Sets a block of memory to a specific value over a defined length.
 *
 * @param buffer Pointer to the starting position of the memory block.
 * @param character The value to fill the memory block with.
 * @param length Specifies how many bytes of memory should be set.
 *
 * @return The original pointer to the block of memory.
 */
void	*ft_memset(void *buffer, int character, size_t length);

/**
 * @brief Sets a block of memory to zero over a defined length.
 *
 * @param buffer Pointer to the starting position of the memory block.
 * @param length Specifies how many bytes of memory should be set.
 */
void	ft_bzero(void *buffer, size_t length);

/**
 * @brief Copies memory from a source to a destination over a defined length.
 *
 * @param destination Pointer to the memory area where the data is copied.
 * @param source Pointer to the memory area from which data is copied.
 * @param length Amount of bytes to be copied.
 *
 * @return The "destination" pointer, after copying is done.
 */
void	*ft_memcpy(void *destination, const void *source, size_t length);

/**
 * @brief Safe memory-moving function that handles memory overlapping.
 *
 * @param destination Pointer to the memory area where the data is moved.
 * @param source Pointer to the memory area from which data is moved.
 * @param length Amount of bytes to be moved.
 *
 * @return The "destination" pointer, after moving is done.
 *
 * Moves memory from a source to a destination over a defined length.
 * It ensures that data is copied correctly, even if the memory areas overlap.
 *
 * The most important aspect is how it handles memory overlapping:
 *
 * When the destination is lower than the source, copies forwards.
 * When the destination is higher than the source, copying in reverse 
 * ensures that the source data isn't overwritten before it's moved 
 * to the destination.
 */
void	*ft_memmove(void *destination, const void *source, size_t length);

/**
 * @brief Copies a string from source to destination.
 *
 * @param destination The buffer where the string will be copied.
 * @param source The string that will be copied.
 * @param length Total size of the destination buffer.
 *
 * @return The length of the source string.
 *
 * Ensures that the destination string is null-terminated.
 * No more than "length - 1" characters are copied to prevent overflow.
 */
size_t	ft_strlcpy(char *destination, const char *source, size_t length);

/**
 * @brief Appends the source string to the destination string.
 *
 * @param destination The buffer containing the initial string.
 * @param source The string to append to the end of "destination".
 * @param length The total size of the destination buffer.
 *
 * @return The length of the string it tried to create. The initial length 
 *         of "destination" plus the length of "source".
 *
 * Ensures that the resulting string is null-terminated.
 * Doesn't exceed the buffer size specified by "length".
 */
size_t	ft_strlcat(char *destination, const char *source, size_t length);

/**
 * @brief Converts a lower case character to its upper case equivalent.
 *
 * @param character The character.
 *
 * @return The upper case equivalent of the character.
 *
 * If the character isn't lower case, returns the character unchanged.
 */
int		ft_toupper(int character);

/**
 * @brief Converts an upper case character to its lower case equivalent.
 *
 * @param character The character.
 *
 * @return The lower case equivalent of the character.
 *
 * If the character isn't upper case, returns the character unchanged.
 */
int		ft_tolower(int character);

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * @param string The null-terminated string to be searched.
 * @param character The character.
 *
 * @return A pointer to the first occurrence of the character in the string, 
 *         or NULL if the character isn't found.
 */
char	*ft_strchr(const char *string, int character);

/**
 * @brief Locates the last occurrence of a character in a string.
 *
 * @param string The null-terminated string to be searched.
 * @param character The character.
 *
 * @return A pointer to the last occurrence of the character in the string, 
 *         or NULL if the character isn't found.
 */
char	*ft_strrchr(const char *string, int character);

/**
 * @brief Compares two strings.
 *
 * @param ptr_find The first string to compare.
 * @param ptr_str The second string to compare.
 *
 * @return An integer less than, equal to, or greater than zero if the 
 *         first string is found to be less than, equal to, or greater 
 *         than the second string, respectively.
 *
 * This function compares two strings character by character 
 * until a null-terminator is encountered.
 *
 * The return value indicates the difference between the two strings 
 * at the first differing position.
 */
int		ft_strcmp(const char *ptr_find, const char *ptr_str);

/**
 * @brief Compares two strings up to a specified amount of characters.
 *
 * @param ptr_find The first string to compare.
 * @param ptr_str The second string to compare.
 *
 * @return An integer less than, equal to, or greater than zero if the 
 *         first string is found to be less than, equal to, or greater 
 *         than the second string, respectively.
 *
 * This function compares two strings character by character up to the 
 * specified length or until a null-terminator is encountered.
 *
 * The return value indicates the difference between the two strings 
 * at the first differing position.
 */
int		ft_strncmp(const char *ptr_find, const char *ptr_str, size_t length);

/**
 * @brief Searches for the first occurrence of a byte in a memory block.
 *
 * @param ptr_str The memory block to search.
 * @param character The byte to search for, interpreted as an "unsigned char".
 * @param length The amount of bytes to search in the memory block.
 *
 * @return A pointer to the first occurrence of "character" in the 
 *         memory block, or NULL if the byte isn't found within 
 *         the specified length.
 *
 * This function scans the first "length" bytes of the memory area pointed 
 * to by "ptr_str" for the first occurrence of the byte value "character".
 */
void	*ft_memchr(const void *ptr_str, int character, size_t length);

/**
 * @brief Compares two memory blocks byte by byte.
 *
 * @param ptr_find The first memory block to compare.
 * @param ptr_str The second memory block to compare.
 * @param length The amount of bytes to compare in each memory block.
 *
 * @return An integer less than, equal to, or greater than zero if the 
 *         first block is found to be less than, equal to, 
 *         or greater than the second block.
 *
 * This function compares the first "length" bytes of 
 * the memory areas "ptr_find" and "ptr_str".
 */
int		ft_memcmp(const void *ptr_find, const void *ptr_str, size_t length);

/**
 * @brief Searches for a substring in a string up to a specified length.
 *
 * @param string The string to be searched.
 * @param to_find The substring to search for.
 * @param length The maximum number of characters to search.
 *
 * @return A pointer to the beginning of the located substring 
 *         within the string, or NULL if the substring is not found.
 *
 * The "ft_strnstr" function searches for the first occurrence 
 * of the substring "to_find" within the string "string", 
 * but it only examines the first "length" characters. 
 */
char	*ft_strnstr(const char *string, const char *to_find, size_t length);

/**
 * @brief Validates the string representation of an int against overflows.
 *
 * @param value The string representation of an integer value.
 *
 * @return If the value doens't trigger overflow against INT_MIN or INT_MAX,
 *         returns 0. Returns 1 for positive overflows,
 *         and -1 for negative overflows.
 */
int		ft_ioverflow(const char *value);

/**
 * @brief Validates the string representation of a long against overflows.
 *
 * @param value The string representation of an integer value.
 *
 * @return If the value doens't trigger overflow against INT_MIN or INT_MAX,
 *         returns 0. Returns 1 for positive overflows,
 *         and -1 for negative overflows.
 */
int		ft_loverflow(const char *value);

/**
 * @brief Converts a string to an integer.
 *
 * @param value A pointer to the string containing the number to be converted.
 *
 * @return The integer value represented by the string,  
 *         or 0 if the string doesn't contain a valid number.
 *
 * This function converts the initial portion of the string pointed to 
 * by "value" to an integer. It handles optional leading spaces, 
 * an optional sign ('+' or '-'), and numeric characters.
 */
int		ft_atoi(const char *value);

/**
 * @brief Converts a string to a long.
 *
 * @param value A pointer to the string containing the number to be converted.
 *
 * @return The long value represented by the string,  
 *         or 0 if the string doesn't contain a valid number.
 *
 * This function converts the initial portion of the string pointed to 
 * by "value" to a long. It handles optional leading spaces, 
 * an optional sign ('+' or '-'), and numeric characters.
 */
long	ft_atol(const char *value);

/**
 * @brief Allocates memory for an array and initializes all bytes to zero.
 *
 * @param amount The number of elements to allocate.
 * @param size The size of each element in bytes.
 *
 * @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void	*ft_calloc(size_t amount, size_t size);

/**
 * @brief Duplicates a string by allocating sufficient memory for it.
 *
 * @param string The string to be duplicated.
 *
 * @return A pointer to the duplicated string, or NULL if the input string 
 *         is NULL or memory allocation fails.
 *
 * This function allocates memory for a new string, copies the input string 
 * into the allocated memory, and returns a pointer to the new string.
 */
char	*ft_strdup(const char *string);

/**
 * @brief Extracts a substring from a string.
 *
 * @param string The original string from which to extract the substring.
 * @param start The starting position of the substring in the original string.
 * @param length The maximum number of characters to include in the substring.
 *
 * @return A pointer to the substring, or NULL if 
 *         the input string is NULL or memory allocation fails.
 *
 * This function allocates memory for and returns a substring of 
 * the given string. The substring starts at the specified position and 
 * will contain up to "length" characters, or fewer 
 * if the string ends before that.
 */
char	*ft_substr(const char *string, unsigned int start, size_t length);

/**
 * @brief Joins two strings into a new allocated string.
 *
 * @param string The first string.
 * @param to_join The string to append to the first string.
 *
 * @return A pointer to the allocated string containing both "string" 
 *         and "to_join", or NULL if memory allocation fails or 
 *         any of the inputs is NULL.
 *
 * This function concatenates the contents of "string" followed by "to_join" 
 * into a newly allocated string.
 */
char	*ft_strjoin(const char *string, const char *to_join);

/**
 * @brief Trims leading and trailing characters from a string.
 *
 * @param string The string to be trimmed.
 * @param characters The set of characters to trim for both ends of the string.
 *
 * @return A pointer to the trimmed string, or NULL if 
 *         memory allocation fails or if either input is NULL.
 *
 * This function removes any characters found in "characters" from the 
 * start and end of the string "string", returning a new string with the 
 * trimmed content.
 *
 * The original string is not modified, and the result is stored in 
 * newly allocated memory.
 */
char	*ft_strtrim(const char *string, const char *characters);

/**
 * @brief Splits a string into an array of substrings based on a delimiter.
 *
 * @param string The string to be split.
 * @param delim The delimiter character used to split the string.
 *
 * @return A pointer to the array of substrings, or NULL if 
 *         memory allocation fails or if the input string is NULL.
 *
 * This function splits the given string "string" into multiple substrings 
 * delimited by the character "delim".
 *
 * The resulting substrings are stored in a newly allocated array of strings, 
 * and the last element of the array is a NULL pointer to mark the end.
 */
char	**ft_split(const char *string, const char delim);

/**
 * @brief Converts an integer to its string representation.
 *
 * @param value The integer to be converted.
 *
 * @return A pointer to the string containing the representation 
 *         of the integer, or NULL if memory allocation fails.
 *
 * This function takes an integer "value" and converts it to a dynamically 
 * allocated string representation.
 *
 * The string is null-terminated and can represent both positive and 
 * negative integers.
 */
char	*ft_itoa(int value);

/**
 * @brief Converts a long to its string representation.
 *
 * @param value The long to be converted.
 *
 * @return A pointer to the string containing the representation 
 *         of the long, or NULL if memory allocation fails.
 *
 * This function takes a long "value" and converts it to a dynamically 
 * allocated string representation.
 *
 * The string is null-terminated and can represent both positive and 
 * negative longs.
 */
char	*ft_ltoa(long value);

/**
 * @brief Applies a function to each character of a string.
 *
 * @param string The input string to be transformed.
 * @param function A pointer to a function that takes an index and 
 *                 a character, returning a transformed character.
 *
 * @return A pointer to the string with transformed characters, or NULL if 
 *         memory allocation fails or if the input string or function is NULL.
 *
 * This function creates a new string by applying the function to 
 * each character of the input string.
 *
 * The function takes the index of the character and the character itself 
 * as parameters and returns the transformed character.
 *
 * The new string is dynamically allocated.
 */
char	*ft_strmapi(const char *string, char (*function)(unsigned int, char));

/**
 * @brief Modifies a string applying a function to each character.
 *
 * @param string The mutable string to be iterated over.
 * @param function A pointer to a function that takes an index and 
 *                 a pointer to a character. This function can 
 *                 modify the original character.
 *
 * This function iterates over each character of the input string, 
 * passing both the character's index and a pointer to the character 
 * itself to the specified function.
 *
 * This allows the function to modify the original string.
 */
void	ft_striteri(char *string, void (*function)(unsigned int, char*));

/**
 * @brief Writes a character to a file descriptor.
 *
 * @param character The character.
 * @param file_descriptor The file descriptor.
 *
 * This function sends the "character" to the given "file_descriptor", 
 * allowing for output to standard output, files, or other output streams.
 */
void	ft_putchar_fd(const char character, int file_descriptor);

/**
 * @brief Writes a string to a file descriptor.
 *
 * @param string The string.
 * @param file_descriptor The file descriptor.
 *
 * This function outputs the given string to the specified file descriptor, 
 * character by character.
 *
 * If the string is NULL, the function does nothing.
 */
void	ft_putstr_fd(const char *string, int file_descriptor);

/**
 * @brief Writes a string to a file descriptor, followed by a newline.
 *
 * @param string The string.
 * @param file_descriptor The file descriptor.
 *
 * This function outputs the given string to the specified file descriptor, 
 * character by character, with a newline at the end.
 *
 * If the string is NULL, the function does nothing.
 */
void	ft_putendl_fd(const char *string, int file_descriptor);

/**
 * @brief Outputs an integer, as a string, to a file descriptor.
 *
 * @param value The integer.
 * @param file_descriptor The file descriptor.
 *
 * This function converts an integer to a string and writes it to the 
 * specified file descriptor.
 *
 * It uses "ft_itoa" to perform the conversion, and it ensures the 
 * allocated memory is freed after use.
 */
void	ft_putnbr_fd(int value, int file_descriptor);

/**
 * @brief Outputs a long, as a string, to a file descriptor.
 *
 * @param value The long.
 * @param file_descriptor The file descriptor.
 *
 * This function converts a long to a string and writes it to the 
 * specified file descriptor.
 *
 * It uses "ft_ltoa" to perform the conversion, and it ensures the 
 * allocated memory is freed after use.
 */
void	ft_putlong_fd(long value, int file_descriptor);

/**
 * @brief Creates a new list node with the provided data.
 *
 * @param data A pointer to the data to be stored in the node.
 * 
 * @return A pointer to the new node, or NULL if the memory allocation fails.
 */
t_list	*ft_list_new(void *data);

/**
 * @brief Adds a new node to the front of the linked list.
 *
 * @param list A double pointer to the head of the list.
 * @param new_node The node to be added to the front of the list.
 */
void	ft_list_add_front(t_list **list, t_list *new_node);

/**
 * @brief Calculates the number of nodes in a linked list.
 *
 * @param list A pointer to the head of the list.
 *
 * @return The number of nodes in the list.
 */
int		ft_list_size(t_list *list);

/**
 * @brief Finds the last node in a linked list.
 *
 * @param list A pointer to the head of the list.
 *
 * @return A pointer to the last node in the list, or 
 *         NULL if the list is empty.
 */
t_list	*ft_list_last(t_list *list);

/**
 * @brief Adds a node at the end of a linked list.
 *
 * @param list A double pointer to the first node of the linked list.
 * @param new_node The node to add to the end of the list.
 *
 * This function traverses the linked list to find the last node and 
 * adds the provided node at the end.
 *
 * If the list is empty, the new node becomes the first node of the list.
 */
void	ft_list_add_back(t_list **list, t_list *new_node);

/**
 * @brief Deletes a node from a linked list.
 *
 * @param list The node to delete.
 * @param function A pointer to a function used to free the memory 
 *                 associated with the node's data.
 *
 * This function frees the memory associated with the node's data 
 * using the provided function pointer and then frees the memory of the node.
 */
void	ft_list_delete_one(t_list *list, void (*function)(void *));

/**
 * @brief Clears a list, freeing all its nodes.
 *
 * @param list A pointer to the head of the list.
 * @param function The function to apply to the data of each node.
 *
 * This function iterates through each node of a linked list, applies 
 * the function to the data in each node, and frees the memory of the node.
 */
void	ft_list_clear(t_list **list, void (*function)(void *));

/**
 * @brief Applies a function to the data of each node in a linked list.
 *
 * @param list The head of the linked list.
 * @param function A function to apply to each node's data.
 *
 * This function traverses through the provided linked list and applies 
 * the specified function to the data in each node.
 */
void	ft_list_iterate(t_list *list, void (*function)(void *));

/**
 * @brief Creates a modified copy of a linked list.
 *
 * @param list The original linked list.
 * @param f The function to apply to each node's data.
 * @param d The function to free the data in case of an error.
 *
 * @return A new linked list with the transformed data, 
 *         or NULL if memory allocation fails.
 *
 * This function traverses the given linked list, applies the "f" function 
 * to each node's data, and creates a new list with the results.
 *
 * If an error occurs during the creation of a new node, the new list 
 * is cleared using the "d" function to free the memory of each node's data.
 */
t_list	*ft_list_map(t_list *list, void *(*f)(void *), void (*d)(void *));

/**
 * @brief Gets a bit from the binary representation of a number.
 *
 * @param number The number whose bit will be extracted.
 * @param bit_position The position of the bit, starting from the right (0-n).
 *
 * @return A 0 or a 1, depending on the value of the bit.
 *
 * This function shifts to the right the bits of "number" 
 * by an amount of "bit_position" and returns the bit value using a bit mask.
 *
 * This function uses bitwise operators to work with individual bits.
 */
int		ft_get_bit(const long number, const int bit_position);

/**
 * @brief Gets the binary representation of a number as a string.
 *
 * @param number The number whose binary representation will be obtained.
 *
 * @return A null-terminated string containing a binary representation.
 *
 * This function allocates memory for a new string of "BITS_IN_INT + 1" size.
 *
 * If the memory allocation fails, it returns NULL.
 *
 * This function iterates for each bit in the binary representation of the 
 * number and introduces each bit in the string using bitwise operators.
 *
 * The returned string is null-terminated.
 */
char	*ft_to_binary_int(const int number);

/**
 * @brief Gets the binary representation of a number as a string.
 *
 * @param number The number whose binary representation will be obtained.
 *
 * @return A null-terminated string containing a binary representation.
 *
 * This function allocates memory for a new string of "BITS_IN_LONG + 1" size.
 *
 * If the memory allocation fails, it returns NULL.
 *
 * This function iterates for each bit in the binary representation of the 
 * number and introduces each bit in the string using bitwise operators.
 *
 * The returned string is null-terminated.
 */
char	*ft_to_binary_long(const long number);

/**
 * @brief Adds spaces between nibbles in a dynamically allocated string.
 *
 * @param binary A double pointer to a dynamically allocated string.
 *
 * @return 1 if the split was successful, 0 otherwise.
 *
 * This function allocates memory for a new string, adds the binary 
 * representation of the passed string to it, frees the passed string, 
 * and changes the double pointer to point to the newly allocated string.
 *
 * This function expects a dynamically allocated string, and 
 * frees it at the end.
 *
 * It does nothing if the double pointer is null, or if the string 
 * is not a binary representation.
 *
 * Both the "binary" and the returned strings are considered
 * to be null-terminated.
 */
int		ft_split_binary_free(char **binary);

/**
 * @brief Copies and returns a formatted binary string.
 *
 * @param A pointer to the binary representation to be formatted.
 *
 * @return A pointer to the new formatted binary representation.
 *
 * This function dynamically allocates memory for a new string, 
 * fills it with the contents of "binary" adding spaces between nibbles.
 *
 * Both the "binary" string and the returned string are 
 * considered to be null-terminated.
 */
char	*ft_split_binary_copy(const char *binary);

// @note Prototypes of printf start here.

/**
 * @brief Prints a pointer as a hexadecimal value, prepended by "0x".
 *
 * @param args The variadic argument list to retrieve the pointer from.
 * @param count A pointer to the counter, updated 
 *              with the number of characters printed.
 * 
 * This function retrieves the pointer from a variadic argument list, 
 * converts it to its hexadecimal representation, and prints it.
 *
 * If the pointer is NULL, it prints "(nil)".
 */
void	ft_pf_ptr(va_list args, int *count);

/**
 * @brief Prints a character from a variadic argument list.
 *
 * @param args The variadic argument list to retrieve the character from.
 * @param count A pointer to the counter, updated with the number 
 *              of characters printed.
 *
 * This function retrieves a character from the variadic argument list 
 * and prints it using the "ft_putchar_fd" function.
 *
 * It also increments the counter that tracks the number of 
 * printed characters.
 */
void	ft_pf_char(va_list args, int *count);

/**
 * @brief Prints a string from a variadic argument list.
 *
 * @param args The variadic argument list to retrieve the string from.
 * @param count A pointer to the counter, updated with the number 
 *              of characters printed.
 *
 * This function retrieves a string from the variadic argument list 
 * and prints it using the "ft_putstr_fd" function. 
 *
 * It also increments the counter that tracks the number of 
 * printed characters by the length of the string.
 */
void	ft_pf_str(va_list args, int *count);

/**
 * @brief Handles a string format specifier.
 *
 * @param ph The format specifier character.
 * @param args The variadic argument list from which the values are retrieved.
 * @param i A pointer to the index of the format string.
 * @param count A pointer to the counter.
 *
 * This function checks the "ph" format specifier and calls the appropiate 
 * print function from the variadic argument list.
 *
 * It also increments both the index and the count of printed characters.
 *
 * It handles specifiers for character, string, and pointer formats.
 */
void	ft_pf_ph_str(char const ph, va_list args, int *i, int *count);

/**
 * @brief Prints an integer value from a variadic argument list.
 *
 * @param args The variadic argument list to retrieve the integer from.
 * @param count A pointer to the counter, updated with the number 
 *              of characters printed.
 *
 * This function retrieves an integer from the variadic argument list, 
 * converts it to a string using "ft_itoa", and prints it to the 
 * standard output using "ft_putstr_fd".
 *
 * It also updates the count of printed characters by adding 
 * the length of the printed string.
 */
void	ft_pf_int(va_list args, int *count);

/**
 * @brief Prints a long value from a variadic argument list.
 *
 * @param args The variadic argument list to retrieve the long from.
 * @param count A pointer to the counter, updated with the number 
 *              of characters printed.
 *
 * This function retrieves a long from the variadic argument list, 
 * converts it to a string using "ft_ltoa", and prints it to the 
 * standard output using "ft_putstr_fd".
 *
 * It also updates the count of printed characters by adding 
 * the length of the printed string.
 */
void	ft_pf_long(va_list args, int *count);

/**
 * @brief Prints an unsigned integer from a variadic argument list.
 *
 * @param args The variadic argument list to retrieve the value from.
 * @param count A pointer to the counter, updated with the number 
 *              of characters printed.
 *
 * This function retrieves an unsigned integer from the variadic 
 * argument list, converts it to a string, and prints it to the 
 * standard output.
 */
void	ft_pf_uns_int(va_list args, int *count);

/**
 * @brief Handles an integer format specifier.
 *
 * @param ph The format specifier character.
 * @param args The variadic argument list from which the values are retrieved.
 * @param i A pointer to the index of the format string.
 * @param count A pointer to the counter.
 *
 * This function checks the "ph" format specifier and calls the appropiate 
 * print function from the variadic argument list.
 *
 * It also increments both the index and the count of printed characters.
 *
 * It handles specifiers for integer, and unsigned integer formats.
 */
void	ft_pf_ph_int(char const ph, va_list args, int *i, int *count);

/**
 * @brief Handles a long format specifier.
 *
 * @param ph The format specifier character.
 * @param args The variadic argument list from which the values are retrieved.
 * @param i A pointer to the index of the format string.
 * @param count A pointer to the counter.
 *
 * This function checks the "ph" format specifier and calls the appropiate 
 * print function from the variadic argument list.
 *
 * It also increments both the index and the count of printed characters.
 *
 * It handles specifiers for the signed long format.
 */
void	ft_pf_ph_long(char const ph, va_list args, int *i, int *count);

/**
 * @brief Prints a percentage sign '%' and updates the counters.
 *
 * @param i A pointer to an integer representing the current index.
 * @param count A pointer to an integer representing the total 
 *              number of characters printed.
 *
 * This function increments the index counter by 2, outputs a percentage sign 
 * to the standard output, and updates the character count to reflect 
 * that one character has been printed.
 */
void	ft_pf_ph_percentage(int *i, int *count);

/**
 * @brief Prints the (lower) hexadecimal representation of an unsigned integer.
 *
 * @param args The variable argument list from which to retrieve the 
 *             unsigned integer.
 * @param count A pointer to an integer representing the total number 
 *              of characters printed.
 * 
 * This function retrieves an unsigned integer from the argument list and 
 * prints its hexadecimal representation using lower case letters.
 */
void	ft_pf_lower_hex(va_list args, int *count);

/**
 * @brief Prints the (upper) hexadecimal representation of an unsigned integer.
 *
 * @param args The variable argument list from which to retrieve the 
 *             unsigned integer.
 * @param count A pointer to an integer representing the total number 
 *              of characters printed.
 * 
 * This function retrieves an unsigned integer from the argument list and 
 * prints its hexadecimal representation using upper case letters.
 */
void	ft_pf_upper_hex(va_list args, int *count);

/**
 * @brief Handles a base format specifier.
 *
 * @param ph The format specifier character.
 * @param args The variadic argument list from which the values are retrieved.
 * @param i A pointer to the index of the format string.
 * @param count A pointer to the counter.
 *
 * This function checks the "ph" format specifier and calls the appropiate 
 * print function from the variadic argument list.
 *
 * It also increments both the index and the count of printed characters.
 *
 * It handles specifiers for lower, and upper hexadecimal formats.
 */
void	ft_pf_ph_base(char const ph, va_list args, int *i, int *count);

/**
 * @brief Handles the printing of a literal percentage sign '%'.
 *
 * @param i A pointer to an integer representing the current index.
 * @param count A pointer to an integer representing the total number 
 *              of characters prined.
 *
 * This function prints a '%' character to the standard output and 
 * increments both the index and the count of characters printed by one.
 */
void	ft_pf_ph_default(int *i, int *count);

/**
 * @brief Custom implementation of a printf-like function.
 *
 * @param format The format string containing plain characters and 
 *               placeholders for values to be printed.
 *
 * @return The total number of characters printed, or 
 *         -1 if the format string is NULL.
 *
 * This function processes a format string and prints the corresponding 
 * characters and formatted values to the standard output.
 *
 * It supports various format specifiers, including characters, strings, 
 * integers, unsigned integers, and hexadecimal values.
 */
int		ft_printf(char const *format, ...);

// @note Prototypes of gnl start here.

/**
 * @brief Checks if a character is present in a string.
 *
 * @param string The string to search within.
 * @param character The character to search for.
 *
 * @return A pointer to the first occurrence of the character in the string, 
 *         or NULL if the character is not found or the string is NULL.
 *
 * This function searches for the first occurrence of a specified character 
 * in a given string.
 *
 * If found, it returns a pointer to that character in the string, 
 * otherwise, it returns NULL.
 */
char	*ft_gnl_contains(const char *string, char character);

/**
 * @brief Computes the length of a string.
 *
 * @param string The string whose length is to be calculated.
 *
 * @return The length of the string, or 0 if the string is NULL.
 *
 * This function calculates the number of characters in a string, 
 * excluding the null terminator.
 */
size_t	ft_gnl_length(const char *string);

/**
 * @brief Concatenates two strings.
 *
 * @param source The string to append to the destination.
 * @param destination The string to which the source will be appended.
 *
 * @return A pointer to the newly created string containing the concatenation, 
 *         or NULL if either string is NULL or if memory allocation fails.
 */
char	*ft_gnl_concat(const char *source, const char *destination);

/**
 * @brief Creates a copy of a string.
 *
 * @param string The string to copy.
 *
 * @return A pointer to the newly allocated string containing the copy, 
 *         or NULL if the input string is NULL or if memory allocation fails.
 * This function allocates memory for a new string and copies the 
 * contents of the given string into it, including the null terminator.
 */
char	*ft_gnl_copy(const char *string);

/**
 * @brief Cuts a substring from a given string.
 *
 * @param string The original string to cut from.
 * @param start The starting index from which to cut.
 * @param length The number of characters to cut.
 *
 * @return A pointer to the newly allocated string containing the cut portion, 
 *         or NULL if the original string is NULL or 
 *         if memory allocation fails.
 *
 * This function allocates memory for and returns a new string that contains 
 * a specified portion of the original string, defined by 
 * the start index and length.
 */
char	*ft_gnl_cut(const char *string, size_t start, size_t length);

/**
 * @brief Reads a line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 *
 * @return A pointer to the line read from the file, or NULL if 
 *         an error occurs or if the end of the file is reached.
 *
 * This function reads a line from the specified file descriptor and returns 
 * it as a dynamically allocated string.
 *
 * It uses a static buffer to maintain the state across multiple calls, 
 * allowing for the reading of lines in sequence.
 */
char	*ft_gnl(int fd);
#endif
