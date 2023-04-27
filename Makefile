NAME		:=	push_swap
BONUS		:=	checker
MAIN_DIR	:=	main

CC			:=	gcc
CXXFLAGS	:=	-Wall -Werror -Wextra
# CXXFLAGS	+=	-g3 -fsanitize=address
# CXXFLAGS	+=	-Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

SRC_DIR		:=	srcs
SRCS		:=	$(shell find ${SRC_DIR} -name "*.c")

HEADER		:=	$(shell find ${SRC_DIR} -name "*.h") libft/include/libft.h
CFLAGS		:=	$(addprefix -I, $(dir ${HEADER}))

OBJ_DIR		:=	objs
OBJS 		:=	$(patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRCS})
RM			:=	rm -rf

LIBFT_DIR	:=	libft
LIBFT		:=	${LIBFT_DIR}/libft.a
LIBFT_MAKE	:=	make -C ${LIBFT_DIR}

GREY		:=	\033[30m
RED			:=	\033[31m
CYAN		:=	\033[36m
LIGHT_CYAN	:=	\033[1;36m
RESET		:=	\033[0m

all: ${NAME}

bonus: ${BONUS}

${OBJ_DIR}:
	@printf "${GREY}mkdir $@${RESET}\n"
	@mkdir $@

# Default Builder
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ${HEADER} | ${OBJ_DIR}
	@mkdir -p ${@D}
	@printf "${CYAN}${CC} ${CXXFLAGS} ${CFLAGS} -c $< -o $@${RESET}\n"
	@${CC} ${CXXFLAGS} ${CFLAGS} -c $< -o $@

# Main Builder
${OBJ_DIR}/${MAIN_DIR}/%.o: ${MAIN_DIR}/%.c ${HEADER} | ${OBJ_DIR}
	@mkdir -p ${@D}
	@printf "${CYAN}${CC} ${CXXFLAGS} ${CFLAGS} -c $< -o $@${RESET}\n"
	@${CC} ${CXXFLAGS} ${CFLAGS} -c $< -o $@

# Main
${NAME}: ${OBJS} ${OBJ_DIR}/${MAIN_DIR}/push_swap.o
	${LIBFT_MAKE}
	@printf "${LIGHT_CYAN}${CC} ${CXXFLAGS} $^ -o $@${RESET}\n"
	@${CC} ${CXXFLAGS} $^ ${LIBFT} -o $@

# Bonus
${BONUS}: ${OBJS} ${OBJ_DIR}/${MAIN_DIR}/checker.o
	${LIBFT_MAKE}
	@printf "${LIGHT_CYAN}${CC} ${CXXFLAGS} $^ -o $@${RESET}\n"
	@${CC} ${CXXFLAGS} $^ ${LIBFT} -o $@

clean:
	${LIBFT_MAKE} clean
	@printf "${RED}${RM} ${OBJ_DIR}${RESET}\n"
	@${RM} ${OBJ_DIR}

fclean: clean
	${LIBFT_MAKE} fclean
	@printf "${RED}${RM} ${NAME} ${BONUS}${RESET}\n"
	@${RM} ${NAME} ${BONUS}

re:	fclean all

run: ${NAME}
	./$<

thisre:
	${RM} ${NAME} ${OBJ_DIR}
	${MAKE} ${NAME}

log: ${NAME}
	./$< > log.log

logerr: ${NAME}
	./$< 2> errlog.log

.PHONY: all clean fclean re run log logerr bonus san

norm:
	norminette ${SRC_DIR} ${MAIN_DIR}
