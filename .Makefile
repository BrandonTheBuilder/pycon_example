zipcode_data.o: zipcode_data.c
	clang -O3 -o zipcode_data.o -c zipcode_data.c -Izipcode_data.h

count_orders.o: count_orders.c
	clang -O3 -o count_orders.o -c count_orders.c -Izipcode_data.h

count_orders: count_orders.o zipcode_data.o
	clang -o count_orders count_orders.o zipcode_data.o
	chmod u+x count_orders


pyincludes = $$(python3-config --includes)
pysharedflags = $$(python3-config --ldflags) -lpython3.12

zipcodes.o: zipcodes.c
	clang -O3 -o zipcodes.o -c zipcodes.c -Izipcode_data.h $(pyincludes)

zipcodes.so: zipcodes.o zipcode_data.o
	clang -o zipcodes.so -shared zipcodes.o zipcode_data.o $(pysharedflags)


pymain.o: pymain.c
	clang -O3 -o pymain.o -c pymain.c $(pyincludes)

pymain: pymain.o zipcodes.o zipcode_data.o
	clang -o pymain pymain.o zipcodes.o zipcode_data.o $$(python3-config --ldflags --embed)
	chmod u+x pymain


clean:
	rm -f ./*.o
	rm -f ./*.so
	rm -f count_orders
	rm -f pymain
