objects=obj/main.o \

obj/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ -o $@ -c $<

the_network: $(objects)
	g++ $(objects) -o the_network

.PHONY: clean
clean:
	rm-rf obj the_network
do:
	make clean
	clear
	make the_network


commit:
	git add .
	git commit -m "$(m)"
	git push

sort_conflicts:
	git stash
	git pull

sort_commit:
	make sort_conflicts
	make commit m="$(m)"
