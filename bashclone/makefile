INCDIR=inc
OBJDIR=obj

BIN=./mybash

$(BIN):$(OBJDIR)/mycp.o  $(OBJDIR)/shell.o $(OBJDIR)/main.o  $(OBJDIR)/myfile.o $(OBJDIR)/math.o -lm
	gcc -Wall  -o $@ $^  


$(OBJDIR)/shell.o:./shell.c inc/shell.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

$(OBJDIR)/main.o:./main.c inc/shell.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*

