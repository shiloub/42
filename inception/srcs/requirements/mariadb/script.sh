#!/bin/bash

#mysql_install_db --user=root --basedir=/usr --datadir=/var/lib/mysql


/etc/init.d/mysql start -u root -p${ADMIN_PASS}
mysql -u root -p${ADMIN_PASS} << EOF

CREATE DATABASE IF NOT EXISTS db_db ;
SHOW DATABASES ;
CREATE USER "shiloub"@"wordpress.srcs_my_network" IDENTIFIED BY "$MYSQL_DB_PASS";
GRANT ALL PRIVILEGES ON db_db.* TO "shiloub"@"wordpress.srcs_my_network" IDENTIFIED BY "$MYSQL_DB_PASS";
FLUSH PRIVILEGES;
EOF
sleep 3
service mysql stop
exec mysqld
