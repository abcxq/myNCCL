INCDIR=inc
OBJDIR=obj

BIN=./mybash

$(BIN):$(OBJDIR)/mycp.o  $(OBJDIR)/shell.o $(OBJDIR)/main.o 
	gcc -Wall  -o $@ $^  

$(OBJDIR)/mycp.o:mycp/mycp.c inc/shell.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

$(OBJDIR)/shell.o:./shell.c inc/shell.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

$(OBJDIR)/main.o:./main.c inc/shell.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
