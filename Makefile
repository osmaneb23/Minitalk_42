# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obouayed <obouayed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 19:59:53 by obouayed          #+#    #+#              #
#    Updated: 2024/06/27 20:51:05 by obouayed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executables
SERVER = server
CLIENT = client

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source directories
SRC_DIR = src

# Source files
SERVER_SRC = server.c
CLIENT_SRC = client.c

# Object files
SERVER_OBJ = $(addprefix $(SRC_DIR)/, $(SERVER_SRC:.c=.o))
CLIENT_OBJ = $(addprefix $(SRC_DIR)/, $(CLIENT_SRC:.c=.o))

# Printf library
PRINTF_DIR = ./printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a

# Rules
# Main rule to build everything
all: $(PRINTF_LIB) $(SERVER) $(CLIENT)

# Rule to build printf library
$(PRINTF_LIB):
		$(MAKE) -C $(PRINTF_DIR)

# Rule to build server executable
$(SERVER): $(SERVER_OBJ) $(PRINTF_LIB)
		$(CC) $(CFLAGS) -o $@ $^ -L$(PRINTF_DIR) -lftprintf
	
# -lftprintf links against libftprintf.a
# The 'lib' prefix and '.a' suffix are automatically added by the linker

# Rule to build client executable
$(CLIENT): $(CLIENT_OBJ) $(PRINTF_LIB)
		$(CC) $(CFLAGS) -o $@ $^ -L$(PRINTF_DIR) -lftprintf

# Generic rule to compile .c files to .o files
%.o: %.c
		$(CC) $(CFLAGS) -I$(PRINTF_DIR) -c $< -o $@

# Clean rule: removes object files and cleans printf directory
clean:
		$(MAKE) -C $(PRINTF_DIR) clean
		rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

# Full clean: removes executables and performs clean
fclean: clean
		$(MAKE) -C $(PRINTF_DIR) fclean
		rm -f $(SERVER) $(CLIENT)

# To recompile everything
re: fclean all

# To ensure that rules are not mistaken for files
.PHONY: all clean fclean re

