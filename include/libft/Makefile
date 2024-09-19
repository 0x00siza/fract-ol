NAME = libft.a

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCF = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c  ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strcmp.c\
	ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c get_next_line_bonus.c\
	
	
RM = rm -f

OBJF = $(SRCF:.c=.o)


OBJBF = $(BONUSF:.c=.o) 

%.o: %.c libft.h
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):$(OBJF)
	ar -rc $(NAME) $(OBJF)

all: $(NAME)

clean:
	@$(RM) $(OBJF) $(OBJBF)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
