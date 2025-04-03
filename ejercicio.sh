#! /bin/bash

if [ "$UID" = 1000 ]; then
	echo "Este usuario es root"
else
	echo "Este usuario no es root"
	
fi

Usuario="$1"
Grupo="$2"
archivo="$3"


if [ ! -f "$archivo" ]; then
    echo "Este archivo no existe"
    
fi


if ! getent group "$Grupo"; then
    echo "El grupo no existe, procederemos a crearlo"
    sudo addgroup "$Grupo"
else
    echo "Este grupo ya existe"
fi


if ! id "$Usuario"; then
    echo "Tu usuario no existe, vamos a crearlo e ingresarlo al grupo"
    sudo useradd -m -g "$Grupo" "$Usuario"
else
    echo "Tu usuario ya existe, vamos ingresarlo al grupo"
    sudo usermod -aG "$Grupo" "$Usuario"
fi


echo "Vamos a cambiar la propiedad del archivo al usuario y grupo indicado"
sudo chown "$Usuario:$Grupo" "$archivo"

chmod 750 "$archivo"

echo "Se modificaron los permisos del archivo"


