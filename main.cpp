#include"crow.h"
#include<cstdlib>
#include<string>

int main(){
  crow::SimpleApp app;

  CROW_ROUTE(app,"/")([]{
  return "<html><head><title>My C++ Website</title></head>"
    "<body style='font-family:Arial;text-align:center;"
    "background:#101827;color:white;padding:center;'>"
    "<h1>Welcome to My Website</h1>"
    "<P>This website runs using C++.</p>"
    <a href='/api/hello' style='color:#63e6be'>"
    "Test my C++ backend</a></body></html>";
  });
CROW_ROUTE(app,"/api/hello")([]{
  crow::json::wvalue response;
  response["message"]="Your C++ backend is working!";
  return response;
});
const char* env=std::getenv("PORT");
unsigned short port=env
  ? static-cast<unsigned short>(std::stoi(env))
  : 8080;
app.port(port).bindaddr("0.0.0.0)->run();
  }
