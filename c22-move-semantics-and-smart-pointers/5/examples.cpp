#include <iostream>
#include <memory>  // for std::unique_ptr

class Resource {
 public:
  Resource() { std::cout << "Resource acquired\n"; }
  ~Resource() { std::cout << "Resource destroyed\n"; }
};

std::ostream& operator<<(std::ostream& out, const Resource&) {
  out << "I am a resource";
  return out;
}
std::unique_ptr<Resource> createResource() {
  return std::make_unique<Resource>();
}

int main() {
  auto ptr{createResource()};

  // do whatever
  std::cout << "here\n";

  return 0;
}
