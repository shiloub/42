#!/bin/bash
#mysql_install_db --user=root --basedir=/usr --datadir=/var/lib/mysql

# sleep 20;
# exit;
service mysql start
mysql_secure_installation << EOF
${ADMIN_PASS}
n
y
n
y
y
EOF

mysql -u root -p${ADMIN_PASS} << EOF
CREATE DATABASE IF NOT EXISTS db_db ;
FLUSH PRIVILEGES;
CREATE USER IF NOT EXISTS "shiloub"@"wordpress.srcs_inception" IDENTIFIED BY "$MYSQL_DB_PASS";
GRANT ALL PRIVILEGES ON db_db.* TO "shiloub"@"wordpress.srcs_inception" IDENTIFIED BY "$MYSQL_DB_PASS";
ALTER USER 'root'@'localhost' IDENTIFIED BY "${ADMIN_PASS}";
SET PASSWORD FOR 'root'@'localhost' = PASSWORD('$ADMIN_PASS');
FLUSH PRIVILEGES;
EOF
sleep 3
service mysql stop
exec mysqld

# DROP USER shiloub@wordpress.srcs_inception;