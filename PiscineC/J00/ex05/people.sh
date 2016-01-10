#!/bin/sh
ldapsearch -LLLQ "uid=z*" cn | grep cn | cut -c 5- | sort -rf
