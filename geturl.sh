#!/bin/bash

[ "$@" == 0 ] && exit

url=$(urlencode $1)
wget -O /tmp/url$$ "www.flvcd.com/parse.php?format=&kw=$url" && iconv -f gbk -t utf-8 /tmp/url$$ -o /tmp/rurl$$ && grep "下载地址" /tmp/rurl$$ && exit  
