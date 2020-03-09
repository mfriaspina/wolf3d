/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfrias <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:41:47 by mfrias            #+#    #+#             */
/*   Updated: 2020/03/05 13:09:48 by mfrias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFF_SIZE 32
# define MAX_SIZE_FD 2560

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define END   "\x1B[0m"

typedef struct		s_flags
{
	char			left;
	char			prepend;
	char			zero;
	char			hash;
	int				width;
	int				precision;
	int				length;
	int				size;
}					t_flags;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				*ft_lstfold(void *(*f)(t_list *elem, void *), t_list *lst);
t_list				*ft_lstsplit(char const *s, char c);

void				ft_putnbr_endl(int n);
int					ft_countwords(char const *s, char c);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
int					get_next_line(const int fd, char **line);
int					ft_strsize(char *str, char delim);
char				*ft_replace(char *original, char new, char old);
char				*ft_strtrimchar(char const *s, char c);
char				*ft_strtoupper(char *str);
char				*ft_strrev(char *str);
char				*ft_ftoa(double n, int digits);
char				*ft_utoa(unsigned long long u);
intmax_t			ft_abs(intmax_t num);
double				ft_fabs(double num);
int					ft_sizeputstr(char *str);
int					ft_sizeputchar(char c);
void				ft_sort(char **str);
char				*ft_itoa_base(unsigned long long val, size_t base);
long				ft_atol(const char *str);
int					ft_orup(char a, char c);
long				ft_num_digits(const long n);

int					ft_printf(char *format, ...);
int					typepercent(t_flags *flag);
int					typef(va_list ap, t_flags *flag, long double val);
int					typep(va_list ap, t_flags *flag);
int					typec(va_list ap, t_flags *flag);
int					typest(va_list ap, t_flags *flag);
int					typex(va_list ap, t_flags *flag, intmax_t val, char c);
int					typeo(va_list ap, t_flags *flag, intmax_t val);
int					typeu(va_list ap, t_flags *flag, intmax_t val);
int					typed(va_list ap, t_flags *flag, intmax_t val);
int					width(t_flags *flag, int i, char *s);
int					clean(char *str);
int					clean_num(char *str);
char				*free_strjoin(char *one, char *two, int i);
int					ft_intlen(int num);
int					colors(t_flags *flag, char *str);
int					binary(va_list ap, t_flags *flag, intmax_t val);
int					invalid(t_flags *flag, char c);
int					fields(int *j, char *format, va_list ap, t_flags *flag);

#endif
