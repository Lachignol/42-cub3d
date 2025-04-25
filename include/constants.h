/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:11:17 by aoger             #+#    #+#             */
/*   Updated: 2025/04/25 17:11:18 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define _USE_MATH_DEFINES

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef M_PI_2
#  define M_PI_2 1.57079632679489661923
# endif

// window settings
# define WIN_WIDTH_TO_SCREEN 0.8
# define WIN_HEIGHT_TO_SCREEN 0.8

// game settings
# define BLOCK_SIZE 64

// minimap settings
# define PLAYER_CIRCLE_DIAM_TO_BLOCK_SIZE 0.8
# define MINIMAP_WIDTH 160
# define MINIMAP_MAX_WIDTH_TO_WIN 0.10
# define MINIMAP_MAX_HEIGHT_TO_WIN 0.20
# define MINIMAP_BLOCKS_IN_HEIGHT 16
# define MINIMAP_MARGIN 8

// player settings
# define FOV_DEG 60
# define PLAYER_STEP_SIZE_TO_BLOCK_SIZE 4
# define PLAYER_ROT_DEG 60
# define MOUSE_SENSITIVITY 0.03

// mlx settings
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define MOUSE_BTN_LEFT 1
# define MOUSE_BTN_RIGHT 3
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define MOUSE_LEFT 0
# define MOUSE_RIGHT 1

// gun sprites settings
# define NBR_OF_GUN_SPRITES 6
# define GUN_SIZE_TO_SCREEN 0.3
# define GUN_X_OFFSET_TO_GUN_WIDTH 1

// gun animation settings
# define GUN_ANIM_NBR_FRAMES 5
# define GUN_ANIM_DUR 0.25

#endif
