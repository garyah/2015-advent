cat tests_input.txt | ./main > tests_output.txt
diff tests_output_expected.txt tests_output.txt
