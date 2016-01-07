#!/bin/sh
ldapsearch -LLLQ "sn=*bon*" cn | grep cn: | wc -l | tr -d " "
