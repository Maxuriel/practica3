-Tener Google RPC instalado para Python.
-Primero ejecuta los protos para crear los archivos necesarios.
Ejemplo (proto de Fecha):
En la carpeta protos ejecuta el comando:
python -m grpc_tools.protoc -I=proto --python_out=proto --grpc_python_out=proto proto/fecha.proto

-Teniendo el proto, ya puedes ejecutar el cliente y servidor.

Ejemplo (ej_fecha):
-Ejecutar Servidor: python3 server.py
-Ejecutar Cliente: python3 client.py

