#!/bin/bash

rm   -f ci.o reg_user_mailid.o server.o itoa.o backup_svcreg.o seek.o sseek.o server libuim.a
gcc -c server.c
gcc -c ci.c reg_user_mailid.c itoa.c backup_svcreg.c seek.c sseek.c
ar rs libuim.a ci.o reg_user_mailid.o itoa.o backup_svcreg.o seek.o sseek.o 
gcc -o server -L. server.o -luim -lpthread

