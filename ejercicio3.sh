#!/bin/bash

Directorio="$HOME/monitoreo"
Log_File="$HOME/monitoreo/cambios.log"

touch"$Log_File"

inotifiywait -m -e ceate, delete, modify "$Directorio" --format '%T %w%f %e' --timefmt '%Y-%m-%d %H:%M:%' >> "$Log_File" &
