objects=obj/functions/loss_functions/classification.o \
				obj/functions/loss_functions/hinge.o \
				obj/functions/loss_functions/other_functions.o \
				obj/functions/loss_functions/regressive.o \
				obj/functions/optimisers/adam.o \
				obj/functions/optimisers/SGD.o \
				obj/functions/activation_functions.o \
				obj/networks/node.o \
				obj/networks/feed_forward.o \

obj/%.o: src/%.cpp
	mkdir -p $(@D)
	g++ -Iinclude -o $@ -c $<

the_network: $(objects)
	g++ $(objects) -o the_network

clear:
	make clean
	clear

do:
	make clear
	make the_network


.PHONY: clean
clean:
	rm-rf obj the_network
