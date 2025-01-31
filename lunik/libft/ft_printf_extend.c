/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-21 19:07:47 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-21 19:07:47 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(char *str, int fd)
{
	if (str == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	write(fd, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	int	count;

	count = 0;
	if (nbr >= (unsigned int) base_len(base))
		count += ft_putnbr_hex(nbr / base_len(base), base);
	count += write(1, &base[nbr % base_len(base)], 1);
	return (count);
}

int	ft_putadress(void *nbr, char *base)
{
	int					count;
	unsigned long long	res;

	count = 0;
	res = (unsigned long long) nbr;
	if (nbr == 0)
		return (ft_putstr("(nil)", 1));
	count += ft_putstr("0x", 1);
	count += ft_putnbr_base_ul(res, base);
	return (count);
}

// Le 6 par defaut, mais doit devenir le nombre de chiffre apres virgule (0 >= value && value <= 9 && format[i+1] == 'f')
// FT_HANDLE_PRECISION

int ft_putnbr_float(double n, int precision, int fd)
{
    int 		count;
    long long 	int_part;
    double 		frac_part;
	int 		i;
	int			digit;

	count = 0;
	digit = 0;
    if (n < 0)
    {
        count += write(fd, "-", 1);
        n = -n;
    }
    int_part = (long long)n;
    frac_part = n - int_part;
    count += ft_putnbr(int_part, fd);
    if (precision > 0)
    {
        count += write(fd, ".", 1);
        i = 0;
        while (i < precision)
        {
            frac_part *= 10;
            digit = (int)frac_part;
            count += ft_putchar(digit + '0', fd);
            frac_part -= digit;
            i++;
        }
    }
    return (count);
}

