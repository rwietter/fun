docker stop $(docker ps -q)
docker volume rm 6-banco_devbook
docker-compose up -d