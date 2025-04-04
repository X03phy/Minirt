/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:30 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/03 13:40:06 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"
#include <stdio.h>

void	tuples_tests(void)
{
	printf(GRN "Tuples tests : \n" RESET);

	printf(YEL "ADD : \n" RESET);
	t_tuple test = tuple_create(3, -2, 5, 1);
	t_tuple test2 = tuple_create(-2, 3, 1, 0);
	t_tuple	test3 = tuple_add(test, test2);
	tuple_prints(&test);
	tuple_prints(&test2);
	tuple_prints(&test3);

	printf(YEL "SUB : \n" RESET);
	test = tuple_create(3, 2, 1, POINT);
	test2 = tuple_create(5, 6, 7, POINT);
	test3 = tuple_substitute(test, test2);
	tuple_prints(&test);
	tuple_prints(&test2);
	tuple_prints(&test3);

	printf(YEL "NEG : \n" RESET);
	test = tuple_create(1, -2, 3, VEC);
	test3 = neg_tuples(test);
	tuple_prints(&test);
	tuple_prints(&test3);

	printf(YEL "MUL : \n" RESET);
	test = tuple_create(1, -2, 3, -4);
	test3 = tuple_multiply(test, 3.5);
	tuple_prints(&test);
	tuple_prints(&test3);
	
	printf(YEL "DIV : \n" RESET);
	test = tuple_create(1, -2, 3, -4);
	test3 = tuple_divide(test, 2);
	tuple_prints(&test);
	tuple_prints(&test3);


	printf(YEL "MAG : \n" RESET);
	test = tuple_create(1, 2, 3, VEC);
	printf("Magnitude of vector : ");
	tuple_prints(&test);
	printf("=> %f\n", vector_magnitude(test));

	printf(YEL "NORM : \n" RESET);
	test = tuple_create(1, 2, 3, VEC);
	t_tuple norm = vector_normalize(test);
	tuple_prints(&test);
	tuple_prints(&norm);

	printf(YEL "DOT : \n" RESET);
	t_tuple testa = tuple_create(1, 2, 3, VEC);
	t_tuple testb = tuple_create(2, 3, 4, VEC);
	tuple_prints(&testa);
	tuple_prints(&testb);
	printf("dot product : %f\n", dot_tuple(testa, testb));

	printf(YEL "CROSS : \n" RESET);
	testa = tuple_create(1, 2, 3, VEC);
	testb = tuple_create(2, 3, 4, VEC);
	tuple_prints(&testa);
	tuple_prints(&testb);
	printf("cross product (a, b) : ");
	t_tuple testc = cross_tuple(testa, testb);
	tuple_prints(&testc);
	printf("cross product (b, a) : ");
	testc = cross_tuple(testb, testa);
	tuple_prints(&testc);
}

void	tuples_proj_test(void)
{
	t_tuple position = tuple_create(0, 1, 0, POINT);
	t_tuple vel = vector_normalize(tuple_create(1, 1, 0, VEC));
	t_tuple gravity = tuple_create(0, -0.5, 0, VEC);
	t_tuple vent = tuple_create(-0.01, 0, 0, VEC);

	int total_tick = 0;

	while (position.y >= 0) {
		tuple_prints(&position);
		total_tick++;
		usleep(100000);
		position = tuple_add(position, vel);
		vel = tuple_add(vel, tuple_add(gravity, vent));
	}
	printf("totaltick : %d\n", total_tick);
}
