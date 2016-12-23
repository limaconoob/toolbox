/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpepin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 06:45:33 by jpepin            #+#    #+#             */
/*   Updated: 2016/02/04 06:45:58 by jpepin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifdef DEBUG
#  include <string.h>
#  define PRINT(debug_message) write(2, debug_message, strlen(debug_message))
# endif
