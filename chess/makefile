INCDIR=inc
SRCDIR=src
OBJDIR=obj
BINDIR=bin

BIN=$(BINDIR)/chess

$(BIN):$(OBJDIR)/chess.o  $(OBJDIR)/find.o  $(OBJDIR)/think.o $(OBJDIR)/main.o    
	gcc -Wall  -o $@ $^  

$(OBJDIR)/main.o:$(SRCDIR)/main.c inc/chess.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

$(OBJDIR)/chess.o:$(SRCDIR)/chess.c inc/chess.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

$(OBJDIR)/find.o:$(SRCDIR)/find.c inc/chess.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@

$(OBJDIR)/think.o:$(SRCDIR)/think.c inc/chess.h
	gcc -Wall  -I$(INCDIR)  -c $< -o $@
clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*

