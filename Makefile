CG = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR := src
INCLUDE_DIR := include
EXECUTABLE = abstractvm

SRC := 	$(SRC_DIR)/main.c      \
		$(SRC_DIR)/tools.c     \
		$(SRC_DIR)/core.c      \
		$(SRC_DIR)/linked.c    \
		$(SRC_DIR)/lines.c

OBJ := 	$(SRC_DIR)/main.o      \
		$(SRC_DIR)/tools.o     \
		$(SRC_DIR)/core.o      \
		$(SRC_DIR)/linked.o    \
		$(SRC_DIR)/lines.o

HEADER := 	$(INCLUDE_DIR)/main.h      \
			$(INCLUDE_DIR)/tools.h     \
			$(INCLUDE_DIR)/core.h      \
			$(INCLUDE_DIR)/linked.h    \
			$(INCLUDE_DIR)/lines.h

GREEN_COLOR = \033[0;92m
RED_COLOR = \033[0;91m
OFF_COLOR = \033[0m

all: abstractvm_bin

$(OBJ): $(SRC)
	@echo "${GREEN_COLOR}Compiling objects :${OFF_COLOR}"
	$(CG) -c $(SRC)
	mv *.o $(SRC_DIR)

abstractvm_bin: $(OBJ)
	@echo "${GREEN_COLOR}Compiling executable :${OFF_COLOR}"
	$(CG) $(CFLAGS) -o $(EXECUTABLE) $(OBJ) $(HEADER) -lm

clean:
	@echo "${RED_COLOR}Remove objects files :${OFF_COLOR}"
	rm -f $(SRC_DIR)/*.o

fclean: clean
	@echo "${RED_COLOR}Remove outputs files :${OFF_COLOR}"
	rm -f $(EXECUTABLE)

.PHONY : clean

re: fclean all
