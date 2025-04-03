#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Uso: $0 <comando>"
    exit 1
fi

LOG_FILE="monitoreo.log"
PLOT_FILE="grafica.png"
echo "# Timestamp CPU(%) Mem(KB)" > $LOG_FILE  # Agregar encabezado con #

$@ &  
PID=$!

echo "Monitoreando proceso con PID: $PID"

while kill -0 $PID 2> /dev/null; do
    TIMESTAMP=$(date +"%Y-%m-%d %H:%M:%S")
    CPU=$(ps -p $PID -o %cpu --no-headers | awk '{print $1+0}')
    MEM=$(ps -p $PID -o rss --no-headers | awk '{print $1+0}')
    
    if [[ -n "$CPU" && -n "$MEM" ]]; then
        echo "$TIMESTAMP $CPU $MEM" >> $LOG_FILE
    fi
    
    sleep 1
done

echo "Proceso finalizado. Generando grafica..."

echo "set terminal png
set output '$PLOT_FILE'
set title 'Consumo de CPU y Memoria'
set xlabel 'Tiempo'
set ylabel 'Uso'
set xdata time
set timefmt '%Y-%m-%d %H:%M:%S'
set format x '%H:%M:%S'
set key outside
plot '$LOG_FILE' using 1:2 with lines title 'CPU (%)', \
     '$LOG_FILE' using 1:3 with lines title 'Memoria (KB)'
" | gnuplot

echo "Grafica guardada en $PLOT_FILE"