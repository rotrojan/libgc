NAME = libgc.a

SRCS = gc_exit.c gc_malloc.c gc_free.c gc_free_all.c gc_utils.c
OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)

SRCS_DIR = $(SRCS)
OBJS_DIR = .objs
DEPENDENCIES= $(OBJS:%.o=%.d)

CC= clang
MKDIR = mkdir -p
RM = rm -f
AR = ar

CFLAGS = -Wall -Wextra -Werror -MMD -I includes

vpath %.c srcs 

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)

-include $(DEPENDENCIES)
$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
