FROM nginx
USER root
LABEL version="1.0"
ENV NGINX_VERSION 1.15.6-1~stretch
WORKDIR /home/
COPY ./run.sh .
COPY /server-part3/nginx.conf /etc/nginx/nginx.conf
RUN apt-get update && apt-get install -y spawn-fcgi gcc libfcgi-dev && \
    rm -rf /var/lib/apt/lists/*; \
    chmod u-s /bin/su; \
    chmod u-s /usr/bin/newgrp; \
    chmod u-s /usr/bin/passwd; \
    chmod u-s /usr/bin/gpasswd; \
    chmod u-s /bin/umount; \
    chmod u-s /usr/bin/chfn; \
    chmod u-s /usr/bin/chsh; \
    chmod u-s /bin/mount; \
    chmod g-s /usr/bin/expiry; \
    chmod g-s /usr/bin/chage; \
    chmod g-s /usr/bin/wall; \
    chmod g-s /sbin/unix_chkpwd; \
    chown -R nginx:nginx /etc/nginx/nginx.conf; \
    chown -R nginx:nginx /home/; \
    chown -R nginx:nginx /var/cache/nginx; \
    touch /var/run/nginx.pid; \
    chown nginx:nginx /var/run/nginx.pid; \
    chmod +x run.sh
USER nginx
ENTRYPOINT [ "sh", "./run.sh" ]
HEALTHCHECK NONE
