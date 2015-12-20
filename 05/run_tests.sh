cat tests_input_a.txt | ./05a > tests_output_a.txt
diff tests_output_a_expected.txt tests_output_a.txt
cat tests_input_b.txt | ./05b > tests_output_b.txt
diff tests_output_b_expected.txt tests_output_b.txt

