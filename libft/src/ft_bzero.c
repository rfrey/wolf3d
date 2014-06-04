/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:04:52 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/13 01:10:26 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			ft_bzero(void *s, size_t n)
{
	if (s != NULL)
	{
		while (n > 0)
		{
			*(unsigned char *)s++ = 0;
			n--;
		}
	}
}
