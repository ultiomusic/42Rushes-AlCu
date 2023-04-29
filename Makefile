# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra -g3

# Name of the executable
NAME = alum1

# Directories
SRCDIR = src
INCDIR = inc
OBJDIR = obj
LIBDIR = libft

# Source files
SRC = $(shell find $(SRCDIR) -type f -name "*.c")

# Object files
OBJ = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Includes
INC = -I$(INCDIR) -I$(LIBDIR)/$(INCDIR)

# Libraries
LIB = -L$(LIBDIR) -lft

# Rule to build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) $^ -o $@ $(LIB)

# Rule to build object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Clean rule
clean:
	$(RM) $(OBJDIR)

# Full clean rule
fclean: clean
	$(RM) $(NAME)

# Rebuild rule
re: fclean all

# Default rule
all: $(NAME)
