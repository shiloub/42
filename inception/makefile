start :
	cd srcs && sudo docker-compose up --build -d

stop :
	cd srcs && sudo docker-compose stop

fclean : stop
	sudo docker system prune -af

