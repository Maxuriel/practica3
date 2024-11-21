const grpc = require('@grpc/grpc-js');
const protoLoader = require('@grpc/proto-loader');
const readline = require('readline');
const path = require('path');

// Ruta al archivo tiro.proto en la carpeta `protos`
const tiroProtoPath = path.resolve(__dirname, '../protos/tiro.proto');

// Cargar el archivo .proto desde la carpeta `protos`
const packageDefinition = protoLoader.loadSync(tiroProtoPath, {
  keepCase: true,
  longs: String,
  enums: String,
  defaults: true,
  oneofs: true,
});
const tiroProto = grpc.loadPackageDefinition(packageDefinition).tiro;

// Crear el cliente gRPC
const client = new tiroProto.TiroAlBlanco('localhost:50051', grpc.credentials.createInsecure());

// Configurar la interfaz para leer entradas del usuario
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// Obtener la distancia al centro de la diana
function getCentroDiana() {
  client.DimeCentroDiana({}, (err, response) => {
    if (err) {
      console.error('Error al obtener el centro:', err.message);
      return;
    }
    console.log('Distancia al centro de la diana:', response.distancia);
    solicitarDisparo();
  });
}

// Pedir ángulo y velocidad al usuario y realizar el disparo
function solicitarDisparo() {
  rl.question('Ingresa el ángulo de disparo en grados: ', (angulo) => {
    rl.question('Ingresa la velocidad de disparo en m/s: ', (velocidad) => {
      dispararCannon('jugador1', parseFloat(angulo), parseFloat(velocidad));
    });
  });
}

// Realizar el disparo
function dispararCannon(usuario, angulo, velocidad) {
  const request = {
    usuario: usuario,
    angulo: (angulo * Math.PI) / 180, // Convertir a radianes
    velocidad: velocidad,
  };

  client.DisparaCannon(request, (err, response) => {
    if (err) {
      console.error('Error al disparar:', err.message);
      return;
    }

    console.log('Distancia al centro después del disparo:', response.distancia_al_centro);

    if (Math.abs(response.distancia_al_centro) <= 1.0) {
      console.log('¡Acertaste al centro de la diana!');
      obtenerMejorDisparo();
    } else {
      console.log('Inténtalo de nuevo para acercarte al centro de la diana.');
      solicitarDisparo();
    }
  });
}

// Obtener el mejor disparo
function obtenerMejorDisparo() {
  client.MejorDisparo({}, (err, response) => {
    if (err) {
      console.error('Error al obtener el mejor disparo:', err.message);
      rl.close(); // Cerrar la interfaz
      return;
    }
    console.log(
      `Mejor disparo realizado por ${response.usuario} a ${response.distancia} metros del centro.`
    );
    rl.close(); // Cerrar la interfaz
  });
}

// Iniciar el programa
getCentroDiana();
