CC = gcc

RM = rm -f

TARGET = main
SRCS = main.c yylex.c id1.c
OBJS = main.o yylex.o id1.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

.c.o:
	$(CC) -c $<

main.o: yylex.h

yylex.o: yylex.h

clean:
	$(RM)