#!/bin/bash

SUCCESS=0
FAILS=0

if [ -z "$1" ]
then
printf "You must put asm exe in argument\n"
exit 84
fi

$(rm -rf ./*.cor)

for file in "./error"/*.s
do
    $(./$1 "$file")
    if [ $? -ne 84 ]
    then
        ((FAILS+=1))
    else
	((SUCCESS+=1))
    fi
done

$(rm -rf *.cor)

echo -e "SUCCESS: $SUCCESS"
echo -e "FAILS: $FAILS"
