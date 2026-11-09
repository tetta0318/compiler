CC = gcc

CFLAGS = 

TARGET = parser
SRCS = parser.c lex.c
OBJS = parser.o lex.o

RM = rm -f

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o:
	$(CC) $(CFLAGS) -c $<

parser.o: parser.h

lex.o: lex.h

clean:
	$(RM) $(OBJS)

clean_target:
	$(RM) $(TARGET)

clean_all:
	$(RM) $(TARGET) $(OBJS)