

NAME =	alum1
CC = 	cc
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	#-Wall -Werror -Wextra
CFLAGS +=	-g3
# CFLAGS +=	-fsanitize=address

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

SRCSPATH =	./src/
OBJSPATH =	./obj/
INC =		./inc/

SRCS =		$(filter %.c,$(shell find $(SRCSPATH) -type f))
SRCSNAME =	$(notdir $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

define	progress_bar
	@i=0
	@while [[ $$i -le $(words $(SRCS)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	@printf "$(B)]\r[$(D)"
endef

all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"

test:		all
	@./$(NAME)

launch:
	$(call progress_bar)

$(NAME):	$(OBJS) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBNAME) -o $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "$(B)$(GRE)█$(D)"

$(LIBNAME):
	@printf "$(D)$(B)$(BLU)\n$(NAME) objects compiled\n\n$(D)"
	@$(MAKE) -C $(LIBPATH)
	
clean:
	@$(RM) $(OBJSPATH)
	@$(MAKE) clean -C $(LIBPATH)

fclean:		clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(LIBPATH)

re:			fclean all

.PHONY: all clean fclean re launch test
