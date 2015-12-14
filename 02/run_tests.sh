cat tests_input.txt | ./02a > tests_output_a.txt
diff tests_output_a_expected.txt tests_output_a.txt
cat tests_input.txt | ./02b > tests_output_b.txt
diff tests_output_b_expected.txt tests_output_b.txt
