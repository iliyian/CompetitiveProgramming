#include <bits/stdc++.h>
using namespace std;

void iterateFilesInFolder(const std::string& folderPath) {
    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        std::cout << entry.path() << std::endl;
    }
}

int main(int argc, char **argv) {
  string folder = "data";
  if (argc > 1) folder = argv[1];
  std::vector<std::string> names;
  for (auto &entry : filesystem::directory_iterator(folder)) {
    if (entry.path().extension() == ".in") {
      names.push_back(entry.path().filename().stem().string());
    }
  }
  for (auto &name : names) {
    std::string main = std::format("main.exe {}/{}.in {}/{}.out", folder, name, folder, name);
    system(main.c_str());
    // std::string bf = std::format("bf.exe {}/{}.in {}/{}.ans", folder, name, folder, name);
    // system(bf.c_str());

    // std::string compareCommand = std::format("fc.exe .\\{}\\{}.out .\\{}\\{}.ans", folder, name, folder, name);
    // if (system(compareCommand.c_str()) != 0) {
    //   std::cerr << "Comparison failed for " << name << std::endl;
    //   return 1;
    // }
  }
  return 0;
}