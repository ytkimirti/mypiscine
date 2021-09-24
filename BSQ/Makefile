
SRCS = main.c utility.c map_reader1.c map_reader2.c find_qr.c
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: bsq

run: bsq
	@./bsq map.txt

genrun: mapgen bsq
	@./bsq a.map

%.o: %.c
	gcc ${FLAGS} -c $^ -o $@

bsq: ${OBJS}
	gcc ${FLAGS} -o $@ $^

norm:
	norminette

map_print:
	@cat map.txt
	@echo ''
	@echo ' ----- '
	@echo ''

# column row amount-of-obstacles
%.map:
	@perl mapgen.pl 10 10 4 > $@

mapgen: mapclear a.map 

mapclear:
	@rm -f *.map

clean: mapclear
	rm -f ${OBJS}
	rm -f .buff map.txt

fclean: clean
	rm -f bsq


