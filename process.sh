#!/bin/bash
echo "#Algorithm AvgTime(sec) AvgMemory(KB)" > data.txt
for file in results/*.txt; do
    algo=$(basename $file .txt)
    awk '{t+=$2; m+=$3; n++} END {print algo, t/n, m/n}' algo="$algo" "$file" >> data.txt
done
