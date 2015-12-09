cat tests_input.txt | ./02a > tests_output_a.txt
diff tests_output_a_expected.txt tests_output_a.txt
