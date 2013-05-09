set terminal pdfcairo enhanced font "Gill Sans,18" linewidth 3 rounded dashed

set style line 100 lt 1 lc rgb "#606060"
set style line 101 lt 0 lc rgb "#606060"

set border 3 back ls 100
set grid noxtics ytics back ls 101
set xtics nomirror
set ytics nomirror

set style line 1 lt rgb "#000000" lw 2 pt 2
set style line 2 lt rgb "#CF0000" lw 2 pt 8
set style line 3 lt rgb "#0BC681" lw 2 pt 6
set style line 4 lt rgb "#0E1589" lw 2 pt 4

set title "Performance of OpenAtom"
set xlabel "Number of cores"
set ylabel "Time per iteration (s)"
set logscale x 2
set yrange [0:12]

set output "map.pdf"

plot 'map.dat' u 1:2 t "Default Mapping" with linespoints ls 1, \
'map.dat' u 1:3 t "Topology Mapping" with linespoints ls 2
