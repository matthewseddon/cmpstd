#include <cmpstd/tools/tools.h>

#include <eigen3/Eigen/Dense>
#include <rdkit/GraphMol/GraphMol.h>
#include <rdkit/GraphMol/FileParsers/MolSupplier.h>
#include <rdkit/GraphMol/SmilesParse/SmilesWrite.h>
#include <rdkit/GraphMol/SmilesParse/SmilesParse.h>
#include <iostream>

namespace cmpstd {
namespace tools {
void PrintSmiles() {
  std::unique_ptr<RDKit::ROMol> mol(RDKit::SmilesToMol( "Cc1ccccc1" ));
  std::cout << "Num atoms: " << mol->getNumAtoms() << std::endl;
}
  
void PrintHello () {
  std::cout << "Hello!" << std::endl;
  Eigen::Vector2d v{ 3.0, 4.0 };
  std::cout << v.norm () << std::endl;
}
} // namespace tools
} // namespace cmpstd
