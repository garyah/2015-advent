cat tests_input_a.txt | ./03a > tests_output_a.txt
diff tests_output_a_expected.txt tests_output_a.txt
cat tests_input_b.txt | ./03b > tests_output_b.txt
diff tests_output_b_expected.txt tests_output_b.txt

