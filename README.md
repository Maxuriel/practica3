
# Tiro al Blanco - Proyecto con gRPC y Protobuf

## Descripción

Este proyecto implementa un sistema cliente-servidor para un juego de "Tiro al Blanco" utilizando **gRPC** y **Protobuf**. Proporcionamos implementaciones de cliente en **C++**, **Python** y **Node.js**, y el servidor en **Python**. Los jugadores pueden realizar disparos simulados, calcular su distancia al centro de la diana y competir por el mejor puntaje.

---

## Tecnologías utilizadas

- **gRPC**: Para la comunicación cliente-servidor.
- **Protobuf**: Para la definición y serialización de mensajes.
- **C++**, **Python**, **Node.js**: Lenguajes utilizados en los clientes y servidor.
- **CMake**: Para la gestión de la construcción en el cliente C++.
- **npm**: Para la gestión de dependencias en Node.js.

---

## Requisitos

### Herramientas necesarias

1. **gRPC y Protobuf**:
   - Cliente `protoc`: versión 27.2 o superior.
   - Complemento `grpc_cpp_plugin` para código C++.
   - Complemento gRPC para Python y Node.js.
2. **Python**: versión 3.7 o superior.
3. **Node.js**: versión 14.x o superior.
4. **CMake**: versión 3.10 o superior.
5. Librerías adicionales:
   - gRPC C++ y Python.
   - Protobuf C++ y Python.
   - gRPC para Node.js.
6. **Git** para clonar el repositorio.

---

## Instalación de dependencias

### Instalar gRPC y Protobuf

#### Protobuf
```bash
git clone https://github.com/protocolbuffers/protobuf.git
cd protobuf
git checkout v27.2
cmake -Bbuild -H.
cmake --build build --target install
```

#### gRPC
```bash
git clone https://github.com/grpc/grpc.git
cd grpc
git submodule update --init
cmake -Bbuild -H.
cmake --build build --target install
```

### Instalar dependencias para Python
```bash
pip install grpcio grpcio-tools
```

### Instalar dependencias para Node.js
```bash
npm install @grpc/grpc-js @grpc/proto-loader
```

---

## Estructura del proyecto

```plaintext
.
├── client.cpp          # Código del cliente en C++
├── client.py           # Código del cliente en Python
├── client.js           # Código del cliente en Node.js
├── server.py           # Código del servidor en Python
├── tiro.proto          # Definiciones de Protobuf
├── CMakeLists.txt      # Configuración para construir el cliente C++
├── README.md           # Este archivo
```

---

## Configuración y ejecución

### Compilar el cliente en C++
1. **Configurar y construir**:
   ```bash
   mkdir build
   cd build
   cmake -DCMAKE_PREFIX_PATH="/usr/local/lib/cmake/grpc;/usr/lib/x86_64-linux-gnu/cmake/grpc" ..
   make
   ```

   Esto generará un ejecutable llamado `client` en la carpeta `build`.

2. **Ejecutar**:
   ```bash
   ./client
   ```

---

### Ejecutar el cliente en Python
1. **Ejecutar el cliente**:
   ```bash
   python3 client.py
   ```

---

### Ejecutar el cliente en Node.js
1. **Ejecutar el cliente**:
   ```bash
   node client.js
   ```

---

### Ejecutar el servidor en Python
1. **Ejecutar el servidor**:
   ```bash
   python3 server.py
   ```

---

## Detalles de implementación

### Cliente en C++
- Comunicación con el servidor usando gRPC.
- Simula disparos enviando ángulo y velocidad.
- Recibe la distancia al centro de la diana y resultados del mejor disparo.

### Cliente en Python
- Simula disparos interactivos en la terminal.
- Compatible con el servidor implementado en Python.

### Cliente en Node.js
- Utiliza las librerías `@grpc/grpc-js` y `@grpc/proto-loader`.
- Proporciona funcionalidades similares al cliente en Python.

### Servidor en Python
- Simula disparos a la diana.
- Calcula distancias y mantiene el registro del mejor disparo.
- Implementa los métodos definidos en el archivo `tiro.proto`.

---

## Cómo contribuir

1. Haz un fork del repositorio.
2. Crea una rama para tus cambios:
   ```bash
   git checkout -b feature-nueva-funcionalidad
   ```
3. Realiza tus cambios y haz commits:
   ```bash
   git commit -m "Descripción de los cambios"
   ```
4. Haz un push a tu rama:
   ```bash
   git push origin feature-nueva-funcionalidad
   ```
5. Crea un Pull Request en GitHub.

---

## Licencia

Este proyecto está bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles.
```

