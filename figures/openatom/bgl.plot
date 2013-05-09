set terminal pdfcairo enhanced font "Gill Sans,18" linewidth 3 rounded dashed size 6in, 3in

set style line 100 lt 1 lc rgb "#606060"
set style line 101 lt 0 lc rgb "#606060"

set border 3 back ls 100
set grid noxtics ytics back ls 101
set ytics nomirror
set key outside

set style line 1 lt rgb "#000000" lw 2 pt 2
set style line 2 lt rgb "#CF0000" lw 2 pt 8
set style line 3 lt rgb "#0BC681" lw 2 pt 6
set style line 4 lt rgb "#0E1589" lw 2 pt 4
set style line 5 lt rgb "#E69F00" lw 2 pt 3
set style line 6 lt rgb "#8B008B" lw 2 pt 7

set title "Performance of OpenAtom on Blue Gene/L"
set xlabel "Number of cores"
set ylabel "Time per iteration (s)"
set logscale x 2
set logscale y 10
set xrange [32:32768]
# set yrange [0.01:1000]

set xtics ("32" 32, "128" 128, "512" 512, "2K" 2048, "8K" 8192, "32K" 32768, "128K" 131072) nomirror

set output "bgl.pdf"

plot 'bgl.dat' u 1:7 t "WATER 256" with linespoints ls 1, \
'bgl.dat' u 1:6 t "WATER 128" with linespoints ls 2, \
'bgl.dat' u 1:5 t "WATER 64" with linespoints ls 3, \
'bgl.dat' u 1:4 t "WATER 32" with linespoints ls 4, \
'bgl.dat' u 1:3 t "WATER 16" with linespoints ls 5, \
'bgl.dat' u 1:2 t "WATER 8" with linespoints ls 6
