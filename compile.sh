gcc -Wall -Wextra -Werror split_command.c test_functions/test_main.c test_functions/test_compare_answers.c test_functions/test_create_array.c test_functions/test_display_delete_functions.c -I parsing.h libft/libft.a
./a.out
rm a.out
