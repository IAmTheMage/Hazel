
namespace Hazel {
  __declspec(dllimport) void Test();
}

int main(int argc, char** argv) {
  Hazel::Test();
}