#!/bin/bash
for fn in $(find .|grep -e ".cpp$" -e ".c$"|grep -e "^./$1"|sort)
do
iconv -f GBK -t UTF-8 <$fn >${fn:0:-3}r.cpp

done
