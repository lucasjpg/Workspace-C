#!/bin/bash

for nome in ./*/src/*.c
do
  destino=$(echo $nome | sed -e "s|/src||g")
  mv $nome $destino
done