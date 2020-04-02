#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void ft_putchar( char c)
{
	write(1,&c,1);
}	

void  	ft_printnbrx( unsigned int nbr)
{
	char *base = "0123456789abcdef";
		if(nbr>= 16)
			ft_printnbrx(nbr / 16);
		ft_putchar(base[nbr % 16]);
}	
void 	ft_printnbr( unsigned int nbr)
{
		if(nbr >= 10)
			ft_printnbr(nbr / 10);
		ft_putchar(nbr % 10 + '0');
}	
int ft_nbrlen(unsigned int nb)
{
	int len = 0;
	if (nb == 0)
		return(1);
	while( nb > 0)
	{
		nb = nb/10;
		len++;
	}	
	return(len);
}
int ft_nbrlenx(unsigned int nb)
{
	int len = 0;
	if (nb == 0)
		return(1);
	while( nb > 0)
	{
		nb = nb/16;
		len++;
	}	
	return(len);
}	

void	cerospace(int nb, char x)
{
	while(nb > 0)
	{
		write(1,&x,1);
		nb--;
	}	
}	
int	ft_printf(char *str, ...)
{
	int width,precision,space,zero,sign,pflag,len,leng,nb;
	unsigned int nbr;
	char *string;
	va_list valist;
	leng = 0;
	va_start(valist,str);

	while(*str != '\0')
	{
		if(*str == '%')
		{
			width = 0; precision = 0; zero = 0; space = 0; nb = 0; nbr = 0; sign = 0; pflag = 0; len = 0;
			str++;
			while(*str >= '0' && *str <= '9')
			{	
				width = width * 10 + (*str - '0');
				str++;
			}
			if(*str == '.')
			{
				pflag = 1;
				str++;
				while(*str >= '0' && *str <= '9')
				{	
				precision = precision * 10 + (*str - '0');
				str++;
				}
			}
			if (*str == 's')
			{
				len = 0;
				string = va_arg(valist, char *);
				if (!string)
					string = "(null)";
				len = ft_strlen(string);
				if ( precision < len && pflag)
						len = precision;
				if (width > len)
				{
					cerospace(width - len, ' ');
					leng = leng + (width - len);
				}	
				leng = leng + (write(1,string,len));
				str++;		
			}	
			if (*str == 'd')
			{
				len = 0;
				nb = va_arg(valist, int);
				if (nb < 0)
				{	
					sign = 1;
					nb = nb * (-1);
				}
				len = ft_nbrlen(nb);
				if (precision > len)
				{
						if(width > (precision + sign))
								space = width - precision - sign;
						zero = precision - len;		
				}
				else
				{
					if( width > (len + sign))
							space = width - len - sign;
				}
				if ( space > 0)
				{
					cerospace(space, ' ');
					leng = leng + space;
				}
				if ( sign == 1)
				{
					write(1,"-",1);
					leng++;
				}
				if (zero > 0)
				{
					cerospace(zero, '0');
					leng = leng + zero;
				}
				if (nb == 0 && pflag == 1 && precision == 0)
				{
						if(width == 0 && !width)
							cerospace(0, ' ');
						else
						{
							cerospace(1, ' ');
							leng++;
						}
				}
				else
				{
					ft_printnbr(nb);
					leng = leng + len;
				}
				str++;
			}
			if (*str == 'x')
			{
				len = 0;
				nbr = va_arg(valist, unsigned int);
				len = ft_nbrlenx(nbr);
				if (precision > len)
				{
						if(width > precision)
								space = width - precision;
						zero = precision - len;		
				}
				else
				{
					if( width > len)
							space = width - len;
				}
				if ( space > 0)
				{
					cerospace(space, ' ');
					leng = leng + space;
				}
				if (zero > 0)
				{
					cerospace(zero, '0');
					leng = leng + zero;
				}
				if (nbr == 0 && pflag == 1 && precision == 0)
				{
						if(width == 0 && !width)
							cerospace(0, ' ');
						else
						{
							cerospace(1, ' ');
							leng++;
						}
				}
				else
				{
					ft_printnbrx(nbr);
					leng = leng + len;
				}
				str++;
			}	

		}
		else
		{
			write(1,str,1);
			leng++;
			str++;
		}	
	}	
	va_end(valist);
	return(leng);

}	
