/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:57:45 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/12 00:25:31 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIGO_H
# define TRIGO_H
# define PI_VALUE 3.14159265
# define ABS(x) (x < 0 ? -x : x)

double		ft_sin(double alpha);
double		ft_cos(double alpha);
double		ft_tan(double alpha);
double		ft_report_angle(double alpha);
double		ft_deg_to_rad(double alpha);

#endif /* !TRIGO_H */
