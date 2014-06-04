/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfrey <rfrey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 15:21:16 by rfrey             #+#    #+#             */
/*   Updated: 2014/01/14 18:23:36 by rfrey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define ERR_UNDEF "Undefined error."
# define ERR_MLX_INIT "Can't initialize mlx library."
# define ERR_MLX_WIN "Mlx error : can't create window."
# define ERR_MLX_IMG "Mlx error : can't create image."
# define ERR_MALLOC "Memory allocation error."
# define ERR_FOPEN "Can't open file."
# define ERR_FREAD "Error when reading file."
# define ERR_MAP "Map format error."
# define ERR_TEXTURE_LOAD "Error when loading texture."
# define ERR_TEXTURE_NOT_EXIST "Invalid map, texture not exists."
#endif /* !ERROR_H */
