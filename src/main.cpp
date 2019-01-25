#include "CmdLineArgProcessor.hpp"

int main (int argc, char* argv[]) {
  CmdLineArgProcessor token_proc{ argc, argv };
  token_proc.process_args();
  return (0);
}

