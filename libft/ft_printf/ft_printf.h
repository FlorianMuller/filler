/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:18:16 by fmuller           #+#    #+#             */
/*   Updated: 2017/06/11 04:43:38 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct	s_word
{
	char	**color_word;
	char	**color_value;
	char	**attribute_word;
	char	**attribute_value;
}				t_word;

typedef struct	s_color
{
	char	attribute[2];
	char	forground[2];
	char	background[2];
	char	new_attribute[2];
	char	new_forground[2];
	char	new_background[2];
	size_t	is_fg_light;
	size_t	is_bg_light;
	size_t	new_is_fg_light;
	size_t	new_is_bg_light;
	int		dontchange;
}				t_color;

typedef struct	s_param
{
	int		flag_lst[7];
	int		width;
	int		precision;
	char	lenght[3];
	char	type;
	size_t	len;
	size_t	start;
	char	default_value;
}				t_param;

typedef struct	s_buff
{
	char			*str;
	int				i;
	struct s_buff	*next;
}				t_buff;

typedef struct	s_all
{
	va_list	ap;
	char	*output;
	t_color	color_status;
	int		*param_list;
	int		i;
	int		current_param;
	int		end;
	int		write;
	int		rett;
	int		len;
}				t_all;

int				ft_printf(const char *format, ...);
int				ft_printf_fd(int fd, const char *format, ...);
int				ft_truc(t_all *all, int ret);
int				ft_(t_all *all, const char *str);
int				ft_free_all(t_all *all);

void			ft_init_all_printf(t_all *all);
char			*ft_reset_all_printf(t_all *all);
int				ft_init_param_list(int **param_list, va_list ap,
				const char *str);
void			ft_find_param(int wanted_param, t_all *all);

int				ft_read(char *str, t_all *all);
int				ft_is_flags(char c);
int				ft_is_type(char c);
int				ft_is_lenght(char c);
int				ft_is_nbr(char c);

void			ft_set_nbr_param(const char *str, int *wanted_param,
				t_all *all);
size_t			ft_set_flag(char *str, t_param *param);
size_t			ft_set_width(char *str, t_param *param, va_list ap,
				int *param_list);
size_t			ft_set_precision(char *str, t_param *param, va_list ap,
				int *param_list);
size_t			ft_set_type(char *str, t_param *param);

int				ft_write_nbr(t_param *param, t_all *all);
void			ft_tolower_pchar(char *c);
int				ft_write_pointer(t_param *param, t_all *all);
int				ft_write_s(t_param *param, t_all *all);
int				ft_write_big_s(t_param *param, t_all *all);
void			ft_write_c(t_param *param, t_all *all);
int				ft_write_big_c(t_param *param, t_all *all);
void			ft_write_percent(t_param *param, t_all *all);
void			ft_write_n(t_param *param, t_all *all);

void			ft_write_all(t_param *param, char *str, t_all *all);
void			ft_write_string(t_param *param, char *str, t_all *all);

void			ft_putchar_output(char c, t_all *all, size_t index);
void			ft_putchar_endoutput(char c, t_all *all);
void			ft_putstr_output(char *src, t_all *all, size_t index);
void			ft_putstr_endoutput(char *src, t_all *all);

int				ft_color(t_all *all, const char *str);
int				ft_read_color(char *str, t_all *all);
size_t			ft_set_argument(char *str);
int				ft_init_key_word(t_word *key_word);
void			ft_set_is_light(char *str, int *i, t_color *color_status);
size_t			ft_set_len(char *str);
int				ft_change_color(t_all *all);
int				ft_free_key_word(t_word *key_word);
void			ft_reset_new_color_status(t_color *color_status);
int				ft_reset_color(t_all *all);
t_color			ft_init_status(void);
void			ft_change_status(t_color *color_status);

#endif
