FROM mysql:5.7

COPY ./db/ /docker-entrypoint-initdb.d/

RUN chown -R mysql:mysql /docker-entrypoint-initdb.d/

ENV MYSQL_ROOT_PASSWORD=123456

EXPOSE 3306

CMD ["mysqld"]