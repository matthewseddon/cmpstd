#include "tools.h"
#include <cmpstd/tools/tools.h>

#include <rdkit/GraphMol/GraphMol.h>
#include <rdkit/GraphMol/FileParsers/MolSupplier.h>
#include <rdkit/GraphMol/SmilesParse/SmilesParse.h>
#include <rdkit/GraphMol/MolStandardize/MolStandardize.h>
#include <iostream>
#include <string>

namespace cmpstd {
namespace tools {
std::string StandardizeSmiles(std::string input_smiles) {
    std::string std_smiles = RDKit::MolStandardize::standardizeSmiles(input_smiles);
    return std_smiles;
}
} // namespace tools
} // namespace cmpstd
