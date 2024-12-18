// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: tiro.proto

#include "tiro.pb.h"
#include "tiro.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace tiro {

static const char* TiroAlBlanco_method_names[] = {
  "/tiro.TiroAlBlanco/DimeCentroDiana",
  "/tiro.TiroAlBlanco/DisparaCannon",
  "/tiro.TiroAlBlanco/MejorDisparo",
};

std::unique_ptr< TiroAlBlanco::Stub> TiroAlBlanco::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< TiroAlBlanco::Stub> stub(new TiroAlBlanco::Stub(channel, options));
  return stub;
}

TiroAlBlanco::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_DimeCentroDiana_(TiroAlBlanco_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DisparaCannon_(TiroAlBlanco_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_MejorDisparo_(TiroAlBlanco_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status TiroAlBlanco::Stub::DimeCentroDiana(::grpc::ClientContext* context, const ::tiro::CentroRequest& request, ::tiro::CentroResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tiro::CentroRequest, ::tiro::CentroResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DimeCentroDiana_, context, request, response);
}

void TiroAlBlanco::Stub::async::DimeCentroDiana(::grpc::ClientContext* context, const ::tiro::CentroRequest* request, ::tiro::CentroResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tiro::CentroRequest, ::tiro::CentroResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DimeCentroDiana_, context, request, response, std::move(f));
}

void TiroAlBlanco::Stub::async::DimeCentroDiana(::grpc::ClientContext* context, const ::tiro::CentroRequest* request, ::tiro::CentroResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DimeCentroDiana_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tiro::CentroResponse>* TiroAlBlanco::Stub::PrepareAsyncDimeCentroDianaRaw(::grpc::ClientContext* context, const ::tiro::CentroRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tiro::CentroResponse, ::tiro::CentroRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DimeCentroDiana_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tiro::CentroResponse>* TiroAlBlanco::Stub::AsyncDimeCentroDianaRaw(::grpc::ClientContext* context, const ::tiro::CentroRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDimeCentroDianaRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status TiroAlBlanco::Stub::DisparaCannon(::grpc::ClientContext* context, const ::tiro::DisparoRequest& request, ::tiro::DisparoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tiro::DisparoRequest, ::tiro::DisparoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DisparaCannon_, context, request, response);
}

void TiroAlBlanco::Stub::async::DisparaCannon(::grpc::ClientContext* context, const ::tiro::DisparoRequest* request, ::tiro::DisparoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tiro::DisparoRequest, ::tiro::DisparoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DisparaCannon_, context, request, response, std::move(f));
}

void TiroAlBlanco::Stub::async::DisparaCannon(::grpc::ClientContext* context, const ::tiro::DisparoRequest* request, ::tiro::DisparoResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DisparaCannon_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tiro::DisparoResponse>* TiroAlBlanco::Stub::PrepareAsyncDisparaCannonRaw(::grpc::ClientContext* context, const ::tiro::DisparoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tiro::DisparoResponse, ::tiro::DisparoRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DisparaCannon_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tiro::DisparoResponse>* TiroAlBlanco::Stub::AsyncDisparaCannonRaw(::grpc::ClientContext* context, const ::tiro::DisparoRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDisparaCannonRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status TiroAlBlanco::Stub::MejorDisparo(::grpc::ClientContext* context, const ::tiro::MejorDisparoRequest& request, ::tiro::MejorDisparoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::tiro::MejorDisparoRequest, ::tiro::MejorDisparoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_MejorDisparo_, context, request, response);
}

void TiroAlBlanco::Stub::async::MejorDisparo(::grpc::ClientContext* context, const ::tiro::MejorDisparoRequest* request, ::tiro::MejorDisparoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::tiro::MejorDisparoRequest, ::tiro::MejorDisparoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_MejorDisparo_, context, request, response, std::move(f));
}

void TiroAlBlanco::Stub::async::MejorDisparo(::grpc::ClientContext* context, const ::tiro::MejorDisparoRequest* request, ::tiro::MejorDisparoResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_MejorDisparo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::tiro::MejorDisparoResponse>* TiroAlBlanco::Stub::PrepareAsyncMejorDisparoRaw(::grpc::ClientContext* context, const ::tiro::MejorDisparoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::tiro::MejorDisparoResponse, ::tiro::MejorDisparoRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_MejorDisparo_, context, request);
}

::grpc::ClientAsyncResponseReader< ::tiro::MejorDisparoResponse>* TiroAlBlanco::Stub::AsyncMejorDisparoRaw(::grpc::ClientContext* context, const ::tiro::MejorDisparoRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncMejorDisparoRaw(context, request, cq);
  result->StartCall();
  return result;
}

TiroAlBlanco::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TiroAlBlanco_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< TiroAlBlanco::Service, ::tiro::CentroRequest, ::tiro::CentroResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](TiroAlBlanco::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tiro::CentroRequest* req,
             ::tiro::CentroResponse* resp) {
               return service->DimeCentroDiana(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TiroAlBlanco_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< TiroAlBlanco::Service, ::tiro::DisparoRequest, ::tiro::DisparoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](TiroAlBlanco::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tiro::DisparoRequest* req,
             ::tiro::DisparoResponse* resp) {
               return service->DisparaCannon(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      TiroAlBlanco_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< TiroAlBlanco::Service, ::tiro::MejorDisparoRequest, ::tiro::MejorDisparoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](TiroAlBlanco::Service* service,
             ::grpc::ServerContext* ctx,
             const ::tiro::MejorDisparoRequest* req,
             ::tiro::MejorDisparoResponse* resp) {
               return service->MejorDisparo(ctx, req, resp);
             }, this)));
}

TiroAlBlanco::Service::~Service() {
}

::grpc::Status TiroAlBlanco::Service::DimeCentroDiana(::grpc::ServerContext* context, const ::tiro::CentroRequest* request, ::tiro::CentroResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TiroAlBlanco::Service::DisparaCannon(::grpc::ServerContext* context, const ::tiro::DisparoRequest* request, ::tiro::DisparoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status TiroAlBlanco::Service::MejorDisparo(::grpc::ServerContext* context, const ::tiro::MejorDisparoRequest* request, ::tiro::MejorDisparoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace tiro

