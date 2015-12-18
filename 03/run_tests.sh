cat tests_input.txt | ./03a > tests_output.txt
diff tests_output_expected.txt tests_output.txt
