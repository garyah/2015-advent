cat tests_input_a.txt | ./05a > tests_output_a.txt
diff tests_output_a_expected.txt tests_output_a.txt
