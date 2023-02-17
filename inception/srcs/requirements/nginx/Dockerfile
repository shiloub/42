FROM debian:buster
RUN apt-get update
RUN apt-get install -y nginx
RUN mkdir -p /etc/nginx/ssl
RUN apt-get install openssl -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=amontant.42.fr/UID=amontant"
RUN apt-get update
RUN mkdir -p /var/run/nginx
COPY ./conf/nginx.conf /etc/nginx/site-enabled/default
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html
CMD [ "nginx", "-g", "daemon off;" ]