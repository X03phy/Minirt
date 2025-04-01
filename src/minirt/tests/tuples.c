/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebonutto <ebonutto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:46:30 by maecarva          #+#    #+#             */
/*   Updated: 2025/04/01 14:09:22 by ebonutto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/matrix.h"
#include <stdio.h>

void	tuples_tests(void)
{
	printf(GRN "Tuples tests : \n" RESET);

	printf(YEL "ADD : \n" RESET);
	t_tuple test = new_tuple(3, -2, 5, 1);
	t_tuple test2 = new_tuple(-2, 3, 1, 0);
	t_tuple	test3 = add_tuples(test, test2);
	print_tuples(&test);
	print_tuples(&test2);
	print_tuples(&test3);

	printf(YEL "SUB : \n" RESET);
	test = new_tuple(3, 2, 1, POINT);
	test2 = new_tuple(5, 6, 7, POINT);
	test3 = sub_tuples(test, test2);
	print_tuples(&test);
	print_tuples(&test2);
	print_tuples(&test3);

	printf(YEL "NEG : \n" RESET);
	test = new_tuple(1, -2, 3, VEC);
	test3 = neg_tuples(test);
	print_tuples(&test);
	print_tuples(&test3);

	printf(YEL "MUL : \n" RESET);
	test = new_tuple(1, -2, 3, -4);
	test3 = mul_tuple(test, 3.5);
	print_tuples(&test);
	print_tuples(&test3);
	
	printf(YEL "DIV : \n" RESET);
	test = new_tuple(1, -2, 3, -4);
	test3 = div_tuple(test, 2);
	print_tuples(&test);
	print_tuples(&test3);


	printf(YEL "MAG : \n" RESET);
	test = new_tuple(1, 2, 3, VEC);
	printf("Magnitude of vector : ");
	print_tuples(&test);
	printf("=> %f\n", mag_tuple(test));

	printf(YEL "NORM : \n" RESET);
	test = new_tuple(1, 2, 3, VEC);
	t_tuple norm = normalize_tuple(test);
	print_tuples(&test);
	print_tuples(&norm);

	printf(YEL "DOT : \n" RESET);
	t_tuple testa = new_tuple(1, 2, 3, VEC);
	t_tuple testb = new_tuple(2, 3, 4, VEC);
	print_tuples(&testa);
	print_tuples(&testb);
	printf("dot product : %f\n", dot_tuple(testa, testb));

	printf(YEL "CROSS : \n" RESET);
	testa = new_tuple(1, 2, 3, VEC);
	testb = new_tuple(2, 3, 4, VEC);
	print_tuples(&testa);
	print_tuples(&testb);
	printf("cross product (a, b) : ");
	t_tuple testc = cross_tuple(testa, testb);
	print_tuples(&testc);
	printf("cross product (b, a) : ");
	testc = cross_tuple(testb, testa);
	print_tuples(&testc);
}

void	tuples_proj_test(void)
{
	t_tuple position = new_tuple(0, 1, 0, POINT);
	t_tuple vel = normalize_tuple(new_tuple(1, 1, 0, VEC));
	t_tuple gravity = new_tuple(0, -0.5, 0, VEC);
	t_tuple vent = new_tuple(-0.01, 0, 0, VEC);

	int total_tick = 0;

	while (position.y >= 0) {
		print_tuples(&position);
		total_tick++;
		usleep(100000);
		position = add_tuples(position, vel);
		vel = add_tuples(vel, add_tuples(gravity, vent));
	}
	printf("totaltick : %d\n", total_tick);
}
