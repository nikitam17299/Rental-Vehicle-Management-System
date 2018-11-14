#MAKEFILE

CXXFLAGS += --std=c++17

main: main.o Renter.o Vehicle.o main_window.o Rental_Site.o View.o Controller.o Dialogs.o
	${CXX} ${CXXFLAGS} -o main main.o Renter.o Vehicle.o main_window.o Rental_Site.o View.o Controller.o Dialogs.o `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main.o: main.cpp *.h
	${CXX} ${CXXFLAGS} -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main_window.o: main_window.cpp *.h
	${CXX} ${CXXFLAGS} -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
Renter.o: Renter.cpp *.h
	${CXX} ${CXXFLAGS} -c Renter.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags--libs`

Vehicle.o: Vehicle.cpp *.h
	${CXX} ${CXXFLAGS} -c Vehicle.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`


Rental_Site.o: Rental_Site.cpp *.h
	$(CXX) $(CXXFLAGS) -c Rental_Site.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

View.o: View.cpp *.h
	${CXX} ${CXXFLAGS} -c View.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

Controller.o: Controller.cpp *.h
	${CXX} ${CXXFLAGS} -c Controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
 
Dialogs.o: Dialogs.cpp *.h
	${CXX} ${CXXFLAGS} -c Dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

clean: 
	rm -f *.o *.gch main
