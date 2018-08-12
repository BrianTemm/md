cc=g++
flags=-Wall  -std=c++11 
#a comment line
md: Table.o Cmdline.o Utility.o Markdown.o main.o
	@echo "======= Compile all ============"
	$(cc) $(flags) main.o Utility.o Cmdline.o Table.o Markdown.o  -o md

main.o: main.cpp 
	$(cc) $(flags) -c main.cpp 
	
Cmdline.o: Cmdline.cpp Cmdline.h
	$(cc) $(flags) -c Cmdline.cpp 

Table.o: Table.cpp Table.h
	$(cc) $(flags) -c Table.cpp

Utility.o: Utility.cpp Utility.h
	$(cc) $(flags) -c Utility.cpp 

Markdown.o: Markdown.cpp Markdown.h
	$(cc) $(flags) -c Markdown.cpp

clean: remove_dir
	@echo ""
	@echo "======================== Clean ===================="
	rm -f *.o
	rm -f *~
	rm -f *orig
	rm -f *.gch
	rm -f at
	rm -f a.out
	rm -f md
	rm -f .*.swp
	@astyle --style=kr  *.cpp
	@echo ""
	@ls  -l --color
	@echo ""
remove_dir:
	@echo "================== Remove Dirs ==================="
	rm -fr html
	rm -fr def
	rm -fr docbook
	rm -fr latex
	rm -fr man
	rm -fr perlmod
	rm -fr rtf
	rm -fr xml
doc: remove_dir
	@echo "================= Doxygen ========================"
	doxygen Doxyfile
	show
# debug
debug:  flags+=-d
debug:  all
