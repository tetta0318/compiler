CC      = gcc
CFLAGS  = -g -Wall -DDEBUG
YACC    = bison --yacc -dv
GPERF   = gperf -tT -L ANSI-C

MEMORY  = memory.o storage.o
OBJS    = y.tab.o yylex.o id1.o create.o visitor.o traversor.o util.o interface.o

TARGETS = prst astt treet memtest

all: $(TARGETS)

prst: parsetest.o $(OBJS) $(MEMORY)
	$(CC) -o $@ $^

astt: asttest.o $(OBJS) $(MEMORY)
	$(CC) -o $@ $^

treet: treetest.o $(OBJS) $(MEMORY)
	$(CC) -o $@ $^

memtest: memtest.o $(MEMORY)
	$(CC) -o $@ $^

y.tab.c y.tab.h: grammer.y
	$(YACC) grammer.y

id1.c: id1.key
	$(GPERF) $< > $@

%.o: %.c
	$(CC) -c $(CFLAGS) $<

# ヘッダ依存
y.tab.o:     y.tab.c csua.h MEM.h
yylex.o:     yylex.c yylex.h id1.h y.tab.h
id1.o:       id1.c id1.h
create.o:    create.c csua.h MEM.h
interface.o: interface.c csua.h MEM.h
util.o:      util.c csua.h
visitor.o:   visitor.c visitor.h csua.h MEM.h
traversor.o: traversor.c visitor.h csua.h
asttest.o:   asttest.c csua.h MEM.h
treetest.o:  treetest.c visitor.h MEM.h
memtest.o memory.o storage.o: MEM.h

clean:
	rm -f $(TARGETS) *.o y.tab.c y.tab.h y.output

.PHONY: all clean
