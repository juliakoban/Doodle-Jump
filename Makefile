build:
	g++ -c ./main.cpp
	g++ -c Entity.cpp -o Entity.o
	g++ -c Camera.cpp -o Camera.o
	g++ -c CollisionHandler.cpp -o CollisionHandler.o
	g++ -c Player.cpp -o Player.o
	g++ -c Collider.cpp -o Collider.o
	g++ -c EntityState.cpp -o EntityState.o
	g++ main.o Entity.o EntityState.o Player.o Collider.o CollisionHandler.o Camera.o -o app -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o
	rm app
run:
	./app