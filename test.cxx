#include <iostream>
#include <pistache/endpoint.h>
#include "test.hxx"

using namespace Pistache;

class HelloHandler : public Http::Handler {
	public:
		HTTP_PROTOTYPE(HelloHandler);
		void onRequest(const Http::Request& request, Http::ResponseWriter response) {
			response.send(Http::Code::Ok, "Hello, world\n");
		}
};

int main(){
	std::cout << "Test " << VER << " at " << KERNEL_VER << std::endl;
	Address addr(Ipv4::any(), Port(8080));

	auto opts = Http::Endpoint::options().threads(1);
	Http::Endpoint server(addr);
	server.init(opts);
	server.setHandler(Http::make_handler<HelloHandler>());
	server.serve();
	return 0;
}

