main: client server clean

client: client.c
		gcc ./client.c -o ./bin/client
server: server.c
		gcc ./server.c -o ./bin/server

.PHONY: clean

clean:
		rm -rf *.o