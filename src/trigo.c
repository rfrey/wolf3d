/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:53:13 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/12 18:51:21 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "trigo.h"

double		ft_sin(double alpha)
{
	return (sin(ft_deg_to_rad(alpha)));
}

double		ft_cos(double alpha)
{
	return (cos(ft_deg_to_rad(alpha)));
}

double		ft_tan(double alpha)
{
	return (tan(ft_deg_to_rad(alpha)));
}

double		ft_deg_to_rad(double alpha)
{
	return (alpha * PI_VALUE / 180.0);
}

double		ft_report_angle(double alpha)
{
	if (alpha < 0)
		alpha += 360;
	else if (alpha >= 360)
		alpha -= 360;
	return (alpha);
}
