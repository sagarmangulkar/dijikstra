all: clean Q1-1_brute_force_knapsack.out Q1-2_greedy_algorithm.out Q1-3_dynamic_programming_knapsack.out Q2_dijikstra.out

Q1-1_brute_force_knapsack.out:
		gcc -std=c11 Q1-1_brute_force_knapsack.c -o Q1-1_brute_force_knapsack.out

Q1-2_greedy_algorithm.out:
		gcc -std=c11 Q1-2_greedy_algorithm.c -o Q1-2_greedy_algorithm.out

Q1-3_dynamic_programming_knapsack.out:
		gcc -std=c11 Q1-3_dynamic_programming_knapsack.c -o Q1-3_dynamic_programming_knapsack.out

Q2_dijikstra.out:
		gcc -std=c11 Q2_dijikstra.c -o Q2_dijikstra.out

clean:
	rm -f Q1-1_brute_force_knapsack.out Q1-2_greedy_algorithm.out Q1-3_dynamic_programming_knapsack.out Q2_dijikstra.out
