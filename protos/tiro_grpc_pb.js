// GENERATED CODE -- DO NOT EDIT!

'use strict';
var grpc = require('grpc');
var tiro_pb = require('./tiro_pb.js');

function serialize_tiro_CentroRequest(arg) {
  if (!(arg instanceof tiro_pb.CentroRequest)) {
    throw new Error('Expected argument of type tiro.CentroRequest');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_tiro_CentroRequest(buffer_arg) {
  return tiro_pb.CentroRequest.deserializeBinary(new Uint8Array(buffer_arg));
}

function serialize_tiro_CentroResponse(arg) {
  if (!(arg instanceof tiro_pb.CentroResponse)) {
    throw new Error('Expected argument of type tiro.CentroResponse');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_tiro_CentroResponse(buffer_arg) {
  return tiro_pb.CentroResponse.deserializeBinary(new Uint8Array(buffer_arg));
}

function serialize_tiro_DisparoRequest(arg) {
  if (!(arg instanceof tiro_pb.DisparoRequest)) {
    throw new Error('Expected argument of type tiro.DisparoRequest');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_tiro_DisparoRequest(buffer_arg) {
  return tiro_pb.DisparoRequest.deserializeBinary(new Uint8Array(buffer_arg));
}

function serialize_tiro_DisparoResponse(arg) {
  if (!(arg instanceof tiro_pb.DisparoResponse)) {
    throw new Error('Expected argument of type tiro.DisparoResponse');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_tiro_DisparoResponse(buffer_arg) {
  return tiro_pb.DisparoResponse.deserializeBinary(new Uint8Array(buffer_arg));
}

function serialize_tiro_MejorDisparoRequest(arg) {
  if (!(arg instanceof tiro_pb.MejorDisparoRequest)) {
    throw new Error('Expected argument of type tiro.MejorDisparoRequest');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_tiro_MejorDisparoRequest(buffer_arg) {
  return tiro_pb.MejorDisparoRequest.deserializeBinary(new Uint8Array(buffer_arg));
}

function serialize_tiro_MejorDisparoResponse(arg) {
  if (!(arg instanceof tiro_pb.MejorDisparoResponse)) {
    throw new Error('Expected argument of type tiro.MejorDisparoResponse');
  }
  return Buffer.from(arg.serializeBinary());
}

function deserialize_tiro_MejorDisparoResponse(buffer_arg) {
  return tiro_pb.MejorDisparoResponse.deserializeBinary(new Uint8Array(buffer_arg));
}


var TiroAlBlancoService = exports.TiroAlBlancoService = {
  // Método para obtener la distancia al centro de la diana
dimeCentroDiana: {
    path: '/tiro.TiroAlBlanco/DimeCentroDiana',
    requestStream: false,
    responseStream: false,
    requestType: tiro_pb.CentroRequest,
    responseType: tiro_pb.CentroResponse,
    requestSerialize: serialize_tiro_CentroRequest,
    requestDeserialize: deserialize_tiro_CentroRequest,
    responseSerialize: serialize_tiro_CentroResponse,
    responseDeserialize: deserialize_tiro_CentroResponse,
  },
  // Método para disparar el cañón
disparaCannon: {
    path: '/tiro.TiroAlBlanco/DisparaCannon',
    requestStream: false,
    responseStream: false,
    requestType: tiro_pb.DisparoRequest,
    responseType: tiro_pb.DisparoResponse,
    requestSerialize: serialize_tiro_DisparoRequest,
    requestDeserialize: deserialize_tiro_DisparoRequest,
    responseSerialize: serialize_tiro_DisparoResponse,
    responseDeserialize: deserialize_tiro_DisparoResponse,
  },
  // Método para obtener el mejor disparo
mejorDisparo: {
    path: '/tiro.TiroAlBlanco/MejorDisparo',
    requestStream: false,
    responseStream: false,
    requestType: tiro_pb.MejorDisparoRequest,
    responseType: tiro_pb.MejorDisparoResponse,
    requestSerialize: serialize_tiro_MejorDisparoRequest,
    requestDeserialize: deserialize_tiro_MejorDisparoRequest,
    responseSerialize: serialize_tiro_MejorDisparoResponse,
    responseDeserialize: deserialize_tiro_MejorDisparoResponse,
  },
};

exports.TiroAlBlancoClient = grpc.makeGenericClientConstructor(TiroAlBlancoService);
