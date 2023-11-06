/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcayot <jcayot@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:32:18 by jcayot            #+#    #+#             */
/*   Updated: 2023/11/06 13:34:12 by jcayot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "libft.h"

int	main()
{
	char	*long_str;
	clock_t	start, end;
	double	user_time, system_time;
	size_t	user_result, system_result;

	long_str = malloc(100001 * sizeof (char));
	for (size_t i = 0; i < 100000; i++)
		long_str[i] = 'j';
	long_str[100000] = 0;

	start = clock();
	user_result = ft_strlen(long_str);
	end = clock();
	user_time = (double) (end - start) / CLOCKS_PER_SEC;
	start = clock();
	system_result = strlen(long_str);
	end = clock();
	system_time = (double) (end - start) / CLOCKS_PER_SEC;

	printf("Taille : %lu time : %lf\n", user_result, user_time);
	printf("Taille : %lu time : %lf\n", system_result, system_time);
	if (user_result != system_result) {
		printf("Even your strlen is wrong you're definitely dumb as fuck !\n");
	} else if (system_time < user_time) {
		printf("FAILED BRAINFAULT\n");
		printf("Your strlen is %lf times slower than libc strlen.\nYou're retard. Kill yourself FAST !\n", user_time / system_time);
	} else {
		printf("Congratulation Mr Github for copy pasting libc strlen !");
	}
}
