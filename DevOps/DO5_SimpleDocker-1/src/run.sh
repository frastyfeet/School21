#!/bin/bash
set -e

echo "Compiling server..."
gcc server.c -lfcgi -o server

echo "Starting FastCGI server..."
spawn-fcgi -s /var/run/fcgi.sock ./server

echo "Starting nginx..."
nginx -g 'daemon off;'
