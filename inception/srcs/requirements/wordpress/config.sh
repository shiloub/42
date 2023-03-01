#!/bin/bash

wppath="/var/www/html"

sleep 10
yes | wp core download --allow-root --path="$wppath" 

wp config create --dbpass=$MYSQL_DB_PASS --path="$wppath" --allow-root --dbname=db_db --dbuser=shiloub --dbhost=mariadb.srcs_inception --config-file="$wppath/wp-config.php"

chmod 777 $wppath/wp-config.php
ls -la "$wppath"

wp core install --allow-root --path="$wppath" --url=amontant.42.fr --title="amontant" --admin_name=super --admin_password=$ADMIN_PASS --admin_email=amontant@42.fr --skip-email

wp user create --allow-root --path="$wppath" user user@example.com --role=author --user_pass=$ADMIN_PASS
exec php-fpm7.3 -F