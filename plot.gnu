set terminal png size 800,600
set output 'time_plot.png'
set title "Avg Time for Sorting Algorithms"
set xlabel "Algorithm"
set ylabel "Time (seconds)"
set style data histograms
set style fill solid
set boxwidth 0.5
plot 'data.txt' using 2:xtic(1) title 'Time'

set output 'memory_plot.png'
set title "Avg Memory for Sorting Algorithms"
set ylabel "Memory (KB)"
plot 'data.txt' using 3:xtic(1) title 'Memory'
