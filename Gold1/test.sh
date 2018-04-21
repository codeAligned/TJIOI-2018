#!/bin/bash
TIMEFORMAT=%R
for i in `seq 0 9`;
do
	printf "Test $i: "
	time OUT=$(cat input/input$i.txt | ./s)
	OUT=$(echo $OUT | awk '{$1=$1};1')
	ANS=$(cat output/output$i.txt)
	ANS=$(echo $ANS | awk '{$1=$1};1')
	if ! test "$ANS" = "$OUT"; then
		echo "----------- WRONG ANSWER ON TEST $i ----------"
	fi
done
