rm -f *.o *.a
gcc -Wall -Wextra -Werror -c *.c
ar -rcs libft.a *.o
rm -f *.o
